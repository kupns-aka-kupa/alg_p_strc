cmake_minimum_required(VERSION 3.5)

project(TMP LANGUAGES CXX)

set(MATH_TEST_DIR "${PROJECT_SOURCE_DIR}/MathTestCase")

add_subdirectory(${MATH_TEST_DIR})
