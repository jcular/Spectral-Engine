cmake_minimum_required (VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Core STATIC ${OxygEngine_Core_SRC})

find_package(OpenGL REQUIRED)
target_link_libraries(Core OpenGL)

target_include_directories(Core PUBLIC ${LIBRARIES_INCLUDE_DIR}/Glm)
target_include_directories(Core PUBLIC ${LIBRARIES_INCLUDE_DIR}/Glad)
target_include_directories(Core PUBLIC ${LIBRARIES_INCLUDE_DIR}/KHR)
target_include_directories(Core PUBLIC ${LIBRARIES_INCLUDE_DIR}/GLFW)
target_include_directories(Core PUBLIC "./")
target_include_directories(Core PRIVATE ${LIBRARIES_INCLUDE_DIR}/STB_Image)