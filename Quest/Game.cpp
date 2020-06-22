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
//bool Game::run()
//{
//	srand(time(0));
//	bool result = 0;
//	char bufer = 0;
//	int hints = 3;
//	int randomIndex = rand() % list.getSize();
//	Quest current = list.getQuest(randomIndex);
//	answer = current.getAnswer();
//
//	string any(answer.size(), '.');
//
//	do {
//		system("cls");
//		cout << current.getQuestion() << '\n';
//		cout << any << endl;
//		cout << "You have " << hints << " hints \nguess a letter (# - write whole word) ";
//		if (hints <= 0)break;
//		cin >> bufer;
//		if (bufer == filler)break;
//		for (int i = 0; i < answer.size(); i++)
//		{
//			if (bufer == answer[i] || char(bufer - 32) == answer[i])any[i] = answer[i];
//		}
//		hints--;
//	} while (true);
//	cout << "\nwrite your answer: ";
//	cin >> any;
//	for (int i = 0; i < any.size(); i++)
//	{
//		any[i] = toupper(any[i]); // convert to higher registr
//	}
//	cout << any << endl;
//	if (any == answer) {
//		cout << "Congratulation! You gave a wright answer!\n";
//		return 1;
//	}
//	else {
//		cout << "Wrong! Wright answer is : " << answer << "!\n";
//		return 0;
//	}
//}