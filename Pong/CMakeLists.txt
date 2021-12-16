cmake_minimum_required(VERSION 3.13)

project(Pong)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

add_executable(Pong main.cc Ball.cc Ball.h Scoreboard.cc Scoreboard.h)

target_link_libraries(Pong AGE4)
