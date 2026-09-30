execute_process(
    COMMAND "${PROGRAM}"
    INPUT_FILE "${INPUT}"
    OUTPUT_VARIABLE actual
    ERROR_VARIABLE diagnostic
    RESULT_VARIABLE result
    TIMEOUT 2)

if(NOT "${result}" STREQUAL "0")
    message(FATAL_ERROR
        "Программа завершилась с ошибкой или превысила 2 секунды.\n"
        "Тест: ${INPUT}\nРезультат: ${result}\n stderr: ${diagnostic}")
endif()

file(READ "${EXPECTED}" expected)
string(REPLACE "\r\n" "\n" actual "${actual}")
string(REPLACE "\r\n" "\n" expected "${expected}")
if(MODE STREQUAL "tokens")
    string(STRIP "${actual}" actual)
    string(STRIP "${expected}" expected)
    string(REGEX REPLACE "[ \t\r\n]+" " " actual "${actual}")
    string(REGEX REPLACE "[ \t\r\n]+" " " expected "${expected}")
elseif(MODE STREQUAL "line")
    # Пробелы значимы; только один завершающий перевод строки необязателен.
    string(REGEX REPLACE "\n$" "" actual "${actual}")
    string(REGEX REPLACE "\n$" "" expected "${expected}")
else()
    message(FATAL_ERROR "Неизвестный режим проверки: ${MODE}")
endif()

if(NOT "${actual}" STREQUAL "${expected}")
    string(REPLACE "\n" "\\n" actual "${actual}")
    string(REPLACE "\n" "\\n" expected "${expected}")
    message(FATAL_ERROR
        "Неверный ответ. Тест: ${INPUT}\n"
        "Ожидалось: [${expected}]\nПолучено:  [${actual}]")
endif()
