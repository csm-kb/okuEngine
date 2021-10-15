add_library(okuEngine)
target_sources(
    okuEngine
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/okuEngine.cpp
)

add_subdirectory(debug)
add_subdirectory(input)
add_subdirectory(exceptions)
add_subdirectory(renderer)

target_link_libraries(
    okuEngine
    PRIVATE
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
)

target_include_directories(
    okuEngine
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${OPENGL_INCLUDE_PATH}
)