cmake_minimum_required(VERSION 3.5)

project(patterns LANGUAGES CXX)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/inc)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${INCLUDE_DIR}
)

file(GLOB SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/*.cpp
)

file(GLOB HEADER_FILES
    ${PROJECT_SOURCE_DIR}/*.h
)

add_library(${PROJECT_NAME} STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES}
)
