#include "Complexity.h"

void Print()
{
}

void lecture1()
{
	// 시간 복잡도의 단순계산 1

	float s = 0.0f; // 연산 1번
	for (int i = 0; i < 10; i++) // 비교 1번, 덧셈 1번, 증감연산 1 * 10
	{
		s += i;
	} // 3n+1 연산 시간 복잡도 : O(n)
	std::cout << "0부터 10까지의 합 : " << s << std::endl;


	int sum = 0;

	int count = 100;

	sum = sum + 1;
	sum = sum / 2;
	sum = sum * count; // 시간 복잡도 5 O(1)

	// 시간 복잡도 계산을 위한 방법 : 빅오 계산법
	// Best Case : 빅 오메가
	// Worst Case : 빅오 표기법
	// 평균 Case : 빅 세타

	// 빅오 표기법의 특징
	// 1. 가장 큰 차수 n
	// 2. 자주 사용하는 빅오의 차이

	// O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n!)
	// a를 숫자를 n번 곱해서  - x   a^n - x

	
}

void Example01()
{
	// 1. 시간 복잡도를 빠른 순서대로 빅오 표기로 출력
	// 출력 형태는 O(기호)를 갖추어서
	const char* arr[6] = { "1", "logn", "n", "nlogn", "n^2", "n!" };
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	// 2. 아래의 코드의 시간 복잡도와 공간 복잡도를 계산해서 출력
}

// 공간 복잡도 예시
float abc(float a, float b, float c)
{
	return (a + b + b * c + (a + b - c) / (a + b) + 4.0);
	// 공간 복잡도 : 0(문제 해결과 전혀 관계없는 메모리 공간)
}

float sum(float a[], int n)
{
	float result = 0.0f;
	for (int i = 0; i <= n; i++)
	{
		result += a[i];
	}
	return result;
}
