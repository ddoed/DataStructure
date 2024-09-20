#pragma once
#include <iostream>
#include <string>
#include <vector>

// �н� ��ǥ : [Room - User System] �ڷᱸ���� ����ؼ� Ŭ������ ����ڴ�
// 1. List<Ŭ����> iList; <<- �ڷᱸ�� ���ο� Ŭ���� Ÿ���� �����Ѵ�
// 2. class GameRoom{private : vector m_Vector;}

// �濡 ���� ������ ����
// (private) �ʵ� : name : std::string, id : int, level : int
// (public) ��� : getName(), getId(), getLevel(), GetUserInfo()

// GameRoom ������ �����ϴ� Ŭ����
// UserInfo - �迭, �����迭, ������ ����Ʈ�� ����
// addPlayer, deletePlayer, showPlayerList, BanPlayer(�߰� ����), isEmpty, isFull

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
		std::cout << "���� �̸� : " << name << std::endl;
	}
	void GetId()
	{
		std::cout << "���� ���̵� : " << id << std::endl;
	}
	void GetLevel()
	{
		std::cout << "���� ���� : " << level << std::endl;
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
	// ������
	GameRoom(int max = 8)
	{
		maxCount = max;
		userCount = 0;
	}

	// ���
	void AddPlayer(UserInfo& user)
	{
		if (!IsFull())
		{
			users.push_back(user);
			userCount++;
		}
		else
		{
			std::cout << "���� ����á���ϴ�." << std::endl;
		}
	}

	void BanPlayer(int Order)
	{
		if (0 <= Order <= users.size())
		{
			users[Order].GetName();
			std::cout << "��(��) �߹��߽��ϴ�." << std::endl;

			users.erase(users.begin() + Order);

			userCount--;
		}
		else
		{
			std::cout << "�ε����� ��ȿ���� �ʽ��ϴ�." << std::endl;
		}
		
	}

	void ShowListplayer()
	{
		if (IsEmpty())
		{
			std::cout << "�濡 ����� �����ϴ�" << std::endl;
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

	void ClearRoom() // ���� �������� �Լ�
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