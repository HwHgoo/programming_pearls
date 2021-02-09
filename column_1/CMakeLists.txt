cmake_minimum_required(VERSION 3.0)
project(column_1)

set(CMAKE_C_STANDARD 99)
#aux_source_directory(*.c ALL_SRCS)
file(GLOB ALL_SRCS *.c)
add_subdirectory(src)
add_executable(${PROJECT_NAME} ${ALL_SRCS})
target_link_libraries(${PROJECT_NAME} myhead)
