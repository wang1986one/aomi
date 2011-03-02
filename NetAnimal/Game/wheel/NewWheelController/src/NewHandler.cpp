#include "NewWheelControllerStableHeaders.h"
#include "NewHandler.h"
#include "NewHardwareCode.h"
using namespace Orz;

NewHandler::NewHandler(void):_state(SLEEP),_isEasy(false),_num(0)//,_isEmpty(true)
{

}
NewHandler::~NewHandler(void)
{

}
void NewHandler::push(unsigned char data)
{
	

	if(_state == SLEEP)
	{
		if(data == 0)
			return;
		if(data == WheelEnum::HW_FIND_PC)
		{
			_isEasy = true;
			
		}else
		{
			_isEasy = false;
		}
		_num = 0;
		_msgs.at(_num)= data;
		_num++;
		_state = READ;
	}
	else if(_state == READ)
	{
		_msgs.at(_num)= data;
		_num++;
		if(
			((_num >= 2) && _isEasy)
			||((_num >= 40) && !_isEasy)
			
			)
		{


			//NewHardwareCode code;
			//NewHardwareCode::getSingleton().decode(_msgs, _msg);
			NewHardwareCode::getSingleton().push_decode(_msgs);
			//_isEmpty =false;
			_state = SLEEP;
		}
		
	}
}
//bool NewHandler::empty(void)
//{
//	return _isEmpty;
//}
//HardwareMsg NewHandler::pop(void)
//{
//
//	_isEmpty = true;
//	return _msg;
//}
