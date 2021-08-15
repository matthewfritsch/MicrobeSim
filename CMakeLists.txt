cmake_minimum_required(VERSION 3.10)

project(MicrobeSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(src)

set(CMAKE_CXX_FLAGS "-pthread")

add_executable(MicrobeApp src/main.cpp)
target_link_libraries(MicrobeApp LINK_PUBLIC MicrobeSrc)
