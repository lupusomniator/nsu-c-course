---
title: B. Паспорт числа
parent: "24.09.2026 — Основы Си"
nav_order: 2
permalink: /tasks/seminars/2026-09-24/B-digits/
---

# B. Паспорт числа

Найдите количество цифр, сумму цифр и наибольшую цифру неотрицательного целого числа. У числа `0` одна цифра, её сумма и максимум равны нулю.

## Формат ввода

Одно целое число `n`, `0 <= n <= 2000000000`. В записи нет ведущих нулей, кроме самого числа `0`.

## Формат вывода

Три целых числа через пробел: количество цифр, сумма цифр, наибольшая цифра.

## Пример 1

Ввод:

```text
5072
```

Вывод:

```text
4 14 7
```

## Пример 2

Ввод:

```text
0
```

Вывод:

```text
1 0 0
```

## Примечание

Решите задачу с помощью целочисленного деления, остатка от деления и цикла, без преобразования числа в строку.

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
cd practice/seminars/2026-09-24/B-digits
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
cd practice/seminars/2026-09-24/B-digits
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
