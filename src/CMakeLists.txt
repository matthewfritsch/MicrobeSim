add_library(PlagueSrc main.cpp Game.cpp Console.cpp)

target_include_directories(PlagueSrc PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))
