cmake_minimum_required (VERSION 3.0.0)

project (DLL)

set(CMAKE_CXX_STANDARD 14)

add_library(DLL INTERFACE)
target_include_directories(DLL INTERFACE include)

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE ext/catch)

add_subdirectory(test)
