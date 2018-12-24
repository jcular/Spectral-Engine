# CMakeList.txt : CMake project for OxygEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (OxygEngine "main.cpp")

include(Core/CMakeSources.cmake)
add_library(Core STATIC ${OxygEngine_Core_SRC})
add_library(OpenGL STATIC ${OxygEngine_Libraries_SRC})


target_link_libraries(OxygEngine Core)
target_link_libraries(Core OpenGL)
target_link_libraries(OxygEngine ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/lib/glfw3.lib)

set(LIBRARIES_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Header)

target_include_directories(OxygEngine PRIVATE ${LIBRARIES_INCLUDE_DIR}/Glm)
target_include_directories(OxygEngine PRIVATE ${LIBRARIES_INCLUDE_DIR}/Glad)
target_include_directories(OxygEngine PRIVATE ${LIBRARIES_INCLUDE_DIR}/KHR)
target_include_directories(OxygEngine PRIVATE ${LIBRARIES_INCLUDE_DIR}/STB_Image)
target_include_directories(OxygEngine PRIVATE ${LIBRARIES_INCLUDE_DIR}/GLFW)

target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/Glm)
target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/Glad)
target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/KHR)
target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/STB_Image)
target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/GLFW)
target_include_directories(Core PRIVATE "./")

target_include_directories(OpenGL PRIVATE ${LIBRARIES_INCLUDE_DIR}/Glad)
target_include_directories(OpenGL PRIVATE ${LIBRARIES_INCLUDE_DIR}/KHR)

set(EXECUTABLE_OUTPUT_PATH "../bin/executable")
set(LIBRARY_OUTPUT_PATH "../bin/lib")
# TODO: Add tests and install targets if needed.
