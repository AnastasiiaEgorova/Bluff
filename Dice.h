#pragma once
#include <random>

class Dice
{
public:
	enum class Face {
		One,
		Two,
		Three,
		Four,
		Five,
		Star
	};

													Dice();
	Dice::Face										getFace() const;

private:
	Face											rollDice();

private:
	std::uniform_int_distribution<unsigned int>		dist{ 1, 6 };
	static std::mt19937								rEng;

	Face											face;
};

