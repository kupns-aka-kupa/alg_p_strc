cmake_minimum_required(VERSION 3.5)

project(TestList LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(TestList
    tst_testlist.cpp
    tst_teststack.cpp
    tst_testqueue.cpp
    tst_testgraph.cpp
)
add_test(NAME TestList COMMAND TestList)

target_link_libraries(TestList PRIVATE Qt5::Test)

