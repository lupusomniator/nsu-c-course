include_guard(GLOBAL)

option(COURSE_USE_SOLUTIONS "Build solution.c instead of the student's main.c" OFF)

function(add_course_task target comparison)
    if(COURSE_USE_SOLUTIONS)
        set(source solution.c)
    else()
        set(source main.c)
    endif()
    message(STATUS "${target}: ${source}")
    add_executable(${target} "${source}")
    set_target_properties(${target} PROPERTIES
        C_STANDARD 17 C_STANDARD_REQUIRED YES C_EXTENSIONS NO)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /utf-8)
        target_compile_definitions(${target} PRIVATE _CRT_SECURE_NO_WARNINGS)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()

    file(GLOB inputs CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.in")
    file(GLOB outputs CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.out")
    if(NOT inputs)
        message(FATAL_ERROR "No tests for ${target}")
    endif()
    foreach(expected IN LISTS outputs)
        get_filename_component(case_name "${expected}" NAME_WE)
        if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/${case_name}.in")
            message(FATAL_ERROR "Missing input for ${expected}")
        endif()
    endforeach()
    foreach(input IN LISTS inputs)
        get_filename_component(case_name "${input}" NAME_WE)
        set(expected "${CMAKE_CURRENT_SOURCE_DIR}/tests/${case_name}.out")
        if(NOT EXISTS "${expected}")
            message(FATAL_ERROR "Missing expected output: ${expected}")
        endif()
        add_test(NAME "${target}.${case_name}"
            COMMAND "${CMAKE_COMMAND}"
                "-DPROGRAM=$<TARGET_FILE:${target}>"
                "-DINPUT=${input}"
                "-DEXPECTED=${expected}"
                "-DMODE=${comparison}"
                -P "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/RunTest.cmake")
        set_tests_properties("${target}.${case_name}" PROPERTIES TIMEOUT 5)
    endforeach()
endfunction()
