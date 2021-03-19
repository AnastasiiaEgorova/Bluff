#include "AIPlayer3.h"

AIPlayer3::AIPlayer3(int n) : AIPlayer(n)
{
	numberOfPlayers = n;

	setPlayersDiceAmount();

	initializeBidsPlayed();
	initializeFacesWerePlayed();
}

Bid AIPlayer3::makeMove(Bid currentBid)
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

Bid AIPlayer3::makeBid(Bid currentBid)
{
	int currentNumber = 0;

	Dice::Face face;

	if (currentBid.getFace() == Dice::Face::Star) {
		if (currentBid.getNumber() < numberOfPlayers)
			face = Dice().getFace();
		else {
			face = calculateFaceValue();
		}

		currentNumber = currentBid.getNumber() * 2;  //because there is different path for stars (next star is always *2 of current position)
	}
	else {

		// find face
		if (currentBid.getNumber() < numberOfPlayers * 3) {						// if start of game => bluff 
			face = Dice().getFace();											// default C_TOR uses random engine
		}
		else {																	// if middle of game => real bids
			face = calculateFaceValue();
		}

		// find number
		if (face > currentBid.getFace())
			currentNumber = currentBid.getNumber();
		else
			currentNumber = currentBid.getNumber() + 1;
	}

	return Bid(currentNumber, face);
}

void AIPlayer3::setPlayersDiceAmount()
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

void AIPlayer3::initializeFacesWerePlayed()
{
	facesWerePlayed[Dice::Face::One] = 0;
	facesWerePlayed[Dice::Face::Two] = 0;
	facesWerePlayed[Dice::Face::Three] = 0;
	facesWerePlayed[Dice::Face::Four] = 0;
	facesWerePlayed[Dice::Face::Five] = 0;
	facesWerePlayed[Dice::Face::Star] = 0;
}

void AIPlayer3::initializeBidsPlayed()
{
	bidsPlayed[Dice::Face::One] = 0;
	bidsPlayed[Dice::Face::Two] = 0;
	bidsPlayed[Dice::Face::Three] = 0;
	bidsPlayed[Dice::Face::Four] = 0;
	bidsPlayed[Dice::Face::Five] = 0;
	bidsPlayed[Dice::Face::Star] = 0;
}

void AIPlayer3::updateInfoForPlayer(const Bid& bid)
{
	updateBidsPlayed(bid);
	updateFacesWerePlayed(bid);
}

void AIPlayer3::updateBidsPlayed(const Bid& bid)
{
	bidsPlayed.find(bid.getFace())->second = bid.getNumber();
}

void AIPlayer3::updateFacesWerePlayed(const Bid& bid)
{
	facesWerePlayed.find(bid.getFace())->second++;
}

Dice::Face AIPlayer3::calculateFaceValue()
{
	Dice::Face face;
	int currentNumber = 0;

	for (auto& f : playersDiceAmount)
		roundBidsValue[f.first] = f.second;

	for (auto& f : facesWerePlayed)
		roundBidsValue[f.first] += f.second * WEIGHT_FACES_WERE_PLAYED;

	for (auto& f : bidsPlayed)
		roundBidsValue[f.first] += f.second * WEIGHT_PLAYED_BIDS;

	for (auto& f : roundBidsValue)
		if (roundBidsValue[f.first] > currentNumber) {
			face = f.first;
			currentNumber = f.second;
		}

	return face;
}