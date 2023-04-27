cmake_minimum_required(VERSION 3.23)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp matrix/matrix.cpp matrix/matrix.h matrix/testmatrix.cpp customqueue/customqueue.h customqueue/customqueue.cpp customqueue/testqueue.cpp)
