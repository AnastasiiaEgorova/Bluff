#include "AIPlayer1.h"

AIPlayer1::AIPlayer1(int n) : AIPlayer(n) 
{
	numberOfOpponents = n;

	amountTopFace = 0;

	std::map<Dice::Face, int> counters;
	for (auto& f : playersDice)
		++counters[f.getFace()];

	topFace = findTopFaceInHand(counters);
}

Bid AIPlayer1::makeMove(Bid currentBid)
{
	if ((currentBid).getNumber() > amountTopFace + 2)
		return callBluff();
	else
		return makeBid(currentBid);
}

Bid AIPlayer1::makeBid(Bid currentBid)
{
	if (currentBid.getFace() != Dice::Face::Star)
		return Bid(currentBid.getNumber() + 1, topFace);
	else
		return ++currentBid;
}

Dice::Face AIPlayer1::findTopFaceInHand(std::map<Dice::Face, int> &counters)
{
	amountTopFace = 0;
	 
	for (auto it = counters.begin(); it != counters.end(); ++it)
		if ((it->second > amountTopFace)) {
			topFace = it->first;
			amountTopFace = it->second;
		}

	for (auto it = counters.begin(); it != counters.end(); ++it)
		if (it->first == Dice::Face::Star)
			++amountTopFace;

	return topFace;
}
