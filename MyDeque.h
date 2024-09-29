#pragma once
#include <deque>
#include <vector>
#include <iostream>

/*
* �н� ��ǥ : Deque�� ���� �����ϰ� �����Ѵ�.
* 
*		Vector�� Deque�� ���ؼ� ����
* 
*	Vector
* - ������ ���� �����ϴ� �ð� O(1)
* - �ڿ��� ���� ���Ҹ� ������ �� ȿ���� O(1)
* - �߰��� ���Ҹ� ���� ���� O(n)     - Node ��� O(1)
* 
* 
*	Deque
* - ������ ���� �����ϴ� �ð� O(1)
* - �հ� �ڿ��� ���Ҹ� ������ �� ȿ���� O(1)
* - �߰��� ���Ҹ� ���� ���� O(n)
* 
*/

template <typename T>
class MyDeque
{
private:
	std::vector<T*> blocks; // �� ����� �����ϴ� �ڷᱸ��, �񿬼����� �޸� ���� ���
	int blockSize;			// ����� �ִ�� ������ �� �ִ� ũ��
	int frontIndex;			// ù��° ����� �ε���
	int backIndex;			// ������ ����� �ε���
	int iCount;				// ���� Deque ����� ������ ����
	int blockNum=0;

	void allocateBlock()	// ��� ���� �Լ�
	{
		blocks.push_back(new T[blockSize]);
	}

	void addFrontBlock()	// ���� ��� �߰�
	{
		blocks.insert(blocks.begin(), new T[blockSize]);
		frontIndex = blockSize - 1;
	}

	void addBackBlock()		// ���� ��� �߰�
	{
		blocks.push_back(new T[blockSize]);
		backIndex = 0;
	}

public:
	// ������ & �Ҹ���
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
			throw std::out_of_range("���� �����");
		}
		return blocks[0][frontIndex];
	}
	T& getBack() const
	{
		if (IsEmpty())
		{
			throw std::out_of_range("���� �����");
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
			std::cout << "���� ������ϴ�." << std::endl;
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
			std::cout << "���� ������ϴ�." << std::endl;
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