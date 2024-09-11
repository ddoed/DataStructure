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

	if (nullptr == phead) // Head가 가리키고 있는 포인터 null 비어있는 자료구조
	{
		// Head 포인터를 새로운 노드로 변경
		phead = pNewNode;
		ptail = pNewNode;
	}
	
	// 새로운 노드의 next 주소를 head를 가리키도록 만들어라
	pNewNode->pNext = phead;
	phead = pNewNode;
	++iCount;
}

void ILinkedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode();
	pNewNode->value += _data;

	if (nullptr == phead) // Head가 가리키고 있는 포인터 null 비어있는 자료구조
	{
		// Head 포인터를 새로운 노드로 변경
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
		std::cout << "데이터가 없습니다. 실행을 취소합니다" << std::endl;
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
	std::cout << "첫번째 원소의 값 출력 : " << phead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "마지막 원소의 값 출력 : " << ptail->value << std::endl;
}


