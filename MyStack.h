#pragma once
#include <iostream>

/*
* 자료구조 컨테이너 : Array, Vector, Linked List
* 
* 기존 컨테이너를 변형해서 (자료를 삽입, 삭제) 기능을 제한해서 프로그래밍 최적화를 구현한 자료구조
*/

// Stack 자료구조
// Last In Fist Out

// 스택의 장점
// 1. 클래스 구현하기가 쉽다 저장

// 1. 실행 취소(Undo) : Ctrl + z
// 2. 후위 표기법 : 컴퓨터가 읽기에 쉽게 표현된 연산 표기법

// 배열 기반 Stack
template <typename T>
class MyArrayStack
{
// 필드
private:
	T*	stackArray; // 스택 데이터 저장하기위한 배열
	int capacity; // 스택의 최대 크기
	int top; // 현재 가장 상단에 있는 인덱스

// 기능
public:
	// 생성자
	MyArrayStack() {}
	MyArrayStack(int size)
	{
		// 데이터가 생성되지 않음을 표현 -> -1
		stackArray = new T[size];
		capacity = size;
		top = -1;
	}
	// 소멸자
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
		// 2. 새로 만든 배열에 기존 배열 대입
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
	
	// top이 가리키고 있는 녀석이 -1 true false
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

	// isEmpty() -> 현재 스택에 데이터가 비었습니다
	// return
	// top 1감소

	T Top() const
	{
		return stackArray[top];
	}

	void pop()
	{
		if (IsEmpty())
		{
			std::cout << "현재 스택에 데이터가 없습니다." << std::endl;
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