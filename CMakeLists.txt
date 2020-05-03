cmake_minimum_required(VERSION 3.14)
project(EpiGimp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE OFF) # Turn on to debug cmake/make

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

set(JSON_URL https://github.com/nlohmann/json/releases/download/v3.7.3/json.hpp)
set(JSON_TARGET ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/json/json.hpp)
if (NOT EXISTS ${JSON_TARGET})
    message(STATUS "Downloading JSON dependency")
    file(DOWNLOAD ${JSON_URL} ${JSON_TARGET})
    message(STATUS "Downloading JSON dependency - done")
endif ()
include_directories(Dependencies/json)

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
        # Slows CI builds somehow
        # INSTALL_ARGS -s build_type=${CMAKE_BUILD_TYPE}
)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS TARGETS)
message(STATUS "Setting up conan - done")

if (UNIX)
    add_compile_options(
            -Wall -Wextra

            # FIXME: SFML has effc++ warnings
            # -Weffc++
    )

    if (EPIGIMP_ERROR)
        add_compile_options(-Werror)
    endif ()
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(EPIGIMP_DEBUG=1)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_definitions(EPIGIMP_RELEASE=1)
endif ()

add_subdirectory(Engine)
add_subdirectory(EpiGimp)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
