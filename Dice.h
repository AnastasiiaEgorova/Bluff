#pragma once
#include <random>

class Dice
{
public:
	enum Face {
		One,
		Two,
		Three,
		Four,
		Five,
		Star
	};

	Dice();

private:
	Face rollDice();

private:
	std::uniform_int_distribution<unsigned int> dist{ 1, 6 };
	static std::mt19937 rEng;

	Face face;
};

