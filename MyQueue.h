#pragma once
#include <iostream>
#include <queue>

using namespace std;

/*
* 자료구조 : 컨테이너를 변형해서 순서를 정해두고 사용하는 어댑터 자료구조
* 
* 큐 자료구조 구현
* - 데이터가 출력되는 인덱스를 front이름으로 표현
* - 데이터가 저장되는 인덱스를 rear 이름으로 표현
* - 선형 큐 front rear 초기값으로 되돌아갈 수 없다.
*/

// 구현해야할 함수
// 입력 및 삭제 : push, pop
// 필드 값 표현 : empty(), size(), front(), back()

template <typename T>
class ArrayBasedQueue
{
private:
	T* queue; // 데이터를 저장하기위한 배열 이름
	int front; // 출력 위치를 가리키는 인덱스
	int rear; // 데이터 입력 위치를 가리키는 인덱스
	int iCount; // 현재 자료구조의 원소의 갯수
	class Iterator
	{
	private:
		T* ptr;
	public:
		Iterator() : ptr(nullptr) {}
		Iterator(T* ptr) : ptr(ptr) {}

		T& operator*()
		{
			return *ptr;
		}

		Iterator& operator++()
		{
			ptr++;
			return *this;

		}

		Iterator& operator++(int)
		{
			iterator temp = *this;
			ptr++;
			return temp;
		}

		Iterator operator+(const int count)
		{
			Iterator temp = *this;
			temp.ptr += count;
			return temp;
		}

		bool operator==(const Iterator& other)
		{
			return ptr == other.ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return ptr != other.ptr;
		}
	};
	// iterator 허용된 함수
public:
	using iterator = Iterator; // using -> typedef
	iterator begin() { return iterator(queue); }
	iterator end() { return begin() + iCount; }
public:
	// 생성자
	ArrayBasedQueue(int size = 10)
	{
		queue = new T[size];
		front = 0;
		rear = 0;
		iCount = 0;
	}
	~ArrayBasedQueue()
	{
		delete[] queue;
	}

	// 필드에 접근을 위한 함수
	
	int size()
	{
		return iCount;
	}
	T getfront()
	{
		return queue[front];
	}
	
	T getback()
	{
		return queue[rear-1];
	}

	bool empty()
	{
		return (iCount == 0) ? true : false;
	}

	void push(T data)
	{
		queue[iCount] = data;
		rear++;
		iCount++;
	}

	void pop()
	{
		if (iCount != 0)
		{
			front++;
			iCount--;
		}
		else
		{
			std::cout << "비었습니다" << std::endl;
		}
			
	}

	void print()
	{
		std::cout << "Front Index : " << front << std::endl;
		std::cout << "Rear Index : " << rear << std::endl;
		std::cout << "Queue Count : " << iCount << std::endl;
	}

	// Main Method 기능을 위한 함수 : 삽입, 삭제
};

template <typename T>
class LinkedQueue
{
private:
	struct QueueNode
	{
		T		   data;
		QueueNode* pNext;

		QueueNode(T data, QueueNode* pNode)
		{
			this->data = data;
			pNext = pNode;
		}
	};

	QueueNode*	front;
	QueueNode*	rear;
	int			iCount;
public:
	// 생성자 & 소멸자
	LinkedQueue()
	{
		front	= nullptr;
		rear	= nullptr;
		iCount	= 0;
	}
	~LinkedQueue() 
	{
		while (!Empty())
		{
			Pop();
		}
	}
	// Accessor
	T Front()
	{
		return front->data;
	}

	T Back()
	{
		return rear->data;
	}

	int Size()
	{
		return iCount;
	}

	bool Empty()
	{
		return iCount == 0 ? true : false;
	}

	void Push(T data)
	{
		QueueNode* newNode = new QueueNode(data, nullptr);

		if (Empty())
		{
			front	= newNode;
			rear	= newNode;
		}
		else
		{
			rear->pNext = newNode;
			rear = newNode;
		}
		iCount++;
	}

	void Pop()
	{
		if (Empty()) return;
		QueueNode* OldNode = front;
		front = front->pNext;
		delete OldNode;
		iCount--;
	}
};

/// <summary>
/// 원형 큐는 선형 큐의 단점을 개선하기 위해 등장한 자료구조입니다.
/// 선형 큐는 Frontm Rear를 재활용하기 힘들다
/// Pop(Dequeue) : Front = (Front + 1) % 최대값
/// Push(Enqueu) : Rear = (Rear + 1) % 최대값
/// </summary>

template <typename T>
class MyCircularQueue
{
private:
	T* queueArray;
	int capacity;
	int front;
	int rear;
public:
	MyCircularQueue() {}
	MyCircularQueue(int size=5) : capacity(size), front(0), rear(0)
	{
		queueArray = new T[size + 1];
	}
	~MyCircularQueue() 
	{
		delete[] queueArray;
		queueArray = nullptr;
	}

	bool IsEmpty() const
	{
		return front == rear;
	}

	bool IsFull() const
	{
		return (rear + 1) % (capacity + 1) == front;
	}

	void push(T data)
	{
		if (IsFull())
		{
			cout << "큐가 가득 찼습니다" << endl;
			return;
		}
		queueArray[rear] = data;
		rear = (rear + 1) % (capacity + 1);
	}

	void pop()
	{
		if(IsEmpty()) {
			cout << "큐가 비어 있습니다" << endl;
			return;
		}
		T data = queueArray[front];
		front = (front + 1) % (capacity + 1);
		cout << data << endl;
	}
};

void IQueueExample()
{
	//MyCircularQueue<int> cq(5);
	//
	//cq.push(1);
	//cq.push(2);
	//cq.push(3);
	//cq.push(4);
	//cq.push(5);
	//cq.push(6);
	//
	//cq.pop();
	//cq.pop();
	//cq.pop();
	//cq.pop();
	//cq.pop();
	//cq.pop();
	//ArrayBasedQueue<int> myQueue;
	//myQueue.push(1);
	//myQueue.push(2);
	//myQueue.push(3);
	//myQueue.push(4);
	//myQueue.push(5);
	//
	//myQueue.print();
	//std::cout << myQueue.getback() << std::endl;
	//
	LinkedQueue<int> LQueue;
	LQueue.Push(1);
	LQueue.Push(2);
	LQueue.Push(3);
	LQueue.Push(4);
	LQueue.Push(5);
	cout << LQueue.Front() << endl;
	LQueue.Pop();
	cout << LQueue.Front() << endl;
	LQueue.Pop();
	cout << LQueue.Front() << endl;
	LQueue.Pop();
	cout << LQueue.Front() << endl;
	LQueue.Pop();
	cout << LQueue.Front() << endl;
	LQueue.Pop();
	
	//// iterator로 반복문 출력하기
	//
	//ArrayBasedQueue<int>::iterator queIt = myQueue.begin();
	//
	//for (queIt;queIt != myQueue.end();queIt++)
	//{
	//	std::cout << *queIt << std::endl;
	//}
	//LQueue.Pop();
	//
	//std::cout << LQueue.Front() << std::endl <<  LQueue.Back() << std::endl;
}
