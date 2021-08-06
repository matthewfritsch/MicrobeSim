add_library(PlagueSrc Console.cpp Game.cpp Utils.cpp main.cpp )
target_include_directories(PlagueSrc PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))
