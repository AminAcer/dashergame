cmake_minimum_required(VERSION 3.26)
project(dasher)

add_subdirectory(src/app)
add_subdirectory(src/library)

set(BUILD_SHARED_LIBS ON)

