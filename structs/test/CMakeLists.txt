cmake_minimum_required(VERSION 3.5)

project(TMP LANGUAGES CXX)

set(GRAPH_TEST_CASE_DIR "${PROJECT_SOURCE_DIR}/GraphTestCase")
set(QUEUE_TEST_CASE_DIR "${PROJECT_SOURCE_DIR}/QueueTestCase")
set(LIST_TEST_CASE_DIR "${PROJECT_SOURCE_DIR}/ListTestCase")
set(STACK_TEST_CASE_DIR "${PROJECT_SOURCE_DIR}/StackTestCase")

add_subdirectory(${GRAPH_TEST_CASE_DIR})
add_subdirectory(${QUEUE_TEST_CASE_DIR})
add_subdirectory(${LIST_TEST_CASE_DIR})
add_subdirectory(${STACK_TEST_CASE_DIR})
