#include "Bid.h"

std::map<std::string, int> const Bid::numberNames{
	{"1", 1},
	{"2", 2},
	{"3", 3},
	{"4", 4},
	{"5", 5},
	{"6", 6},
	{"7", 7},
	{"8", 8},
	{"9", 9},
	{"10", 10}
};

std::map<std::string, Dice::Face> const Bid::faceNames{
	{"Ones", Dice::Face::One},
	{"Twos", Dice::Face::Two},
	{"Threes", Dice::Face::Three},
	{"Fours", Dice::Face::Four},
	{"Fives", Dice::Face::Five},
	{"Stars", Dice::Face::Star}
};

Bid::Bid() {
	number = 1;
	face = Dice::Face::One;
}

Bid::Bid(int n, Dice::Face f) {
	number = n;
	face = f;
}

std::string Bid::convertFaceToString() const
{
	switch (face) {
		case Dice::Face::One:
			return "Ones";
		case Dice::Face::Two:
			return "Twos";
		case Dice::Face::Three:
			return "Threes";
		case Dice::Face::Four:
			return "Fours";
		case Dice::Face::Five:
			return "Fives";
		default:
			return "Stars";
	}
}

int Bid::getNumber() const
{
	return number;
}

Dice::Face Bid::getFace() const
{
	return face;
}

bool Bid::operator==(const Bid& rhs) const 
{
	return (this->number == rhs.number
		&& this->face == rhs.face);
}

Bid& Bid::operator++()
{
	if (face == Dice::Face::One)
		face = Dice::Face::Two;
	else if (face == Dice::Face::Two)
		face = Dice::Face::Three;
	else if (face == Dice::Face::Three)
		face = Dice::Face::Four;
	else if (face == Dice::Face::Four)
		face = Dice::Face::Five;

	else if (face == Dice::Face::Five) {
		++number;
		face = Dice::Face::One;
	}

	else if (face == Dice::Face::Star) {
		number *= 2;
		face = Dice::Face::One;
	}

	return *this;
}

std::ostream& operator<< (std::ostream & os, const Bid & b) 
{
	os << std::to_string(b.number) << " " << b.convertFaceToString();
	return os;
}