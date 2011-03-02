#ifndef __Orz_Banker__
#define __Orz_Banker__
#include <boost/multi_array.hpp>
#include <iostream>
#include <CEGUI/cegui.h>
#include "WheelEnum.h"
#include "UIAnimation.h"
namespace Orz
{
	class Banker
	{
	public:
		Banker(void):_isPlay(false),_time(0.0f),_isOK(false)
		{
			_animation.setWindow(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Outlineborder/Banker"));
			_animation.push_back("set:AnimalUIEX image:Banker00", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker01", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker02", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker03", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker04", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker05", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker06", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker07", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker08", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker09", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker10", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker11", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker12", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker13", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker14", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker15", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker16", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker17", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker18", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker19", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker20", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker21", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker22", 0.02f);
			_animation.push_back("set:AnimalUIEX image:Banker23", 0.02f);
			_win = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Outlineborder");
			
		}
		~Banker(void)
		{
			
		}

		void update(TimeType i)
		{
			if(_isPlay)
			{
				if(_time<=0)
				{
					_isPlay = false;
					_time = 0.f;
					_isOK = true;

					switch(_banker)
					{
					case WheelEnum::Dealer:
						ISoundManager::getSingleton().quickPlay("zhuang.wav");
						_animation.setPic("set:AnimalUIEX image:Banker00");
						break;
					case WheelEnum::Player:
						ISoundManager::getSingleton().quickPlay("xian.wav");
						_animation.setPic("set:AnimalUIEX image:Banker08");
						break;
					case WheelEnum::Draw:
						ISoundManager::getSingleton().quickPlay("he.wav");
						_animation.setPic("set:AnimalUIEX image:Banker16");
						break;
						
					}
					
				}
				_time -= i;
				_animation.update(i,_isOK);
				
			}
		}
		void reset(void)
		{	
			_animation.reset();
			_isPlay = false;
			_isOK = false;
		}
		void show(void)
		{
			_win->setVisible(true);
		}
		void hide(void)
		{
			_win->setVisible(false);
		}
		void play(WheelEnum::WINNER banker)
		{

			switch(banker)
			{
			case WheelEnum::Dealer:
				_time = 7.2f;
				break;
			case WheelEnum::Player:
				_time = 0.16f +7.2f;
				break;
			case WheelEnum::Draw:
				_time = 0.32f+7.2f;
				break;
				
			}
			reset();
			_banker = banker;
			_isPlay =true;
		}

		//获取庄闲和是否已经旋转完成
		bool getIsOK()
		{
			return _isOK;
		}

	private:
		UIAnimation _animation;
		bool _isPlay;
		bool _isOK;			//庄闲和是否已经旋转完成
		TimeType _time;
		CEGUI::Window * _win;

	
		WheelEnum::WINNER _banker;
	};
}


#endif