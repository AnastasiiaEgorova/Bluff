#pragma once
#include "Dice.h"

class Bid {

public:
	Bid();
	Bid(int n, Dice::Face f);

private:
	int number;
	Dice::Face face;
};


