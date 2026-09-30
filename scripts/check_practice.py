#!/usr/bin/env python3
"""Validate task materials; optionally build stubs and test solutions with CMake."""

import argparse
from pathlib import Path
import re
import subprocess
import tempfile


ROOT = Path(__file__).resolve().parents[1]


def check_sources():
    tasks = sorted((ROOT / "practice").glob("*/*/*/condition.md"))
    if not tasks:
        raise SystemExit("No practice tasks found")
    total = 0
    groups = set()
    for condition in tasks:
        folder = condition.parent
        groups.add(folder.parent)
        for name in ("main.c", "solution.c", "explanation.md", "CMakeLists.txt"):
            if not (folder / name).is_file():
                raise SystemExit(f"Missing {folder / name}")
        inputs = {path.stem for path in (folder / "tests").glob("*.in")}
        outputs = {path.stem for path in (folder / "tests").glob("*.out")}
        if not inputs or inputs != outputs:
            raise SystemExit(f"Unpaired or missing tests in {folder}")
        text = condition.read_text(encoding="utf-8")
        if "\0" in text:
            raise SystemExit(f"NUL byte in {condition}")
        for include in ("{% include_relative explanation.md %}",
                        "{% include_relative solution.c %}"):
            if include not in text:
                raise SystemExit(f"Missing {include} in {condition}")
        examples = re.findall(
            r"Ввод:\n\n```text\n(.*?)\n```\n\nВывод:\n\n```text\n(.*?)\n```",
            text, re.S,
        )
        if not examples:
            raise SystemExit(f"No examples in {condition}")
        for number, (input_text, output_text) in enumerate(examples, 1):
            for suffix, expected in (("in", input_text), ("out", output_text)):
                test = folder / "tests" / f"{number:02}_example.{suffix}"
                if not test.exists() or test.read_text(encoding="utf-8") != expected + "\n":
                    raise SystemExit(f"Example {number} does not match {test}")
        total += len(inputs)
    print(f"Checked {len(tasks)} tasks, {total} test pairs and all statement examples.", flush=True)
    return sorted(groups)


def run(*command):
    subprocess.run(command, check=True)


def check_builds(groups):
    # Fresh paths catch missing files and do not use the teacher's local builds.
    with tempfile.TemporaryDirectory(prefix="course practice ") as directory:
        for number, group in enumerate(groups):
            for mode in ("OFF", "ON"):
                build = str(Path(directory) / f"group-{number}-{mode}")
                run("cmake", "-S", str(group), "-B", build,
                    f"-DCOURSE_USE_SOLUTIONS={mode}")
                run("cmake", "--build", build, "--config", "Debug")
                if mode == "ON":
                    run("ctest", "--test-dir", build, "-C", "Debug",
                        "--output-on-failure", "--no-tests=error")
            # Each task must also work when opened as an independent IDE project.
            for condition in sorted(group.glob("*/condition.md")):
                build = str(Path(directory) / f"task-{number}-{condition.parent.name}")
                run("cmake", "-S", str(condition.parent), "-B", build,
                    "-DCOURSE_USE_SOLUTIONS=ON")
                run("cmake", "--build", build, "--config", "Debug")
                run("ctest", "--test-dir", build, "-C", "Debug",
                    "--output-on-failure", "--no-tests=error")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build", action="store_true", help="also compile and run CTest")
    args = parser.parse_args()
    groups = check_sources()
    if args.build:
        check_builds(groups)
