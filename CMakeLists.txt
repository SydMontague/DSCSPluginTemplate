cmake_minimum_required (VERSION 3.20)

project ("DSCSPluginTemplate")

set(CMAKE_CXX_STANDARD 20)

find_library(DSCSMODLOADER_LIBRARY DSCSModLoader)
include_directories(${DSCSMODLOADER_INCLUDE_DIR})

add_subdirectory ("DSCSPluginTemplate")
