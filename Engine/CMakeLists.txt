cmake_minimum_required(VERSION 3.14)

add_library(
        ${PROJECT_NAME}Engine
        src/Application.cpp include/Engine/Application.hpp
)

target_include_directories(${PROJECT_NAME}Engine PRIVATE include)
target_link_libraries(${PROJECT_NAME}Engine ${CONAN_LIBS})
