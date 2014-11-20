cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
SET(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
 
# Link runTests with what we want to test and the GTest and pthread library
add_library(Commission Commission.cpp)
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread Commission)
