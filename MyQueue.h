#pragma once
#include <iostream>
#include <queue>

using namespace std;

/*
* �ڷᱸ�� : �����̳ʸ� �����ؼ� ������ ���صΰ� ����ϴ� ����� �ڷᱸ��
* 
* ť �ڷᱸ�� ����
* - �����Ͱ� ��µǴ� �ε����� front�̸����� ǥ��
* - �����Ͱ� ����Ǵ� �ε����� rear �̸����� ǥ��
* - ���� ť front rear �ʱⰪ���� �ǵ��ư� �� ����.
*/

// �����ؾ��� �Լ�
// �Է� �� ���� : push, pop
// �ʵ� �� ǥ�� : empty(), size(), front(), back()

template <typename T>
class ArrayBasedQueue
{
private:
	T* queue; // �����͸� �����ϱ����� �迭 �̸�
	int front; // ��� ��ġ�� ����Ű�� �ε���
	int rear; // ������ �Է� ��ġ�� ����Ű�� �ε���
	int iCount; // ���� �ڷᱸ���� ������ ����
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
	// iterator ���� �Լ�
public:
	using iterator = Iterator; // using -> typedef
	iterator begin() { return iterator(queue); }
	iterator end() { return begin() + iCount; }
public:
	// ������
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

	// �ʵ忡 ������ ���� �Լ�
	
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
			std::cout << "������ϴ�" << std::endl;
		}
			
	}

	void print()
	{
		std::cout << "Front Index : " << front << std::endl;
		std::cout << "Rear Index : " << rear << std::endl;
		std::cout << "Queue Count : " << iCount << std::endl;
	}

	// Main Method ����� ���� �Լ� : ����, ����
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
	// ������ & �Ҹ���
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
/// ���� ť�� ���� ť�� ������ �����ϱ� ���� ������ �ڷᱸ���Դϴ�.
/// ���� ť�� Frontm Rear�� ��Ȱ���ϱ� �����
/// Pop(Dequeue) : Front = (Front + 1) % �ִ밪
/// Push(Enqueu) : Rear = (Rear + 1) % �ִ밪
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
			cout << "ť�� ���� á���ϴ�" << endl;
			return;
		}
		queueArray[rear] = data;
		rear = (rear + 1) % (capacity + 1);
	}

	void pop()
	{
		if(IsEmpty()) {
			cout << "ť�� ��� �ֽ��ϴ�" << endl;
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
	
	//// iterator�� �ݺ��� ����ϱ�
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
