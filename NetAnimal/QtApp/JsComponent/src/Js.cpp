#include "JsComponentStableHeaders.h"
#include "Js.h"
#include <WheelGobal/WinData.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace Orz;


Orz::WheelEnum::AnimalItem Js::getItem(const std::string & c) const
{

	switch(c.at(0))
	{
	case 'D':
		return Orz::WheelEnum::AnimalItem( WheelEnum::LION ,WheelEnum::Red);
	case 'E':
		return Orz::WheelEnum::AnimalItem( WheelEnum::LION ,WheelEnum::Green);
	case 'F':
		return Orz::WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow);



	case 'G':
		return Orz::WheelEnum::AnimalItem( WheelEnum::PANDA ,WheelEnum::Red);
	case 'H':
		return Orz::WheelEnum::AnimalItem( WheelEnum::PANDA ,WheelEnum::Green);
	case 'I':
		return Orz::WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow);



	case 'J':
		return Orz::WheelEnum::AnimalItem( WheelEnum::MONKEY ,WheelEnum::Red);
	case 'K':
		return Orz::WheelEnum::AnimalItem( WheelEnum::MONKEY ,WheelEnum::Green);
	case 'L':
		return Orz::WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow);


	case 'M':
		return Orz::WheelEnum::AnimalItem( WheelEnum::RABBIT ,WheelEnum::Red);
	case 'N':
		return Orz::WheelEnum::AnimalItem( WheelEnum::RABBIT ,WheelEnum::Green);
	case 'O':
		return Orz::WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow);

	
	}
	return Orz::WheelEnum::AnimalItem();
}

Orz::WheelEnum::Winner Js::getWinner(const std::string & c) const
{

	switch(c.at(0))
	{
	case 'A':
		return Orz::WheelEnum::Dealer;
	case 'B':
		return Orz::WheelEnum::Player;
	case 'C':
		return Orz::WheelEnum::Draw;
	}
	return Orz::WheelEnum::Player;
}
		
Js::Js(void)
{

}
Js::~Js(void)
{

}

Js & Js::getInstance(void)
{
	return *(getInstancePtr());
}
Js * Js::getInstancePtr(void)
{
	static Js instance;
	return &instance;
}



//void Js::setButtonEnable(bool enable)
//{
//	_enableButton(enable);
//}
//
//boost::signals2::connection Js::subscribeEnableButton(const JsInterface::EnableButtonSignalType::slot_type &subscriber)
//{
//	return _enableButton.connect(subscriber);
//}
//

//
//void Js::deal_None(boost::property_tree::ptree & pt)
//{
//	WinData::getInstance().setWinMode(WheelEnum::NONE);
//	WheelEnum::AnimalItem item = getItem(pt.get<std::string>("item", "D"));
//	WinData::getInstance().push_back(item, pt.get<int>("rate", 20));
//}
//void Js::deal_Color(boost::property_tree::ptree & pt)
//{
//	
//	WinData::getInstance().setWinMode(WheelEnum::ALL_COLOR);
//}
//void Js::deal_Animal(boost::property_tree::ptree & pt)
//{
//
//	WinData::getInstance().setWinMode(WheelEnum::ALL_ANIMAL);
//}
//void Js::deal_Double(boost::property_tree::ptree & pt)
//{
//
//	WinData::getInstance().setWinMode(WheelEnum::DOUBLE);
//}
//void Js::deal_Treble(boost::property_tree::ptree & pt)
//{
//
//	WinData::getInstance().setWinMode(WheelEnum::TREBLE);
//}
//void Js::deal_Many(boost::property_tree::ptree & pt)
//{
//
//	WinData::getInstance().setWinMode(WheelEnum::MANY);
//}
//



void Js::setTime(int time)
{
	std::cout<<"??"<<time<<std::endl;
	_setTime(time);
}
//
boost::signals2::connection Js::subscribeSetTime(const JsInterface::SetTimeSignalType::slot_type &subscriber)
{
	return _setTime.connect(subscriber);
}




void Js::askPanelData(void)
{
	_askPanelData();
}

