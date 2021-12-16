cmake_minimum_required(VERSION 3.13)
project(AGE4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++-10)

add_library(AGE4 STATIC
        AGE4.h
        CursesController.h
        CursesView.cc
        CursesView.h
        Actor.cc
        Actor.h
        InputActions.h
        Game.cc
        Game.h
        Scene.cc
        Scene.h
        Status.cc
        Status.h
        ActorBehavior.cc
        ActorBehavior.h
        Bitmap.cc
        Bitmap.h
        CursesController.cc
        Config.h
        Borders.h)

target_include_directories(AGE4 PUBLIC ./)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

target_include_directories(AGE4 PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(AGE4 PRIVATE ${CURSES_LIBRARIES})
