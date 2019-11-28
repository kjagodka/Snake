cmake_minimum_required(VERSION 3.14)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(Snake main.cpp board.cpp board.h field.cpp field.h coords.h coords.cpp)

target_link_libraries(Snake glfw GLEW::GLEW)