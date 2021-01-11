cmake_minimum_required(VERSION 3.17)
project(cuda)

set(CMAKE_CXX_STANDARD 14)
find_package(CUDA 9.0 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${CUDA_LIBRARIES})
