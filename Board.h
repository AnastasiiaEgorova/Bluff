#pragma once
#include <utility>
#include <map>
#include "Dice.h"
#include "Bid.h"

enum class BidsNames {

	One_Ones = 0,
	One_Twos,
	One_Threes,
	One_Fours,
	One_Fives,

	One_Star,

	Two_Ones,
	Two_Twos,
	Two_Threes,
	Two_Fours,
	Two_Fives,

	Three_Ones,
	Three_Twos,
	Three_Threes,
	Three_Fours,
	Three_Fives,

	Two_Stars,

	Four_Ones,
	Four_Twos,
	Four_Threes,
	Four_Fours,
	Four_Fives,

	Five_Ones,
	Five_Twos,
	Five_Threes,
	Five_Fours,
	Five_Fives,

	Three_Stars,

	Six_Ones,
	Six_Twos,
	Six_Threes,
	Six_Fours,
	Six_Fives,

	Seven_Ones,
	Seven_Twos,
	Seven_Threes,
	Seven_Fours,
	Seven_Fives,

	Four_Stars,

	Eight_Ones,
	Eight_Twos,
	Eight_Threes,
	Eight_Fours,
	Eight_Fives,

	Nine_Ones,
	Nine_Twos,
	Nine_Threes,
	Nine_Fours,
	Nine_Fives,

	Five_Stars,

	Ten_Ones, 
	Ten_Twos,
	Ten_Threes,
	Ten_Fours,
	Ten_Fives,

	Eleven_Ones, 
	Eleven_Twos,
	Eleven_Threes,
	Eleven_Fours,
	Eleven_Fives,

	Six_Stars,

	Twelve_Ones, 
	Twelve_Twos,
	Twelve_Threes,
	Twelve_Fours,
	Twelve_Fives,

	Thirteen_Ones,
	Thirteen_Twos,
	Thirteen_Threes,
	Thirteen_Fours,
	Thirteen_Fives,

	Seven_Stars,

	Fourteen_Ones,
	Fourteen_Twos,
	Fourteen_Threes,
	Fourteen_Fours,
	Fourteen_Fives,

	Fifteen_Ones,
	Fifteen_Twos,
	Fifteen_Threes,
	Fifteen_Fours,
	Fifteen_Fives,

	Eight_Stars,

	Sixteen_Ones,
	Sixteen_Twos,
	Sixteen_Threes,
	Sixteen_Fours,
	Sixteen_Fives,

	Seventeen_Ones,
	Seventeen_Twos,
	Seventeen_Threes,
	Seventeen_Fours,
	Seventeen_Fives,

	Nine_Stars,

	Eighteen_Ones,
	Eighteen_Twos,
	Eighteen_Threes,
	Eighteen_Fours,
	Eighteen_Fives,

	Nineteen_Ones,
	Nineteen_Twos,
	Nineteen_Threes,
	Nineteen_Fours,
	Nineteen_Fives,

	Ten_Stars,

	Twenty_Ones,
	Twenty_Twos,
	Twenty_Threes,
	Twenty_Fours,
	Twenty_Fives
};

class Board
{
public:
	static std::map<BidsNames, Bid> const AllBids;

				Board();

	Bid			getCurrentBid();
	void		setCurrentBid(Bid bid);

	bool		isMoveValid(Bid& bid);

private:
	Bid			currentBid;
};

