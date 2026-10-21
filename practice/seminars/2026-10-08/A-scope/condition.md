---
title: A. Одна переменная или три?
parent: "08.10.2026 — Области видимости и модули"
nav_order: 1
permalink: /tasks/seminars/2026-10-08/A-scope/
---

# A. Одна переменная или три?

**Время: 5 минут.** Откройте `main.c`. До запуска запишите вывод программы.
Для каждого из трёх объектов `x` укажите область видимости имени (scope),
время хранения (storage duration) и связывание (linkage).

1. Почему внутренний `x` меняется между вызовами, а средний — нет?
2. Можно ли обратиться к внутреннему `x` по имени из `main`?
3. Как изменится вывод, если убрать `static` у внутреннего `x`?
4. Независимо от пункта 3: что произойдёт, если заменить `int x = 20;` на `x = 20;`?
5. Что означает `static` перед функцией `show`? Сравните с `static` внутри блока.

Эксперименты делайте по одному и возвращайте исходный код перед CTest:
проверка ожидает вывод исходной программы. На странице пример ниже раскрывает
вывод — сначала сделайте собственный прогноз.

## Пример проверки

Ввод:

```text

```

Вывод:

```text
30 20
31 20
10
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
cd practice/seminars/2026-10-08/A-scope
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
cd practice/seminars/2026-10-08/A-scope
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
