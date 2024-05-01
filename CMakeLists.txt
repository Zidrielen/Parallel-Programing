cmake_minimum_required(VERSION 3.16.0)
project(Lab_1 VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(PROJECTNAME "program")

add_executable(${PROJECTNAME}
    source/main.cpp
    source/matrix_mult.cpp
    source/matrix_mult.hpp
    source/other.cpp
    source/other.hpp
)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
