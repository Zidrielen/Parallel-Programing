cmake_minimum_required(VERSION 3.16.0)
project(Lab_1 VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable("program" 
    source/main.cpp
    source/matrix_mult.cpp
    source/matrix_mult.hpp
    source/other.cpp
    source/other.hpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
