cmake_minimum_required(VERSION 3.22.1)
set(PROJECT_NAME_STR quidditch-simulator)
project(${PROJECT_NAME_STR} C CXX)

# C++ 20 Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Features of Compiler
#message("Your C++ compiler supports these C++ features:")
#foreach(i ${CMAKE_CXX_COMPILE_FEATURES})
#  message("${i}")
#endforeach()

# For SonarLint
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## BUILD
include_directories(include)

set(SOURCES
    src/main.cpp
    src/Ball.cpp
    src/Player.cpp
    #src/PlayerData.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

## TEST
enable_testing()
add_subdirectory(test)