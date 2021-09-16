cmake_minimum_required (VERSION 3.8)

add_library (DSCSPluginTemplate SHARED "DSCSPluginTemplate.cpp" "DSCSPluginTemplate.h")

target_link_libraries(DSCSPluginTemplate PUBLIC ${DSCSMODLOADER_LIBRARY})