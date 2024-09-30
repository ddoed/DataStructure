#pragma once
#include <vector>
#include <iostream>
#include <string>
// 포인터의 사용법

// int abc = 10;
// int * intptr = &abc;
// 포인터 연산자 : *ptr ptr++, ptr == , !=

class Item
{
private:
	float time;
	int idx;
public:
	Item() {}
	Item(float Name, int Idx) : time(Name), idx(Idx) {}

	void Print()
	{
		std::cout << "No." << idx << " , " << "아이템 이름 : " << time << std::endl;
	}


};

template <typename T>
class Container
{
private:
	T* arr;
	int size;
	int capacity;

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
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + Size(); }

public:
	Container(int _size = 3)
	{
		arr = new T[_size];
		size = 0;
		capacity = _size;
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

	Container<int>::iterator myIt = mycon.begin();

	for (int elem : mycon)
	{
		std::cout << "iterator 출력 : " << elem << std::endl;
	}

	auto a = 10;
	auto b = 0.1f;
	auto c = 'c';
	auto d = "hello";

	std::cout << "Item Class 사용 예시" << std::endl;

	Container<Item> inventory;

	Item item1(0.1, 1);
	Item item2(0.2, 2);
	Item item3(0.3, 3);

	inventory.push_back(item1);
	inventory.push_back(item2);

	auto itemIt = inventory.begin();

	for (itemIt; itemIt != inventory.end(); itemIt++)
	{
		(*itemIt).Print();
	}

}