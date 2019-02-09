cmake_minimum_required(VERSION 3.8)

enable_testing()

set (GTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/GTest/include)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Test Tests.cpp)

set(GTEST_LIBRARY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/GTest/lib/gtestd.lib)
set(GTEST_MAIN_LIBRARY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/GTest/lib/gtest_maind.lib)

target_link_libraries(Test ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG})

find_package(Core)

include_directories(SpectralEngine_Core_SRC)

target_link_libraries(Test Core)

add_test(Test Test)