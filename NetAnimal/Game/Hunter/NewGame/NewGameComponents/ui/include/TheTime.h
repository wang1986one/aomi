#ifndef __Orz_Time__
#define __Orz_Time__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include "Number.h"

#include "UIAnimation.h"
namespace Orz
{
	namespace UI

	{
		class Time
		{

		private:
			Number number;

			UIAnimation _goOut;
			UIAnimation _comeIn;

			UIAnimation * _play;
		public:
			Time(void):_play(NULL)
			{

				_goOut.push_back(std::string("set:sample1 image:time01"), 0.04f);
				_goOut.push_back(std::string("set:sample1 image:time05"), 0.04f);
				_goOut.push_back(std::string("set:sample1 image:time09"), 0.03f);
				_goOut.push_back(std::string("set:sample1 image:time12"), 0.03f);
		
				_goOut.push_back(std::string("set:sample1 image:time15"), 0.02f);
				_goOut.push_back(std::string("set:sample1 image:time17"), 0.02f);
				_goOut.push_back(std::string("set:sample1 image:time19"), 0.02f);
				_goOut.push_back(std::string("set:sample1 image:time21"), 0.02f);
				_goOut.push_back(std::string("set:sample1 image:time23"), 0.01f);

				_goOut.setWindow(CEGUI::WindowManager::getSingleton().getWindow("GUI/right"));
				_comeIn.push_back(std::string("set:sample1 image:time23"), 0.01f);
				_comeIn.push_back(std::string("set:sample1 image:time21"), 0.02f);
				_comeIn.push_back(std::string("set:sample1 image:time19"), 0.02f);
				_comeIn.push_back(std::string("set:sample1 image:time17"), 0.02f);
				_comeIn.push_back(std::string("set:sample1 image:time15"), 0.02f);
				_comeIn.push_back(std::string("set:sample1 image:time12"), 0.03f);
				_comeIn.push_back(std::string("set:sample1 image:time09"), 0.03f);
				_comeIn.push_back(std::string("set:sample1 image:time05"), 0.04f);
				_comeIn.push_back(std::string("set:sample1 image:time01"), 0.04f);


				_comeIn.setWindow(CEGUI::WindowManager::getSingleton().getWindow("GUI/right"));
				CEGUI::WindowManager::getSingleton().getWindow("GUI/time1")->hide();
				CEGUI::WindowManager::getSingleton().getWindow("GUI/time2")->hide();


				number.setFigure(0, "set:sample2 image:number0");
				number.setFigure(1, "set:sample2 image:number1");
				number.setFigure(2, "set:sample2 image:number2");
				number.setFigure(3, "set:sample2 image:number3");
				number.setFigure(4, "set:sample2 image:number4");
				number.setFigure(5, "set:sample2 image:number5");
				number.setFigure(6, "set:sample2 image:number6");
				number.setFigure(7, "set:sample2 image:number7");
				number.setFigure(8, "set:sample2 image:number8");
				number.setFigure(9, "set:sample2 image:number9");

				number.push_back(CEGUI::WindowManager::getSingleton().getWindow("GUI/time2"));
				number.push_back(CEGUI::WindowManager::getSingleton().getWindow("GUI/time1"));
			}
			void show(int num)
			{
				number.show(num);

			}
			~Time(void)
			{

			}


			void update(TimeType i)
			{
				if(_play)
				{
					bool ret = _play->update(i);
					if(!ret)
					{
						if(_play ==  &_comeIn)
						{

							CEGUI::WindowManager::getSingleton().getWindow("GUI/time1")->show();
							CEGUI::WindowManager::getSingleton().getWindow("GUI/time2")->show();
						}

						_play = NULL;
					}
				}

			}



			void comeIn(void)
			{
				_play = &_comeIn;
				_play->reset();
			}


			void goOut(void)
			{
				_play = &_goOut;

				CEGUI::WindowManager::getSingleton().getWindow("GUI/time1")->hide();
				CEGUI::WindowManager::getSingleton().getWindow("GUI/time2")->hide();
				_play->reset();
			}
		};
	}
}


#endif