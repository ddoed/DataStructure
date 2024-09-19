#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

int ReturnRandomNumber(int startNumber, int endNumber)
{
	std::srand(time(nullptr)); // ���� �ð��� ������(seed)
	int randomNumber = std::rand() % (endNumber+1);
	return randomNumber;
}

int R_Number(int startNumber, int endNumber)
{
	std::random_device rd; // �õ带 �����ϱ� ���� ��ü
	std::mt19937 gen(rd()); // mt19937 �˰����� ����Ͽ� ���� ����
	std::uniform_int_distribution<> distrib(startNumber, endNumber); // ���� ���ں��� �� ���ڱ��� ������ִ� ���
	int randomNumber = distrib(gen);
	return randomNumber;
}
