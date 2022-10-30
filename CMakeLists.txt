cmake_minimum_required (VERSION 3.21)

project ("DSCSPluginTemplate")

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)

# --- Dependencies ---
CPMAddPackage(
  NAME DSCSModLoader
  GITHUB_REPOSITORY "SydMontague/DSCSModLoader"
  GIT_TAG "72496efb53cada499b77ee28df91775fdaf96c6c"
)

# --- Building ---
add_library (DSCSPluginTemplate SHARED)

target_sources(DSCSPluginTemplate
    PRIVATE
    "DSCSPluginTemplate/DSCSPluginTemplate.cpp"
)

target_link_libraries(DSCSPluginTemplate PRIVATE DSCSModLoader)
