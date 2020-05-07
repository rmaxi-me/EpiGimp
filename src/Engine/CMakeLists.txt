add_library(
        ${PROJECT_NAME}Engine
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Application.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Settings/Settings.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Settings/Settings.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Utils/Platform.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Utils/Warnings.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Json.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Scene.hpp
)

target_include_directories(
        ${PROJECT_NAME}Engine
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
        ${PROJECT_NAME}Engine
        PUBLIC project_warnings project_options CONAN_PKG::imgui-sfml
)
