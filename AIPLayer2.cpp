#include "AIPLayer2.h"

AIPlayer2::AIPlayer2(int n) : AIPlayer(n)
{
	numberOfPlayers = n;

	setPlayersDiceAmount();

	initializeFacesWerePlayed();
}

Bid AIPlayer2::makeMove(Bid currentBid)
{
	if (currentBid.getFace() == Dice::Face::Star) {
		if ((currentBid).getNumber() > numberOfPlayers)
			return callBluff();
		else
			return makeBid(currentBid);
	}
	else
	{
		if ((currentBid).getNumber() > numberOfPlayers * playersDice.size() / 3)
			return callBluff();
		else
			return makeBid(currentBid);
	}
}

Bid AIPlayer2::makeBid(Bid currentBid)
{
	int currentNumber = 0;

	Dice::Face face;

	if (currentBid.getFace() == Dice::Face::Star) {
		for (auto it = playersDiceAmount.begin(); it != playersDiceAmount.end(); ++it) {
			if (it->second > currentNumber) {
				face = it->first;
				currentNumber = it->second;
			}
		}
		currentNumber = currentBid.getNumber() * 2;  //because there is different path for stars (next star is always *2 of current position)
	}
	else {
		for (auto& f : playersDiceAmount)
			if (f.second + facesWerePlayed.find(f.first)->second >= currentNumber) {
				face = f.first;
				currentNumber = f.second + facesWerePlayed.find(f.first)->second;
			}

		if (face == Dice::Face::Star)
			currentNumber = currentBid.getNumber() / 2 + 1;

		if (!(currentNumber == currentBid.getNumber() && face > currentBid.getFace()))
			currentNumber = currentBid.getNumber() + 1;
	}

	return Bid(currentNumber, face);
}

void AIPlayer2::setPlayersDiceAmount()
{
	for (auto& f : playersDice) {
		++playersDiceAmount[f.getFace()];
		if (f.getFace() == Dice::Face::Star) {
			playersDiceAmount[Dice::Face::One]++;
			playersDiceAmount[Dice::Face::Two]++;
			playersDiceAmount[Dice::Face::Three]++;
			playersDiceAmount[Dice::Face::Four]++;
			playersDiceAmount[Dice::Face::Five]++;
		}
	}
}

void AIPlayer2::initializeFacesWerePlayed()
{
	facesWerePlayed[Dice::Face::One] = 0;
	facesWerePlayed[Dice::Face::Two] = 0;
	facesWerePlayed[Dice::Face::Three] = 0;
	facesWerePlayed[Dice::Face::Four] = 0;
	facesWerePlayed[Dice::Face::Five] = 0;
	facesWerePlayed[Dice::Face::Star] = 0;
}

void AIPlayer2::updateInfoForPlayer(const Bid& bid)
{
	updateFacesWerePlayed(bid);
}

void AIPlayer2::updateFacesWerePlayed(const Bid& bid)
{
	facesWerePlayed.find(bid.getFace())->second++;
}
