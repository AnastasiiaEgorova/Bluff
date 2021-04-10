#include "AIPlayerBrittasaurus.h"

AIPlayerBrittasaurus::AIPlayerBrittasaurus(int n) : AIPlayer(n) 
{
	numberOfPlayers = n;

	amountTopFace = 0;

	std::map<Dice::Face, int> counters;
	for (auto& f : playersDice)
		++counters[f.getFace()];

	topFace = findTopFaceInHand(counters);
}

Bid AIPlayerBrittasaurus::makeMove(Bid currentBid)
{
	if ((currentBid).getNumber() > amountTopFace + numberOfPlayers / 2)
		return callBluff();
	else
		return makeBid(currentBid);
}

Bid AIPlayerBrittasaurus::makeBid(Bid currentBid)
{
	if (currentBid.getFace() != Dice::Face::Star)
		return Bid(currentBid.getNumber() + 1, topFace);
	else
		return ++currentBid;
}

std::string AIPlayerBrittasaurus::getName()
{
	return "Brittasaurus";
}

Dice::Face AIPlayerBrittasaurus::findTopFaceInHand(std::map<Dice::Face, int> &counters)
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
