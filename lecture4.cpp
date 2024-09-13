#include "lectures.h"
#include <iostream>
#include <list>
#include <string>

// 연결 리스트 std::list template

// 게임 아이템. 삭제 추가 인벤토리
// 배열 - 연결 리스트
// 장점 : 임의의 원소 접근이 빠르다 <-> 임의의 원소 접근이 불가능하다
// 단점 : 데이터의 삭제 및 추가가 느리다 <-> 데이터 삭제 및 추가가 빠르다

class Item
{
private:
	int itemCode;
	std::string name;
public:
	Item(int _itemCode, std::string _name) : itemCode(_itemCode), name(_name) {}
	void ShowInfo()
	{
		std::cout << "아이템 코드 : " << itemCode << std::endl;
		std::cout << "아이템 이름 : " << name << std::endl;
	}
};

class Pos
{
private:
	int posX;
	int posY;
	char tag;
public:
	Pos(int x, int y, char v) : posX(x), posY(y), tag(v) {}
};

class Point
{
public:

	Pos data;
	Point* next;
	Point(Pos _data) : data(_data) {}
};

void lecture4()
{
	std::cout << "STL : 연결 리스트" << std::endl;

	
	// 동적할당 std::list<int>* iList = new std::list<int>();

	//std::list<int> iList;
	std::list<Item> inventory;

	Item* newItem = new Item(1001, "깨달음 물약");
	Item* newItem2 = new Item(1002, "해도 3번");
	Item* newItem3 = new Item(1003, "전설 중독 룬");

	inventory.push_front(*newItem);
	inventory.push_back(*newItem2);
	inventory.push_back(*newItem3);
	inventory.pop_back();

	std::list<Item>::iterator iPos = inventory.begin();

	inventory.insert(iPos, 1, *newItem3);
	

	// iterator : 포인터를 일반화시킨 클래스
	std::list<Item>::iterator iterEnd = inventory.end();

	for (std::list<Item>::iterator iterPos = inventory.begin(); iterPos != iterEnd;++iterPos)
	{
		iterPos->ShowInfo();
	}


	// 예제 문제

	// 도형을 클래스로 정의
	// A(50,200) B(20,80) C(75,10) D(130,80) E(100,200)
	// class Pos(posX, posY)

	

	Pos A(50, 200, 'A');
	Pos B(50, 200, 'B');
	Pos C(50, 200, 'C');
	Pos D(50, 200, 'D');
	Pos E(50, 200, 'E');

	std::list<Point> Star;

	Star.push_back(A);
	Star.push_back(B);
	Star.push_back(C);
	Star.push_back(D);
	Star.push_back(E);

	Point A_P = Point(A);
	Point B_P = Point(B);
	Point C_P = Point(C);
	Point D_P = Point(D);
	Point E_P = Point(E);

	A_P.next = &B_P;
	B_P.next = &C_P;
}
