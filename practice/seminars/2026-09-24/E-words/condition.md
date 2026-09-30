---
title: E. Слова в строке
parent: "24.09.2026 — Основы Си"
nav_order: 5
permalink: /tasks/seminars/2026-09-24/E-words/
---

# E. Слова в строке

Посчитайте слова в строке. Слово — максимальная непустая последовательность латинских букв. Соседние слова разделяются одним или несколькими пробелами. В начале и конце строки тоже могут быть пробелы.

## Формат ввода

Одна строка длиной от `0` до `1000` символов без учёта перевода строки. Разрешены только латинские буквы `a`–`z`, `A`–`Z` и обычный пробел. Табуляций нет. Пустая строка задаётся одним переводом строки. У непустой строки завершающий перевод строки может отсутствовать.

## Формат вывода

Одно целое число — количество слов. Для пустой строки и строки только из пробелов выведите `0`.

## Пример 1

Ввод:

```text
  C   is fun  
```

Вывод:

```text
3
```

## Пример 2

Ввод:

```text
hello
```

Вывод:

```text
1
```

## Примечание

Нужно прочитать всю строку с пробелами, например с помощью `fgets`. Для строки из 1000 символов, перевода строки и завершающего нулевого символа достаточно `char line[1002]`. Перевод строки не является частью слова.

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
cd practice/seminars/2026-09-24/E-words
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
cd practice/seminars/2026-09-24/E-words
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
