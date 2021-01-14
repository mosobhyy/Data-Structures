cmake_minimum_required(VERSION 3.15)
project(BSTFCI)

set(CMAKE_CXX_STANDARD 14)

add_executable(BSTFCI main.cpp BSTFCI.cpp BSTFCI.h BSTNode.cpp BSTNode.h)