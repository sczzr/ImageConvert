project(image)
cmake_minimum_required(VERSION 3.12)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)
add_subdirectory(third_party)
add_subdirectory(tool)
add_subdirectory(testcase)