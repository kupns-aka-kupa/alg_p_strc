cmake_minimum_required(VERSION 3.5)

project(struct)

set(UTILS_DIR "${PROJECT_SOURCE_DIR}/utils")

set(INCLUDE_DIRi "${PROJECT_SOURCE_DIR}/inc")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

include_directories (
    ${UTILS_DIR}
    ${INCLUDE_DIR}
    ${SOURCE_DIR}
)

file(GLOB SOURCE_FILES
    ${UTILS_DIR}/*.tpp
    ${PROJECT_SOURCE_DIR}/*.tpp
    ${SOURCE_FILES}/*.tpp
    ${HEADER_FILES}/*.tpp
)

file(GLOB HEADER_FILES
    ${UTILS_DIR}/*.hpp
    ${PROJECT_SOURCE_DIR}/*.hpp
    ${SOURCE_FILES}/*.hpp
    ${HEADER_FILES}/*.hpp
)

add_library(${PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

set_target_properties(${PROJECT_NAME}
 PROPERTIES LINKER_LANGUAGE CXX)

target_link_directories(${PROJECT_NAME}
    PRIVATE ${UTILS_DIR}
            ${SOURCE_DIR}
            ${PROJECT_SOURCE_DIR}
    PUBLIC
            ${INCLUDE_DIR}
)


