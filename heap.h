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