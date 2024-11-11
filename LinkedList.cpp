#include "LinkedList.h"

ILinkedList::ILinkedList() : phead(nullptr), ptail(nullptr), iCount(0)
{
}

ILinkedList::~ILinkedList()
{
	while (phead != nullptr) {
		RemoveFront();  // 남아있는 노드 모두 해제
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

	if (nullptr == phead) // Head가 가리키고 있는 포인터 null 비어있는 자료구조
	{
		// Head 포인터를 새로운 노드로 변경
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

	if (nullptr == phead) // Head가 가리키고 있는 포인터 null 비어있는 자료구조
	{
		// Head 포인터를 새로운 노드로 변경
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
		std::cout << "데이터가 없습니다. 실행을 취소합니다" << std::endl;
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
		std::cout << "데이터가 없습니다. 실행을 취소합니다" << std::endl;
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
	std::cout << "첫번째 원소의 값 출력 : " << phead->value << std::endl;
}

void ILinkedList::TailValue()
{
	std::cout << "마지막 원소의 값 출력 : " << ptail->value << std::endl;
}


