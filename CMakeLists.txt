cmake_minimum_required(VERSION 3.5)
project(Lexer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Lexer.cpp Lexer.hpp Token.cpp Token.hpp)
add_executable(Lexer ${SOURCE_FILES})