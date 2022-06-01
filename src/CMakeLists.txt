project(imageConvert)
cmake_minimum_required(VERSION 3.22)

include_directories(../third_party/lodepng)
include_directories(../tool)

file(GLOB SOURCES
	${PROJECT_SOURCE_DIR}/*.h
	${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries (${PROJECT_NAME} third-party)
target_link_libraries (${PROJECT_NAME} tool)
