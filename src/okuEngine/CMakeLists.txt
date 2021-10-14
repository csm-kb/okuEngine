add_library(okuEngine)
target_sources(
    okuEngine
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/okuEngine.cpp
)

add_subdirectory(debug)
add_subdirectory(exceptions)

target_include_directories(
    okuEngine
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)