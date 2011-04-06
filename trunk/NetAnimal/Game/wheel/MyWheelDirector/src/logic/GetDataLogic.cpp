
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
	
	getOwner()->addBottomToUI();
	//game->setWinner(false);
}


void GetDataLogic::postData(JsInterface::ButtonId, int profit)
{
	
}
GetDataLogic::GetDataLogic(my_context ctx):LogicAdv(ctx),_over(false)
{
	GameInterface<0> * game = getOwner()->getJs()->queryInterface<GameInterface<0> >();
	game->askPanelData();
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