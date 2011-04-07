
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"

#include "GameInterface.h"
using namespace Orz;
void GetDataLogic::exit(void)
{

	_connection.disconnect();

	int num = getOwner()->addAndGetNum();

	WinData::getInstance().setBonus(rand()%1000 +1000);
	WinData::getInstance().setWinner(WheelEnum::Winner(rand()%3));
	WinData::getInstance().clear();
	switch(num%11)
	{
	case 0:
		WinData::getInstance().setWinMode(WheelEnum::NONE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow), 4);
		break;
	case 1:
		WinData::getInstance().setWinMode(WheelEnum::NONE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red), 13);
		break;
	case 2:
		WinData::getInstance().setWinMode(WheelEnum::NONE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green), 20);
		break;
	case 3:
		WinData::getInstance().setWinMode(WheelEnum::NONE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow), 25);
		break;

	case 4:
		WinData::getInstance().setWinMode(WheelEnum::ALL_ANIMAL);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow), 25);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green), 40);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red), 46);
		break;
	case 5:
		WinData::getInstance().setWinMode(WheelEnum::ALL_COLOR);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow), 4);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow), 40);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow), 7);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow), 12);
		break;
	case 6:
		WinData::getInstance().setWinMode(WheelEnum::DOUBLE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow), 4);
		break;
	case 7:
		WinData::getInstance().setWinMode(WheelEnum::TREBLE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red), 13);
		break;
	case 8:
		WinData::getInstance().setWinMode(WheelEnum::DOUBLE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green), 20);
		break;
	case 9:
		WinData::getInstance().setWinMode(WheelEnum::TREBLE);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow), 25);
		break;


	case 10:
		WinData::getInstance().setWinMode(WheelEnum::MANY);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green), 40);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow), 7);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red), 46);
		WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow), 12);
		break;


	}
	WinData::getInstance().getWinner();
	getOwner()->addBottomToUI();

	send2Js();
}


void GetDataLogic::send2Js(void)
{
	sendWinner();
	sendAnimal();
}

void GetDataLogic::sendAnimal(void)
{
	
	GameInterface<0> * game = getOwner()->getJs()->queryInterface<GameInterface<0> >();

	for(size_t i=0; i < WinData::getInstance().size(); ++i)
	{
		WheelEnum::AnimalItem item = WinData::getInstance().getAnimalItem(i);
		
		JsInterface::ButtonId id = JsInterface::ButtonRedRabbit;
		switch(item.first)
		{
		case WheelEnum::RABBIT:
			switch(item.second)
			{
			case WheelEnum::Red:
				id = JsInterface::ButtonRedRabbit;
				break;
			case WheelEnum::Yellow:
				id = JsInterface::ButtonYellowRabbit;
				break;
			case WheelEnum::Green:
				id = JsInterface::ButtonGreenRabbit;
				break;
			}
			break;

		case WheelEnum::MONKEY:
			switch(item.second)
			{
			case WheelEnum::Red:
				id = JsInterface::ButtonRedMonkey;
				break;
			case WheelEnum::Yellow:
				id = JsInterface::ButtonYellowMonkey;
				break;
			case WheelEnum::Green:
				id = JsInterface::ButtonGreenMonkey;
				break;
			}
			break;
		case WheelEnum::PANDA:
			switch(item.second)
			{
			case WheelEnum::Red:
				id = JsInterface::ButtonRedPanda;
				break;
			case WheelEnum::Yellow:
				id = JsInterface::ButtonYellowPanda;
				break;
			case WheelEnum::Green:
				id = JsInterface::ButtonGreenPanda;
				break;
			}
			break;
		case WheelEnum::LION:
			switch(item.second)
			{
			case WheelEnum::Red:
				id = JsInterface::ButtonRedLoin;
				break;
			case WheelEnum::Yellow:
				id = JsInterface::ButtonYellowLoin;
				break;
			case WheelEnum::Green:
				id = JsInterface::ButtonGreenLoin;
				break;
			}
			break;
		}
		game->setWinner(id, getProfit(id) * WinData::getInstance().getRate(i));
	}
	
}
void GetDataLogic::sendWinner(void)
{	

	GameInterface<0> * game = getOwner()->getJs()->queryInterface<GameInterface<0> >();
	switch(WinData::getInstance().getWinner())
	{
	case WheelEnum::Dealer:
		{
			game->setWinner(JsInterface::ButtonZhuang, getProfit(JsInterface::ButtonZhuang) * 2);
		}
		break;
	case WheelEnum::Player:
		{
			game->setWinner(JsInterface::ButtonXian, getProfit(JsInterface::ButtonXian) * 2);
		}
		break;
	case WheelEnum::Draw:
		{
			game->setWinner(JsInterface::ButtonHe, getProfit(JsInterface::ButtonHe) *8 + getProfit(JsInterface::ButtonZhuang) + getProfit(JsInterface::ButtonXian) );
		}
		break;
	}
}


int GetDataLogic::getProfit(JsInterface::ButtonId id)
{
	Map::iterator it = _buttons.find(id);
	if(it == _buttons.end())
		return 0;
	return it->second;
}
void GetDataLogic::postData(JsInterface::ButtonId id, int profit)
{
	_buttons[id] = profit;
}
GetDataLogic::GetDataLogic(my_context ctx):LogicAdv(ctx),_over(false)
{
	GameInterface<0> * game = getOwner()->getJs()->queryInterface<GameInterface<0> >();
	game->askPanelData();
	game->subscribePostPanelData(boost::bind(&GetDataLogic::postData, this, _1, _2));
	_over = true;

}
GetDataLogic::~GetDataLogic(void)
{



}

sc::result GetDataLogic::react(const UpdateEvt & evt)
{
	if(_over)
		return transit<GameRunLogic>();	
	return forward_event();

}