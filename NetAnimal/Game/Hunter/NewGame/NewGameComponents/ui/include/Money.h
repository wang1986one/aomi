#ifndef __Orz_Money__
#define __Orz_Money__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include "NewGameComponentsStableHeaders.h"	
#include <WheelGobal/WheelEnum.h>
#include "Number.h"
namespace Orz
{
	namespace UI
	{
		class Money
		{


		private:

			TimeType _time;;
			Number _number;
			int _bonus;
		public:
			Money(void):_time(0.f),_bonus(0)
			{


				_number.setFigure(0, "set:sample2 image:number0");
				_number.setFigure(1, "set:sample2 image:number1");
				_number.setFigure(2, "set:sample2 image:number2");
				_number.setFigure(3, "set:sample2 image:number3");
				_number.setFigure(4, "set:sample2 image:number4");
				_number.setFigure(5, "set:sample2 image:number5");
				_number.setFigure(6, "set:sample2 image:number6");
				_number.setFigure(7, "set:sample2 image:number7");
				_number.setFigure(8, "set:sample2 image:number8");
				_number.setFigure(9, "set:sample2 image:number9");

				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("GUI/bonus5"));
				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("GUI/bonus4"));
				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("GUI/bonus3"));
				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("GUI/bonus2"));
				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("GUI/bonus1"));
			}

			void setBonus(int bonus)
			{
				_bonus = bonus;
			}

			void clear(void)
			{
				_bonus = 0;
			}

			void update(TimeType i)
			{
				_time+=i;
				while(_time > 0.2f)
				{
					_time-=0.2f;
					if(_bonus == 0)
						_number.show(rand()%20000);
					else
						_number.show(_bonus);
				}
			}
			~Money(void)
			{

			}
		};
	}
}


#endif