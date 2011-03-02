#ifndef __Orz_Money__
#define __Orz_Money__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include <WheelGobal/WheelEnum.h>
#include "ui/Number.h"
namespace Orz
{
	class Money
	{
		
	public:
		Money(void):_time(0.f)
		{

			_number.setFigure(0, "set:sanui1 image:num00");
			_number.setFigure(1, "set:sanui1 image:num01");
			_number.setFigure(2, "set:sanui1 image:num02");
			_number.setFigure(3, "set:sanui1 image:num03");
			_number.setFigure(4, "set:sanui1 image:num04");
			_number.setFigure(5, "set:sanui1 image:num05");
			_number.setFigure(6, "set:sanui1 image:num06");
			_number.setFigure(7, "set:sanui1 image:num07");
			_number.setFigure(8, "set:sanui1 image:num08");
			_number.setFigure(9, "set:sanui1 image:num09");

			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("main/shangyin/1"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("main/shangyin/2"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("main/shangyin/3"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("main/shangyin/4"));
		}
	
		void update(TimeType i)
		{
			_time+=i;
			while(_time > 0.2f)
			{
				_time-=0.2f;
				/*if(_bonus == 0)*/
				_number.show(rand());
			/*	else
					_number.show(_bonus);*/
			}
		}
		~Money(void)
		{

		}
		
	private:
		
		TimeType _time;;
		Number _number;
	};
}


#endif