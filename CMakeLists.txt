cmake_minimum_required(VERSION 3.26)
project(assignment1)

set(CMAKE_CXX_STANDARD 14)

include_directories(assignment1)

add_executable(assignment1
        assignment1/Date.cc
        assignment1/Date.h
        assignment1/defs.h
        assignment1/main.cc
        assignment1/Tester.h
        assignment1/Event.cc
        assignment1/Event.h
        assignment1/PlannerDate.cc
        assignment1/PlannerDate.h
        assignment1/Planner.cc
        assignment1/Planner.h
        assignment1/printTest.cpp
)
