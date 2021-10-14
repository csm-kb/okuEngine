cmake_minimum_required(VERSION 3.0.0...3.21)
project(okuEngine VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

add_executable(okutest okutest.cpp)

target_include_directories(
    okutest
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

set(OKUTEST_LIBS okuEngine SDL2::Main)
target_link_libraries(
    okutest
    ${OKUTEST_LIBS}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
