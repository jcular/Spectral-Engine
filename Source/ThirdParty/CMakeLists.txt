cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(ThirdParty STATIC ${ThirdParty_SRC})
target_link_libraries(ThirdParty ${CMAKE_CURRENT_SOURCE_DIR}/GLFW/glfw3.lib)
target_link_libraries(ThirdParty ${CMAKE_CURRENT_SOURCE_DIR}/FreeType/freetype281d.lib)

target_include_directories(ThirdParty PUBLIC ${ThirdParty_Include_Dirs})