project(codec)
cmake_minimum_required(VERSION 3.12)

include_directories(${APP_PATH}/src)
include_directories(${APP_PATH}/tool)

add_executable(${PROJECT_NAME} codec_tc.cpp)

target_link_libraries(${PROJECT_NAME} src)
target_link_libraries(${PROJECT_NAME} third-party)
target_link_libraries(${PROJECT_NAME} tool)