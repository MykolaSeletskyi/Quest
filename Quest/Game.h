#pragma once
#include "Quest.h"
#include <ctime>
class Game
{
	static const char filler = '#';
	QuestList list; // default ctor, заповнення питаннями вектору
	Quest quest;
	string userWord;  // шаблон слова, спочатку заповнити певним символом
	void  start()
	{
		quest = list.getQuest(rand() % 3);
	}; // обрати випадковим чином пару запитання–відповідь з бази запитань list
public:
	Game()
	{};
		void run();
		bool updateUserWord(char letter);
	};

