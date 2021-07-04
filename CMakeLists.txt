cmake_minimum_required(VERSION 3.19)
project(Voronoi_Diagram)

set(CMAKE_CXX_STANDARD 20)

add_executable(Voronoi_Diagram src/main.cpp)

include_directories(include /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Voronoi_Diagram ${SFML_LIBRARIES})
endif()

# Copy dlls to build because such files need to be in the same folder
# as SFML is dynamically linked by default on Windows (cursed platform)
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


install(TARGETS Voronoi_Diagram DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin)