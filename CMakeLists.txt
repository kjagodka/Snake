cmake_minimum_required(VERSION 3.14)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(Snake main.cpp board.cpp board.h coords.h coords.cpp drawer.h drawer.cpp entity.cpp entity.h wall.cpp wall.h snakeSegment.cpp snakeSegment.h snakeBody.cpp snakeBody.h void.cpp void.h snakeHead.cpp snakeHead.h snakeTail.cpp snakeTail.h)

target_link_libraries(Snake ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )