cmake_minimum_required(VERSION 3.19)
project(Voronoi_Diagram)

set(CMAKE_CXX_STANDARD 20)

add_executable(Voronoi_Diagram main.cpp)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Voronoi_Diagram ${SFML_LIBRARIES})
endif()