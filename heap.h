#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// ADT 우선순위큐 -> 가장 큰 수가 우선순위가 가장 높다.

// Heap
// 특징 : 완전 이진 트리의 특징을 가지고 있다

// 가장위의 데이터(노드)를 root라고 부르고 root 1개만 존재
// 각 노드들은 자식을 2개까지 가질 수 있다
// 노드들의 level 이 가득찰 때 까지 자식을 추가하고
// 노드의 자식들을 왼쪽부터 차례대로 채우는 형식

// 종류 : 
// Max Heap : 우선순위가 높은 데이터(큰 수) 가장 큰 수가 올라가는 형태
// Min Heap : 가장 작은 수가 Root 노드에 존재하는 Heap 구조

// Heapify의 규칙
// root의 노드를 pop
// 가장 마지막에 들어온 노드를 root에 넣어준다
// root의 자식들과 부모랑 비교를 해서 큰 수를 부모와 바꾼다
// 최초에 root 들어간 값이 더 이상 변경되지 않을 때 까지 반복

// 부모노드 : (idx - 1) / 2

// 자식노드 : 왼 : idx*2+1 / 오 : idx*2+2

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
			throw std::out_of_range("힙이 비어있습니다.");
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
			throw std::out_of_range("힙이 비어있습니다.");
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
		std::cout << "우선 순위 큐 결과 : " << pQ.pop() << std::endl;
	}
}