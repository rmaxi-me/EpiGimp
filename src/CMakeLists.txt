configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Detail/Config/Definitions.hpp.in
    ${CMAKE_CURRENT_SOURCE_DIR}/Detail/Config/Definitions.hpp
    @ONLY
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Detail)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Engine)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/EpiGimp)
