cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(ThirdParty STATIC ${ThirdParty_SRC})

target_include_directories(ThirdParty PUBLIC ${ThirdParty_Include_Dirs})