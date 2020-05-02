cmake_minimum_required(VERSION 3.15)
project(Socket01)

set(CMAKE_CXX_STANDARD 14)

add_executable(Socket01 main.cpp server.cpp client.cpp)