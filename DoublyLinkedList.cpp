#include "DoublyLinkedList.h"

void DoublyLinkedList::PushFront(const string _data)
{
	// ���� �Ҵ� Node ���� next prev
	// ���->value = _data;
	StringNode* newNode = new StringNode();
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	// head�� nullptr�� ��
	if (nullptr == phead)
	{
		phead = newNode;
		ptail = newNode;
		iCount++;
		return;
	}

	// �� �̿��� ��� - �� �տ� ��� ��� ��ġ, ���� ��带 ���ο� ������ �����Ѵ�
	newNode->pPrev = nullptr;
	newNode->pNext = phead;
	phead->pPrev = newNode;
	phead = newNode;
	
	++iCount;
}

void DoublyLinkedList::PushBack(const string _data)
{
	// ���� �Ҵ� Node ���� next prev
	// ���->value = _data;
	StringNode* newNode = new StringNode();
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	// head�� nullptr�� ��
	if (nullptr == phead)
	{
		phead = newNode;
		ptail = newNode;
		iCount++;
		return;
	}

	// �� �̿��� ��� - �� �տ� ��� ��� ��ġ, ���� ��带 ���ο� ������ �����Ѵ�

	newNode->pNext = nullptr;
	newNode->pPrev = ptail;
	ptail->pNext = newNode;
	ptail = newNode;
	++iCount;
}

void DoublyLinkedList::Insert(int index, const string _data)
{
	
	if (index < 0 || index > iCount)
	{
		cout << "�ε��� ���� �߻�!";
		return;
	}

	// index 0 (PushFront �Լ� ����)
	else if (index == 0)
	{
		PushFront(_data);
	}

	// index iCount -1 (PushBack �Լ� ����)
	else if (index == iCount)
	{
		PushBack(_data);
	}
	else
	{
		StringNode* newNode = new StringNode();
		newNode->value = _data;
		newNode->pNext = nullptr;
		newNode->pPrev = nullptr;

		StringNode* curNode = phead;

		int i = 0;
		while (i < index - 1)
		{
			curNode = curNode->pNext;
			i++;
		}
		newNode->pPrev = curNode;
		newNode->pNext = curNode->pNext;
		curNode->pNext->pPrev = newNode;
		curNode->pNext = newNode;

		iCount++;
	}


}

void DoublyLinkedList::Print()
{
	StringNode* printNode = phead;
	while (printNode != nullptr)
	{
		if (printNode->pNext == nullptr)
		{
			cout << printNode->value << endl;
		}
		else
		{
			cout << printNode->value << " " << "<->" << " ";
			
		}
		printNode = printNode->pNext;
	}
}

void DoublyLinkedList::RemoveFront()
{
	if (phead != nullptr)
	{
		StringNode* remove = phead;
		
		if (nullptr == remove->pNext)
		{
			phead = ptail = nullptr;
		}
		else
		{
			phead = phead->pNext;
			phead->pPrev = nullptr;
		}
		delete remove;
		iCount--;
	}

}

void DoublyLinkedList::RemoveBack()
{
	if (phead != nullptr)
	{
		StringNode* remove = ptail;

		if (nullptr == remove->pPrev)
		{
			phead = ptail = nullptr;
		}
		else
		{
			ptail = ptail->pPrev;
			ptail->pNext = nullptr;
			
		}
		delete remove;
		iCount--;
	}
}

void DoublyLinkedList::RemoveAt(int index)
{
	if (index < 0 || index >= iCount)
	{
		cout << "�ε��� ���� �߻�!" << endl;
		return;
	}

	if (index == 0)
	{
		RemoveFront();
		return;
	}

	if (index == iCount - 1)
	{
		RemoveBack();
		return;
	}

	StringNode* remove = phead;
	int i = 0;
	while (i < index)
	{
		remove = remove->pNext;
		i++;
	}

	remove->pNext->pPrev = remove->pPrev;
	remove->pPrev->pNext = remove->pNext;
	delete remove;
	iCount--;
}
