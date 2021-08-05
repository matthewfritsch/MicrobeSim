cmake_minimum_required(VERSION 3.10)

project(PlagueSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(src)

add_executable(PlagueApp src/main.cpp)
target_link_libraries(PlagueApp LINK_PUBLIC PlagueSrc)
