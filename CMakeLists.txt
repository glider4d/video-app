cmake_minimum_required(VERSION 3.20.0)
project(videoapp)

set(PROJECT_NAME videoapp)

set(CMAKE_CXX_STANDARD 20)
 
add_subdirectory(lib/glfw)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} glfw)