#include "LinkedList.h"

ILinkedList::ILinkedList()
{
}

ILinkedList::~ILinkedList()
{
}

void ILinkedList::PushFront(const int& _data)
{
	IntNode* pNewNode = new IntNode();
	pNewNode->value += _data;

	if (nullptr == phead) // Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��
	{
		// Head �����͸� ���ο� ���� ����
		phead = pNewNode;
		ptail = pNewNode;
	}
	
	// ���ο� ����� next �ּҸ� head�� ����Ű���� ������
	pNewNode->pNext = phead;
	phead = pNewNode;
	++iCount;
}

void ILinkedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode();
	pNewNode->value += _data;

	if (nullptr == phead) // Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��
	{
		// Head �����͸� ���ο� ���� ����
		phead = pNewNode;
		ptail = pNewNode;
	}
	ptail->pNext = pNewNode;
	ptail = pNewNode;
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
		phead == nullptr;
		ptail == nullptr;
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
}

void ILinkedList::FrontValue()
{
	std::cout << "ù��° ������ �� ��� : " << phead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "������ ������ �� ��� : " << ptail->value << std::endl;
}


