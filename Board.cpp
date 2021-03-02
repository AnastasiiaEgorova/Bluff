#include "Board.h"

std::map<BidsNames, Bid> const Board::AllBids{

	{BidsNames::One_Ones, Bid(1, Dice::Face::One)},
	{BidsNames::One_Twos, Bid(1, Dice::Face::Two)},
	{BidsNames::One_Threes, Bid(1, Dice::Face::Three)},
	{BidsNames::One_Fours, Bid(1, Dice::Face::Four)},
	{BidsNames::One_Fives, Bid(1, Dice::Face::Five)},

	{BidsNames::One_Star, Bid(1, Dice::Face::Star)},

	{BidsNames::Two_Ones, Bid(2, Dice::Face::One)},
	{BidsNames::Two_Twos, Bid(2, Dice::Face::Two)},
	{BidsNames::Two_Threes, Bid(2, Dice::Face::Three)},
	{BidsNames::Two_Fours, Bid(2, Dice::Face::Four)},
	{BidsNames::Two_Fives, Bid(2, Dice::Face::Five)},

	{BidsNames::Three_Ones, Bid(3, Dice::Face::One)},
	{BidsNames::Three_Twos, Bid(3, Dice::Face::Two)},
	{BidsNames::Three_Threes, Bid(3, Dice::Face::Three)},
	{BidsNames::Three_Fours, Bid(3, Dice::Face::Four)},
	{BidsNames::Three_Fives, Bid(3, Dice::Face::Five)},

	{BidsNames::Two_Stars, Bid(2, Dice::Face::Star)},

	{BidsNames::Four_Ones, Bid(4, Dice::Face::One)},
	{BidsNames::Four_Twos, Bid(4, Dice::Face::Two)},
	{BidsNames::Four_Threes, Bid(4, Dice::Face::Three)},
	{BidsNames::Four_Fours, Bid(4, Dice::Face::Four)},
	{BidsNames::Four_Fives, Bid(4, Dice::Face::Five)},

	{BidsNames::Five_Ones, Bid(5, Dice::Face::One)},
	{BidsNames::Five_Twos, Bid(5, Dice::Face::Two)},
	{BidsNames::Five_Threes, Bid(5, Dice::Face::Three)},
	{BidsNames::Five_Fours, Bid(5, Dice::Face::Four)},
	{BidsNames::Five_Fives, Bid(5, Dice::Face::Five)},

	{BidsNames::Three_Stars, Bid(3, Dice::Face::Star)},

	{BidsNames::Six_Ones, Bid(6, Dice::Face::One)},
	{BidsNames::Six_Twos, Bid(6, Dice::Face::Two)},
	{BidsNames::Six_Threes, Bid(6, Dice::Face::Three)},
	{BidsNames::Six_Fours, Bid(6, Dice::Face::Four)},
	{BidsNames::Six_Fives, Bid(6, Dice::Face::Five)},

	{BidsNames::Seven_Ones, Bid(7, Dice::Face::One)},
	{BidsNames::Seven_Twos, Bid(7, Dice::Face::Two)},
	{BidsNames::Seven_Threes, Bid(7, Dice::Face::Three)},
	{BidsNames::Seven_Fours, Bid(7, Dice::Face::Four)},
	{BidsNames::Seven_Fives, Bid(7, Dice::Face::Five)},

	{BidsNames::Four_Stars, Bid(4, Dice::Face::Star)},

	{BidsNames::Eight_Ones, Bid(8, Dice::Face::One)},
	{BidsNames::Eight_Twos, Bid(8, Dice::Face::Two)},
	{BidsNames::Eight_Threes, Bid(8, Dice::Face::Three)},
	{BidsNames::Eight_Fours, Bid(8, Dice::Face::Four)},
	{BidsNames::Eight_Fives, Bid(8, Dice::Face::Five)},

	{BidsNames::Nine_Ones, Bid(9, Dice::Face::One)},
	{BidsNames::Nine_Twos, Bid(9, Dice::Face::Two)},
	{BidsNames::Nine_Threes, Bid(9, Dice::Face::Three)},
	{BidsNames::Nine_Fours, Bid(9, Dice::Face::Four)},
	{BidsNames::Nine_Fives, Bid(9, Dice::Face::Five)},

	{BidsNames::Five_Stars, Bid(5, Dice::Face::Star)},

	{BidsNames::Ten_Ones, Bid(10, Dice::Face::One)},
	{BidsNames::Ten_Twos, Bid(10, Dice::Face::Two)},
	{BidsNames::Ten_Threes, Bid(10, Dice::Face::Three)},
	{BidsNames::Ten_Fours, Bid(10, Dice::Face::Four)},
	{BidsNames::Ten_Fives, Bid(10, Dice::Face::Five)},

	{BidsNames::Eleven_Ones, Bid(11, Dice::Face::One)},
	{BidsNames::Eleven_Twos, Bid(11, Dice::Face::Two)},
	{BidsNames::Eleven_Threes, Bid(11, Dice::Face::Three)},
	{BidsNames::Eleven_Fours, Bid(11, Dice::Face::Four)},
	{BidsNames::Eleven_Fives, Bid(11, Dice::Face::Five)},

	{BidsNames::Six_Stars, Bid(6, Dice::Face::Star)},

	{BidsNames::Twelve_Ones, Bid(12, Dice::Face::One)},
	{BidsNames::Twelve_Twos, Bid(12, Dice::Face::Two)},
	{BidsNames::Twelve_Threes, Bid(12, Dice::Face::Three)},
	{BidsNames::Twelve_Fours, Bid(12, Dice::Face::Four)},
	{BidsNames::Twelve_Fives, Bid(12, Dice::Face::Five)},

	{BidsNames::Thirteen_Ones, Bid(13, Dice::Face::One)},
	{BidsNames::Thirteen_Twos, Bid(13, Dice::Face::Two)},
	{BidsNames::Thirteen_Threes, Bid(13, Dice::Face::Three)},
	{BidsNames::Thirteen_Fours, Bid(13, Dice::Face::Four)},
	{BidsNames::Thirteen_Fives, Bid(13, Dice::Face::Five)},

	{BidsNames::Seven_Stars, Bid(7, Dice::Face::Star)},

	{BidsNames::Fourteen_Ones, Bid(14, Dice::Face::One)},
	{BidsNames::Fourteen_Twos, Bid(14, Dice::Face::Two)},
	{BidsNames::Fourteen_Threes, Bid(14, Dice::Face::Three)},
	{BidsNames::Fourteen_Fours, Bid(14, Dice::Face::Four)},
	{BidsNames::Fourteen_Fives, Bid(14, Dice::Face::Five)},

	{BidsNames::Fifteen_Ones, Bid(15, Dice::Face::One)},
	{BidsNames::Fifteen_Twos, Bid(15, Dice::Face::Two)},
	{BidsNames::Fifteen_Threes, Bid(15, Dice::Face::Three)},
	{BidsNames::Fifteen_Fours, Bid(15, Dice::Face::Four)},
	{BidsNames::Fifteen_Fives, Bid(15, Dice::Face::Five)},

	{BidsNames::Eight_Stars, Bid(8, Dice::Face::Star)},

	{BidsNames::Sixteen_Ones, Bid(16, Dice::Face::One)},
	{BidsNames::Sixteen_Twos, Bid(16, Dice::Face::Two)},
	{BidsNames::Sixteen_Threes, Bid(16, Dice::Face::Three)},
	{BidsNames::Sixteen_Fours, Bid(16, Dice::Face::Four)},
	{BidsNames::Sixteen_Fives, Bid(16, Dice::Face::Five)},

	{BidsNames::Seventeen_Ones, Bid(17, Dice::Face::One)},
	{BidsNames::Seventeen_Twos, Bid(17, Dice::Face::Two)},
	{BidsNames::Seventeen_Threes, Bid(17, Dice::Face::Three)},
	{BidsNames::Seventeen_Fours, Bid(17, Dice::Face::Four)},
	{BidsNames::Seventeen_Fives, Bid(17, Dice::Face::Five)},

	{BidsNames::Nine_Stars, Bid(9, Dice::Face::Star)},

	{BidsNames::Eighteen_Ones, Bid(18, Dice::Face::One)},
	{BidsNames::Eighteen_Twos, Bid(18, Dice::Face::Two)},
	{BidsNames::Eighteen_Threes, Bid(18, Dice::Face::Three)},
	{BidsNames::Eighteen_Fours, Bid(18, Dice::Face::Four)},
	{BidsNames::Eighteen_Fives, Bid(18, Dice::Face::Five)},

	{BidsNames::Nineteen_Ones, Bid(19, Dice::Face::One)},
	{BidsNames::Nineteen_Twos, Bid(19, Dice::Face::Two)},
	{BidsNames::Nineteen_Threes, Bid(19, Dice::Face::Three)},
	{BidsNames::Nineteen_Fours, Bid(19, Dice::Face::Four)},
	{BidsNames::Nineteen_Fives, Bid(19, Dice::Face::Five)},

	{BidsNames::Ten_Stars, Bid(10, Dice::Face::Star)},

	{BidsNames::Twenty_Ones, Bid(20, Dice::Face::One)},
	{BidsNames::Twenty_Twos, Bid(20, Dice::Face::Two)},
	{BidsNames::Twenty_Threes, Bid(20, Dice::Face::Three)},
	{BidsNames::Twenty_Fours, Bid(20, Dice::Face::Four)},
	{BidsNames::Twenty_Fives, Bid(20, Dice::Face::Five)}
};

