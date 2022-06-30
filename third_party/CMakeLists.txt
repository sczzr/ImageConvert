project(third-party)
cmake_minimum_required(VERSION 3.12)
include_directories(./lodepng)

file(GLOB SOURCES
	${PROJECT_SOURCE_DIR}/lodepng/lodepng.h
	${PROJECT_SOURCE_DIR}/lodepng/lodepng.cpp	)

add_library(${PROJECT_NAME} ${SOURCES})
add_library(lib::third ALIAS ${PROJECT_NAME})
