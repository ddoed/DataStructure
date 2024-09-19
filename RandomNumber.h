#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

int ReturnRandomNumber(int startNumber, int endNumber)
{
	std::srand(time(nullptr)); // 현재 시간을 난수로(seed)
	int randomNumber = std::rand() % (endNumber+1);
	return randomNumber;
}

int R_Number(int startNumber, int endNumber)
{
	std::random_device rd; // 시드를 생성하기 위한 객체
	std::mt19937 gen(rd()); // mt19937 알고리즘을 사용하여 난수 생성
	std::uniform_int_distribution<> distrib(startNumber, endNumber); // 시작 숫자부터 끝 숫자까지 출력해주는 기능
	int randomNumber = distrib(gen);
	return randomNumber;
}
