---
title: D. Сколько простых?
parent: "24.09.2026 — Основы Си"
nav_order: 4
permalink: /tasks/seminars/2026-09-24/D-primes/
---

# D. Сколько простых?

Посчитайте простые числа на отрезке от `a` до `b` включительно. Простое число — целое число больше `1`, у которого ровно два положительных делителя: `1` и само число.

Напишите функцию `int IsPrime(int n)`, которая возвращает `1`, если `n` простое, и `0` в противном случае. Используйте её в `main`.

## Формат ввода

Два целых числа `a` и `b`: `1 <= a <= b <= 10000`.

## Формат вывода

Одно целое число — количество простых чисел на отрезке.

## Пример 1

Ввод:

```text
10 20
```

Вывод:

```text
4
```

## Пример 2

Ввод:

```text
1 1
```

Вывод:

```text
0
```

## Примечание

Для проверки одного числа достаточно цикла поиска делителей. Число `1` не является простым. В первом примере простые числа: `11`, `13`, `17`, `19`.

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
cd practice/seminars/2026-09-24/D-primes
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
cd practice/seminars/2026-09-24/D-primes
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
