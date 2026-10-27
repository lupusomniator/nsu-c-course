cmake_minimum_required(VERSION 3.21)
project(homework_1_D LANGUAGES C)

enable_testing()
include("${CMAKE_CURRENT_LIST_DIR}/../../../cmake/Task.cmake")
add_course_task(homework_1_D tokens)
