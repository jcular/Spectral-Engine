cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

find_package(Threads REQUIRED)

add_library(ThirdParty STATIC ${ThirdParty_SRC})

include(ExternalProject)

# FreeType:

set(FreeType_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/FreeType)

ExternalProject_Add(FreeType_external
    PREFIX          ${FreeType_INSTALL_DIR}
    GIT_REPOSITORY  https://github.com/aseprite/freetype2
    GIT_TAG         VER-2-8-1
    UPDATE_COMMAND  ""
    INSTALL_DIR     ${FreeType_INSTALL_DIR}
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${FreeType_INSTALL_DIR})

target_link_libraries(ThirdParty ${FreeType_INSTALL_DIR}/lib/libfreetype.a)

# GLFW:

set(GLFW_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GLFW)

ExternalProject_Add(glfw_external
    PREFIX         ${GLFW_INSTALL_DIR}
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.2.1
    UPDATE_COMMAND ""
    INSTALL_DIR    ${GLFW_INSTALL_DIR}
    CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${GLFW_INSTALL_DIR}
)

target_link_libraries(ThirdParty ${GLFW_INSTALL_DIR}/lib/libglfw3.a)

find_package(X11 REQUIRED)
target_link_libraries(ThirdParty ${CMAKE_DL_LIBS} ${X11_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(ThirdParty PUBLIC ${ThirdParty_Include_Dirs})