#pragma once
#include <deque>
#include <vector>
#include <iostream>

/*
* 학습 목표 : Deque에 대해 이해하고 구현한다.
* 
*		Vector와 Deque를 비교해서 설명
* 
*	Vector
* - 임의의 원소 접근하는 시간 O(1)
* - 뒤에서 부터 원소를 삽입할 때 효율적 O(1)
* - 중간에 원소를 삽입 삭제 O(n)     - Node 기반 O(1)
* 
* 
*	Deque
* - 임의의 원소 접근하는 시간 O(1)
* - 앞과 뒤에서 원소를 삽입할 떄 효율적 O(1)
* - 중간에 원소를 삽입 삭제 O(n)
* 
*/

template <typename T>
class MyDeque
{
private:
	std::vector<T*> blocks; // 각 블록을 저장하는 자료구조, 비연속적인 메모리 관리 방식
	int blockSize;			// 블록이 최대로 저장할 수 있는 크기
	int frontIndex;			// 첫번째 블록의 인덱스
	int backIndex;			// 마지막 블록의 인덱스
	int iCount;				// 현재 Deque 저장된 원소의 개수
	int blockNum=0;

	void allocateBlock()	// 블록 생성 함수
	{
		blocks.push_back(new T[blockSize]);
	}

	void addFrontBlock()	// 앞쪽 블록 추가
	{
		blocks.insert(blocks.begin(), new T[blockSize]);
		frontIndex = blockSize - 1;
	}

	void addBackBlock()		// 뒤쪽 블록 추가
	{
		blocks.push_back(new T[blockSize]);
		backIndex = 0;
	}

public:
	// 생성자 & 소멸자
	MyDeque(int blockSize = 4) : blockSize(blockSize), frontIndex(0), backIndex(0), iCount(0)
	{
		allocateBlock();
	}
	~MyDeque()
	{
		for (T* block : blocks)
		{
			delete[] block;
		}

	}

	// Accessor
	int getSize() const { return iCount; }
	bool IsEmpty() const { return iCount == 0 ? true : false; }
	T& getFront() const
	{
		if (IsEmpty())
		{
			throw std::out_of_range("덱이 비었음");
		}
		return blocks[0][frontIndex];
	}
	T& getBack() const
	{
		if (IsEmpty())
		{
			throw std::out_of_range("덱이 비었음");
		}
		return blocks.back()[backIndex-1];
	}

	// Main Method
	void pushFront(const T& data)
	{
		if (frontIndex < 0)
		{
			addFrontBlock();
		}
		blocks[0][frontIndex--] = data;
		++iCount;
	}

	void pushBack(const T& data)
	{
		if (backIndex == blockSize)
		{
			addBackBlock();
		}
		blocks.back()[backIndex++] = data;
		++iCount;
	}

	void popFront()
	{
		if (IsEmpty())
		{
			std::cout << "덱이 비었습니다." << std::endl;
			return;
		}
		++frontIndex;
		--iCount;

		if (frontIndex == blockSize)
		{
			delete[] blocks.front();
			blocks.erase(blocks.begin());
			frontIndex = 0;
		}
	}

	void popBack()
	{
		if (IsEmpty())
		{
			std::cout << "덱이 비었습니다." << std::endl;
			return;
		}
		--backIndex;
		--iCount;

		if (backIndex < 0)
		{
			delete[] blocks.back();
			backIndex = blockSize - 1;
			if (!blocks.empty())
			{
				backIndex = blockSize - 1;
			}
		}
	}
	

};

void IDequeExample()
{
	MyDeque<int> mDeque;
	mDeque.pushFront(1);
	mDeque.pushBack(2);
	mDeque.pushBack(3);
	mDeque.pushBack(4);
	mDeque.pushFront(0);
	mDeque.popFront();

	std::cout << mDeque.getFront() << " " << mDeque.getBack() << std::endl;

}