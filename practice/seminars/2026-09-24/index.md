---
title: "24.09.2026 — Основы Си"
parent: Семинары
nav_order: 1
permalink: /tasks/seminars/2026-09-24/
has_children: true
has_toc: false
---

# 24.09.2026 — Основы Си

Семь задач на условия, циклы, функции и строки. Достаточно базовых типов,
операторов и символьных массивов фиксированного размера. Динамическая память,
структуры и рекурсия не нужны.

[Как клонировать репозиторий и подготовить инструменты](../../../tasks.md).
На каждой странице есть команды проверки для Windows, альтернатива для
macOS/Linux и полный разбор под катом.

| Задача | Тема | Тестов |
| --- | --- | ---: |
| [A. Середина из трёх](A-middle/condition.md) | Условия и сравнения | 17 |
| [B. Паспорт числа](B-digits/condition.md) | Цифры числа, деление и остаток | 15 |
| [C. Возрастающий участок](C-increasing-run/condition.md) | Обработка последовательности | 18 |
| [D. Сколько простых?](D-primes/condition.md) | Функции и делители | 16 |
| [E. Слова в строке](E-words/condition.md) | Чтение строки и границы слов | 16 |
| [F. Слово-палиндром](F-palindrome/condition.md) | Индексы строки | 18 |
| [G. Аккуратные пробелы](G-spaces/condition.md) | Посимвольный вывод | 16 |

Решайте по порядку или выбирайте нужную тему для повторения.
Требования к способу решения (например, выделение функции в D) проверяйте
по коду: автоматические тесты проверяют только результат программы.

## Проверить все готовые решения

В Developer PowerShell перейдите из корня репозитория в папку семинара:

```powershell
cd practice/seminars/2026-09-24
cmake -S . -B build-solution -G "NMake Makefiles" -DCOURSE_USE_SOLUTIONS=ON
if ($LASTEXITCODE -ne 0) { throw "Не удалось настроить сборку" }
cmake --build build-solution
if ($LASTEXITCODE -ne 0) { throw "Исправьте ошибки компиляции" }
ctest --test-dir build-solution --output-on-failure
```

Для проверки всех своих `main.c` используйте папку `build` вместо
`build-solution` и параметр `-DCOURSE_USE_SOLUTIONS=OFF`.

<details markdown="1">
<summary>Проверить все готовые решения — macOS / Linux</summary>

Из корня репозитория:

```sh
cd practice/seminars/2026-09-24
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>
