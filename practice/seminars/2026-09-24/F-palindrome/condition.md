---
title: F. Слово-палиндром
parent: "24.09.2026 — Основы Си"
nav_order: 6
permalink: /tasks/seminars/2026-09-24/F-palindrome/
---

# F. Слово-палиндром

Проверьте, читается ли слово одинаково слева направо и справа налево. Такое слово называется палиндромом.

## Формат ввода

Одно слово длиной от `1` до `1000` символов, состоящее только из строчных латинских букв `a`–`z`. Пробелов нет. Завершающий перевод строки может отсутствовать.

## Формат вывода

Выведите `YES`, если слово является палиндромом, иначе `NO`.

## Пример 1

Ввод:

```text
level
```

Вывод:

```text
YES
```

## Пример 2

Ввод:

```text
hello
```

Вывод:

```text
NO
```

## Примечание

Для хранения слова нужен массив как минимум из 1001 символа с учётом завершающего `\0`. При чтении через `scanf` ограничивайте длину: `%1000s`.

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
cd practice/seminars/2026-09-24/F-palindrome
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
cd practice/seminars/2026-09-24/F-palindrome
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
