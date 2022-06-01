project(tool)
cmake_minimum_required(VERSION 3.22)

file(GLOB SOURCES
	${PROJECT_SOURCE_DIR}/*.h
	${PROJECT_SOURCE_DIR}/*.cpp	)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(lib::tool ALIAS ${PROJECT_NAME})


