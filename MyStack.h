#pragma once
#include <iostream>

/*
* �ڷᱸ�� �����̳� : Array, Vector, Linked List
* 
* ���� �����̳ʸ� �����ؼ� (�ڷḦ ����, ����) ����� �����ؼ� ���α׷��� ����ȭ�� ������ �ڷᱸ��
*/

// Stack �ڷᱸ��
// Last In Fist Out

// ������ ����
// 1. Ŭ���� �����ϱⰡ ���� ����

// 1. ���� ���(Undo) : Ctrl + z
// 2. ���� ǥ��� : ��ǻ�Ͱ� �б⿡ ���� ǥ���� ���� ǥ���

// �迭 ��� Stack
template <typename T>
class MyArrayStack
{
// �ʵ�
private:
	T*	stackArray; // ���� ������ �����ϱ����� �迭
	int capacity; // ������ �ִ� ũ��
	int top; // ���� ���� ��ܿ� �ִ� �ε���

// ���
public:
	// ������
	MyArrayStack() {}
	MyArrayStack(int size)
	{
		// �����Ͱ� �������� ������ ǥ�� -> -1
		stackArray = new T[size];
		capacity = size;
		top = -1;
	}
	// �Ҹ���
	~MyArrayStack()
	{
		if (stackArray != nullptr)
		{
			delete[] stackArray;
		}
		
	}

	// Resize()
	void Resize(int newSize)
	{
		T* newstackArray = new T[newSize];
		// 2. ���� ���� �迭�� ���� �迭 ����
		for (int i = 0; i <= top; i++)
		{
			newstackArray[i] = stackArray[i];
		}
		delete[] stackArray;
		stackArray = newstackArray;
		capacity = newSize;
	}

	// top == capacity
	bool IsFull()
	{
		return top == capacity -1 ? true : false;
	}
	
	// top�� ����Ű�� �ִ� �༮�� -1 true false
	bool IsEmpty()
	{
		return top <= -1 ? true : false;
	}
	
	
	void push(T data)
	{
		if (IsFull())
		{
			Resize(capacity * 2);
		}
		top++;
		stackArray[top] = data;
	}

	// isEmpty() -> ���� ���ÿ� �����Ͱ� ������ϴ�
	// return
	// top 1����

	T Top() const
	{
		return stackArray[top];
	}

	void pop()
	{
		if (IsEmpty())
		{
			std::cout << "���� ���ÿ� �����Ͱ� �����ϴ�." << std::endl;
			return;
		}
		
		std::cout << Top() << std::endl;
		--top;
	}

	void Clear()
	{
		capacity = 10;
		top = -1;
	}
};

void StackExample()
{
	MyArrayStack<int> mStack(10);
	mStack.push(5);
	mStack.push(4);
	mStack.push(3);
	mStack.push(2);
	mStack.push(1);

	mStack.pop();
	mStack.pop();
	mStack.pop();
	mStack.pop();
	mStack.pop();
	mStack.pop();
}