cmake_minimum_required(VERSION 3.1)

project("Integer Multiplication")

set(CMAKE_CXX_STANDARD 14)

add_executable(intmult src/integer_multiplication.cc src/karatsuba.cc main.cpp)

include_directories(include)

add_executable(Test src/integer_multiplication.cc src/karatsuba.cc test/first.cpp)

target_compile_options(Test PUBLIC -g)

enable_testing()