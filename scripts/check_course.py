#!/usr/bin/env python3
"""Validate the reading route and compile/run its complete examples (no student tasks)."""

import argparse
import json
import os
from pathlib import Path
import re
import shlex
import subprocess
import tempfile


ROOT = Path(__file__).resolve().parents[1]
INCLUDE = re.compile(r"{%\s*include_relative\s+([^\s%]+)\s*%}")
SOURCE_LINK = re.compile(r"['\"](/materials/(?:guide/)?examples/[^'\"]+\.c)['\"]\s*\|\s*relative_url")


def load_course():
    return json.loads((ROOT / "_data/course.json").read_text(encoding="utf-8"))


def front_matter(path):
    text = path.read_text(encoding="utf-8")
    match = re.match(r"\A---\n(.*?)\n---\n", text, re.S)
    if match is None:
        raise SystemExit(f"Missing front matter: {path}")
    # Course metadata deliberately uses scalar fields, not general YAML syntax.
    fields = {}
    for line in match.group(1).splitlines():
        key, value = line.split(":", 1)
        fields[key] = value.strip().strip('"')
    return fields


def included_sources(path):
    return [(path.parent / name).resolve()
            for name in INCLUDE.findall(path.read_text(encoding="utf-8"))]


def linked_sources(path):
    return [(ROOT / name.lstrip("/")).resolve()
            for name in SOURCE_LINK.findall(path.read_text(encoding="utf-8"))]


def check_sources():
    course = load_course()
    if not course:
        raise SystemExit("The reading route is empty")
    seen = set()
    urls = set()
    paths = set()
    sources = set()
    for number, chapter in enumerate(course, 1):
        identifier = chapter["id"]
        if identifier in seen or chapter["url"] in urls:
            raise SystemExit(f"Duplicate chapter or URL: {identifier}")
        if not set(chapter["requires"]).issubset(seen):
            raise SystemExit(f"Unknown, later or cyclic dependency: {identifier}")
        if number > 1 and not chapter["requires"]:
            raise SystemExit(f"Missing dependency information: {identifier}")
        path = (ROOT / chapter["path"]).resolve()
        if not path.is_relative_to(ROOT / "materials/guide") or not path.is_file():
            raise SystemExit(f"Missing or invalid chapter path: {path}")
        fields = front_matter(path)
        expected = {
            "lesson": identifier, "permalink": chapter["url"],
            "nav_order": str(number), "parent": "Материалы",
            "title": f"{number}. {chapter['title']}",
        }
        for key, value in expected.items():
            if fields.get(key) != value:
                raise SystemExit(f"{path}: expected {key}: {value}")
        text = path.read_text(encoding="utf-8")
        for include in ("{% include course-context.html %}", "{% include course-nav.html %}"):
            if include not in text:
                raise SystemExit(f"{path}: missing {include}")
        chapter_sources = included_sources(path)
        if not chapter_sources:
            raise SystemExit(f"No complete example in {path}")
        for source in chapter_sources:
            if (not source.is_relative_to(ROOT / "materials/guide/examples")
                    or not source.is_file() or source.suffix not in (".c", ".h")):
                raise SystemExit(f"Invalid source include in {path}: {source}")
        sources.update(chapter_sources)
        for source in linked_sources(path):
            if not source.is_relative_to(ROOT / "materials") or not source.is_file():
                raise SystemExit(f"Invalid linked example: {source}")
            sources.add(source)
        seen.add(identifier)
        urls.add(chapter["url"])
        paths.add(path)
    if paths != set((ROOT / "materials/guide").glob("*.md")):
        raise SystemExit("Some guide pages are missing from the reading route")

    examples = json.loads((ROOT / "scripts/course_examples.json").read_text(encoding="utf-8"))
    tested = {ROOT / source for example in examples for source in example["sources"]}
    if {source for source in sources if source.suffix == ".c"} != tested:
        raise SystemExit("The example manifest must cover exactly the C files included or linked in the guide")
    if len({example["id"] for example in examples}) != len(examples):
        raise SystemExit("Duplicate example identifier")
    print(f"Checked {len(course)} chapters, their dependency order and {len(examples)} examples.", flush=True)
    return examples


def check_builds(examples):
    compiler = shlex.split(os.environ.get("CC", "cl" if os.name == "nt" else "cc"))
    msvc = Path(compiler[0]).stem.lower() == "cl"
    cases = 0
    with tempfile.TemporaryDirectory(prefix="course examples ") as temporary:
        for example in examples:
            if msvc and example.get("requires_vla"):
                print(f"Skipped {example['id']}: VLA is not supported by MSVC.", flush=True)
                continue
            directory = Path(temporary) / example["id"]
            directory.mkdir()
            executable = directory / ("example.exe" if os.name == "nt" else "example")
            sources = [str(ROOT / source) for source in example["sources"]]
            if msvc:
                command = compiler + ["/nologo", "/TC", "/std:c17", "/W4", "/WX", "/utf-8"]
                # Microsoft recommends its own nonstandard I/O API; teach standard C here.
                command += ["/D_CRT_SECURE_NO_WARNINGS"]
                # Some examples deliberately demonstrate constructs warned about by MSVC.
                command += [f"/wd{code}" for code in example.get("msvc_disabled_warnings", [])]
                command += [f"/D{value}" for value in example.get("defines", [])]
                command += sources + [f"/Fe:{executable}"]
            else:
                command = compiler + ["-std=c17", "-Wall", "-Wextra", "-Wpedantic", "-Werror"]
                command += [f"-D{value}" for value in example.get("defines", [])]
                command += sources + ["-o", str(executable)]
                if example.get("math"):
                    command += ["-lm"]
            result = subprocess.run(command, cwd=directory, capture_output=True, text=True, timeout=60)
            if result.returncode:
                raise SystemExit(f"Cannot compile {example['id']}:\n{result.stdout}\n{result.stderr}")
            for case in example["cases"]:
                result = subprocess.run([str(executable)], input=case.get("input", ""),
                                        cwd=directory, capture_output=True, text=True, timeout=5)
                output_matches = (result.stdout == case["output"] if "output" in case else
                                  re.fullmatch(case["output_regex"], result.stdout) is not None)
                if (result.returncode != case.get("exit", 0) or not output_matches or result.stderr):
                    raise SystemExit(f"Unexpected result for {example['id']}: {result}")
                for name, content in case.get("files", {}).items():
                    if (directory / name).read_text(encoding="utf-8") != content:
                        raise SystemExit(f"Unexpected file content: {example['id']}/{name}")
                cases += 1
            print(f"Built and ran {example['id']}.", flush=True)
    print(f"Checked {cases} runs; enabled compiler warnings are treated as errors.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build", action="store_true", help="compile examples and check their results")
    arguments = parser.parse_args()
    examples = check_sources()
    if arguments.build:
        check_builds(examples)
