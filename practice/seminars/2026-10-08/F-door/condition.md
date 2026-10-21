---
title: F. Дверь как конечный автомат
parent: "08.10.2026 — Области видимости и модули"
nav_order: 6
permalink: /tasks/seminars/2026-10-08/F-door/
---

# F. Дверь как конечный автомат

**Время: 20 минут.** Реализуйте функции в `door.c` по интерфейсу `door.h`.
`Door` хранит состояние одной двери. Два экземпляра должны работать независимо:
глобального состояния двери быть не должно.

`door_init` устанавливает закрытое, незапертое состояние, в том числе при
повторном вызове. `door_state` возвращает текущее состояние, не меняя его.
`door_apply` применяет событие и возвращает **1 только для разрешённого перехода**.
При запрещённом событии возвращает **0** и сохраняет состояние.

| Состояние | OPEN_EVENT | CLOSE_EVENT | LOCK_EVENT | UNLOCK_EVENT |
| --- | --- | --- | --- | --- |
| CLOSED | OPEN, 1 | CLOSED, 0 | LOCKED, 1 | CLOSED, 0 |
| OPEN | OPEN, 0 | CLOSED, 1 | OPEN, 0 | OPEN, 0 |
| LOCKED | LOCKED, 0 | LOCKED, 0 | LOCKED, 0 | CLOSED, 1 |

В коде ко всем именам из таблицы добавлен префикс `DOOR_`.
Например, повторное открытие уже открытой двери считается запрещённым событием.
Используйте `switch` по состоянию. Все указатели корректны и не равны `NULL`,
объекты инициализированы, события — только значения из `DoorEvent`.
Проверка произвольных целых вместо перечислителей не требуется.
Поля структуры открыты ради упражнения с `struct`, но клиент меняет состояние
только через функции. Непрозрачные типы здесь не требуются.

Готовый `main.c` создаёт две двери и читает до конца файла пары:
номер двери (0 или 1) и команду `o`, `c`, `l`, `u` или `i` (инициализация).
Для каждой пары выводится результат операции и состояния **обеих** дверей
в порядке 0, 1. Для `i` драйвер печатает 1; сама `door_init` ничего не возвращает.
Ввод корректен; менять драйвер и заголовок не нужно.

Объясните, почему `const Door *` подходит для функции чтения, а для изменения
нужен `Door *`. Что даёт `typedef` в объявлениях типов?

## Пример проверки

Ввод:

```text
0 o
0 l
1 l
0 c
1 u
```

Вывод:

```text
1 open closed
0 open closed
1 open locked
1 closed locked
1 closed closed
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
cd practice/seminars/2026-10-08/F-door
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
cd practice/seminars/2026-10-08/F-door
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
