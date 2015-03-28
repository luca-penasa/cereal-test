project(cereal-testcase)
cmake_minimum_required(VERSION 2.8)
#aux_source_directory(. SRC_LIST)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cereal-git/include)


set (CMAKE_INCLUDE_CURRENT_DIR ON)



add_library(classes SHARED classes.cpp classes.h)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} classes)
