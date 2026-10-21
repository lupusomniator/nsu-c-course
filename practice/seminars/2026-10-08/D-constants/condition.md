---
title: D. Константа в заголовке
parent: "08.10.2026 — Области видимости и модули"
nav_order: 4
permalink: /tasks/seminars/2026-10-08/D-constants/
---

# D. Константа в заголовке

**Время: 7–10 минут.** Здесь важно различать объект с запретом изменения
и целочисленное константное выражение (integer constant expression, ICE).
В `broken/course_limits.h` написано `const int CAPACITY = 4;`.

Проведите два **независимых** эксперимента из каталога задачи:

```sh
cc -std=c17 -pedantic-errors broken/main.c broken/other.c -o broken-demo
cc -std=c17 -pedantic-errors -c broken/ice.c
```

Первый должен завершиться ошибкой компоновки, второй — диагностикой при компиляции.
В Developer PowerShell используйте соответственно:

```powershell
cl /std:c17 /W4 broken/main.c broken/other.c /Fe:broken-demo.exe
cl /std:c17 /W4 /c broken/ice.c
```

Почему в C17 `const` на уровне файла не делает имя внутренним?
Поможет ли `static const int CAPACITY = 4;` в каждом эксперименте?
Поможет ли `extern const int CAPACITY;` с одним определением в `.c`?

Исправьте `course_limits.h` рядом с условием: задайте `CAPACITY = 4` через
`enum` (допустима также объектоподобная макроподстановка).
В `main.c` создайте массив `static int values[CAPACITY]` **на уровне файла**
и функцию со `switch`, возвращающую 1 для `case CAPACITY` и 0 иначе.
Выведите длину массива, результат функции для `CAPACITY` и для `CAPACITY - 1`.

Не заменяйте массив на VLA внутри функции: это обходит вопрос про ICE.
Расширения компилятора не считаются решением. Используйте C17, не C++.

## Пример проверки

Ввод:

```text

```

Вывод:

```text
4 1 0
```

[Команды сборки и проверки](../index.md#проверка). Пустой блок ввода означает,
что программа не читает стандартный ввод. Тесты проверяют результат;
объяснения и требования к устройству модуля проверяйте по коду.

<details markdown="1">
<summary>Разбор и решение</summary>

{% include_relative explanation.md %}

### Код решения (главная программа)

```c
{% include_relative solution.c %}
```

Для многофайловых задач остальные файлы решения приведены в разборе.
Соберите готовое решение с `-DCOURSE_USE_SOLUTIONS=ON` в отдельном `build-solution`.

### Проверить готовое решение — Windows

Из корня репозитория в Developer PowerShell:

```powershell
cd practice/seminars/2026-10-08/D-constants
cmake -S . -B build-solution -G "NMake Makefiles" -DCOURSE_USE_SOLUTIONS=ON
if ($LASTEXITCODE -ne 0) { throw "Не удалось настроить сборку" }
cmake --build build-solution
if ($LASTEXITCODE -ne 0) { throw "Исправьте ошибки компиляции" }
ctest --test-dir build-solution --output-on-failure
```

<details markdown="1">
<summary>Проверить готовое решение — macOS / Linux</summary>

Из корня репозитория:

```sh
cd practice/seminars/2026-10-08/D-constants
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
