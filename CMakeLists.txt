cmake_minimum_required(VERSION 3.10)
project(VoronoiDiagram)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(Voronoi_Diagram src/main.cpp)
target_link_libraries(Voronoi_Diagram ${OPENGL_LIBRARIES})

install(TARGETS Voronoi_Diagram DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin)