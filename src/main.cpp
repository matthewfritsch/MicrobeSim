#include <iostream>
#include <cstdlib>
#include <thread>

#include "Game.hpp"
#include "Utils.hpp"

#define LOGGER_ENABLE true

using namespace std;

int main(int argc, char** argv)
{
#if !(LOGGER_ENABLE)
	Game game;
#else
	Logger *lgr = new Logger();
	Game game(lgr);
	lgr->Log("All done!");
#endif
	WaitSecs(3);

	return ClearTerm();
}
