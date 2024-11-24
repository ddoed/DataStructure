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
		adjMatrix[v2][v1] = 1;
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

class Graph
{
private:
	int Vertex;		// ������ ��
	vector<vector<int>> adjMatrix;		// �׷������� ���� ���� ���� ǥ��

	set<int> seen;						// ����� ������ ������ �ڷᱸ��, �ߺ� Ž�� ����

	void recur_DFS(int index)
	{
		std::cout << index << " ";				// ���� ������ ���
		seen.insert(index);						// 0�� seen�� ����
		vector<int>& keys = adjMatrix[index];		// ���� vertex�� ���� vertex�� ã�´�. 1, 0���� ũ�� �ִ�.
		
		for (int key : keys)
		{
			if (seen.find(key) == seen.end())	// seen�� ���� �����Ͷ�� ����
			{
				recur_DFS(key);
			}
		}
	}

public:
	Graph(int vertices) : Vertex(vertices)
	{
		adjMatrix.resize(vertices);
	}

	void addEdge(int v1, int v2)		// directed, undirected
	{
		adjMatrix[v1].push_back(v2);
		adjMatrix[v2].push_back(v1);
	}

	bool RecurDFS()		// Graph DFS ����ؼ� ��� ��ΰ� ����Ǿ� �ִ��� �ľ��ϴ� �Լ�
	{
		seen.clear();
		recur_DFS(0);

		if (seen.size() == adjMatrix.size())
			std::cout << "��� ��ΰ� ����Ǿ� �ֽ��ϴ�." << std::endl;
		else
			std::cout << "��� ��ΰ� ����Ǿ� ���� �ʽ��ϴ�." << std::endl;

		return seen.size() == adjMatrix.size();
	}

	void IterDFS(int index)
	{
		seen.clear();

		stack<int> s;		// ������ vertex ���� -> ������ vertex
		s.push(index);

		while (!s.empty())
		{
			int vertex = s.top();
			s.pop();
			if (seen.find(vertex) == seen.end())
			{
				cout << vertex << " ";
				seen.insert(vertex);

				for (auto it = adjMatrix[vertex].rbegin();it != adjMatrix[vertex].rend();it++)
				{
					if (seen.find(*it) == seen.end())
						s.push(*it);
				}
			}
		}
		if (seen.size() == adjMatrix.size())
			std::cout << "��� ��ΰ� ����Ǿ� �ֽ��ϴ�." << std::endl;
		else
			std::cout << "��� ��ΰ� ����Ǿ� ���� �ʽ��ϴ�." << std::endl;
	}

	void IterBFS(int index)
	{
		seen.clear();

		queue<int> s;		// ������ vertex ���� -> ������ vertex
		s.push(index);

		while (!s.empty())
		{
			int vertex = s.front();
			s.pop();
			if (seen.find(vertex) == seen.end())
			{
				cout << vertex << " ";
				seen.insert(vertex);

				for (auto it = adjMatrix[vertex].begin();it != adjMatrix[vertex].end();it++)
				{
					if (seen.find(*it) == seen.end())
						s.push(*it);
				}
			}
		}
		if (seen.size() == adjMatrix.size())
			std::cout << "��� ��ΰ� ����Ǿ� �ֽ��ϴ�." << std::endl;
		else
			std::cout << "��� ��ΰ� ����Ǿ� ���� �ʽ��ϴ�." << std::endl;
	}

	void printGraph()
	{
		for (int i = 0; i < Vertex; i++)
		{
			cout << "����" << i << "�� ���� ��Ʈ����:";
			for (auto x : adjMatrix[i])
			{
				std::cout << " ->" << x;
			}
			cout << std::endl;
		}
	}
};

void GraphExample()
{
	Graph graphL(7);
	//graphL.addEdge(0, 2);
	//graphL.addEdge(0, 3);
	//graphL.addEdge(1, 3);
	//graphL.addEdge(1, 4);
	//graphL.addEdge(2, 4);

	graphL.addEdge(0, 1);
	graphL.addEdge(1, 4);
	graphL.addEdge(4, 6);
	graphL.addEdge(0, 2);
	graphL.addEdge(2, 4);
	graphL.addEdge(2, 5);
	graphL.addEdge(0, 3);

	graphL.printGraph();
	graphL.RecurDFS();
	graphL.IterDFS(0);
	graphL.IterBFS(0);

	cout << "Graph Matrix" << endl;

	GraphMatrix graphM(5);
	graphM.addEdge(0, 2);
	graphM.addEdge(0, 3);
	graphM.addEdge(1, 3);
	graphM.addEdge(1, 4);
	graphM.addEdge(2, 4);

	graphM.printGraph();

	cout << endl;

	//vector<vector<int>> example
	//{
	//	{0,1}, {0,2}, {0,3}
	//}
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
