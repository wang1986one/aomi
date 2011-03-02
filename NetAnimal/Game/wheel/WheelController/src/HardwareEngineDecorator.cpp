#include "WheelControllerStableHeaders.h"
#include "HardwareEngineDecorator.h"
#include "MsgHandler.h"
#include <orz/View_SingleChip/SingleChipManager.h>


using namespace Orz;

void HardwareEngineDecorator::addListener(WheelEngineListener * listener)
{
	_engine->addListener(listener);
}
void HardwareEngineDecorator::removeListener(WheelEngineListener * listener)
{
	_engine->removeListener(listener);

}
HardwareEngineDecorator::HardwareEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine)
{
	Orz::IInputManager::getSingleton().addKeyListener(this);
	//Orz::SingleChipManager::getSingleton().addListener(this);
}
HardwareEngineDecorator::~HardwareEngineDecorator(void)
{
	Orz::IInputManager::getSingleton().removeKeyListener(this);
	//Orz::SingleChipManager::getSingleton().removeListener(this);
}

void HardwareEngineDecorator::pushMessage(MsgBuffer & buffer)
{
	if(_engine)
		_engine->pushMessage(buffer);
}
void HardwareEngineDecorator::read(boost::circular_buffer<unsigned char> & data)
{
	boost::circular_buffer<unsigned char>::iterator it;
	for(it = data.begin(); it != data.end(); ++ it)
	{
		_handler.push(static_cast<unsigned char>(*it));
		while(!_handler.empty())
		{
			MsgBuffer buffer = _handler.pop();
				_engine->pushMessage(buffer);

		}
	}
}
void HardwareEngineDecorator::refreshMenuData(void)
{
	if(_engine)
		_engine->refreshMenuData();
}
///通知键盘按下事件
bool HardwareEngineDecorator::onKeyPressed(const KeyEvent & arg)
{

	return true;
}
///通知键盘释放事件
bool HardwareEngineDecorator::onKeyReleased(const KeyEvent & arg)
{

	MsgHandler handler;
	Orz::MsgBuffer head;
	Orz::MsgBuffer msg;

	switch(arg.getKey())
	{
	case Orz::KC_F4:  
		{
			head,0,0,KEY_F4;
		}
		break;

	case Orz::KC_F5:  
		{
			head,0,0,KEY_F5;
		}
		break;
	case Orz::KC_F6:  
		{
			head,0,0,KEY_F6;
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
	return false;
}


