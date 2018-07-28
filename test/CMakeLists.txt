cmake_minimum_required(VERSION 3.0.0)

project(test)

add_executable(tests
              src/main.cpp
              src/LinkedList.cpp)
target_link_libraries(tests DLL)
target_link_libraries(tests catch)
