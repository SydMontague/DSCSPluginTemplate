cmake_minimum_required (VERSION 3.21)

project ("DSCSPluginTemplate")

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)

# --- Dependencies ---
CPMAddPackage(
  NAME DSCSModLoader
  GITHUB_REPOSITORY "SydMontague/DSCSModLoader"
  GIT_TAG "33f18ca2e3112648ffa31633517c5b1da4d8501c"
)

# --- Building ---
add_library (DSCSPluginTemplate SHARED)

target_sources(DSCSPluginTemplate
    PRIVATE
    "src/DSCSPluginTemplate.cpp"
)

target_link_libraries(DSCSPluginTemplate PRIVATE DSCSModLoader)
