cmake_minimum_required(VERSION 3.10)
project(opengl_glfw)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(opengl_glfw source/main.cpp)
target_link_libraries(opengl_glfw GL glfw3 X11 pthread dl glad)

add_custom_command(
        TARGET opengl_glfw POST_BUILD
        COMMAND rsync -r
        ${CMAKE_CURRENT_SOURCE_DIR}/resource/
        ${CMAKE_CURRENT_BINARY_DIR}/resource/
)
