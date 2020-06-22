#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::vector;
class Quest
{
	string question;
	string answer;
public:
	Quest() = default;
	Quest(const string& question, const string& answer) :
		question(question),
		answer(answer) {};
	const string& getQuestion() const
	{
		return question;
	}
	const string& getAnswer() const
	{
		return answer;
	}
	Quest &operator =(const Quest& obj)
	{
		if (this != &obj)
		{
		this->question = obj.question;
		this->answer = obj.answer;
		}
		return *this;
	}
};

class QuestList
{
	vector <Quest> list;
public:
	QuestList() 
	{
		list.push_back(Quest("Popular programming language?", "PYTHON"));
		list.push_back(Quest("OOP principle?", "INCAPSULATION"));
		list.push_back({ "Key word for overload operation?", "OPERATOR" });
	};
	const Quest& getQuest(int index) // отримати пару питання-відповідь із  бази
	{
		if (index <list.size())
		{
			return list[index];
		}
		return  list[list.size()-1];
	};
	void pushBack(const Quest& obj)
	{
		list.push_back(obj);
	};
	size_t getSize() const
	{
		return list.size();
	}
};
