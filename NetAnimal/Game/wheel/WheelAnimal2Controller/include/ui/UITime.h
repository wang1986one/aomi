#ifndef __Orz_Time__
#define __Orz_Time__
#include <boost/multi_array.hpp>
#include <iostream>
#include <CEGUI/cegui.h>
#include "UIAnimation2.h"
#include "Number.h"
namespace Orz
{
	class Time
	{
	public:
		Time(void):_play(NULL)
		{
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder00"), 0.1f);
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder01"), 0.1f);
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder02"), 0.1f);
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder03"), 0.1f);
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder04"), 0.1f);
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder05"), 0.1f);
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder06"), 0.1f);
			_goOut.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder07"), 0.1f);

			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder07"), 0.1f);
			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder06"), 0.1f);
			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder05"), 0.1f);
			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder04"), 0.1f);
			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder03"), 0.1f);
			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder02"), 0.1f);
			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder01"), 0.1f);
			_comeIn.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder00"), 0.1f);
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder")->hide();

			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder/num/right"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder/left"));
			_number.setNumber(0, "set:AnimalUIEX image:Timenum0");
			_number.setNumber(1, "set:AnimalUIEX image:Timenum1");
			_number.setNumber(2, "set:AnimalUIEX image:Timenum2");
			_number.setNumber(3, "set:AnimalUIEX image:Timenum3");
			_number.setNumber(4, "set:AnimalUIEX image:Timenum4");
			_number.setNumber(5, "set:AnimalUIEX image:Timenum5");
			_number.setNumber(6, "set:AnimalUIEX image:Timenum6");
			_number.setNumber(7, "set:AnimalUIEX image:Timenum7");
			_number.setNumber(8, "set:AnimalUIEX image:Timenum8");
			_number.setNumber(9, "set:AnimalUIEX image:Timenum9");

		
		}
		~Time(void)
		{

		}
		void show(int i)
		{
			if(i<=5 && i>=1)
				ISoundManager::getSingleton().quickPlay("Countdown.wav");
			_number.show(i);
		}
		void update(TimeType i)
		{
			if(_play)
			{
				bool ret = _play->update(i);
				if(!ret)
				{
					if(_play ==  &_comeIn)
						CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder")->show();
					
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
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Timeoutlineborder")->hide();
			_play->reset();
		}
	private:
		UIAnimation2 _goOut;
		UIAnimation2 _comeIn;
		UIAnimation2 * _play;
		Number _number;

	};
}


#endif