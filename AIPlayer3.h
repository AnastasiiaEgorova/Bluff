#pragma once
#include "AIPlayer.h"

class AIPlayer3 : public AIPlayer
{
public:
									AIPlayer3(int n);

	Bid								makeMove(Bid currentBid) override;
	void							updateInfoForPlayer(const Bid& bid);

private:
	Bid								makeBid(Bid currentBid) override;

	void							setPlayersDiceAmount();
	void							initializeFacesWerePlayed();
	void							initializeBidsPlayed();

	void							updateBidsPlayed(const Bid& bid);
	void							updateFacesWerePlayed(const Bid& bid);

	Dice::Face						calculateFaceValue();

private:
	std::map<Dice::Face, int>		playersDiceAmount;
	std::map<Dice::Face, int>		facesWerePlayed;			// how many times the faces were used in bids by other players
	std::map<Dice::Face, int>		bidsPlayed;					// collects other players' bids (face + number)

	std::map<Dice::Face, double>	roundBidsValue;

	const double					WEIGHT_FACES_WERE_PLAYED = 0.2;
	const double					WEIGHT_PLAYED_BIDS = 0.3;
};

