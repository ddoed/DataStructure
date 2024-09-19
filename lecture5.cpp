#include "lectures.h"
#include "MyVector.h"
#include "RandomNumber.h"

// �н� ��ǥ : ���� �迭(Vector) - Array List

// ����(Vector)
// ���� ����ϴ� �ڷᱸ�� �� �ϳ�. Linked List, Array List(Vector)
// int arr[10];
// ������ �����ε����� ���� [], ==, !=

// ���� ����Ʈ vs ���� �迭

//					        | �ڷᱸ���� ũ�� ���� ��� | �߰� ����, ���� ��� | ���� ���� ��� | ���� ���� ���
// ���� ����Ʈ(Linked List) |           o               |          o           |          o     |        x     
// ���� �迭 (Vector)       |           o               |          x           |          o     |        o

// ���� : ũ�� �߰� ���� ��ɰ� ���� ���� ����� ������
// �߰� ���� ���� �߻� -> ����
// �߰� ���� ���� �߻� -> ���� ����Ʈ

void lecture5()
{
	MyVector<int> i_Vec(20);
	MyVector<int> i_Vec2;

	i_Vec.push_back(3);
	i_Vec.push_back(5);
	i_Vec.push_back(4);

	int r_index = R_Number(0, i_Vec.GetSize());
	std::cout << i_Vec[r_index] << std::endl;

	//i_Vec.Print();
}