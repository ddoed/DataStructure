#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// ADT �켱����ť -> ���� ū ���� �켱������ ���� ����.

// Heap
// Ư¡ : ���� ���� Ʈ���� Ư¡�� ������ �ִ�

// �������� ������(���)�� root��� �θ��� root 1���� ����
// �� ������ �ڽ��� 2������ ���� �� �ִ�
// ������ level �� ������ �� ���� �ڽ��� �߰��ϰ�
// ����� �ڽĵ��� ���ʺ��� ���ʴ�� ä��� ����

// ���� : 
// Max Heap : �켱������ ���� ������(ū ��) ���� ū ���� �ö󰡴� ����
// Min Heap : ���� ���� ���� Root ��忡 �����ϴ� Heap ����

// Heapify�� ��Ģ
// root�� ��带 pop
// ���� �������� ���� ��带 root�� �־��ش�
// root�� �ڽĵ�� �θ�� �񱳸� �ؼ� ū ���� �θ�� �ٲ۴�
// ���ʿ� root �� ���� �� �̻� ������� ���� �� ���� �ݺ�

// �θ��� : (idx - 1) / 2

// �ڽĳ�� : �� : idx*2+1 / �� : idx*2+2

class PriorityQueue
{
private:
	std::vector<int> pQueue;
public:
	void heapifyUp(int idx)
	{
		while (true)
		{
			if (pQueue[idx * 2 + 1] > pQueue[idx])
			{
				std::swap(pQueue[idx * 2 + 1], pQueue[idx]);
			}
			else if (pQueue[idx * 2 + 2] > pQueue[idx])
			{
				std::swap(pQueue[idx * 2 + 2], pQueue[idx]);
			}
		}
		
		
	}

	void heapifyDown(int idx)
	{

	}
};