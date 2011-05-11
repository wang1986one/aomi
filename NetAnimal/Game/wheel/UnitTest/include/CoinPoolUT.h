#ifndef __Orz_UnitTest_CoinPoolUT__
#define __Orz_UnitTest_CoinPoolUT__
#include "UnitTestConfig.h"
#include "CoinPool.h"
#include "WinDataPrototype.h"
#include "WinData.h"
#include <boost/random.hpp>
#include <boost/lambda/lambda.hpp>
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/
float probability(int i)
{
	float n = 0;
	if(i > 500)
		n = 1.f;
	else 
		n = i/500.f;

	return 1.f - (1.f-n)*(1.f-n);

}

BOOST_AUTO_TEST_CASE(CoinPoolUT)
{
	CoinPoolPtr coinPool(new CoinPool(100));
	CoinPoolPtr earningsPool(new CoinPool(4));
	CoinPoolPtr rebatePool(new CoinPool(96));
	CoinPoolPtr prizePool(new CoinPool(48));
	CoinPoolPtr bonusPool(new CoinPool(48));

	coinPool->link(earningsPool, 4);
	coinPool->link(rebatePool, CoinPool::AllOther);

	rebatePool->link(prizePool, 48);
	rebatePool->link(bonusPool, CoinPool::AllOther);

	for(int i = 0; i<200; ++i)
	{
		coinPool->push();
	}


	BOOST_CHECK_EQUAL(coinPool->total(), 0);
	BOOST_CHECK_EQUAL(earningsPool->total(), 8);
	BOOST_CHECK_EQUAL(rebatePool->total(), 0);
	BOOST_CHECK_EQUAL(prizePool->total(), 96);
	BOOST_CHECK_EQUAL(bonusPool->total(), 96);

	WinDataPrototype wdp(Orz::WheelEnum::NONE);
	wdp.push_back(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red));

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


	  // 5,  8,  5,
	  //8, 13, 8,
	  // 14, 20, 14, 
	  // 28, 40, 28
	
	

	int i = wdp.calculate(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red), WheelEnum::MODE0);
	BOOST_CHECK_EQUAL(i, 6);
	
	i = wdp.calculate(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red), WheelEnum::MODE1);
	BOOST_CHECK_EQUAL(i, 0);
	
	wdp.submit(WheelEnum::MODE0);
	BOOST_CHECK_EQUAL(Orz::WinData::getInstance().getWinMode() ,wdp.getWinMode());
	BOOST_CHECK(Orz::WinData::getInstance().getAnimalItem(0) == WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red));
	BOOST_CHECK_EQUAL(Orz::WinData::getInstance().getRate(0) ,6);
	using namespace boost;
	boost::uniform_int<> distribution(0,100);
	boost::mt19937 engine;
	variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);

	for (int i=0; i<100; ++i)
		std::cout << myrandom() << std::endl;
	float a = 1;
	BOOST_CHECK_EQUAL(probability(0) , 0);
	BOOST_CHECK_EQUAL(probability(100) , 100);
	BOOST_CHECK_EQUAL(probability(200) , 0);
	BOOST_CHECK_EQUAL(probability(300) , 1);
	BOOST_CHECK_EQUAL(probability(400) , 1);
	BOOST_CHECK_EQUAL(probability(500) , 1);
	BOOST_CHECK_EQUAL(probability(600) , 1);
	bool  win = myrandom() < (probability(0) * 100);
	std::cout<<(boost::lambda::_1/10)(a)<<"!!!@#"<<std::endl;
	//BOOST_CHECK_EQUAL(wdp.calculate(AnimalItem(WheelEnum::TYPE0, WheelEnum::Red), WheelEnum::MODE2), 7);
	//BOOST_CHECK_EQUAL(wdp.calculate(AnimalItem(WheelEnum::TYPE0, WheelEnum::Red), WheelEnum::MODE3), 5);
	//BOOST_CHECK_EQUAL(wdp.calculate(AnimalItem(WheelEnum::TYPE0, WheelEnum::Red), WheelEnum::MODE4), 6);
	//BOOST_CHECK_EQUAL(wdp.calculate(AnimalItem(WheelEnum::TYPE0, WheelEnum::Red), WheelEnum::MODE5), 5);
}

#endif