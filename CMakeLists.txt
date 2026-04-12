cmake_minimum_required(VERSION 4.3.1)
project(utilities_math VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

# Build the library
add_library(math STATIC src/math.cpp)
target_include_directories(math PUBLIC include)

# Tests (only when this is the top-level project)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    enable_testing()
    add_subdirectory(tests)
endif()
