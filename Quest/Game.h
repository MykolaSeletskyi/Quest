#pragma once
#include "Quest.h"
#include <ctime>
#include <Windows.h>
class Game
{
	static const size_t MISTAKE = 5;//кількість дозволених помилок(якщо більше то програш)
	static const char FILLER = '#';
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

