---
title: G. Аккуратные пробелы
parent: "24.09.2026 — Основы Си"
nav_order: 7
permalink: /tasks/seminars/2026-09-24/G-spaces/
---

# G. Аккуратные пробелы

Удалите пробелы в начале и конце строки, а каждую группу пробелов между словами замените одним пробелом. Буквы и их регистр должны остаться без изменений.

## Формат ввода

Одна строка длиной от `0` до `1000` символов без учёта перевода строки. Разрешены только латинские буквы `a`–`z`, `A`–`Z` и обычный пробел. Табуляций нет. Пустая строка задаётся одним переводом строки. У непустой строки завершающий перевод строки может отсутствовать.

## Формат вывода

Преобразованная строка. Если слов нет, выведите пустую строку. Лишние пробелы, в том числе в конце, считаются ошибкой.

## Пример 1

Ввод:

```text
  Learn   C  together   
```

Вывод:

```text
Learn C together
```

## Пример 2

Ввод:

```text
hello
```

Вывод:

```text
hello
```

## Примечание

Для чтения строки подходит `fgets` и массив `char line[1002]`. В ответе допускается отсутствие последнего перевода строки, но дополнительные пустые строки не допускаются.

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
cd practice/seminars/2026-09-24/G-spaces
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
cd practice/seminars/2026-09-24/G-spaces
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
