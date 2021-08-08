add_library(MicrobeSrc Board.cpp Console.cpp Game.cpp Microbe.cpp Utils.cpp main.cpp )
target_include_directories(MicrobeSrc PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))
