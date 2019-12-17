cmake_minimum_required(VERSION 3.10.2:)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(branch_and_bound_method)

add_executable(main
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)
