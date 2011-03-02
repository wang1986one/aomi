#ifndef __Orz_WeiShuWu__
#define __Orz_WeiShuWu__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include <WheelGobal/WheelEnum.h>
namespace Orz
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
		//	void update(TimeType i)
		//	{
		//		if(_isPlay)
		//		{
		//			if(_time<=0)
		//			{
		//				_isPlay = false;
		//				_time = 0.f;
		//				_isOK = true;

		//				switch(_banker)
		//				{
		//				case WheelEnum::Dealer:
		//					_animation.setPic("set:sample2 image:banker00");
		//					break;
		//				case WheelEnum::Player:
		//					_animation.setPic("set:sample2 image:banker08");
		//					break;
		//				case WheelEnum::Draw:
		//					_animation.setPic("set:sample2 image:banker16");
		//					break;
		//					
		//				}
		//				
		//			}
		//			_time -= i;
		//			_animation.update(i,_isOK);
		//			
		//		}
		//	}
		//	void reset(void)
		//	{	
		//		_animation.reset();
		//		_isPlay = false;
		//		_isOK = false;
		//	}
		//	void show(void)
		//	{
		//		_win->setVisible(true);
		//	}
		//	void hide(void)
		//	{
		//		_win->setVisible(false);
		//	}
		//	void play(WheelEnum::WINNER banker)
		//	{

		//		switch(banker)
		//		{
		//		case WheelEnum::Dealer:
		//			_time = 7.2f;
		//			break;
		//		case WheelEnum::Player:
		//			_time = 0.16f +7.2f;
		//			break;
		//		case WheelEnum::Draw:
		//			_time = 0.32f+7.2f;
		//			break;
		//			
		//		}
		//		reset();
		//		_banker = banker;
		//		_isPlay =true;
		//	}

		//	//获取庄闲和是否已经旋转完成
		//	bool getIsOK()
		//	{
		//		return _isOK;
		//	}

		//private:
		//	UIAnimation _animation;
		//	bool _isPlay;
		//	bool _isOK;			//庄闲和是否已经旋转完成
		//	TimeType _time;
		//	CEGUI::Window * _win;

		//
		//	WheelEnum::WINNER _banker;
	};
}


#endif