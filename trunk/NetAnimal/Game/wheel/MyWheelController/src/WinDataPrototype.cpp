#include "MyWheelControllerStableHeaders.h"
#include "WinDataPrototype.h"
#include "WinData.h"
#include <boost/random.hpp>
using namespace Orz;



//    =r =h =g  
// 1  6  6  6
// 2  10 10 10
// 3  15 15 15 
// 4  31 31 31


//    +r -h =g  
// 1  7  5  6
// 2  11 8 10
// 3  17 14 15 
// 4  35 28 31


//    +r =h -g  
// 1  7  6  5
// 2  11 10 8
// 3  17 15 14 
// 4  35 31 28


//    -r +h =g  
// 1  5  7  6
// 2  8  11 10
// 3  14 17 15 
// 4  28 35 31


//    =r +h -g  
// 1  6  7  5
// 2  10 11 8
// 3  15 17 14 
// 4  31 35 28
//
//static const int RATE[] = 
//{
//	6,  6,  6,
//	10, 10, 10,
//	15, 15, 15, 
//	31, 31, 31,
//
//	// +r -h =g  
//	7,  5,  6,
//	11, 8, 10,
//	17, 14, 15, 
//	35, 28, 31,
//
//
//	//	    +r =h -g  
//	7,  6,  5,
//	11, 10, 8,
//	17, 15, 14, 
//	35, 31, 28,
//
//
//	//	    -r +h =g  
//	5,  7,  6,
//	8,  11, 10,
//	14, 17, 15, 
//	28, 35, 31,
//
//
//	//	    =r +h -g  
//	6,  7,  5,
//	10, 11, 8,
//	15, 17, 14, 
//	31, 35, 28,
//
//
//	//	    -r ++h -g  
//	5,  8,  5,
//	8, 13, 8,
//	14, 20, 14, 
//	28, 40, 28
//};
//static int getRate()
//{
//
//}
//WinDataPrototype::WinDataPrototype(Orz::WheelEnum::WIN_MODE winMode):_winMode(winMode)
//{
//	/*Orz::IInputManager::getSingleton().addKeyListener(this);*/
//}
//int WinDataPrototype::getRate(const WheelEnum::AnimalItem & animalItem,  const WheelEnum::RATE mode)
//{
//	int i = (mode * 12+animalItem.first * 3 +  animalItem.second);
//	int rate = RATE[i];
//	return rate;
//}
//
//void WinDataPrototype::setBouns(int bouns)
//{
//	if(bouns == -1)
//	{
//		using namespace boost;
//		
//	
//		boost::mt19937 engine(time(NULL));
//		boost::uniform_int<> distribution(3000,19999);
//
//	    variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);
//		bouns = myrandom();
//	}
//
//	WinData::getInstance().setBonus(bouns);
//}
//
//WinDataPrototypePtr WinDataPrototype::gatBounsData(void) const
//{
//	
//	assert(_winMode == Orz::WheelEnum::NONE);
//	WinDataPrototypePtr data(new WinDataPrototype(Orz::WheelEnum::GOLD));
//	BOOST_FOREACH(const WheelEnum::AnimalItem & animalItem, _animals)
//	{
//		data->push_back(animalItem);
//	}
//	return data;
//}
//
//void WinDataPrototype::submit(const WheelEnum::RATE mode) const
//{
//	WinData::getInstance().clear();
//	WinData::getInstance().setWinMode(_winMode);
//	BOOST_FOREACH(const WheelEnum::AnimalItem & animalItem, _animals)
//	{
//		WinData::getInstance().push_back(animalItem, getRate(animalItem, mode));
//	}
//	
//}
//const WheelEnum::WIN_MODE WinDataPrototype::getWinMode(void) const
//{
//	return _winMode;
//}
//size_t WinDataPrototype::calculate(const WheelEnum::AnimalItem & animalItem, const WheelEnum::RATE mode) const
//{
//
//	size_t n = 0;
//	BOOST_FOREACH( WheelEnum::AnimalItem ai, _animals)
//	{
//		if(ai == animalItem)
//		{
//			n = getRate(ai, mode);
//			break;
//
//		}
//
//	}
//
//	if(_winMode == WheelEnum::DOUBLE)
//		n *= 2;
//	else if(_winMode == WheelEnum::TREBLE)
//		n *= 3;
//	return n;
//}
//void WinDataPrototype::push_back(const WheelEnum::AnimalItem & animalItem)
//{
//	_animals.push_back(animalItem);
//}