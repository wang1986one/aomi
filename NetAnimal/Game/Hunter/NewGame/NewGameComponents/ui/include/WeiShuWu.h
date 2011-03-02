#ifndef __Orz_WeiShuWu__
#define __Orz_WeiShuWu__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include "NewGameComponentsStableHeaders.h"	
#include <WheelGobal/WheelEnum.h>
namespace Orz
{
	namespace UI
	{
		const size_t WeiShuWuRunTime = 4;
		class WeiShuWu
		{
			enum Country
			{
				WEI = 0,
				SHU = 1,
				WU = 2 
			};
		public:
			WeiShuWu(void):_allTime(0.f),_country(SHU),_isRunning(false),_winerCountry(SHU)
			{
				setCountry(_country);
			}
			~WeiShuWu(void)
			{

			}
			void update(TimeType i)
			{
				if(!_isRunning)
					return;
				_allTime += i*10;
				Country what = static_cast<Country>(int(_allTime)%3);
				if(_country != what)
				{
					_country = what;
					setCountry(_country);
				}
				if(_allTime/10 >= WeiShuWuRunTime)
				{
					setCountry(_winerCountry);
					_isRunning =false;
					_allTime = 0.f;
				}

			}
			void setCountry(Country country)
			{
				CEGUI::WindowManager::getSingleton().getWindow("main/kuang/wei")->hide();
				CEGUI::WindowManager::getSingleton().getWindow("main/kuang/shu")->hide();
				CEGUI::WindowManager::getSingleton().getWindow("main/kuang/wu")->hide();
				switch(country)
				{
				case WEI:
					CEGUI::WindowManager::getSingleton().getWindow("main/kuang/wei")->show();
					break;

				case SHU:
					CEGUI::WindowManager::getSingleton().getWindow("main/kuang/shu")->show();
					break;

				case WU:
					CEGUI::WindowManager::getSingleton().getWindow("main/kuang/wu")->show();
					break;
				}

			}
			void reset(void)
			{
				_allTime = 0.f;
			}
			void run(WheelEnum::WINNER winner)
			{
				switch(winner)
				{
				case WheelEnum::Dealer:
					_winerCountry = SHU;
					break;

				case WheelEnum::Player:
					_winerCountry = WEI;
					break;

				case WheelEnum::Draw:
					_winerCountry = WU;
					break;
				}
				_isRunning = true;
			}
		private:
			TimeType _allTime;
			Country _country;
			bool _isRunning;
			Country _winerCountry;

		};
	}
}


#endif