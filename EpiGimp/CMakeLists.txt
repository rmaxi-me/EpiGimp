cmake_minimum_required(VERSION 3.14)

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp
        src/EpiGimpApp.cpp include/EpiGimpApp.hpp)

if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} stdc++fs)
endif ()

target_include_directories(${PROJECT_NAME} PRIVATE include ../Engine/include)
target_link_libraries(
        ${PROJECT_NAME}
        ${PROJECT_NAME}Engine
        CONAN_PKG::sfml CONAN_PKG::imgui-sfml CONAN_PKG::imgui
)
