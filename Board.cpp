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

std::map<int, sf::Vector2f> const Board::BidPositions {
	{1, sf::Vector2f(358, 185)},
	{2, sf::Vector2f(472, 181)},
	{3, sf::Vector2f(518, 180)},
	{4, sf::Vector2f(608, 178)},
	{5, sf::Vector2f(650, 187)},
	{6, sf::Vector2f(758, 179)},
	{7, sf::Vector2f(803, 177)},
	{8, sf::Vector2f(858, 248)},
	{9, sf::Vector2f(866, 296)},
	{10, sf::Vector2f(854, 405)},
	{11, sf::Vector2f(849, 469)},
	{12, sf::Vector2f(777, 476)},
	{13, sf::Vector2f(713, 470)},
	{14, sf::Vector2f(613, 467)},
	{15, sf::Vector2f(549, 487)},
	{16, sf::Vector2f(443, 482)},
	{17, sf::Vector2f(397, 480)},
	{18, sf::Vector2f(351, 400)},
	{19, sf::Vector2f(355, 353)},
	{20, sf::Vector2f(350, 255)}
};

std::map<int, sf::Vector2f> const Board::BidStarsPositions{
	{1, sf::Vector2f(403, 185)},
	{2, sf::Vector2f(557, 188)},
	{3, sf::Vector2f(699, 189)},
	{4, sf::Vector2f(846, 200)},
	{5, sf::Vector2f(850, 358)},
	{6, sf::Vector2f(810, 485)},
	{7, sf::Vector2f(669, 475)},
	{8, sf::Vector2f(504, 477)},
	{9, sf::Vector2f(349, 447)},
	{10, sf::Vector2f(348, 311)}
};

std::map<int, float> const Board::BidRotations {
	{1, -6.f},
	{2, 32.f},
	{3, 20.f},
	{4, 6.f},
	{5, -22.f},
	{6, 18.f},
	{7, 9.f},
	{8, 19.f},
	{9, 43.f},
	{10, 15.f},
	{11, -25.f},
	{12, 41.f},
	{13, 12.f},
	{14, 13.f},
	{15, -18.f},
	{16, -20.f},
	{17, 15.f},
	{18, -21.f},
	{19, -17.f},
	{20, -13.f}
};

std::map<int, float> const Board::BidStarsRotations{
	{1, -36.f},
	{2, -10.f},
	{3, -42.f},
	{4, -10.f},
	{5, -7.f},
	{6, 1.f},
	{7, 36.f},
	{8, 9.f},
	{9, -12.f},
	{10, -32.f}
};

Board::Board()
{
	currentBid = Bid();
	//currentBidName = BidsNames::One_Ones;
}

Bid Board::getCurrentBid() const
{
	return currentBid;
}

void Board::setCurrentBid(Bid bid)
{
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
			bidName = it->first;
	}

	if (bidName > currentBidName)
		return true; 

	return false;
}