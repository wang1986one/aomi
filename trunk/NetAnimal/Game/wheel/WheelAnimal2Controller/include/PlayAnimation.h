#ifndef __Orz_Tutorial_PlayWinner_h__
#define __Orz_Tutorial_PlayWinner_h__
#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalSceneObj.h"
#include "WheelAnimalProcess.h"
#include "WinEffect.h"
#include "WinData.h"
#include "WheelData.h"

namespace Orz
{







	class PlayAnimation: public WheelAnimalProcess,public UpdateToEnable<PlayAnimation>
	{
	public:


		PlayAnimation(boost::shared_ptr<WheelAnimalSceneObj> scene,  WinEffectPtr effect , int winner):_scene(scene),_effect(effect)/*, WinData::getSingleton()(WinData::getSingleton())*/,_winner(winner) ,_time(0.f)
		{

			int ov =  WinData::getInstance().getRate(0);//WheelData::getInstance().getOverride(WinData::getInstance().getRate(), WinData::getInstance().getAnimalItem());//WheelEnum::getSingleton().getOverride(WinData::getInstance().getRate(), WinData::getInstance().getAnimalItem());


			if(WinData::getInstance().getWinMode() == WheelEnum::DOUBLE)
				ov *=2;
			else if(WinData::getInstance().getWinMode() == WheelEnum::TREBLE)
				ov *=3;
			if(ov >= 10 && ov <25)
			{				
				_effect->show(WinEffect::Effect1);
			}else if(ov >= 25 && ov <30)
			{				
				_effect->show(WinEffect::Effect2);
			}else if(ov >= 30 && ov <45)
			{

				_effect->show(WinEffect::Effect3); 
			}else if(ov >= 45)
			{
				_effect->show(WinEffect::Effect4);
			}else 
			{
				_effect->show(WinEffect::None);
			}
		}
		virtual ~PlayAnimation(void)
		{
		}

		void clear(void)
		{
			_effect->clear();
		}
		void enable(void)
		{
			_effect->enable();
			_time = 0.f;
			_scene->getAnimal(_winner)->play(WheelEnum::ACTION3);
		}
		bool update(Orz::TimeType interval)
		{
			bool ret = _effect->update(interval);
			_update2enable();
			_time+= interval;
			if(_time >=3.0)
			{
				if(!ret)
					return false;
			}
			return true;
		}
	private:
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		int _winner;
		TimeType _time;
		WinEffectPtr _effect;
	//	 ;
	};



	class AnimalPlayAnimation: public WheelAnimalProcess, public UpdateToEnable<AnimalPlayAnimation>
	{
	public:


		AnimalPlayAnimation():_time(0.f)
		{
		}
		virtual ~AnimalPlayAnimation(void)
		{

		}
		void enable(void)
		{

			_time = 0.f;
		}
		bool update(Orz::TimeType interval)
		{
			_update2enable();
			_time+= interval;
			if(_time >=3.0)
				return false;
			return true;
		}
		void clear(void){}
	private:
		TimeType _time;
	};




}

#endif 