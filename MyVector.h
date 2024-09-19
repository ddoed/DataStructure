#pragma once

#include <iostream>
#include <string>
#include <random>

// �迭 : ũ�Ⱑ ����
// �迭�� ���� ��ȯ�� Ŭ������
// �迭�� ��ü ���� : capacity
// ���� �迭�� ��� ���Ҽ� : size
// push_back() -> size++; ���� : capacity <= size -> �뷮�� �÷��ش�(�˰���)

template<typename T>
class MyVector
{
private:
	T* vec; // ���Ҹ� ���� ���� �ּ�
	int size; // vector�� ���� ��� �ִ� ũ��
	int capacity; // �ִ�� ���� �� �ִ� ũ��
public:
	// ������
	MyVector(int temp = 10)// Ŭ������ ������ �� int ���� ���ڷ� �Ѱ����� ������ 10���� �ڵ� �Ҵ�
	{
		vec = new T[temp];
		size = 0;
		capacity = temp;
	}
	~MyVector()
	{
		delete[] vec;
	}

	// ������ �����ε� [] == !=
	T& operator[](int index) // �迭�� index�� �����ϴ� ���
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

	// ���� �߰� ����
	// ���Ӱ� �迭�� �Ҵ��ϴ� �۾��� �������� �ð��� ���� �ɸ���
	
	void ResizeVector(int _newSize) // �迭�� ũ�Ⱑ �����ϴ� case�� Resize���ش�
	{
		// 1. ���� �Ҵ�
		T* newVec = new T[_newSize];
		// 2. ���� ���� �迭�� ���� �迭 ����
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
			capacity = capacity * 2; // �ִ���뷮�� 2��� �ø���
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
			std::cout << i + 1 << "��° �� ��� : " << vec[i] << std::endl;
		}
	}

	int GetSize() { return size; }
};
