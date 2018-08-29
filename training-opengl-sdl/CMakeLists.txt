cmake_minimum_required(VERSION 3.10)
project(training_opengl_sdl)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cxx)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/source/**.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/source/**.h)

file(GLOB_RECURSE cxx_sources ${CMAKE_CURRENT_SOURCE_DIR}/cxx/**.cpp)
file(GLOB_RECURSE cxx_headers ${CMAKE_CURRENT_SOURCE_DIR}/cxx/**.h)

add_executable(training_opengl_sdl ${sources} ${headers})
target_link_libraries(training_opengl_sdl SDL2 GL glut GLEW)

add_custom_command(
        TARGET training_opengl_sdl POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
        COMMAND rsync -r
        ${CMAKE_CURRENT_SOURCE_DIR}/res/
        ${CMAKE_CURRENT_BINARY_DIR}/res/
)
