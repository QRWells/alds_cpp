cmake_minimum_required(VERSION 3.22)

# Project information
project(alds_cpp
    VERSION 0.0.1
    DESCRIPTION "Algorithms and Data Structures implemented in C++"
    LANGUAGES C CXX)

# ================================

# Global configuration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(benchmark REQUIRED) # Google benchmark

include_directories(${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/src)

# Include directories
add_subdirectory(src)
add_subdirectory(benchmarks)
add_subdirectory(examples)

enable_testing()
add_subdirectory(tests)