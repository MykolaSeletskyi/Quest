#include "Game.h"

void Game::run()
{
	start();
	userWord.resize(quest.getAnswer().size(), filler);
	cout << quest.getQuestion();
	char tmp;
	for (size_t i = 0; i < 5; i++)
	{
		std::cin >> tmp;
		i-=updateUserWord(tmp);
		std::cout << userWord<<std::endl;
	}
}

bool Game::updateUserWord(char letter)
{
	size_t index = quest.getAnswer().find(letter);
	if (string::npos!= index)
	{
		userWord[index] = letter;
		return true;
	}
	return false;
	
}
