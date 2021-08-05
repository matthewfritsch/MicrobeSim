#include <iostream>
#include <cstdlib>
#include <thread>
#include "Game.hpp"

using namespace std;

//wait for `secs` seconds


int main(int argc, char** argv)
{
	
	Game game;
	std::cout << "All done!" << std::endl;
	this_thread::sleep_for(chrono::milliseconds(3000));

	return 0;
}
