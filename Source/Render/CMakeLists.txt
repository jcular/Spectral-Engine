cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Render STATIC ${SpectralEngine_Render_SRC})