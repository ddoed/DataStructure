#pragma once
#include <vector>
#include <iostream>

// 포인터의 사용법

// int abc = 10;
// int * intptr = &abc;
// 포인터 연산자 : *ptr ptr++, ptr == , !=

template <typename T>
class Container
{
private:
	T* arr;
	int size;
	int capacity;

	class iterator
	{
	private:
		T* ptr;
	public:
		iterator() : ptr(nullptr) {}
		iterator(T* ptr) : ptr(ptr) {}

		T& operator*()
		{
			return *ptr;
		}

		iterator& operator++()
		{
			ptr++;
			return *this;
			
		}

		iterator& operator++(int)
		{
			iterator temp = *this;
			ptr++;
			return temp;
		}
		
		iterator operator+(const int count)
		{

		}

		bool operator==(const iterator& other)
		{
			return ptr == other.ptr;
		}

		bool operator!=(const iterator& other)
		{
			return ptr != other.ptr;
		}
	};
	// iterator 허용된 함수
public:
	using iterator = iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() /* + size()*/; }

public:
	Container(int size = 3)
	{
		arr = new T[size];
		size = 0;
		capacity = size;
	}

	void push_back(T data)
	{
		arr[size++] = data;
	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;
	}

	int Size() { return size; }
};

void IteratorExample()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	auto it = vec.begin();

	for (int a : vec)
	{
		std::cout << a << std::endl;
	}

	Container<int> mycon;
	mycon.push_back(10);
	mycon.push_back(20);
	mycon.push_back(30);
}