boost::signals2::connection Js::subscribeAskPanelData(const JsInterface::AskPanelDataSignalType::slot_type &subscriber)
{
	return _askPanelData.connect(subscriber);
}
boost::signals2::connection Js::subscribeStartGame(const JsInterface::StartGameSignalType::slot_type &subscriber)
{
	return _startGame.connect(subscriber);
}

void Js::postPanelData(JsInterface::ButtonId id, size_t num)
{
	std::cout<<"()"<<id<<std::endl;		
	_postPanelDataSignal(id, num);
}
boost::signals2::connection Js::subscribePostPanelData(const GameInterface<0>::PostPanelDataSignalType::slot_type &subscriber)
{
	std::cout<<"================"<<std::endl;
	return _postPanelDataSignal.connect(subscriber);
}





void Js::addProfit(int profit)
{
	_addProfit(profit);
}
boost::signals2::connection Js::subscribeAddProfit(const JsInterface::AddProfitSignalType::slot_type &subscriber)
{
	return _addProfit.connect(subscriber);
}

void Js::setProfit(int profit)
{
	_setProfit(profit);
}
boost::signals2::connection Js::subscribeSetProfit(const JsInterface::SetProfitSignalType::slot_type &subscriber)
{
	return _addProfit.connect(subscriber);
}

void Js::rollProfit(void)
{
	_rollProfit();
}
boost::signals2::connection Js::subscribeRollProfit(const JsInterface::RollProfitSignalType::slot_type &subscriber)
{
	return _rollProfit.connect(subscriber);
}

//
void Js::setWinData(const std::string & data)
{
	
	
	using boost::property_tree::ptree;
	using namespace std;
	/*
	WinData::getInstance().setWinMode(WheelEnum::NONE);
	WinData::getInstance().setWinner(WheelEnum::Player);
	WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::TYPE(animal), WheelEnum::LightColor(color)), 20);*/
	if(WinData::getInstance().waitFor())
	{
		
		WinData::getInstance().clear();
		stringstream ss(data);
		ptree pt;
		
		read_json(ss, pt);
	/*	BOOST_FOREACH(boost::property_tree::ptree::value_type & v, pt)
		{
			std::cout<<v.first<<std::endl;
		}*/
		
		int type = pt.get<int>("type", 1);
		WheelEnum::Winner winner = getWinner(pt.get<std::string>("winner", "B"));
		WinData::getInstance().setWinner(winner);
		switch(type)
		{
		case None:
			WinData::getInstance().setWinMode(WheelEnum::NONE);
			break;
		case Color:
			WinData::getInstance().setWinMode(WheelEnum::ALL_COLOR);
			break;
		case Animal:
			WinData::getInstance().setWinMode(WheelEnum::ALL_ANIMAL);
			break;
		case Double:
			WinData::getInstance().setWinMode(WheelEnum::DOUBLE);
			break;
		case Treble:
			WinData::getInstance().setWinMode(WheelEnum::TREBLE);
			break;
		case Many:
			WinData::getInstance().setWinMode(WheelEnum::MANY);
			break;
		}

		BOOST_FOREACH(const ptree::value_type &v, pt.get_child("item"))
		{
			int rate = pt.get_child("item").get<int>(v.first);
			if(type == Double)
				rate /= 2;
			else if(type == Treble)
				rate /= 3;
			WinData::getInstance().push_back(getItem(v.first), rate);
		}
     
			
		WinData::getInstance().waitFor(false);
	}
}


void Js::startGame(void)
{
	_startGame();
}

void Js::setWinner(JsInterface::ButtonId id, int profit)
{
	_setWinner(id, profit);
}
boost::signals2::connection Js::subscribeSetWinner(const JsInterface::SetWinnerSignalType::slot_type &subscriber)
{
	return _setWinner.connect(subscriber);
}



void Js::setState(JsInterface::State state)
{
	_setState(state);
}
boost::signals2::connection Js::subscribeSetState(const JsInterface::SetStateSignalType::slot_type &subscriber)
{
	return _setState.connect(subscriber);
}



