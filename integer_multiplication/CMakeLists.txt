cmake_minimum_required(VERSION 3.1)

project("Integer Multiplication")

set(CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")

add_executable(growth src/integer_multiplication.cc src/karatsuba.cc growth.cpp)

add_executable(optimal_t src/integer_multiplication.cc src/karatsuba.cc optimal_t.cpp)

include_directories(include)

add_executable(Test src/integer_multiplication.cc src/karatsuba.cc test/first.cpp)

target_compile_options(Test PUBLIC -g)

enable_testing()