cmake_minimum_required(VERSION 3.0.0...3.21)
project(okuEngine VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

add_executable(okutest okutest.cpp)

target_include_directories(
    okutest
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${OPENGL_INCLUDE_PATH}
)

set(OKUTEST_LIBS okuEngine)
target_link_libraries(
    okutest
    ${OKUTEST_LIBS}
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
