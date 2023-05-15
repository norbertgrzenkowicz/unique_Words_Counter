cmake_minimum_required(VERSION 3.20)
project(unique_words)

set (CMAKE_CXX_FLAGS "-Wall -Wextra")

SET(SOURCE_FILES
    src/File_Map.h
    src/File_Map.cpp
    src/main.cpp
    )

add_executable(unique_words ${SOURCE_FILES})