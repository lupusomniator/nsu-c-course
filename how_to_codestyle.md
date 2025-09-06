# Инструкция по оформлению кода

## Базовый стиль: стиль Яндекса

Мы используем **стиль Яндекса** как основу. Коротко о главном:

### Общие правила
* Читаемость важнее «трюков» - простые конструкции предпочтительнее сложных. Например, 
```c
i += 1;
a += i;
```
 лучше, чем
```c
a += ++i;
```
* Одна логическая операция — одна строка; одна мысль — один абзац.
* Имена осмысленные; избегайте «магических чисел» — выносите их в `const`/`enum`.
* Предпочитайте **маленькие** функции, каждая отвечает за одну вещь.
* Обрабатывайте ошибки явно: проверяйте коды возврата/`errno`.

### Синтаксис

* **Только CamelCase для всего, кроме глобальных переменных и макросов.**
  Функции, типы (структуры/enum), имена файловых модулей, поля структур, локальные переменные — всё пишем в *camelCase* (у типов и функций — с Большой Буквы, у локальных — с маленькой).
* **Функции/структуры/enum — `UpperCamelCase`.**
  Структуры начинаются с `T…` (`TMatrix`, `TStudent`), перечисления — с `E…` (`EColor`, `EStatus`). Функции: `ReadArray`, `CalcMean`, `MatrixMultiply`.
* **Локальные переменные — `lowerCamelCase`.**
  Примеры: `rowCount`, `fileHandle`, `inputPath`.
* **Поля структур — `lowerCamelCase`.**
  Примеры: `rows`, `cols`, `data`.
* **Глобальные переменные и макросы — *только* `UPPER_SNAKE_CASE`.**
  Примеры: `GLOBAL_BUFFER`, `MAX_SIZE`. (Глобалы по возможности избегаем.)
* **Скобки обязательны.**
  После `if/for/while/do/else` всегда ставим `{ ... }`, даже если тело в одну строку.
* Отступы — 4 пробелами.

Пример:

```c
// Хорошо
if (needProcess) {
    ProcessItem(item);
}

// Плохо
if (needProcess)
    ProcessItem(item);
```

---

## Архитектурное правило

**В `main.c` допускаются только:**

* функция `main`;
* функции для **парсинга входных данных** (чтение argv/файлов/stdin, базовая валидация, разбор формата).

**Всё остальное** (алгоритмы, вычисления, бизнес-логика, утилиты) вынесите в **модули** в `src/lib`.

Почему так:

* `main.c` остаётся кратким и читабельным;
* модули легко тестировать и переиспользовать;
* проще проводить ревью и отлаживать.

Рекомендуемая структура для каждой лабы:

```
labX/
  src/
    main.c            # только main + разбор входных данных
    lib/
      calc.c
      calc.h
      io.c
      io.h
  CMakeLists.txt
  README.md
```

---


## Публичный интерфейс модулей
### Файлы и модули

* Имя модуля = область ответственности: `calc.c/.h`, `io.c/.h`, `matrix.c/.h`.
* Один модуль — одна тема. Не смешивайте ввод/вывод с вычислениями.

---

### Заголовочный файл (`.h`)

* Только **объявления** функций/типов, необходимые извне.
* Защита от повторного включения (include guard):

```c
#ifndef CALC_H
#define CALC_H

#include <stddef.h>

double calc_mean(const int *a, size_t n);
int    calc_max (const int *a, size_t n, int *out);

#endif // CALC_H
```

### Исходник (`.c`)

* Внутренние (статические) функции помечайте `static` и **не** выносите в `.h`.
* Соблюдайте порядок: includes → локальные макросы/константы → приватные объявления → реализации публичных функций.

### Комментарии и документация

* Комментарии поясняют **зачем**, а не «что делает каждая строка».
* Перед публичной функцией — краткий блок с описанием параметров и кода возврата.

```c
// Вычисляет максимум массива.
// @param a - входной массив
// @param n - размер массива
// @param out - указатель результат операции
// @returns код возврата операции
int CalcMax(const int *a, size_t n, int *out);
```

---

## Пример
### Пример кода в main.c

```c
#include <stdio.h>
#include "lib/io.h"
#include "lib/matrix.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    TMatrix matrix;
    if (!ReadMatrix(argv[1], &matrix)) {
        printf("Error reading matrix\n");
        return 1;
    }

    PrintMatrix(&matrix);
    return 0;
}
```

### Пример модуля

**matrix.h**

```c
#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int *data;
} TMatrix;

void InitMatrix(TMatrix *m, int rows, int cols);
void FreeMatrix(TMatrix *m);
void PrintMatrix(const TMatrix *m);

#endif // MATRIX_H
```

**matrix.c**

```c
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void InitMatrix(TMatrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (int*)malloc(sizeof(int) * rows * cols);
}

void FreeMatrix(TMatrix *m) {
    free(m->data);
    m->data = NULL;
    m->rows = m->cols = 0;
}

void PrintMatrix(const TMatrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}
```

### Пример CMakeLists

Вариант А — перечислять явно:

```cmake
cmake_minimum_required(VERSION 3.5.1)
project(labX C)

set(SRC
    src/main.c
    src/lib/matrix.c
)

add_executable(${PROJECT_NAME} ${SRC})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
```

Вариант Б — автомагически:

```cmake
file(GLOB SRC "src/*.c" "src/lib/*.c")
add_executable(${PROJECT_NAME} ${SRC})
```

