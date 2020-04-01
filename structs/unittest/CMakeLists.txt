cmake_minimum_required(VERSION 3.5)

project(TestStruct LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#enable_testing()

add_executable(TestStruct
    main.cpp
#    tst_testlist.cpp
#    tst_teststack.cpp
#    tst_testqueue.cpp
#    tst_testgraph.cpp
)

target_link_libraries(TestList Qt5::Test)

