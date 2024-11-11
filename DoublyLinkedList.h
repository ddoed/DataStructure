#pragma once
#include <iostream>
#include <string>

using namespace std;

// ���� ���� ����Ʈ
// ���� ���� ����Ʈ�� ��� Ȯ��� ���� Node : value, next, prev
// ���� : ������ ���� ã�Ⱑ �� ������
// ���� : �޸� ������ ���� �� ���

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

	// �Է±��
	void PushFront(const string _data);
	void PushBack(const string _data);
	void Insert(int index, const string _data);

	// ��±��
	string FrontValue() { return phead->value; }
	string TailValue() { return ptail->value; }
	void Print(); // ù��° ������ -> ������ ������ ���

	void RemoveFront();
	void RemoveBack();
	void RemoveAt(int index);
	
};