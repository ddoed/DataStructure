#pragma once

// ���� ���� ����Ʈ : ������ next -> head
// Head�� ���� �������� �ʾƵ� �ȴ� - ��� ��尡 �������� �� �� �ִ�

// ���� ���� ����Ʈ�� head : head->prev : nullptr �ڷᱸ������ ó�� �Է��ϴ� ������
// ���� ���� ����Ʈ ������ : 0, 1, 2, 3, 4, 5
// ���� ���� ����Ʈ�� �������� �ľ��ϴ� �Լ� : ó�� ������ head �ڷᱸ���� ������ �� ����. �������� �Ȱ��� ��尡 ���ö� : �ѹ����� ���Ҵ�

struct cNode
{
	int value;
	cNode* next;
};

class CircularLinkedList
{
private:
	cNode* pHead; // ������
	int iCount;
public:
	int IsEnd()
	{
		cNode* cur = pHead;
		int iCount = 0;
		while (true)
		{
			iCount++;
			cur = cur->next;
			if (cur == pHead)
			{
				return;
			}
		}
		return iCount;
	}
};