#pragma once
#include <utility>
#include <map>
#include "Dice.h"
#include "Bid.h"
#include <unordered_map>

enum class BidsNames {

	One_Ones = 1,
	One_Twos = 2,
	One_Threes = 3,
	One_Fours = 4,
	One_Fives = 5,

	One_Star = 6,

	Two_Ones = 7,
	Two_Twos = 8,
	Two_Threes = 9,
	Two_Fours = 10,
	Two_Fives = 11,

	Three_Ones = 12,
	Three_Twos = 13,
	Three_Threes = 14,
	Three_Fours = 15,
	Three_Fives = 16,

	Two_Stars = 17,

	Four_Ones = 18,
	Four_Twos = 19,
	Four_Threes = 20,
	Four_Fours = 21,
	Four_Fives = 22,

	Five_Ones = 23,
	Five_Twos = 24,
	Five_Threes = 25,
	Five_Fours = 26,
	Five_Fives = 27,

	Three_Stars = 28,

	Six_Ones = 29,
	Six_Twos = 30,
	Six_Threes = 31,
	Six_Fours = 32,
	Six_Fives = 33,

	Seven_Ones = 34,
	Seven_Twos = 35,
	Seven_Threes = 36,
	Seven_Fours = 37,
	Seven_Fives = 38,

	Four_Stars = 39,

	Eight_Ones = 40,
	Eight_Twos = 41,
	Eight_Threes = 42,
	Eight_Fours = 43,
	Eight_Fives = 44,

	Nine_Ones = 45,
	Nine_Twos = 46,
	Nine_Threes = 47,
	Nine_Fours = 48,
	Nine_Fives = 49,

	Five_Stars = 50,

	Ten_Ones = 51, 
	Ten_Twos = 52,
	Ten_Threes = 53,
	Ten_Fours = 54,
	Ten_Fives = 55,

	Eleven_Ones = 56, 
	Eleven_Twos = 57,
	Eleven_Threes = 58,
	Eleven_Fours = 59,
	Eleven_Fives = 60,

	Six_Stars = 61,

	Twelve_Ones = 62, 
	Twelve_Twos = 63,
	Twelve_Threes = 64,
	Twelve_Fours = 65,
	Twelve_Fives = 66,

	Thirteen_Ones = 67,
	Thirteen_Twos = 68,
	Thirteen_Threes = 69,
	Thirteen_Fours = 70,
	Thirteen_Fives = 71,

	Seven_Stars = 72,

	Fourteen_Ones = 73,
	Fourteen_Twos = 74,
	Fourteen_Threes = 75,
	Fourteen_Fours = 76,
	Fourteen_Fives = 77,

	Fifteen_Ones = 78,
	Fifteen_Twos = 79,
	Fifteen_Threes = 80,
	Fifteen_Fours = 81,
	Fifteen_Fives = 82,

	Eight_Stars = 83,

	Sixteen_Ones = 84,
	Sixteen_Twos = 85,
	Sixteen_Threes = 86,
	Sixteen_Fours = 87,
	Sixteen_Fives = 88,

	Seventeen_Ones = 89,
	Seventeen_Twos = 90,
	Seventeen_Threes = 91,
	Seventeen_Fours = 92,
	Seventeen_Fives = 93,

	Nine_Stars = 94,

	Eighteen_Ones = 95,
	Eighteen_Twos = 96,
	Eighteen_Threes = 97,
	Eighteen_Fours = 98,
	Eighteen_Fives = 99,

	Nineteen_Ones = 100,
	Nineteen_Twos = 101,
	Nineteen_Threes = 102,
	Nineteen_Fours = 103,
	Nineteen_Fives = 104,

	Ten_Stars = 105,

	Twenty_Ones = 106,
	Twenty_Twos = 107,
	Twenty_Threes = 108,
	Twenty_Fours = 109,
	Twenty_Fives = 110,
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
	//BidsNames	currentBidName;
};

