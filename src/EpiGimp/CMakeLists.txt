add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EpiGimpApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EpiGimpApp.hpp
##    ${CMAKE_CURRENT_SOURCE_DIR}/src/experimental.cpp
)

## if (UNIX AND NOT APPLE)
##     target_link_libraries(${PROJECT_NAME} stdc++fs)
## endif ()

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Engine/include
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE ${PROJECT_NAME}Engine
)
