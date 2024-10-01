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
	std::vector<int> heap;

	void heapifyUp(int idx)
	{
		while (heap[idx] > heap[(idx - 1) / 2])
		{
			std::swap(heap[(idx - 1) / 2], heap[idx]);
			idx = (idx - 1) / 2;
		}


	}

	void heapifyDown(int idx)
	{
		int size = heap.size();
		int largest = idx;
		int left = idx * 2 + 1;
		int right = idx * 2 + 2;

		while (true)
		{
			if (left < size && heap[largest] < heap[left])
			{
				largest = left;
			}

			if (right < size && heap[largest] < heap[right])
			{
				largest = right;
			}

			if (largest == idx)
			{
				break;
			}

			std::swap(heap[largest], heap[idx]);
			idx = largest;
		}
	}

public:
	void push(int _data)
	{
		heap.push_back(_data);
		heapifyUp(heap.size() - 1);
	}
	
	int pop()
	{
		if (heap.empty())
		{
			throw std::out_of_range("���� ����ֽ��ϴ�.");
		}

		int root = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);
		return root;
	}

	int top() const
	{
		if (heap.empty())
		{
			throw std::out_of_range("���� ����ֽ��ϴ�.");
		}

		return heap[0];
	}

	bool empty() const { return heap.empty(); }

	int size() const { return heap.size(); }
	
};

void PriorityQueueExample()
{
	PriorityQueue pQ;
	pQ.push(1);
	pQ.push(3);
	pQ.push(5);
	pQ.push(7);
	pQ.push(9);

	while (!pQ.empty())
	{
		std::cout << "�켱 ���� ť ��� : " << pQ.pop() << std::endl;
	}
}