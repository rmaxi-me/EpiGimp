add_library(${PROJECT_NAME}Engine
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Application.hpp
        src/Scene.cpp include/Engine/Scene.hpp)

target_include_directories(${PROJECT_NAME}Engine
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME}Engine
    PUBLIC project_warnings project_options CONAN_PKG::imgui-sfml
)
