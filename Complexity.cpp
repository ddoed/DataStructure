#include "Complexity.h"

void Print()
{
}

void lecture1()
{
	// �ð� ���⵵�� �ܼ���� 1

	float s = 0.0f; // ���� 1��
	for (int i = 0; i < 10; i++) // �� 1��, ���� 1��, �������� 1 * 10
	{
		s += i;
	} // 3n+1 ���� �ð� ���⵵ : O(n)
	std::cout << "0���� 10������ �� : " << s << std::endl;


	int sum = 0;

	int count = 100;

	sum = sum + 1;
	sum = sum / 2;
	sum = sum * count; // �ð� ���⵵ 5 O(1)

	// �ð� ���⵵ ����� ���� ��� : ��� ����
	// Best Case : �� ���ް�
	// Worst Case : ��� ǥ���
	// ��� Case : �� ��Ÿ

	// ��� ǥ����� Ư¡
	// 1. ���� ū ���� n
	// 2. ���� ����ϴ� ����� ����

	// O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n!)
	// a�� ���ڸ� n�� ���ؼ�  - x   a^n - x

	
}

void Example01()
{
	// 1. �ð� ���⵵�� ���� ������� ��� ǥ��� ���
	// ��� ���´� O(��ȣ)�� ���߾
	const char* arr[6] = { "1", "logn", "n", "nlogn", "n^2", "n!" };
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	// 2. �Ʒ��� �ڵ��� �ð� ���⵵�� ���� ���⵵�� ����ؼ� ���
}

// ���� ���⵵ ����
float abc(float a, float b, float c)
{
	return (a + b + b * c + (a + b - c) / (a + b) + 4.0);
	// ���� ���⵵ : 0(���� �ذ�� ���� ������� �޸� ����)
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
