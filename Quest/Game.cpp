#include "Game.h"
void Game::run()
{
	start();
	userWord.resize(quest.getAnswer().size(), FILLER);
	cout << quest.getQuestion();
	char tmp;
	for (int i = 1; i <= MISTAKE; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 20,1 });
		std::cin >> tmp;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,1});
		i-=updateUserWord(tmp);
		std::cout << "Mistake " << i << '\\' << MISTAKE << std::endl;;
		std::cout << userWord<<std::endl;
		if (userWord== quest.getAnswer())
		{
			std::cout << "Win !!!" << std::endl;
			return;
		}
	}
	std::cout << "Loss !!!" << std::endl;
}

bool Game::updateUserWord(char letter)
{
	for (size_t i = 0; i < quest.getAnswer().size(); i++)
	{
		if (quest.getAnswer()[i]== letter&& quest.getAnswer()[i]!= userWord[i])
		{
			userWord[i] = letter;
			return true;
		}
	}
	return false;
}