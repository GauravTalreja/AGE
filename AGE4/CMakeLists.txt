cmake_minimum_required(VERSION 3.21)
project(AGE4)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

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
        CursesController.cc Config.h Borders.h)
