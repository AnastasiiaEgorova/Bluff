#pragma once
#include "Dice.h"
#include <string>
#include <iostream>

class Bid {

public:
						Bid();
						Bid(int n, Dice::Face f);

	std::string			convertFaceToString() const;

	bool operator==(const Bid& rhs) const;

	friend std::ostream& operator<<(std::ostream& strm, const Bid& b);

private:
	int number;
	Dice::Face face;
};

std::ostream& operator<<(std::ostream& os, const Bid& b);


