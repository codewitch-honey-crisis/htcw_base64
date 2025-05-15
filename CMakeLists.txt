cmake_minimum_required(VERSION 3.24)
project(htcw_base64 VERSION 0.1)
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_library(htcw_base64 src/source/base64.c)
target_include_directories(htcw_base64 PUBLIC
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_BINARY_DIR}"
)