//std::unordered_map<Bid, BidsNames> Board::AllBids2 {
//
//	{Bid(1, Dice::Face::One), BidsNames::One_Ones},
//	{Bid(1, Dice::Face::Two), BidsNames::One_Twos},
//	{Bid(1, Dice::Face::Three), BidsNames::One_Threes},
//	{Bid(1, Dice::Face::Four), BidsNames::One_Fours},
//	{Bid(1, Dice::Face::Five), BidsNames::One_Fives},
//
//	{Bid(1, Dice::Face::Star), BidsNames::One_Star},
//
//	{Bid(2, Dice::Face::One), BidsNames::Two_Ones},
//	{Bid(2, Dice::Face::Two), BidsNames::Two_Twos},
//	{Bid(2, Dice::Face::Three), BidsNames::Two_Threes},
//	{Bid(2, Dice::Face::Four), BidsNames::Two_Fours},
//	{Bid(2, Dice::Face::Five), BidsNames::Two_Fives},
//
//	{Bid(3, Dice::Face::One), BidsNames::Three_Ones},
//	{Bid(3, Dice::Face::Two), BidsNames::Three_Twos},
//	{Bid(3, Dice::Face::Three), BidsNames::Three_Threes},
//	{Bid(3, Dice::Face::Four), BidsNames::Three_Fours},
//	{Bid(3, Dice::Face::Five), BidsNames::Three_Fives},
//
//	{Bid(2, Dice::Face::Star), BidsNames::Two_Stars},
//
//	{Bid(4, Dice::Face::One), BidsNames::Four_Ones},
//	{Bid(4, Dice::Face::Two), BidsNames::Four_Twos},
//	{Bid(4, Dice::Face::Three), BidsNames::Four_Threes},
//	{Bid(4, Dice::Face::Four), BidsNames::Four_Fours},
//	{Bid(4, Dice::Face::Five), BidsNames::Four_Fives},
//
//	{Bid(5, Dice::Face::One), BidsNames::Five_Ones},
//	{Bid(5, Dice::Face::Two), BidsNames::Five_Twos},
//	{Bid(5, Dice::Face::Three), BidsNames::Five_Threes},
//	{Bid(5, Dice::Face::Four), BidsNames::Five_Fours},
//	{Bid(5, Dice::Face::Five), BidsNames::Five_Fives},
//
//	{Bid(3, Dice::Face::Star), BidsNames::Three_Stars},
//
//	{Bid(6, Dice::Face::One), BidsNames::Six_Ones},
//	{Bid(6, Dice::Face::Two), BidsNames::Six_Twos},
//	{Bid(6, Dice::Face::Three), BidsNames::Six_Threes},
//	{Bid(6, Dice::Face::Four), BidsNames::Six_Fours},
//	{Bid(6, Dice::Face::Five), BidsNames::Six_Fives},
//
//	{Bid(7, Dice::Face::One), BidsNames::Seven_Ones},
//	{Bid(7, Dice::Face::Two), BidsNames::Seven_Twos},
//	{Bid(7, Dice::Face::Three), BidsNames::Seven_Threes},
//	{Bid(7, Dice::Face::Four), BidsNames::Seven_Fours},
//	{Bid(7, Dice::Face::Five), BidsNames::Seven_Fives},
//
//	{Bid(4, Dice::Face::Star), BidsNames::Four_Stars},
//
//	{Bid(8, Dice::Face::One), BidsNames::Eight_Ones},
//	{Bid(8, Dice::Face::Two), BidsNames::Eight_Twos},
//	{Bid(8, Dice::Face::Three), BidsNames::Eight_Threes},
//	{Bid(8, Dice::Face::Four), BidsNames::Eight_Fours},
//	{Bid(8, Dice::Face::Five), BidsNames::Eight_Fives},
//
//	{Bid(9, Dice::Face::One), BidsNames::Nine_Ones},
//	{Bid(9, Dice::Face::Two), BidsNames::Nine_Twos},
//	{Bid(9, Dice::Face::Three), BidsNames::Nine_Threes},
//	{Bid(9, Dice::Face::Four), BidsNames::Nine_Fours},
//	{Bid(9, Dice::Face::Five), BidsNames::Nine_Fives},
//
//	{Bid(5, Dice::Face::Star), BidsNames::Five_Stars},
//
//	{Bid(10, Dice::Face::One), BidsNames::Ten_Ones},
//	{Bid(10, Dice::Face::Two), BidsNames::Ten_Twos},
//	{Bid(10, Dice::Face::Three), BidsNames::Ten_Threes},
//	{Bid(10, Dice::Face::Four), BidsNames::Ten_Fours},
//	{Bid(10, Dice::Face::Five), BidsNames::Ten_Fives},
//
//	{Bid(11, Dice::Face::One), BidsNames::Eleven_Ones},
//	{Bid(11, Dice::Face::Two), BidsNames::Eleven_Twos},
//	{Bid(11, Dice::Face::Three), BidsNames::Eleven_Threes},
//	{Bid(11, Dice::Face::Four), BidsNames::Eleven_Fours},
//	{Bid(11, Dice::Face::Five), BidsNames::Eleven_Fives},
//
//	{Bid(6, Dice::Face::Star), BidsNames::Six_Stars},
//
//	{Bid(12, Dice::Face::One), BidsNames::Twelve_Ones},
//	{Bid(12, Dice::Face::Two), BidsNames::Twelve_Twos},
//	{Bid(12, Dice::Face::Three), BidsNames::Twelve_Threes},
//	{Bid(12, Dice::Face::Four), BidsNames::Twelve_Fours},
//	{Bid(12, Dice::Face::Five), BidsNames::Twelve_Fives},
//
//	{Bid(13, Dice::Face::One), BidsNames::Thirteen_Ones},
//	{Bid(13, Dice::Face::Two), BidsNames::Thirteen_Twos},
//	{Bid(13, Dice::Face::Three), BidsNames::Thirteen_Threes},
//	{Bid(13, Dice::Face::Four), BidsNames::Thirteen_Fours},
//	{Bid(13, Dice::Face::Five), BidsNames::Thirteen_Fives},
//
//	{Bid(7, Dice::Face::Star), BidsNames::Seven_Stars},
//
//	{Bid(14, Dice::Face::One), BidsNames::Fourteen_Ones},
//	{Bid(14, Dice::Face::Two), BidsNames::Fourteen_Twos},
//	{Bid(14, Dice::Face::Three), BidsNames::Fourteen_Threes},
//	{Bid(14, Dice::Face::Four), BidsNames::Fourteen_Fours},
//	{Bid(14, Dice::Face::Five), BidsNames::Fourteen_Fives},
//
//	{Bid(15, Dice::Face::One), BidsNames::Fifteen_Ones},
//	{Bid(15, Dice::Face::Two), BidsNames::Fifteen_Twos},
//	{Bid(15, Dice::Face::Three), BidsNames::Fifteen_Threes},
//	{Bid(15, Dice::Face::Four), BidsNames::Fifteen_Fours},
//	{Bid(15, Dice::Face::Five), BidsNames::Fifteen_Fives},
//
//	{Bid(8, Dice::Face::Star), BidsNames::Eight_Stars},
//
//	{Bid(16, Dice::Face::One), BidsNames::Sixteen_Ones},
//	{Bid(16, Dice::Face::Two), BidsNames::Sixteen_Twos},
//	{Bid(16, Dice::Face::Three), BidsNames::Sixteen_Threes},
//	{Bid(16, Dice::Face::Four), BidsNames::Sixteen_Fours},
//	{Bid(16, Dice::Face::Five), BidsNames::Sixteen_Fives},
//
//	{Bid(17, Dice::Face::One), BidsNames::Seventeen_Ones},
//	{Bid(17, Dice::Face::Two), BidsNames::Seventeen_Twos},
//	{Bid(17, Dice::Face::Three), BidsNames::Seventeen_Threes},
//	{Bid(17, Dice::Face::Four), BidsNames::Seventeen_Fours},
//	{Bid(17, Dice::Face::Five), BidsNames::Seventeen_Fives},
//
//	{Bid(9, Dice::Face::Star), BidsNames::Nine_Stars},
//
//	{Bid(18, Dice::Face::One), BidsNames::Eighteen_Ones},
//	{Bid(18, Dice::Face::Two), BidsNames::Eighteen_Twos},
//	{Bid(18, Dice::Face::Three), BidsNames::Eighteen_Threes},
//	{Bid(18, Dice::Face::Four), BidsNames::Eighteen_Fours},
//	{Bid(18, Dice::Face::Five), BidsNames::Eighteen_Fives},
//
//	{Bid(19, Dice::Face::One), BidsNames::Nineteen_Ones},
//	{Bid(19, Dice::Face::Two), BidsNames::Nineteen_Twos},
//	{Bid(19, Dice::Face::Three), BidsNames::Nineteen_Threes},
//	{Bid(19, Dice::Face::Four), BidsNames::Nineteen_Fours},
//	{Bid(19, Dice::Face::Five), BidsNames::Nineteen_Fives},
//
//	{Bid(10, Dice::Face::Star), BidsNames::Ten_Stars},
//
//	{Bid(20, Dice::Face::One), BidsNames::Twenty_Ones},
//	{Bid(20, Dice::Face::Two), BidsNames::Twenty_Twos},
//	{Bid(20, Dice::Face::Three), BidsNames::Twenty_Threes},
//	{Bid(20, Dice::Face::Four), BidsNames::Twenty_Fours},
//	{Bid(20, Dice::Face::Five), BidsNames::Twenty_Fives}
//};

Board::Board()
{
	currentBid = Bid();
	//currentBidName = BidsNames::One_Ones;
}

Bid Board::getCurrentBid() 
{
	return currentBid;
}

void Board::setCurrentBid(Bid bid)
{
	if (isMoveValid(bid))
		currentBid = bid;
}


bool Board::isMoveValid(Bid& bid)
{
	BidsNames bidName = BidsNames::One_Ones;
	BidsNames currentBidName = BidsNames::One_Ones;

	for (auto it = AllBids.begin(); it != AllBids.end(); ++it) {
		if (it->second == currentBid)
			currentBidName = it->first;
		if (it->second == bid)
			bidName == it->first;
	}

	if (bidName > currentBidName)
		return true; 

	return false;
}