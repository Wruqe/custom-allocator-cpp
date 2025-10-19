cmake_minimum_required(VERSION 3.16)
project(arena_alloc LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic -O2)

# Library
add_library(arena_alloc
    src/BumpAllocator.cpp
)
target_include_directories(arena_alloc PUBLIC include)

# Demo executable
add_executable(arena_demo demo/main.cpp)
target_link_libraries(arena_demo PRIVATE arena_alloc)

# Tests via Catch2 (fetched automatically)
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.10
)
FetchContent_MakeAvailable(catch2)

