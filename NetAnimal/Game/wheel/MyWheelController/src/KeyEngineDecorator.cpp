#include "MyWheelControllerStableHeaders.h"
#include "KeyEngineDecorator.h"
#include "WheelEnum.h"
#include "WheelEvents.h"
#include "WinData.h"
using namespace Orz;


KeyEngineDecorator::KeyEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine)
{
	Orz::IInputManager::getSingleton().addKeyListener(this);
}
KeyEngineDecorator::~KeyEngineDecorator(void)
{
	Orz::IInputManager::getSingleton().removeKeyListener(this);
}

bool KeyEngineDecorator::onKeyPressed(const KeyEvent & evt)
{

	
	switch(evt.getKey())
	{
	case Orz::KC_A:  
		{
			startGame(14);
		}
		break;

	case Orz::KC_B:  
		{
			WinData::getInstance().setWinMode(WheelEnum::NONE);
			WinData::getInstance().setBonus(1000);
			WinData::getInstance().setWinner(WheelEnum::Player);
			WinData::getInstance().clear();
			WinData::getInstance().push_back(WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Yellow), 20);

	

			runGame();
		}
		break;
	//
	//case Orz::KC_7:  
	//	{
	//		pushRate();
	//	}
	//	break;

	default:
		return false;
	}


	return false;
}
		
bool KeyEngineDecorator::onKeyReleased(const KeyEvent & evt)
{

	return true;
}



void KeyEngineDecorator::startGame(size_t time)
{
	_engine->startGame(time);
}
//void KeyEngineDecorator::pushRate(void)
//{
//	_engine->pushRate();
//}
void KeyEngineDecorator::runGame(void)
{
	_engine->runGame();
}

void KeyEngineDecorator::clickButton(int id, int button)
{
	_engine->clickButton(id, button);
}
TimeType KeyEngineDecorator::getTime(void) const
{
	return _engine->getTime();
}
