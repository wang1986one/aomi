#include "MyWheelControllerStableHeaders.h"
#include "ScoreWinner.h"
//using namespace Orz;
//
//ScoreWinner::ScoreWinner(void)
//{
//
//}
//ScoreWinner::~ScoreWinner(void)
//{
//
//}
//
//
////int ScoreWinner::calculate(WheelEnum::WINNER winner, int n) const
////{
////	return 0;
////}
//
//std::pair<int, WheelEnum::WINNER> ScoreWinner::getWinner(const Winner & w, int prize) const
//{
//
//	//int num[3];
//	//num[WheelEnum::Dealer] = dealer;
//	//num[WheelEnum::Player] = player;
//	//num[WheelEnum::Draw] = draw;
//	
////	int all = dealer + player + draw;
//
//
//	//for(int i =0; i<3; ++i)
//	//{
//	//	WheelEnum::WINNER winner = WheelEnum::WINNER(i);
//	//	num_prize_win[winner].get<1>() = num_prize_win[winner].get<0>() * getOverride(winner);
//	//}
//
//	int get = -1;
//	WheelEnum::WINNER winner = getOddsWinner();
//
//	get = getOverride(winner) * w.get(winner);
//	if(get<= prize)
//	{
//		return std::make_pair(get, winner);
//	}
//	else
//	{
//	
//		for(int i =0; i<3; ++i)
//		{
//			winner = WheelEnum::WINNER(i);
//			get = getOverride(winner) * w.get(winner);
//
//			if(get <= prize)
//				return std::make_pair(get, winner);
//		}
//	}
//	
//
//	return std::make_pair(getOverride(WheelEnum::Dealer) * w.get(WheelEnum::Dealer), WheelEnum::Dealer);
//}
//
//
//int ScoreWinner::getOverride(WheelEnum::WINNER winner) const
//{
//	switch(winner)
//	{
//	case WheelEnum::Dealer:
//		return 2;
//		break;
//	case  WheelEnum::Player:
//		return 2;
//		break;
//	case  WheelEnum::Draw:
//		return 8;
//		break;
//	}
//	return 1;
//}
//
//float ScoreWinner::getOdds(WheelEnum::WINNER winner) const
//{
//	switch(winner)
//	{
//	case WheelEnum::Dealer:
//		return 0.45f;
//		break;
//	case  WheelEnum::Player:
//		return 0.45f;
//		break;
//	case  WheelEnum::Draw:
//		return 0.1f;
//		break;
//	}
//	return 0.f;
//}
//
//WheelEnum::WINNER ScoreWinner::getOddsWinner() const
//{
//	using namespace boost;
//	float n = 0.3f;
//
//	boost::mt19937 engine(time(NULL));
//	boost::uniform_real<> distribution(0,1);
//
//	variate_generator<mt19937, uniform_real<> > myrandom (engine, distribution);
//	float r =  myrandom();
//
//
//	if(r<= getOdds(WheelEnum::Dealer))
//	{
//		return WheelEnum::Dealer;
//	}
//
//	if(r<= getOdds(WheelEnum::Dealer) + getOdds(WheelEnum::Player))
//	{
//		return WheelEnum::Player;
//	}
//	return WheelEnum::Draw;
//
//}	
//
//	