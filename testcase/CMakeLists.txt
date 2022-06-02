project(testcase)
cmake_minimum_required(VERSION 3.12)

include_directories(../third_party/lodepng)
include_directories(../tool)
include_directories(../src)

file(GLOB SOURCES
        ${PROJECT_SOURCE_DIR}/*.h
        ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries (${PROJECT_NAME} third-party)
target_link_libraries (${PROJECT_NAME} tool)