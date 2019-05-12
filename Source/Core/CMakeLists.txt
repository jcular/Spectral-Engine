cmake_minimum_required (VERSION 3.8)

include(CMakeSources.cmake)

add_library(Core STATIC ${SpectralEngine_Core_SRC})

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})