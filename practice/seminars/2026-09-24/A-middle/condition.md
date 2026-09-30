---
title: A. Середина из трёх
parent: "24.09.2026 — Основы Си"
nav_order: 1
permalink: /tasks/seminars/2026-09-24/A-middle/
---

# A. Середина из трёх

Даны три целых числа. Выведите то число, которое окажется посередине, если расположить их по неубыванию. Числа могут совпадать.

## Формат ввода

Три целых числа `a`, `b`, `c`, разделённые пробелами. Каждое лежит в диапазоне от `−1000000` до `1000000` включительно.

## Формат вывода

Одно целое число — среднее по порядку из трёх. Это не среднее арифметическое.

## Пример 1

Ввод:

```text
8 2 5
```

Вывод:

```text
5
```

## Пример 2

Ввод:

```text
7 7 1
```

Вывод:

```text
7
```

## Примечание

Достаточно переменных и условных операторов. Сортировка массива не требуется.

<details markdown="1">
<summary>Разбор и решение</summary>

{% include_relative explanation.md %}

### Код решения

```c
{% include_relative solution.c %}
```

### Проверить готовое решение — Windows

Один раз [установите инструменты и клонируйте репозиторий]({{ '/tasks/' | relative_url }}).
Откройте **Developer PowerShell for VS**. Из корня клонированного
`nsu-c-course` выполните:

```powershell
cd practice/seminars/2026-09-24/A-middle
cmake -S . -B build-solution -G "NMake Makefiles" -DCOURSE_USE_SOLUTIONS=ON
if ($LASTEXITCODE -ne 0) { throw "Не удалось настроить сборку" }
cmake --build build-solution
if ($LASTEXITCODE -ne 0) { throw "Исправьте ошибки компиляции" }
ctest --test-dir build-solution --output-on-failure
```

Здесь собирается `solution.c`. Ваш `main.c` остаётся на месте, а результаты
сборки решения хранятся отдельно в `build-solution`.
`100% tests passed` означает успех; при ошибке показаны входной файл,
ожидаемый и полученный ответы. Тесты лежат в `tests/*.in` и `tests/*.out`.
Для проверки своего `main.c` используйте [общую инструкцию]({{ '/tasks/' | relative_url }}#как-проверять-решение).

<details markdown="1">
<summary>Проверить готовое решение — macOS / Linux</summary>

Из корня клонированного репозитория:

```sh
cd practice/seminars/2026-09-24/A-middle
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
