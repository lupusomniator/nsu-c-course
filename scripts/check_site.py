#!/usr/bin/env python3
"""Check links, assets and section anchors in the generated site, without network access."""

from html.parser import HTMLParser
import json
from pathlib import Path
import re
import sys
from urllib.parse import unquote, urlsplit

from check_course import ROOT, included_sources, load_course


class Page(HTMLParser):
    def __init__(self, path):
        super().__init__()
        self.ids = set()
        self.links = []
        self.code_blocks = []
        self.summaries = []
        self.in_pre = False
        self.in_summary = False
        self.open_details = 0
        self.in_course_nav = False
        self.course_links = []
        self.course_neighbors = {}
        self.feed(path.read_text(encoding="utf-8"))

    def handle_starttag(self, tag, attributes):
        attributes = dict(attributes)
        if tag == "nav" and attributes.get("aria-label") == "Главы курса":
            self.in_course_nav = True
        if tag == "a" and self.in_course_nav:
            self.course_links.append(attributes.get("href"))
            if attributes.get("rel") in ("prev", "next"):
                self.course_neighbors[attributes["rel"]] = attributes.get("href")
        if tag == "pre":
            self.in_pre = True
            self.code_blocks.append("")
        if tag == "summary":
            self.in_summary = True
            self.summaries.append("")
        if tag == "details" and "open" in attributes:
            self.open_details += 1
        if attributes.get("id"):
            self.ids.add(attributes["id"])
        key = "href" if tag in {"a", "link"} else "src"
        if tag in {"a", "link", "img", "script"} and attributes.get(key):
            self.links.append(attributes[key])

    def handle_endtag(self, tag):
        if tag == "nav":
            self.in_course_nav = False
        if tag == "pre":
            self.in_pre = False
        if tag == "summary":
            self.in_summary = False

    def handle_data(self, data):
        if self.in_pre:
            self.code_blocks[-1] += data
        if self.in_summary:
            self.summaries[-1] += data


def main():
    root = Path(sys.argv[1] if len(sys.argv) > 1 else "_site").resolve()
    base = (sys.argv[2] if len(sys.argv) > 2 else "/nsu-c-course").rstrip("/")
    if not (root / "index.html").is_file():
        raise SystemExit("Missing site homepage: " + str(root / "index.html"))

    pages = {path: Page(path) for path in root.rglob("*.html")}
    search_path = root / "assets/js/search-data.json"
    search = json.loads(search_path.read_text(encoding="utf-8"))
    if not search:
        raise SystemExit("The search index is empty.")
    pages[root / "index.html"].links.extend(item["url"] for item in search.values())
    errors = []
    checked = 0
    for source, page in pages.items():
        for href in page.links:
            url = urlsplit(href)
            if url.scheme or url.netloc:
                continue
            path = unquote(url.path)
            if path.startswith("/"):
                if base and path != base and not path.startswith(base + "/"):
                    errors.append(f"{source.relative_to(root)}: outside base URL: {href}")
                    continue
                target = root / path[len(base):].lstrip("/")
            else:
                target = source.parent / path if path else source

            target = target.resolve()
            if target.is_dir():
                target /= "index.html"
            if not target.is_relative_to(root) or not target.is_file():
                errors.append(f"{source.relative_to(root)}: missing target: {href}")
            elif url.fragment and target in pages:
                if unquote(url.fragment) not in pages[target].ids:
                    errors.append(f"{source.relative_to(root)}: missing section: {href}")
            checked += 1

    course = load_course()
    for index, chapter in enumerate(course):
        target = root / chapter["url"].strip("/") / "index.html"
        page = pages.get(target)
        if page is None:
            errors.append(f"Missing chapter: {target}")
            continue
        expected_neighbors = {}
        if index:
            expected_neighbors["prev"] = base + course[index - 1]["url"]
        if index + 1 < len(course):
            expected_neighbors["next"] = base + course[index + 1]["url"]
        if page.course_neighbors != expected_neighbors:
            errors.append(f"Wrong reading navigation: {target}")
        for url in ("/", "/materials/glossary/"):
            if base + url not in page.course_links:
                errors.append(f"Missing course navigation link {url}: {target}")
        for source in included_sources(ROOT / chapter["path"]):
            code = source.read_text(encoding="utf-8").rstrip()
            if not any(block.rstrip() == code for block in page.code_blocks):
                errors.append(f"{target}: rendered example differs from {source}")

    sources = ROOT / "practice"
    tasks = sorted(sources.glob("*/*/*/condition.md"))
    for condition in tasks:
        match = re.search(r"^permalink: (/\S+)$", condition.read_text(encoding="utf-8"), re.M)
        if not match:
            errors.append(f"{condition}: missing permalink")
            continue
        target = root / match.group(1).strip("/") / "index.html"
        page = pages.get(target)
        if page is None:
            errors.append(f"Missing task page: {target}")
            continue
        solution = condition.with_name("solution.c").read_text(encoding="utf-8").rstrip()
        if not any(block.rstrip() == solution for block in page.code_blocks):
            errors.append(f"{target}: rendered code differs from solution.c")
        if "Разбор и решение" not in page.summaries or page.open_details:
            errors.append(f"{target}: missing or initially expanded solution disclosure")
        if "Проверить готовое решение — macOS / Linux" not in page.summaries:
            errors.append(f"{target}: missing macOS/Linux disclosure")
    if list(root.rglob("tests/*.in")) or list(root.rglob("CMakeLists.txt")):
        errors.append("Test/build files should stay in the repository, not the rendered site")
    for removed in ("drafts", "materials/details", "materials/guide/files",
                    "materials/guide/algorithms", "materials/guide/examples/files.c",
                    "materials/guide/examples/search.c"):
        if (root / removed).exists():
            errors.append(f"Deferred or retired material should not be published: {removed}")

    if errors:
        raise SystemExit("\n".join(errors))
    print(f"Checked {checked} internal links/assets across {len(pages)} HTML pages.")
    print(f"Checked rendered solutions and disclosures for {len(tasks)} task pages.")
    print(f"Checked navigation and rendered examples for {len(course)} textbook chapters.")


if __name__ == "__main__":
    main()
