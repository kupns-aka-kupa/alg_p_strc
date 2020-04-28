cmake_minimum_required(VERSION 3.5)

project(struct)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(TESTS_DIR "${PROJECT_SOURCE_DIR}/test")

add_subdirectory(${SOURCE_DIR})
add_subdirectory(${TESTS_DIR})
