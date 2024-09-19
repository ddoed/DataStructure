#include "lectures.h"
#include "MyVector.h"
#include "RandomNumber.h"

// 학습 목표 : 가변 배열(Vector) - Array List

// 벡터(Vector)
// 자주 사용하는 자료구조 중 하나. Linked List, Array List(Vector)
// int arr[10];
// 연산자 오버로딩으로 구현 [], ==, !=

// 연결 리스트 vs 가변 배열

//					        | 자료구조의 크기 변경 기능 | 중간 삽입, 삭제 기능 | 순차 접근 기능 | 랜덤 접근 기능
// 연결 리스트(Linked List) |           o               |          o           |          o     |        x     
// 가변 배열 (Vector)       |           o               |          x           |          o     |        o

// 정리 : 크게 중간 삽입 기능과 랜덤 접근 기능이 차이점
// 중간 삽입 적게 발생 -> 벡터
// 중간 삽입 자주 발생 -> 연결 리스트

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