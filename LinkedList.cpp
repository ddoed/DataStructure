#include "LinkedList.h"

ILinkedList::ILinkedList() : phead(nullptr), ptail(nullptr), iCount(0)
{
}

ILinkedList::~ILinkedList()
{
	while (phead != nullptr) {
		RemoveFront();  // �����ִ� ��� ��� ����
	}
}

IntNode* ILinkedList::GetNode(int index)
{
	int curindex = 0;
	IntNode* curNode = phead;
	while (curindex != index)
	{
		curNode = curNode->pNext;
		curindex++;
	}
	
	return curNode;
}

void ILinkedList::PushFront(const int& _data)
{
	IntNode* pNewNode = new IntNode();
	pNewNode->value = _data;

	if (nullptr == phead) // Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��
	{
		// Head �����͸� ���ο� ���� ����
		phead = pNewNode;
		ptail = pNewNode;
	}
	else
	{
		pNewNode->pNext = phead;
		phead = pNewNode;
	}
	++iCount;
}

void ILinkedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode();
	pNewNode->value = _data;

	if (nullptr == phead) // Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��
	{
		// Head �����͸� ���ο� ���� ����
		phead = pNewNode;
		ptail = pNewNode;
	}
	else
	{
		ptail->pNext = pNewNode;
		ptail = pNewNode;
	}
	++iCount;
}

void ILinkedList::InsertAfter(IntNode* prevNode, const int& _data)
{
	IntNode* pNewNode = new IntNode();
	pNewNode->value = _data;

	pNewNode->pNext = prevNode->pNext;
	prevNode->pNext = pNewNode;
	++iCount;
}

void ILinkedList::RemoveFront()
{
	if (nullptr == phead)
	{
		std::cout << "�����Ͱ� �����ϴ�. ������ ����մϴ�" << std::endl;
		return;
	}
	IntNode* pOldNode = phead;
	if (nullptr == pOldNode->pNext)
	{
		phead = nullptr;
		ptail = nullptr;
	}
	else
	{
		phead = pOldNode->pNext;
		
	}
	delete pOldNode;
	iCount--;
	
}

void ILinkedList::RemoveBack()
{
	if (nullptr == phead)
	{
		std::cout << "�����Ͱ� �����ϴ�. ������ ����մϴ�" << std::endl;
		return;
	}

	IntNode* pOldNode = ptail;
	if (phead == ptail)
	{
		phead = nullptr;
		ptail = nullptr;
	}
	else
	{
		IntNode* curNode = phead;
		while (curNode->pNext != ptail)
		{
			curNode = curNode->pNext;
		}
		curNode->pNext = nullptr;
		ptail = curNode;
	}
	delete pOldNode;
	iCount--;
}

void ILinkedList::FrontValue()
{
	std::cout << "ù��° ������ �� ��� : " << phead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "������ ������ �� ��� : " << ptail->value << std::endl;
}


