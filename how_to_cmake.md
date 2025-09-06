# Сборка C-кода через CMake

Во всех лабах в корне папки лабы лежит одинаковый CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.5.1)
project(lab0 C)

set(SRC src/main.c)

add_executable(${PROJECT_NAME} ${SRC})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
```

## Что это значит

`project(lab0 C)` — имя проекта/цели: lab0 (в других лабах будет lab1, lab2, …). Исполняемый файл получит то же имя.

`set(SRC src/main.c)` — точка входа ожидается в labX/src/main.c.

`include(common_lab)` — подключает общие правила курса (предупреждения, стандарт и т.п.). Не меняйте эту строку и путь к модулям. Лежит в `modules/common_lab.cmake`

## Что нужно подготовить

1. CMake ≥ 3.5.1
2. Компилятор C: GCC/Clang (Linux/macOS) или MSVC/MinGW-w64 (Windows)

## Сборка на Linux/macOS
Из корня конкретной лабы:
```bash
# 0) Очистка предыдущей сборки
$ rm -rf build

# 1) Конфигурация
$ cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# 2) Компиляция
$ cmake --build build -j

# 3) Запуск
$ ./build/lab0    # в другой лабе имя будет lab1, lab2, ...
```

## Сборка на Windows
```bash
$ rm -rf build
$ cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
$ cmake --build build --config Debug
$ build/Debug/lab0.exe
```

MinGW-w64:
```bash
$ rm -rf build
$ cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
$ cmake --build build -j
$ build/lab0.exe
```

## Может пригодиться
1. Чтобы добавить файлы в проект — либо перечислите их в SRC, либо используйте:
```cmake
file(GLOB SRC src/*.c)
add_executable(${PROJECT_NAME} ${SRC})
```

2. Подача содержимого файла во входной поток программы:
```bash
$ ./build/lab0 < input.txt > output.txt
```

3. Замерить время выполнения программы:
```bash
# Windows (power-shell):
$ Measure-Command { build/lab0.exe }

# Windows  (MinGW) / Linux / MacOS:
$ time build/lab0.exe
```

## Как запустить тесты локально

```bash
# Windows:
$ test/testlab0.exe

# Linux / MacOS:
$ test/testlab0
```