cmake_minimum_required(VERSION 3.5)

project(struct)

set(NODES_DIR "${PROJECT_SOURCE_DIR}/node")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/includes")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/sources")
set(TEMPLATE_DIR "${PROJECT_SOURCE_DIR}/templates")

include_directories (
    ${NODES_DIR}
    ${INCLUDE_DIR}
    ${SOURCE_DIR}
    ${TEMPLATE_DIR}
)

file(GLOB SOURCE_FILES
    ${SOURCE_DIR}/*.cpp
)

file(GLOB TEMPLATE_FILES
    ${TEMPLATE_DIR}/*hpp
)

file(GLOB HEADER_FILES
    ${NODES_DIR}/*.hpp
    ${INCLUDE_DIR}/*.hpp
)

add_library(${PROJECT_NAME}
    ${TEMPLATE_FILES}
    ${HEADER_FILES}
)

set_target_properties(${PROJECT_NAME}
 PROPERTIES LINKER_LANGUAGE CXX)

target_link_directories(${PROJECT_NAME}
    PRIVATE
            ${NODES_DIR}
            ${TEMPLATE_DIR}
            ${SOURCE_DIR}
            ${PROJECT_SOURCE_DIR}
    PUBLIC
            ${INCLUDE_DIR}
)


