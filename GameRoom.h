#pragma once
#include <iostream>
#include <string>
#include <vector>

// 학습 목표 : [Room - User System] 자료구조를 사용해서 클래스를 만들겠다
// 1. List<클래스> iList; <<- 자료구조 새로운 클래스 타입을 저장한다
// 2. class GameRoom{private : vector m_Vector;}

// 방에 들어온 유저의 정보
// (private) 필드 : name : std::string, id : int, level : int
// (public) 기능 : getName(), getId(), getLevel(), GetUserInfo()

// GameRoom 유저를 저장하는 클래스
// UserInfo - 배열, 가변배열, 연결형 리스트로 저장
// addPlayer, deletePlayer, showPlayerList, BanPlayer(추가 정보), isEmpty, isFull

class UserInfo
{
private:
	std::string name;
	int id;
	int level;
public:
	UserInfo() {}
	UserInfo(std::string name, int id, int level) :
		name(name), id(id), level(level) {}

	void GetName()
	{
		std::cout << "유저 이름 : " << name << std::endl;
	}
	void GetId()
	{
		std::cout << "유저 아이디 : " << id << std::endl;
	}
	void GetLevel()
	{
		std::cout << "유저 레벨 : " << level << std::endl;
	}
	void ShowUserInfo()
	{
		GetName();
		GetId();
		GetLevel();
	}
};

class GameRoom
{
private:
	std::vector<UserInfo> users;
	int maxCount;
	int userCount;
public:
	// 생성자
	GameRoom(int max = 8)
	{
		maxCount = max;
		userCount = 0;
	}

	// 기능
	void AddPlayer(UserInfo& user)
	{
		if (!IsFull())
		{
			users.push_back(user);
			userCount++;
		}
		else
		{
			std::cout << "방이 가득찼습니다." << std::endl;
		}
	}

	void BanPlayer(int Order)
	{
		if (0 <= Order <= users.size())
		{
			users[Order].GetName();
			std::cout << "을(를) 추방했습니다." << std::endl;

			users.erase(users.begin() + Order);

			userCount--;
		}
		else
		{
			std::cout << "인덱스가 유효하지 않습니다." << std::endl;
		}
		
	}

	void ShowListplayer()
	{
		if (IsEmpty())
		{
			std::cout << "방에 사람이 없습니다" << std::endl;
			return;
		}
		for (int i = 0; i < userCount; i++)
		{
			users[i].ShowUserInfo();
		}
	}

	bool IsEmpty()
	{
		return userCount <= 0 ? true : false;
	}

	bool IsFull()
	{
		return userCount >= maxCount ? true : false;
	}

	void ClearRoom() // 방이 없어지는 함수
	{
		users.erase(users.begin(), users.end());
		userCount = 0;
	}
};

void IGameRoomExample()
{
	UserInfo user1("A", 1000, 10);
	UserInfo user2("B", 1001, 10);
	UserInfo user3("C", 1002, 10);

	GameRoom room(3);
	room.AddPlayer(user1);
	room.AddPlayer(user2);
	room.AddPlayer(user3);
	room.ShowListplayer();

	room.ClearRoom();
	room.ShowListplayer();
}