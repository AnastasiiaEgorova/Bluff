#pragma once
#include "AIPlayer.h"

class AIPlayer2 : public AIPlayer
{
public:
									AIPlayer2(int n);

	Bid								makeMove(Bid currentBid) override;
	void							updateInfoForPlayer(const Bid& bid);

private:
	Bid								makeBid(Bid currentBid) override;

	void							setPlayersDiceAmount();
	void							initializeFacesWerePlayed();

	void							updateFacesWerePlayed(const Bid& bid);

private:
	std::map<Dice::Face, int>		playersDiceAmount;
	std::map<Dice::Face, int>		facesWerePlayed;			// how many times the faces were used in bids by other players
};

