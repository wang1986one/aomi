#ifndef __Orz_Time__
#define __Orz_Time__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include <WheelGobal/WheelEnum.h>
#include "ui/Number.h"
namespace Orz
{
	class Time
	{
		
	public:
		Time(void)
		{
			number.setFigure(0, "set:sanui1 image:num00");
			number.setFigure(1, "set:sanui1 image:num01");
			number.setFigure(2, "set:sanui1 image:num02");
			number.setFigure(3, "set:sanui1 image:num03");
			number.setFigure(4, "set:sanui1 image:num04");
			number.setFigure(5, "set:sanui1 image:num05");
			number.setFigure(6, "set:sanui1 image:num06");
			number.setFigure(7, "set:sanui1 image:num07");
			number.setFigure(8, "set:sanui1 image:num08");
			number.setFigure(9, "set:sanui1 image:num09");

			number.push_back(CEGUI::WindowManager::getSingleton().getWindow("main/time/one"));
			number.push_back(CEGUI::WindowManager::getSingleton().getWindow("main/time/ten"));
		}
		void show(int num)
		{
			number.show(num);
			
		}
		~Time(void)
		{

		}
		
	private:
		Number number;
	};
}


#endif