
#ifndef __Orz_Banker__
#define __Orz_Banker__
#include <WheelGobal/WheelEnum.h>
#include "UIAnimation.h"
namespace Orz
{

	namespace UI
	{
	class Banker
	{
	public:
		Banker(void):_isPlay(false),_time(0.0f),_isOK(false)
		{
			_animation.setWindow(CEGUI::WindowManager::getSingleton().getWindow("GUI/text"));
			_animation.push_back("set:sample2 image:banker00", 0.02f);
			_animation.push_back("set:sample2 image:banker01", 0.02f);
			_animation.push_back("set:sample2 image:banker02", 0.02f);
			_animation.push_back("set:sample2 image:banker03", 0.02f);
			_animation.push_back("set:sample2 image:banker04", 0.02f);
			_animation.push_back("set:sample2 image:banker05", 0.02f);
			_animation.push_back("set:sample2 image:banker06", 0.02f);
			_animation.push_back("set:sample2 image:banker07", 0.02f);
			_animation.push_back("set:sample2 image:banker08", 0.02f);
			_animation.push_back("set:sample2 image:banker09", 0.02f);
			_animation.push_back("set:sample2 image:banker10", 0.02f);
			_animation.push_back("set:sample2 image:banker11", 0.02f);
			_animation.push_back("set:sample2 image:banker12", 0.02f);
			_animation.push_back("set:sample2 image:banker13", 0.02f);
			_animation.push_back("set:sample2 image:banker14", 0.02f);
			_animation.push_back("set:sample2 image:banker15", 0.02f);
			_animation.push_back("set:sample2 image:banker16", 0.02f);
			_animation.push_back("set:sample2 image:banker17", 0.02f);
			_animation.push_back("set:sample2 image:banker18", 0.02f);
			_animation.push_back("set:sample2 image:banker19", 0.02f);
			_animation.push_back("set:sample2 image:banker20", 0.02f);
			_animation.push_back("set:sample2 image:banker21", 0.02f);
			_animation.push_back("set:sample2 image:banker22", 0.02f);
			_animation.push_back("set:sample2 image:banker23", 0.02f);
			//_win = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Outlineborder");
			
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
						_animation.setPic("set:sample2 image:banker00");
						Orz::ISoundManager::getSingleton().quickPlay("zhuang.wav");
						break;
					case WheelEnum::Player:
						_animation.setPic("set:sample2 image:banker08");
						Orz::ISoundManager::getSingleton().quickPlay("xian.wav");
						break;
					case WheelEnum::Draw:
						_animation.setPic("set:sample2 image:banker16");
						Orz::ISoundManager::getSingleton().quickPlay("he.wav");
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
		/*void show(void)
		{
			_win->setVisible(true);
		}
		void hide(void)
		{
			_win->setVisible(false);
		}*/
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
		//CEGUI::Window * _win;

	
		WheelEnum::WINNER _banker;
	};

	}
}


#endif