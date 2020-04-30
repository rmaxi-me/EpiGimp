cmake_minimum_required(VERSION 3.14)
project(MediaPlayer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE OFF) # Turn on to debug cmake/make

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

message(STATUS "Setting up conan")
execute_process(COMMAND conan install .. --build=missing)
set(CONAN_CMAKE_SILENT_OUTPUT FALSE)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)

    if (MEDIAPLAYER_ERROR)
        add_compile_options(-Werror)
    endif ()
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(MEDIAPLAYER_DEBUG=1)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_definitions(MEDIAPLAYER_RELEASE=1)
endif ()

add_subdirectory(MediaPlayer)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
