---
title: B. Объявление или определение?
parent: "08.10.2026 — Области видимости и модули"
nav_order: 2
permalink: /tasks/seminars/2026-10-08/B-declarations/
---

# B. Объявление или определение?

**Время: 5–7 минут.** Каждую строку ниже рассматривайте **отдельно**,
на уровне файла, без предыдущих объявлений. Используем C17, не C++.

```c
extern int counter;       /* 1 */
int counter;              /* 2 */
int counter = 42;         /* 3 */
static int counter;       /* 4 */
extern int counter = 42;  /* 5 */
int next(void);           /* 6 */
```

Для каждой строки выберите наиболее точную метку:
`declaration` — объявление, не являющееся определением;
`tentative-definition` — предварительное определение;
`definition` — определение, не являющееся предварительным.
Любое определение одновременно является объявлением.
Заполните `main.c`: выведите номер и метку для каждой строки.
Это упражнение на классификацию, писать анализатор C не нужно.

Обсудите: какое связывание у имён? Что станет со строками 2 и 4 в конце
единицы трансляции? Почему include guard не исправляет размещение строки 3
в заголовке, включённом в два `.c`? Чем отличается строка 6 от тела функции?

## Пример проверки

Ввод:

```text

```

Вывод:

```text
1 declaration
2 tentative-definition
3 definition
4 tentative-definition
5 definition
6 declaration
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
cd practice/seminars/2026-10-08/B-declarations
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
cd practice/seminars/2026-10-08/B-declarations
cmake -S . -B build-solution -DCOURSE_USE_SOLUTIONS=ON &&
cmake --build build-solution &&
ctest --test-dir build-solution --output-on-failure
```

</details>

</details>
