cmake_minimum_required(VERSION 3.23)
project(ch1Bag)

set(CMAKE_CXX_STANDARD 14)

add_executable(ch1Bag main.cpp bag.hpp BagInterface.h)
