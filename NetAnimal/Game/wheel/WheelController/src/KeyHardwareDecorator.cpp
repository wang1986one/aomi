#include "WheelControllerStableHeaders.h"
#include "KeyEngineDecorator.h"
#include "MsgHandler.h"
#include "WheelEnum.h"


using namespace Orz;

void KeyEngineDecorator::addListener(WheelEngineListener * listener)
{
	_engine->addListener(listener);
}
void KeyEngineDecorator::removeListener(WheelEngineListener * listener)
{
	_engine->removeListener(listener);

}
KeyEngineDecorator::KeyEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine)
{
	Orz::IInputManager::getSingleton().addKeyListener(this);
}
KeyEngineDecorator::~KeyEngineDecorator(void)
{
	Orz::IInputManager::getSingleton().removeKeyListener(this);
}

void KeyEngineDecorator::pushMessage(MsgBuffer & buffer)
{
	if(_engine)
		_engine->pushMessage(buffer);
}

void KeyEngineDecorator::refreshMenuData(void)
{
	if(_engine)
		_engine->refreshMenuData();
}
MsgBuffer GetTestData(int i)
{


	MsgBuffer buf;
	//buf.push_back(0);
	//buf.push_back(i+1);
	//buf.push_back(5);

	unsigned char m;

	i ==8 ? m =1:m = 8;

	buf,0,i+1,WheelEngineInterface::DATA_MENU,
		0,0,0,0,
		m,m,m,m,
		m,m,m,m,
		m,m,m,m,
		m,m,m,m,
		m,m,m,m,
		m,m,m,m,
		m,m,m,m,
		m,m,m,m;



	return buf;

}
unsigned char getWinMode(void)
{

	static unsigned char win[14] ={


		


		WheelEnum::ALL_MONKEY,
		WheelEnum::ALL_GREEN,
		WheelEnum::RED_RABBIT_YELLOW_PANDA,//1
		WheelEnum::YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION,//3

		WheelEnum::G_YELLOW_RABBIT,//lm
		WheelEnum::G_GREEN_MONKEY,

		WheelEnum::G_RED_PANDA,
		WheelEnum::G_GREEN_LION,
		WheelEnum::DOUBLE_GREEN_RABBIT,
		WheelEnum::TREBLE_YELLOW_MONKEY,
	
		WheelEnum::ALL_PANDA,
		WheelEnum::YELLOW_RABBIT ,//lm

		WheelEnum::ALL_LION,
		WheelEnum::GREEN_MONKEY,//hb
	};
	static unsigned char winmode = 0;
	winmode = winmode%14;
	return win[winmode++];
}
///通知键盘按下事件
bool KeyEngineDecorator::onKeyPressed(const KeyEvent & arg)
{
	MsgHandler handler;
	Orz::MsgBuffer head;
	Orz::MsgBuffer msg;


	switch(arg.getKey())
	{
	case Orz::KC_A:  
		{
			head,0,0,ASK_TIME;
		}
		break;

	case Orz::KC_B:  
		{
			head,0,0,HOW_WINNER;
			msg,2,getWinMode(),123,10;
		}
		break;
	case Orz::KC_1:  
		{
			head,0,0,HOW_WINNER;
			msg,2,WheelEnum::DOUBLE_GREEN_RABBIT, 123,10;
		}
		break;
	case Orz::KC_2:  
		{
			head,0,0,HOW_WINNER;
			msg,2,WheelEnum::G_RED_PANDA, 123,10;
		}
		break;

	case Orz::KC_3:  
		{
			head,0,0,HOW_WINNER;
			msg,2,WheelEnum::YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION, 123,10;
		}
		break;
	case Orz::KC_4:  
		{
			head,0,0,HOW_WINNER;
			msg,2,WheelEnum::ALL_GREEN, 123,10;
		}
		break;

	case Orz::KC_5:  
		{
			head,0,0,HOW_WINNER;
			msg,2,WheelEnum::ALL_MONKEY, 123,10;
		}
		break;


	case Orz::KC_C:  
		{
			head,0,0,ASK_STATE;
		}
		break;
	case Orz::KC_P:  
		{
			head,0,0,RESET_GAME;
		}
		break;

	case Orz::KC_E:  
		{
			head,0,0,COME_IN_MENU;
		}
		break;
	case Orz::KC_F:  
		{
			pushMessage(GetTestData(0));
			pushMessage(GetTestData(1));
			pushMessage(GetTestData(2));
			pushMessage(GetTestData(3));
			pushMessage(GetTestData(4));
			pushMessage(GetTestData(5));
			pushMessage(GetTestData(6));
			pushMessage(GetTestData(7));
			pushMessage(GetTestData(8));

			head,0,0,REPORT;
			msg,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2;
		}
		break;
	case Orz::KC_G:  
		{
			head,0,0,GO_OUT_MENU;
		}
		break;

	case Orz::KC_7:  
		{
			head,0,0,SET_MODE;
			msg,1,14;
		}
		break;

	case Orz::KC_8:  
		{
			head,0,0,HARDWARE_RETURN1;
			msg,0;
		}
		break;

	case Orz::KC_9:  
		{
			head,0,0,HARDWARE_RETURN1;
			msg,1;
		}
		break;

	case Orz::KC_R:  
		{
			head,0,0,COME_IN_SETUP;
			msg,0,1,2,3,4,5,6,7,8;
		}
		break;
	default:
		return false;
	}

	Orz::MsgBuffer out = handler.encode(head, msg);
	for(size_t i=0; i< out.size(); ++i)
	{
		handler.push(out.at(i));
	}
	if(!handler.empty())
	{
		Orz::MsgBuffer buffer = handler.pop();

		pushMessage(buffer);
	}
	return true;
}
///通知键盘释放事件
bool KeyEngineDecorator::onKeyReleased(const KeyEvent & evt)
{
	return false;
}