---
title: Задачи
nav_order: 4
permalink: /tasks/
has_children: true
has_toc: false
---

# Задачи

- [Семинары](practice/seminars/index.md) — задачи по темам занятий.
- [Домашки](practice/homework/index.md) — домашние задания с разборами.

Сначала попробуйте решить задачу самостоятельно. На каждой странице есть
раскрываемый блок «Разбор и решение», к которому можно вернуться при повторении.
Все условия, заготовки, решения и тесты хранятся в этом Git-репозитории.

## Подготовка на Windows

Нужны [Git for Windows](https://git-scm.com/downloads/win), CMake 3.21 или новее
и компилятор Си с поддержкой C17. Для команд ниже используйте MSVC:
установите [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/)
с компонентом «Разработка классических приложений на C++» (в него входит и Си)
и [CMake](https://cmake.org/download/) с добавлением в `PATH`.
Если инструменты уже настроены, повторная установка не нужна.

Откройте **Developer PowerShell for VS** через меню «Пуск». Это терминал,
в котором настроены пути к `cl` и `nmake`; подробности есть в
[инструкции по инструментам](how_to_cmake.md#подготовка-инструментов) и
[документации Microsoft](https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line).

Перейдите в папку, где хотите хранить курс, и один раз выполните:

```powershell
git clone https://github.com/lupusomniator/nsu-c-course.git
cd nsu-c-course
```

Если репозиторий уже клонирован, откройте его папку. Повторять `git clone`
для каждой задачи не нужно. Новые материалы можно получить командой `git pull`
из папки репозитория; перед обновлением сохраните свою работу коммитом.

На странице задачи указана команда перехода **из корня `nsu-c-course`**
в её папку. Внутри лежат:

| Файл или папка | Для чего нужен |
| --- | --- |
| `condition.md` | Условие и инструкции |
| `main.c` | Здесь пишите своё решение |
| `solution.c` | Готовое решение из разбора |
| `explanation.md` | Объяснение алгоритма и граничных случаев |
| `tests/*.in`, `tests/*.out` | Входы и ожидаемые ответы |
| `CMakeLists.txt` | Описание сборки и тестов |

## Как проверять решение

В папке выбранной задачи выполните:

```powershell
cmake -S . -B build -G "NMake Makefiles" -DCOURSE_USE_SOLUTIONS=OFF
if ($LASTEXITCODE -ne 0) { throw "Не удалось настроить сборку" }
cmake --build build
if ($LASTEXITCODE -ne 0) { throw "Исправьте ошибки компиляции" }
ctest --test-dir build --output-on-failure
```

Эти команды проверяют **ваш `main.c`**. Заготовка компилируется, но до написания
решения весь набор тестов проходить не должен. Готовое решение проверяется
отдельно — команды приведены внутри разбора.

После изменений сохраните файл и повторите сборку и тесты. Проверки
`$LASTEXITCODE` останавливают выполнение при ошибке, чтобы не запустить старую
версию программы. Сообщение `100% tests passed` означает, что все тесты пройдены.
При неудаче CTest показывает путь к входному файлу и ожидаемый/полученный ответ.
Зависшая программа прерывается через 2 секунды.

<details markdown="1">
<summary>Если у вас уже настроен MinGW-w64 или Visual Studio CMake</summary>

Для MinGW-w64 откройте терминал, где доступны `gcc` и `mingw32-make`, и замените
`-G "NMake Makefiles"` на `-G "MinGW Makefiles"`. Используйте новую папку сборки,
например `build-mingw`, во всех трёх командах.

Если вы собираете проект генератором Visual Studio, укажите конфигурацию:
`cmake --build build --config Debug` и
`ctest --test-dir build -C Debug --output-on-failure`.
Не меняйте генератор в уже настроенной папке сборки.

</details>

<details markdown="1">
<summary>macOS / Linux</summary>

Установите Git, CMake и компилятор с инструментом сборки по
[инструкции](how_to_cmake.md#подготовка-инструментов). Затем:

```sh
git clone https://github.com/lupusomniator/nsu-c-course.git
cd nsu-c-course
```

Перейдите в папку нужной задачи по команде с её страницы и выполните:

```sh
cmake -S . -B build -DCOURSE_USE_SOLUTIONS=OFF &&
cmake --build build &&
ctest --test-dir build --output-on-failure
```

Здесь `&&` запускает следующий шаг только после успешного предыдущего.

</details>
