#pragma once
// Game���� �ֱ� �α׾ƿ��� �ð��� ����ϴ� Ŭ���� ���� ����

#include <stack>
#include <string>
#include <iostream>

class GameData
{
private:
	std::string iDate;
public:
	GameData(std::string _date) : iDate(_date) {}
	std::string GetDate() const {
		return iDate;
	}
};

class GameHistory
{
private:
	std::stack<GameData> GameDatas;
public:
	void SaveLogoutTime(GameData data)
	{
		GameDatas.push(data);
	}

	void PrintLogoutTime()
	{
		if (!GameDatas.empty())
		{
			std::cout << "�ֱ� �α׾ƿ� �� �ð� : " << GameDatas.top().GetDate() << std::endl;
		}
	}
};

void GameHistoryExample()
{
	GameData data1("2024-09-23 0900");
	GameData data2("2024-09-23 0900");
	GameData data3("2024-09-23 0900");
	GameData data4("2024-09-23 0900");
	GameData data5("2024-09-23 1500");

	GameHistory GameDatas;
	GameDatas.SaveLogoutTime(data1);
	GameDatas.SaveLogoutTime(data2);
	GameDatas.SaveLogoutTime(data3);
	GameDatas.SaveLogoutTime(data4);
	GameDatas.SaveLogoutTime(data5);

	GameDatas.PrintLogoutTime();
}
