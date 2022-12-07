cmake_minimum_required(VERSION 3.23)
project(Ch17Heap)

set(CMAKE_CXX_STANDARD 14)

add_executable(ch17Heap ch17-arrayHeap-driver.cpp HeapInterface.h ArrayMaxHeap.hpp)
#add_executable(ch17Heap ch17-heapSort-driver.cpp HeapInterface.h ArrayMaxHeap.hpp)


# Clone Google Test
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/lib/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
    )
endif()

add_subdirectory(lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Unit_Tests_run tests_main.cpp )

target_link_libraries(Unit_Tests_run gtest gtest_main)
#target_link_libraries(Unit_Tests_run ${CMAKE_PROJECT_NAME}_lib)