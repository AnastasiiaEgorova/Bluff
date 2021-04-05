#pragma once
#include "AIPlayer.h"

class AIPlayerDean : public AIPlayer
{
public:
									AIPlayerDean(int n);

	Bid								makeMove(Bid currentBid) override;
	void							updateInfoForPlayer(const Bid& bid);

private:
	Bid								makeBid(Bid currentBid) override;
	std::string						getName() override;

	void							setPlayersDiceAmount();
	void							initializeFacesWerePlayed();

	void							updateFacesWerePlayed(const Bid& bid);

private:
	std::map<Dice::Face, int>		playersDiceAmount;
	std::map<Dice::Face, int>		facesWerePlayed;			// how many times the faces were used in bids by other players
};

