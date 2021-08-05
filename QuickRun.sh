# Get all .cpp files in src and update the CMakeLists.txt
CPPFILES=$(ls src | grep 'cpp')
OUT="add_library(PlagueSrc "
for var in $CPPFILES
do
	OUT+="$var "
done
OUT+=$')\ntarget_include_directories(PlagueSrc PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))'
echo "$OUT" > src/CMakeLists.txt

# Run cmake build with verbose, and run the program assuming it all succeeds
cmake . > CMakeOutput && cmake --build . -v > CMakeBuildOutput && bin/PlagueApp


