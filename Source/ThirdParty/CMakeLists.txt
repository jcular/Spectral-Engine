cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(ThirdParty STATIC ${ThirdParty_SRC})
target_link_libraries(ThirdParty ${CMAKE_CURRENT_SOURCE_DIR}/FreeType/freetype281d.lib)

# GLFW:

set(GLFW_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GLFW)

include(ExternalProject)

ExternalProject_Add(glfw_external
    PREFIX         ${GLFW_INSTALL_DIR}
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.2.1
    UPDATE_COMMAND ""
    INSTALL_DIR    ${GLFW_INSTALL_DIR}
    CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${GLFW_INSTALL_DIR}
)

add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES IMPORTED_LOCATION ${GLFW_INSTALL_DIR}/lib/glfw3.lib)

target_link_libraries(ThirdParty glfw)

target_include_directories(ThirdParty PUBLIC ${ThirdParty_Include_Dirs})