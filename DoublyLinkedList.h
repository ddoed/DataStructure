#pragma once
#include <iostream>
#include <string>

using namespace std;

// 이중 연결 리스트
// 단일 연결 리스트의 기능 확장된 버전 Node : value, next, prev
// 장점 : 원소의 값을 찾기가 더 쉬워짐
// 단점 : 메모리 공간을 조금 더 사용

struct StringNode
{
	string value;
	StringNode* pNext;
	StringNode* pPrev;
};

class DoublyLinkedList
{
private:
	StringNode* phead;
	StringNode* ptail;
	int iCount;
public:
	DoublyLinkedList() {}
	~DoublyLinkedList() {}

	// 입력기능
	void PushFront(const string _data);
	void PushBack(const string _data);
	void Insert(int index, const string _data);

	// 출력기능
	string FrontValue() { return phead->value; }
	string TailValue() { return ptail->value; }
	void Print(); // 첫번째 데이터 -> 마지막 데이터 출력

	void RemoveFront();
	void RemoveBack();
	void RemoveAt(int index);
	
};