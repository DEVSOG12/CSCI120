cmake_minimum_required(VERSION 3.23)
project(BlogEntry)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlogEntry  main.cpp test2.cpp Date.cpp Text.cpp BlogEntry.cpp)
