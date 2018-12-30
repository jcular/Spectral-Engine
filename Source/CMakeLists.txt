# CMakeList.txt : CMake project for SpectralEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SpectralEngine "main.cpp")

include(CmakeSources.cmake)

set(LIBRARIES_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Header)

add_subdirectory(Core)
target_link_libraries(SpectralEngine Core)

add_library(OpenGL STATIC ${SpectralEngine_Libraries_SRC})
target_include_directories(OpenGL PRIVATE ${LIBRARIES_INCLUDE_DIR}/Glad)
target_include_directories(OpenGL PRIVATE ${LIBRARIES_INCLUDE_DIR}/KHR)

target_link_libraries(SpectralEngine ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/lib/glfw3.lib)

set(EXECUTABLE_OUTPUT_PATH "../bin/executable")
set(LIBRARY_OUTPUT_PATH "../bin/lib")
# TODO: Add tests and install targets if needed.
