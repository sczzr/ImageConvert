project(src)
cmake_minimum_required(VERSION 3.12)

include_directories(../third_party/lodepng)
include_directories(../tool)
include_directories(./)

file(GLOB SOURCES
        ${PROJECT_SOURCE_DIR}/*.h
        ${PROJECT_SOURCE_DIR}/*.cpp
        ${PROJECT_SOURCE_DIR}/codec/*.h
        ${PROJECT_SOURCE_DIR}/codec/*.cpp
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(lib::src ALIAS ${PROJECT_NAME})
