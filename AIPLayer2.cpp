#include "AIPLayer2.h"

AIPlayer2::AIPlayer2(int n) : AIPlayer(n)
{
	numberOfOpponents = n;

	setPlayersDiceAmount();

	initializePlayedBids();
}

Bid AIPlayer2::makeMove(Bid currentBid)
{
	if ((currentBid).getNumber() > 5)
		return callBluff();
	else
		return makeBid(currentBid);
}

Bid AIPlayer2::makeBid(Bid currentBid)
{
	int currentNumber = 0;

	Dice::Face face;

	for (auto& f : playersDiceAmount)
		if (f.second + playedBids.find(f.first)->second > currentNumber) {
			face = f.first;
			currentNumber = f.second + playedBids.find(f.first)->second;
		}

	return Bid(currentNumber, face);
}

void AIPlayer2::setPlayersDiceAmount()
{
	for (auto& f : playersDice)
		++playersDiceAmount[f.getFace()];
}

void AIPlayer2::initializePlayedBids()
{
	playedBids[Dice::Face::One] = 0;
	playedBids[Dice::Face::Two] = 0;
	playedBids[Dice::Face::Three] = 0;
	playedBids[Dice::Face::Four] = 0;
	playedBids[Dice::Face::Five] = 0;
	playedBids[Dice::Face::Star] = 0;
}

void AIPlayer2::updatePlayedBids(Bid bid)
{
	playedBids.find(bid.getFace())->second = bid.getNumber();
}
