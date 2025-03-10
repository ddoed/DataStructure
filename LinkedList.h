#pragma once
#include <iostream>

// 자료구조 : 데이터를 잘 사용하기 위해서 선택하는 도구
// 배열 : 데이터를 정리해본다
// 시간 복잡도(빅오 표기법) : 연산 속도가 적을 수록 실행이 빠르다
// 공간 복잡도(빅오 표기법) : 크기가 적을 수록 메모리 공간이 많이 남는다

// 1. 데이터의 저장 (Insert) <-> 삭제
// 2. 1번 부터 n번 출력(순회) 역순회
// 3. 데이터 정렬
//4. 데이터 탐색

// 배열
// 단점 : 데이터 삭제 및 저장 : O(n) - 데이터 크기가 크면 클수록 시간이 오래 걸린다
// 장점 : 배열의 속해있는 원소의 접근하는 시간이 짧다

// 연결 리스트
// 장점 : 데이터 삭제 및 저장 : O(1)
// 단점 : 임의의 원소에 접근하는 시간이 길다 O(n)

// 단일 연결 리스트 : 단일 + 연결 + 리스트 = 자료구조
// 추상 데이터 형식(ADT)
// 1. 데이터와 링크(포인터) 쌍으로 이루어져 있는 노드를 원소마다 보유
// 2. 연결 리스트 객체는 첫번째 노드를 head 이름으로 갖는다. 마지막 노드를 tail 이름으로 갖는다 -> tList(head-tail)
// 3. 방향은 단일 방향

// 정수를 저장하는 단일 연결 리스트

// 정수의 값을 저장하는 노드

// 노드를 필드로 갖는 단일 연결 리스트라는 이름의 객체

struct IntNode
{
	int value; // 노드가 저장하고 있는 정수형 값
	IntNode* pNext; // 다음노드의 주소를 저장하는 포인터
};

class ILinkedList
{
private:
	IntNode* phead;
	IntNode* ptail;
	int iCount; // 노드의 총 갯수
public:
	ILinkedList();
	~ILinkedList();

	void PushFront(const int& _data);
	void PushBack(const int& _data);

	void InsertAfter(IntNode* prevNode, const int& _data);
	IntNode* GetNode(int index);

	void RemoveFront();
	void RemoveBack();

	// 데이터를 보여주는 기능
	void FrontValue();
	void TailValue();
};