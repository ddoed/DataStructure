#pragma once
#include <iostream>

// 트리 : 나무, 생김새가 나무처럼 생긴 자료구조

// 트리의 노드가 가질 수 있는 최대 수에 따른 분류
// 2개 : 이진 트리 (binary tree) - 주로 다루어 볼 것
// 3개 : Tenary tree
// 4개 : Octree

// 트리의 용어 : 
// 노드 : 트리의 기본요소로 데이터를 저장하는 단위
// 루트 : 최상위에 있는 노드. 부모 노드가 없는 유일 노드
// 부모 노드 : 하위의 노드와 직접 연결된 노드
// 자식 노드 : 부모 노드의 하위에 직접 연결된 노드
// 형제 노드 : 갗은 부모를 가진 노드들
// 조상 노드 : 특정 노드에서 루트까지 경로에 있는 모든 노드
// 후손 노드 : 특정 노드의 모든 자식, 자식의 자식들을 포함한 노드들.
// 레벨 : 루트로부터의 거리
// 높이 : 트리에서 가장 깊은 레벨을 의미한다
// 서브 트리 : 트리 내부의 노드와 그 후손들로 구성된 트리
// 차수 (degree) : 하나의 노드가 가진 자식 노드의 수
// 경로 : 하나의 노드에서 다른 노드로 이동할 때 거치는 노드의 순서

// 트리
// 1. 루트가 한 개이어야 한다
// 2. 노드들이 순환하지 않아야 한다

// 이진 트리의 종류
// 이진 트리 : 모든 노드들이 가질 수 있는 자식의 수(degree) 2개 이하로 구성된 자료구조
// 이진 탐색, 중간 삽입 삭제 빠른 자료구조 - 이진 검색 트리

// Full binary tree -> 0개 또는 2개
// complete binary tree -> 왼쪽부터 차있음
// perfect binary tree

class Tree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
	};

	void PreOrder(Node* root)
	{
		if (root == nullptr) return;
		std::cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}

	void InOrder(Node* root)
	{
		if (root == nullptr) return;
		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}

	void PostOrder(Node* root)
	{
		if (root == nullptr) return;
		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->data << " ";
	}

};

// BST : 이진 검색 트리
// 선형 자료구조에서 이진 검색이 비효율적이다. 이진 검색을 효율적으로 할 수 있는 자료구조
// 노드를 기준으로 왼쪽 노드는 자신 노드보다 작은 값, 오른쪽 노드는 자신보다 큰 값을 저장한다
// 중복은 허용하지 않는다

// 검색에 걸리는 시간 : logn
// 중간 삽입 삭제 : logn
// Insert
// Delete

// 삭제의 방법
// 1. 삭제하고자 하는 노드의 자식이 없을 때
// 2. 삭제하고자 하는 노드의 왼쪽에만 자식이 있을 때
// 3. 삭제하고자 하는 노드의 오른쪽에만 자식이 있을 떄
// 4. 


class BinarySearchTree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
	};
private:
	Node* root;

	Node* insert(Node* root, int value)
	{
		if (root == nullptr)
			return new Node(value);

		if (value < root->data)
		{
			root->left = insert(root->left, value);
		}

		if (value > root->data)
		{
			root->right = insert(root->right, value);
		}

		return root;
	}

	Node* search(Node* root, int target)
	{
		if (root == nullptr || root->data == target)
		{
			return root;
		}

		if (target < root->data)
		{
			return search(root->left, target);
		}
		else if (target > root->data)
		{
			return search(root->right, target);
		}
	}
	void inOrder(Node* root)
	{
		if (root == nullptr) return;
		inOrder(root->left);
		std::cout << root->data << " ";
		inOrder(root->right);
	}
public:
	BinarySearchTree() : root(nullptr) {}

	bool search(int value)
	{
		return search(root, value) != nullptr;
	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	void InOrder()
	{
		inOrder(root);
		std::cout << std::endl;
	}
};

void TreeExample()
{
	// Tree 자료구조에 저장되어 있는 상태 root
	// 데이터를 순회하는 방법 : preOrder, InOrder, PostOrder
	// preOrder 1 -> 2 -> 4 -> 5 -> 3
	// InOrder 4 -> 2 -> 5 -> 1 -> 3
	Tree::Node* root = new Tree::Node(1);
	root->left = new Tree::Node(2);
	root->right = new Tree::Node(3);
	root->left->left = new Tree::Node(4);
	root->left->right = new Tree::Node(5);

	Tree myTree;

	myTree.PreOrder(root);
	std::cout << '\n';
	myTree.InOrder(root);
	std::cout << '\n';
	myTree.PostOrder(root);

	std::cout << std::endl;

	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(7);
	bst.insert(25);
	bst.insert(8);
	bst.insert(49);

	bst.InOrder();

	std::cout << "탐색 결과 : " << (bst.search(30) ? "찾음" : "못찾음") << std::endl;

}