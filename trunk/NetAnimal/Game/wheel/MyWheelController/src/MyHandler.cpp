#include "MyWheelControllerStableHeaders.h"
#include "MyHandler.h"
#include "MyHardwareCode.h"
using namespace Orz;

MyHandler::MyHandler(void):_state(READ),_oldButtonState(0xffff),_buttonState(0xffff),_isEmpty(true)
{

}
MyHandler::~MyHandler(void)
{

}
void MyHandler::push(unsigned char data)
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




bool MyHandler::empty(void)
{
	return _isEmpty;
}
HardwareMsg MyHandler::pop(void)
{

	_isEmpty = true;
	return _msg;
}
