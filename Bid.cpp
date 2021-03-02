#include "Bid.h"

Bid::Bid() {
	number = 1;
	face = Dice::Face::One;
}

Bid::Bid(int n, Dice::Face f) {
	number = n;
	face = f;
}

bool Bid::operator==(const Bid& rhs) const 
{
	return (this->number == rhs.number
		&& this->face == rhs.face);
}