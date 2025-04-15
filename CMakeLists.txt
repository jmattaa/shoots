cmake_minimum_required(VERSION 3.18)
project(shoots LANGUAGES C)

option(BUILD_RAYLIB_FROM_SOURCE "Build raylib from source" OFF)

set(RAYLIB_VERSION 5.5)
if (BUILD_RAYLIB_FROM_SOURCE)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG ${RAYLIB_VERSION}
    )
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
else()
    find_package(raylib ${RAYLIB_VERSION} REQUIRED)
    if (NOT raylib_FOUND)
        message(FATAL_ERROR "raylib not found, try to set BUILD_RAYLIB_FROM_SOURCE to ON")
    endif()
endif()

include_directories(${raylib_INCLUDE_DIRS})

file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} raylib)
