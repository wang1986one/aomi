#include "MyWheelControllerStableHeaders.h"
#include "ScoreBouns.h"
using namespace Orz;

//
//int ScoreBouns::getBounsAmount(int feedback, int total, float percent) const
//{
//	 
//	if(total == 0)
//		return -1;
//	return int(float(feedback)/(float(total) * percent));
//}
//
//
//bool ScoreBouns::isBounsAmount(int bouns) const
//{
//
//	using namespace boost;
//	if(bouns < 2000 && bouns != -1)
//		return false;
//	boost::mt19937 engine(time(NULL));
//	boost::uniform_int<> distribution(0,100);
//
//	variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);
//	int r =  myrandom();
//
//	return r <= 2;
//}
//
////WinDataPrototypePtr ScoreBouns::getWinData(WinDataPrototypePtr windata;) const
////{
////	assert(windata)
////
////}
////
////WheelEnum::WINNER ScoreWinner::getOddsWinner() const
////{
////	using namespace boost;
////	float n = 0.3f;
////
////	
////
////	
////
////	if(r<= getOdds(WheelEnum::Dealer))
////	{
////		return WheelEnum::Dealer;
////	}
////
////	if(r<= getOdds(WheelEnum::Dealer) + getOdds(WheelEnum::Player))
////	{
////		return WheelEnum::Player;
////	}
////	return WheelEnum::Draw;
////
////}	
//
//	