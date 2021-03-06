#pragma once
#include "Dice.h"
#include <string>
#include <iostream>
#include <map>

class Bid {

public:

	static std::map<std::string, int> const numberNames;
	static std::map<std::string, Dice::Face> const faceNames;

						Bid();
						Bid(int n, Dice::Face f);

	std::string			convertFaceToString() const;
	int					getNumber() const;

	bool operator==(const Bid& rhs) const;
	//bool operator>(const Bid& rhs) const;

	friend std::ostream& operator<<(std::ostream& strm, const Bid& b);

private:
	int number;
	Dice::Face face;
};

std::ostream& operator<<(std::ostream& os, const Bid& b);


