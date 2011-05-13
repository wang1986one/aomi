#include "NetWheelControllerStableHeaders.h"
#include "NetHandler.h"
#include "NetHardwareCode.h"
using namespace Orz;

NetHandler::NetHandler(void):_state(READ),_oldButtonState(0xffff),_buttonState(0xffff),_isEmpty(true)
{

}
NetHandler::~NetHandler(void)
{

}
void NetHandler::push(unsigned char data)
{
	if(_state == READ)
	{

		_state = FILL;
		_buttonState = data<<8; 

	}


	else if(_state == FILL)
	{

		_state = READ;
		_buttonState = data |_buttonState ;

		for(int i = 0; i<32; ++i)
		{

			int button = (_buttonState>>i) & 0x1;
			int oldButton = (_oldButtonState>>i) & 0x1;
			if( button != oldButton)
			{

				if(button)
				{
					_msg.msg = WheelEnum::HW_BUTTON_UP;
				}
				else 
				{
					_msg.msg = WheelEnum::HW_BUTTON_DOWN;
				}

				_msg.data = i;
				
				_isEmpty = false;
			}
		}
		_oldButtonState = _buttonState;
	}
	

	//	std::cout<< _buttonState<<std::endl;
}




bool NetHandler::empty(void)
{
	return _isEmpty;
}
HardwareMsg NetHandler::pop(void)
{

	_isEmpty = true;
	return _msg;
}
