#pragma once

// 그래프 Graph
// 1. 그래프란? vertex(점)와 edge(선)으로 

// 그래프의 특징
// 1. 방향성을 갖거나 갖지 않는다 (directed vs unDirected)
// 2. 연결된 선의 가중치를 부여할 수 있다. weighted 부여하지 않으면 0,1로 표현
// 3. 순회하는가?

// Graph Theory 그래프 이론
// DAG (Directed Acyclic Graph) : 트리의 한 종류

// 그래프의 표현
// 1. adjacent Matrix 인접 매트릭스
// 2. adjacent list 인접 리스트

#include <vector>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

class GraphMatrix
{
private:
	int Vertex;		// 정점의 수
	vector<vector<int>> adjMatrix;		// 그래프들의 연결 관계 정보 표현

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
	int Vertex;		// 정점의 수
	vector<vector<int>> adjMatrix;		// 그래프들의 연결 관계 정보 표현

	set<int> seen;						// 출력한 노드들을 저장할 자료구조, 중복 탐색 방지

	void recur_DFS(int index)
	{
		std::cout << index << " ";				// 시작 데이터 출력
		seen.insert(index);						// 0번 seen에 삽입
		vector<int>& keys = adjMatrix[index];		// 시작 vertex의 인접 vertex를 찾는다. 1, 0보다 크면 있다.
		
		for (int key : keys)
		{
			if (seen.find(key) == seen.end())	// seen에 없는 데이터라면 실행
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

	bool RecurDFS()		// Graph DFS 사용해서 모든 경로가 연결되어 있는지 파악하는 함수
	{
		seen.clear();
		recur_DFS(0);

		if (seen.size() == adjMatrix.size())
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;

		return seen.size() == adjMatrix.size();
	}

	void IterDFS(int index)
	{
		seen.clear();

		stack<int> s;		// 인접한 vertex 저장 -> 인접한 vertex
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
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;
	}

	void IterBFS(int index)
	{
		seen.clear();

		queue<int> s;		// 인접한 vertex 저장 -> 인접한 vertex
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
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;
	}

	void printGraph()
	{
		for (int i = 0; i < Vertex; i++)
		{
			cout << "정점" << i << "의 인접 매트릭스:";
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

// 그래프 탐색 문제
// 0번 : 1, 3 연결
// 1번 : 0, 1, 3, 5 연결
// 2번 : 2,4 연결
// 3번 문 : 0,2 연결
// 4,5번 문 : 연결 X

// 전체가 연결되어 있다면 true 아니면 false

class VisitAllRooms
{
private:
	vector<vector<int>> rooms;	// 방들을 그래프로 표현하는 2차원 배열
	set<int> seen;	// 탐색한 방을 저장하는 자료구조
	

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
