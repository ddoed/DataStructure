#pragma once

#include <iostream>
#include <string>
#include <random>

// 배열 : 크기가 고정
// 배열의 길이 변환을 클래스로
// 배열의 전체 길이 : capacity
// 현재 배열에 담긴 원소수 : size
// push_back() -> size++; 조건 : capacity <= size -> 용량을 늘려준다(알고리즘)

template<typename T>
class MyVector
{
private:
	T* vec; // 원소를 담을 시작 주소
	int size; // vector에 현재 담겨 있는 크기
	int capacity; // 최대로 담을 수 있는 크기
public:
	// 생성자
	MyVector(int temp = 10)// 클래스를 생성할 때 int 값을 인자로 넘겨주지 않으면 10으로 자동 할당
	{
		vec = new T[temp];
		size = 0;
		capacity = temp;
	}
	~MyVector()
	{
		delete[] vec;
	}

	// 연산자 오버로딩 [] == !=
	T& operator[](int index) // 배열의 index에 접근하는 기능
	{
		return vec[index];
	}
	
	bool operator==(MyVector& other)
	{
		if (size != other.size)
			return false;

		if (capacity != other.capacity)
			return false;

		for (int i = 0; i < size;i++)
		{
			if (vec[i] != other[i])
				return false;
		}
		return true;
	}

	bool operator!=(MyVector& other)
	{
		return !(*this == other);
	}

	// 원소 추가 삭제
	// 새롭게 배열을 할당하는 작업이 적을수록 시간이 적게 걸린다
	
	void ResizeVector(int _newSize) // 배열의 크기가 증가하는 case만 Resize해준다
	{
		// 1. 동적 할당
		T* newVec = new T[_newSize];
		// 2. 새로 만든 배열에 기존 배열 대입
		for (int i = 0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		delete[] vec;
		vec = newVec;
	}

	void push_back(T data)
	{
		if (size >= capacity)
		{
			capacity = capacity * 2; // 최대수용량을 2배로 늘린다
			ResizeVector(capacity);
		}
		vec[size] = data;
		size++;
	}
	

	void pop_back()
	{
		size = size > 0 ? size-1 : 0;
	}

	void Print()
	{
		for (int i = 0; i < size;i++)
		{
			std::cout << i + 1 << "번째 값 출력 : " << vec[i] << std::endl;
		}
	}

	int GetSize() { return size; }
};
