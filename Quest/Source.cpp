#include <iostream>
#include "Quest.h"
#include "Game.h"
using namespace std;
int main() 
{
	std::srand(time(NULL));
	Game game;
	game.run();
	return 0;

}