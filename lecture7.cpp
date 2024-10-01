#include <vector>
#include <iostream>
#include <chrono>

using namespace std::chrono;

class MySearchTool
{
public:
	int search(const std::vector<int>& arr, int target)
	{
		auto it = arr.begin();

		// iterator 반복문
		for (it; it != arr.end(); it++)
		{
			if ((*it) == target)
			{
				std::cout << "목표 값 : " << *it << std::endl;
				
				return (*it);
			}
		}
		std::cout << "목표 값이 없습니다" << std::endl;
		return -1;
	}

	int binarySearch(const std::vector<int>& arr, int target)
	{
		int left = 0;
		int right = arr.size()-1;

		while (left <= right)
		{
			int mid = left + (right-left) / 2;

			if (arr[mid] > target)
			{
				right = mid-1;
			}

			else if (arr[mid] == target)
			{
				std::cout << "목표 값 : " << arr[mid] << std::endl;
				return arr[mid];
			}
				

			else if (arr[mid] < target)
			{
				left = mid+1;
			}
		}

		std::cout << "목표 값이 없습니다" << std::endl;
		return -1;
	}
};

void lecture7()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	int targetNumber = 3;

	MySearchTool tool;

	auto start = std::chrono::high_resolution_clock::now();

	tool.search(vec, 7);

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(end - start);

	std::cout << "for 반복문 순회 탐색 방식 걸린 시간 : " << duration.count() / 1000.0 << "ms" << std::endl;



	
	auto start2 = std::chrono::high_resolution_clock::now();

	tool.binarySearch(vec, 2);

	auto end2 = std::chrono::high_resolution_clock::now();

	auto duration2 = duration_cast<milliseconds>(end2 - start2);

	std::cout << "for 반복문 순회 탐색 방식 걸린 시간 : " << duration2.count() / 1000.0 << "ms" << std::endl;

}