cmake_minimum_required(VERSION 3.21)
project(rewrite_dir_catalog)

set(CMAKE_CXX_STANDARD 14)

add_executable(rewrite_dir_catalog main.cpp File.cpp File.h Directory.cpp Directory.h)
