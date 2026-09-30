cmake_minimum_required(VERSION 3.21)
project(task_A LANGUAGES C)

enable_testing()
include("${CMAKE_CURRENT_LIST_DIR}/../../../cmake/Task.cmake")
add_course_task(task_A tokens)
