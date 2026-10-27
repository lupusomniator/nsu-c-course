---
title: Примеры для запуска
parent: Начало работы
nav_order: 5
permalink: /materials/examples/
has_toc: false
---

# Примеры для запуска

Все результаты приведены в самих главах; запускать программы для чтения
учебника не обязательно. Здесь можно скачать исходники и воспроизвести
описанное поведение.

## Один исходный файл

Сохраните нужный `.c` в отдельную папку и откройте в ней терминал.
Каждый пример собирается отдельно: у каждого своя функция `main`.

macOS/Linux, на примере `hello.c`:

```sh
cc -std=c17 -Wall -Wextra -Wpedantic hello.c -o hello && ./hello
```

Windows, Developer PowerShell for VS:

```powershell
cl /nologo /TC /std:c17 /W4 /utf-8 /D_CRT_SECURE_NO_WARNINGS hello.c /Fe:hello.exe
if ($LASTEXITCODE -eq 0) { .\hello.exe }
```

Для другой программы замените имена исходного и исполняемого файлов.
Подробное объяснение команд есть в [первой главе](guide/first-program.md).
Если репозиторий уже скачан, примеры основного маршрута находятся в `materials/guide/examples/`,
а программы из прежних статей — в `materials/examples/`.

| Исходник | Что показывает |
| --- | --- |
| [hello.c]({{ '/materials/guide/examples/hello.c' | relative_url }}) | Вывод строки и завершение программы |
| [values.c]({{ '/materials/guide/examples/values.c' | relative_url }}) | Присваивание и пересчёт результата |
| [conditions.c]({{ '/materials/guide/examples/conditions.c' | relative_url }}) | Выбор ветви |
| [readNumber.c]({{ '/materials/guide/examples/readNumber.c' | relative_url }}) | Чтение числа; например, ввод `12` |
| [loops.c]({{ '/materials/guide/examples/loops.c' | relative_url }}) | Сумма в цикле |
| [functions.c]({{ '/materials/guide/examples/functions.c' | relative_url }}) | Параметр и возвращаемое значение |
| [arrays.c]({{ '/materials/guide/examples/arrays.c' | relative_url }}) | Длина и обход массива |
| [strings.c]({{ '/materials/guide/examples/strings.c' | relative_url }}) | Завершающий ноль и изменение строки |
| [pointers.c]({{ '/materials/guide/examples/pointers.c' | relative_url }}) | Обмен значений через адреса |
| [lifetime.c]({{ '/materials/guide/examples/lifetime.c' | relative_url }}) | Обычная и статическая локальные переменные |
| [records.c]({{ '/materials/guide/examples/records.c' | relative_url }}) | Копирование структуры |
| [memory.c]({{ '/materials/guide/examples/memory.c' | relative_url }}) | Выделение и освобождение массива |
| [recursion.c]({{ '/materials/guide/examples/recursion.c' | relative_url }}) | Рекурсивная сумма |
| [bits.c]({{ '/materials/guide/examples/bits.c' | relative_url }}) | Побитовая маска |
| [decimals.c]({{ '/materials/guide/examples/decimals.c' | relative_url }}) | Целое и дробное деление |
| [preprocessor.c]({{ '/materials/guide/examples/preprocessor.c' | relative_url }}) | Простая подстановка макроса |

## Составные примеры

| Исходник | Что разобрано в главе |
| --- | --- |
| [compactString.c]({{ '/materials/guide/examples/compactString.c' | relative_url }}) | Удаление пробелов на месте, два индекса и сохранение непрочитанных данных |
| [pointerRows.c]({{ '/materials/guide/examples/pointerRows.c' | relative_url }}) | Указатель на строку двумерного массива |
| [genericSwap.c]({{ '/materials/guide/examples/genericSwap.c' | relative_url }}) | Универсальный обмен int, double и целых массивов через void* |
| [selectPointer.c]({{ '/materials/guide/examples/selectPointer.c' | relative_url }}) | Изменение адреса через int** |
| [binaryFraction.c]({{ '/materials/guide/examples/binaryFraction.c' | relative_url }}) | Точный перевод дроби в двоичную запись с целочисленными остатками |
| [dynamicBuffer.c]({{ '/materials/guide/examples/dynamicBuffer.c' | relative_url }}) | Растущий массив, вместимость и обработка неудачи realloc |

## Многофайловый пример

Сохраните в одну папку все три файла:
[program.c]({{ '/materials/guide/examples/modules/program.c' | relative_url }}),
[maximum.c]({{ '/materials/guide/examples/modules/maximum.c' | relative_url }}),
[maximum.h]({{ '/materials/guide/examples/modules/maximum.h' | relative_url }}).

macOS/Linux:

```sh
cc -std=c17 -Wall -Wextra -Wpedantic program.c maximum.c -o program && ./program
```

Windows, Developer PowerShell:

```powershell
cl /nologo /TC /std:c17 /W4 /utf-8 program.c maximum.c /Fe:program.exe
if ($LASTEXITCODE -eq 0) { .\program.exe }
```

Результат — `8`. Объяснение находится в главе
[«Программа из нескольких файлов»](guide/modules.md).

## Развёрнутые примеры из основных глав

| Исходник | Тема и особенности |
| --- | --- |
| [structBasics.c]({{ '/materials/examples/structBasics.c' | relative_url }}) | Копирование структуры и передача в функции |
| [structLayout.c]({{ '/materials/examples/structLayout.c' | relative_url }}) | Размеры, выравнивание и `pack`; результат зависит от платформы |
| [macros.c]({{ '/materials/examples/macros.c' | relative_url }}) | Подстановка, повторные вычисления, `#` и `##` |
| [decodeHeader.c]({{ '/materials/examples/decodeHeader.c' | relative_url }}) | Чтение числа из байтов |
| [stackFrames.c]({{ '/materials/examples/stackFrames.c' | relative_url }}) | Вызовы, рекурсия и локальный `static` |
| [variableArray.c]({{ '/materials/examples/variableArray.c' | relative_url }}) | Массив переменной длины; требуется поддержка VLA в GCC/Clang, MSVC не подходит |
| [numberBits.c]({{ '/materials/examples/numberBits.c' | relative_url }}) | Представление объектов; рассчитано на восьмибитный байт и binary32 для `float` |
| [floatPrecision.c]({{ '/materials/examples/floatPrecision.c' | relative_url }}) | Потеря точности; binary32/binary64 и обычное округление к ближайшему |

`#pragma pack` — расширение компилятора; статья рассматривает GCC, Clang и MSVC.
Для `floatPrecision.c` на Linux может понадобиться `-lm` в конце команды.
Для численных примеров не включайте `-ffast-math` и аналогичные режимы:
они меняют допущения о вычислениях.

[Все материалы](../README.md)
