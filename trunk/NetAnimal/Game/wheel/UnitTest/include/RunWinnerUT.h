#ifndef __Orz_UnitTest_CoinPoolUT__
#define __Orz_UnitTest_CoinPoolUT__
#include "UnitTestConfig.h"
#include "SCMData.h"
#include "WinDataPrototype.h"
#include "WinData.h"
#include <boost/random.hpp>
#include <boost/lambda/lambda.hpp>
#include "ScoreBouns.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

#include "ScoreBouns.h"

BOOST_AUTO_TEST_CASE(RunWinnerUT)
{

	SCMData data;
	
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Dealer), 0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Player), 0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Draw), 0);
	data.clickButton(0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Dealer), 1);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Player), 0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Draw), 0);
	data.clickButton(0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Dealer), 2);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Player), 0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Draw), 0);
	data.clickButton(1);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Dealer), 2);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Player), 1);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Draw), 0);
	data.clickButton(2);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Dealer), 2);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Player), 1);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Draw), 1);


	data.clickButton(3);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red)), 1);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red)), 0);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Yellow)), 0);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE3, WheelEnum::Green)), 0);


	
	data.clickButton(6);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red)), 1);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red)), 1);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Yellow)), 0);

	data.clickButton(6);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red)), 1);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red)), 2);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Yellow)), 0);

	
	data.clickButton(7);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red)), 1);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red)), 2);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Yellow)), 1);

		
	data.clickButton(14);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE3, WheelEnum::Green)), 1);
	data.sum(data);
	
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red)), 2);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red)), 4);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Yellow)), 2);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE3, WheelEnum::Green)), 2);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Dealer), 4);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Player), 2);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Draw), 2);



	ScoreAnimal::Animal animal;
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(0)), 0);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(1)), 1);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(2)), 2);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(3)), 3);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(4)), 4);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(5)), 5);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(6)), 6);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(7)), 7);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(8)), 8);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(9)), 9);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(10)), 10);
	BOOST_CHECK_EQUAL( animal.getInt(animal.getAnimal(11)), 11);

	ScoreBouns sb;
	//	all * 100/scm.getAnimal().getTotal();

	std::cout<<data.getAnimal().getTotal()<<std::endl;
	//std::cout<<sb.getBounsAmount(1000, data.getAnimal().getTotal(), 0.01f)<<std::endl;
	//sb.isBouns(1000);
	////sb.getBounsAmount()
	//WinDataPrototype win = sb.getWinData(WinDataPrototype windata);
	data.clear();
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Dealer), 0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Player), 0);
	BOOST_CHECK_EQUAL( data.getWinner().get(WheelEnum::Draw), 0);

	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red)), 0);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red)), 0);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Yellow)), 0);
	BOOST_CHECK_EQUAL( data.getAnimal().get(WheelEnum::AnimalItem(WheelEnum::TYPE3, WheelEnum::Green)), 0);


	
	BOOST_CHECK_EQUAL( sb.getBounsAmount(101, data.getAnimal().getTotal(), 0.01f), -1);
//	RunWinnerPtr rw(new RunWinner());
	/*rw->calculate(WheelEnum::Player, 1);
	rw->calculate(WheelEnum::Dealer, 1);*/
//	rw->calculate(WheelEnum::Draw, 1);
//	rw->getWinner(1,1,1,100);
//
}

#endif