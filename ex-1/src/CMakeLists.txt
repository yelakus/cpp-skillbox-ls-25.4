cmake_minimum_required(VERSION 3.5.0)

add_executable(OperationsSimulator main.cpp ${MY_INCLUDE_DIR}/instruments.h)
target_include_directories(OperationsSimulator PUBLIC ${MY_INCLUDE_DIR})
