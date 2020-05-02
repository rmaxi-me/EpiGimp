cmake_minimum_required(VERSION 3.14)
project(EpiGimp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE OFF) # Turn on to debug cmake/make

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

message(STATUS "Setting up conan")
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_install(
        CONANFILE conanfile.txt
        BUILD missing
        INSTALL_ARGS -s build_type=${CMAKE_BUILD_TYPE}
)

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)

    if (EPIGIMP_ERROR)
        add_compile_options(-Werror)
    endif ()
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(EPIGIMP_DEBUG=1)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_definitions(EPIGIMP_RELEASE=1)
endif ()

add_subdirectory(EpiGimp)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
