#pragma once
#include "Dice.h"

class Bid {

public:
	Bid();
	Bid(int n, Dice::Face f);

	bool operator==(const Bid& rhs) const;

private:
	int number;
	Dice::Face face;
};


