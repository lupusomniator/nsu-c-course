---
title: C. Почини чужой модуль
parent: "08.10.2026 — Области видимости и модули"
nav_order: 3
permalink: /tasks/seminars/2026-10-08/C-repair-statistics/
---

# C. Почини чужой модуль

**Время: 10 минут.** В `broken/` находится чужая программа.
Откройте три файла, найдите определения данных и объясните ошибку компоновки.
Из каталога задачи воспроизведите её отдельно:

```sh
cc -std=c17 -Wall -Wextra -Wpedantic broken/main.c broken/statistics.c -o broken-demo
```

В Developer PowerShell:

```powershell
cl /std:c17 /W4 /utf-8 broken/main.c broken/statistics.c /Fe:broken-demo.exe
```

Ожидается отказ компоновки из-за `count` и `sum`, хотя include guard есть.
Объясните, почему замена определений на `extern` и перенос их в один `.c`
исправляет компоновку, но **не обеспечивает инкапсуляцию**.

Затем реализуйте исправленную версию в `statistics.c` рядом с `condition.md`.
Заголовок и проверяющий `main.c` уже подготовлены. Спрячьте `count` и `sum`
внутри модуля с помощью `static`; не объявляйте их в заголовке.
Реализуйте четыре функции из `statistics.h`: добавление числа, число наблюдений,
среднее (для пустого набора `0.0`) и сброс обоих накопителей.
Начальное состояние пустое, в том числе без вызова сброса.
`main.c` менять не нужно. Для этой задачи используются только числа 2 и 4.

Файлы `broken/` намеренно не входят в обычную сборку; CMake собирает
исправляемую версию. Её заготовка компилируется, но пока не проходит тест.

## Пример проверки

Ввод:

```text

```

Вывод:

```text
0 0.00
2 3.00
0 0.00
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
cd practice/seminars/2026-10-08/C-repair-statistics
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
cd practice/seminars/2026-10-08/C-repair-statistics
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
