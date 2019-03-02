cmake_minimum_required (VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Core STATIC ${SpectralEngine_Core_SRC})
include_directories(AFTER Core)

target_include_directories(Core PUBLIC ${LIBRARIES_INCLUDE_DIR}/Glad)
target_include_directories(Core PUBLIC ${LIBRARIES_INCLUDE_DIR}/KHR)
target_include_directories(Core PUBLIC ${LIBRARIES_INCLUDE_DIR}/GLFW)
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/STB_Image)
target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/FreeType)

target_link_libraries(Core ${PROJECT_SOURCE_DIR}/Source/Libraries/lib/freetype281d.lib)