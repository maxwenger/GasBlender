cmake_minimum_required(VERSION 3.5)
project(gas_blender)

SET(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "-DDEBUG")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
 
include_directories(include)

file(GLOB SOURCES "src/*.cpp")
 
add_executable(gas_blender ${SOURCES})
