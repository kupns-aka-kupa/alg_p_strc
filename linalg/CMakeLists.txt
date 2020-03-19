cmake_minimum_required(VERSION 3.5)

project(linalg VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(MODULEV_DIR "${PROJECT_SOURCE_DIR}/pymodule")
set(MATRIX_DIR "${SOURCE_DIR}/matrix")
set(VECTOR_DIR "${SOURCE_DIR}/vector")
set(TENSOR_DIR "${SOURCE_DIR}/tensor")

find_package(PythonLibs REQUIRED)

include_directories(
    ${MODULEV_DIR}
    ${SOURCE_DIR}
    ${MATRIX_DIR}
    ${VECTOR_DIR}
    ${TENSOR_DIR}
    ${PYTHON_INCLUDE_DIRS}
)

file(GLOB SOURCE_FILES
    ${MODULEV_DIR}/*.cpp
    ${SOURCE_DIR}/*.cpp
    ${MATRIX_DIR}/*.cpp
    ${VECTOR_DIR}/*.cpp
    ${TENSOR_DIR}/*.cpp
    main.cpp
)

file(GLOB HEADER_FILES
    ${MODULEV_DIR}/*.h
    ${SOURCE_DIR}/*.h
    ${MATRIX_DIR}/*.h
    ${VECTOR_DIR}/*.h
    ${TENSOR_DIR}/*.h
)

add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
