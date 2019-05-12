cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Render STATIC ${SpectralEngine_Render_SRC})
target_link_libraries(Render Core)

target_include_directories(Render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})