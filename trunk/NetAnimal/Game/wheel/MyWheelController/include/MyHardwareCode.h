#ifndef __Orz_MyHardwareCode_h__
#define __Orz_MyHardwareCode_h__
#include "WheelControllerConfig.h"
#include "ThreadQueue.h"
namespace Orz
{


	namespace WheelEnum
	{

		enum HARDWARE
		{
			HW_BUTTON_UP = 0xa1,
			HW_BUTTON_DOWN = 0xa2

		};
	};
	struct HardwareMsg
	{
		WheelEnum::HARDWARE msg;
		int id;
		int data;
	};


}



#endif