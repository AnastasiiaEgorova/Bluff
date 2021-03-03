#include "Bid.h"

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

bool Bid::operator==(const Bid& rhs) const 
{
	return (this->number == rhs.number
		&& this->face == rhs.face);
}

std::ostream& operator<< (std::ostream & os, const Bid & b) 
{
	os << std::to_string(b.number) << " " << b.convertFaceToString();
	return os;
}