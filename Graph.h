#pragma once

// �׷��� Graph
// 1. �׷�����? vertex(��)�� edge(��)���� 

// �׷����� Ư¡
// 1. ���⼺�� ���ų� ���� �ʴ´� (directed vs unDirected)
// 2. ����� ���� ����ġ�� �ο��� �� �ִ�. weighted �ο����� ������ 0,1�� ǥ��
// 3. ��ȸ�ϴ°�?

// Graph Theory �׷��� �̷�
// DAG (Directed Acyclic Graph) : Ʈ���� �� ����

// �׷����� ǥ��
// 1. adjacent Matrix ���� ��Ʈ����
// 2. adjacent list ���� ����Ʈ

#include <vector>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

class GraphMatrix
{
private:
	int Vertex;		// ������ ��
	vector<vector<int>> adjMatrix;		// �׷������� ���� ���� ���� ǥ��

public:
	GraphMatrix(int vertices) : Vertex(vertices), adjMatrix(vertices, vector<int>(vertices, 0))
	{
		
	}
	
	void addEdge(int v1, int v2)
	{
		adjMatrix[v1][v2] = 1;
		//adjMatrix[v2][v1] = 1;
	}

	void printGraph()
	{
		for (int i = 0; i < Vertex; i++)
		{
			for (int j = 0; j < Vertex; j++)
			{
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

class GraphList
{
private:
	int Vertex;		// ������ ��
	vector<vector<int>> adjList;		// �׷������� ���� ���� ���� ǥ��

public:
	GraphList(int vertices) : Vertex(vertices)
	{
		adjList.resize(vertices);
	}

	void addEdge(int v1, int v2)		// directed, undirected
	{
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}

	void printGraph()
	{
		for (int i = 0; i < Vertex; i++)
		{
			cout << "����" << i << "�� ���� ��Ʈ����:";
			for (auto x : adjList[i])
			{
				std::cout << " ->" << x;
			}
			cout << std::endl;
		}
	}
};

void GraphExample()
{
	GraphList graphL(5);
	graphL.addEdge(0, 2);
	graphL.addEdge(0, 3);
	graphL.addEdge(1, 3);
	graphL.addEdge(1, 4);
	graphL.addEdge(2, 4);

	graphL.printGraph();

	cout << "Graph Matrix" << endl;

	GraphMatrix graphM(5);
	graphM.addEdge(0, 2);
	graphM.addEdge(0, 3);
	graphM.addEdge(1, 3);
	graphM.addEdge(1, 4);
	graphM.addEdge(2, 4);

	graphM.printGraph();

	cout << endl;

	GraphMatrix p1(6);
	p1.addEdge(0, 1);
	p1.addEdge(0, 3);
	p1.addEdge(3,2);
	p1.addEdge(1,1);
	p1.addEdge(1,3);
	p1.addEdge(1,5);
	p1.addEdge(2,2);
	p1.addEdge(2,4);

	p1.printGraph();

}

// �׷��� Ž�� ����
// 0�� : 1, 3 ����
// 1�� : 0, 1, 3, 5 ����
// 2�� : 2,4 ����
// 3�� �� : 0,2 ����
// 4,5�� �� : ���� X

// ��ü�� ����Ǿ� �ִٸ� true �ƴϸ� false

class VisitAllRooms
{
private:
	vector<vector<int>> rooms;	// ����� �׷����� ǥ���ϴ� 2���� �迭
	set<int> seen;	// Ž���� ���� �����ϴ� �ڷᱸ��
	

	// recursive
	void recurDFS(vector<vector<int>>& rooms)
	{
		stack<int> stacks;
		seen.emplace(0);
		
		while (true)
		{
			//for (int i = 0; i < )
			//{
			//	if (rooms[0][i])
			//	{
			//
			//	}
			//}
				
		}

	}

	// iterative
	void iterDFS()
	{
		
	}

	void BFS()
	{

	}
 };
