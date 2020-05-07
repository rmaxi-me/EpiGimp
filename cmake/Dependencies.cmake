if(NOT EXISTS ${JSON_TARGET})
  file(DOWNLOAD https://github.com/nlohmann/json/releases/download/v3.7.3/json.hpp
       ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/json/json.hpp)
  message(STATUS "DONE: Downloading JSON dependency")
endif()

# include_directories(Dependencies/json)
