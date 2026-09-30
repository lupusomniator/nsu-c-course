---
title: C. Возрастающий участок
parent: "24.09.2026 — Основы Си"
nav_order: 3
permalink: /tasks/seminars/2026-09-24/C-increasing-run/
---

# C. Возрастающий участок

Дана последовательность чисел. Найдите длину самого длинного непрерывного участка, на котором каждое следующее число строго больше предыдущего. Равные соседние числа прерывают возрастание. Участок из одного числа имеет длину `1`.

## Формат ввода

Сначала целое число `n`, `1 <= n <= 1000`, затем `n` целых чисел от `−1000000` до `1000000`. Числа разделены пробелами или переводами строк.

## Формат вывода

Одно целое число — максимальная длина такого участка.

## Пример 1

Ввод:

```text
8
1 2 2 3 4 0 5 6
```

Вывод:

```text
3
```

## Пример 2

Ввод:

```text
4
9 7 7 1
```

Вывод:

```text
1
```

## Примечание

Числа можно обрабатывать по мере чтения, не сохраняя всю последовательность. Нельзя пропускать элементы: в последовательности `1 3 2 4` ответ `2`, а не `3`.

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
cd practice/seminars/2026-09-24/C-increasing-run
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
cd practice/seminars/2026-09-24/C-increasing-run
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
