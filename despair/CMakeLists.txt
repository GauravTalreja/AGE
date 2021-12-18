cmake_minimum_required(VERSION 3.13)

project(despair)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

add_executable(despair main.cc X.cc X.h P.cc P.h)

target_link_libraries(despair AGE4)
