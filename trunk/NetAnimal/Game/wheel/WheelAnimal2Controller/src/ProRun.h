#ifndef __Orz_Tutorial_ProRun_h__
#define __Orz_Tutorial_ProRun_h__
#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalSceneObj.h"
#include "AnimalChange.h"
#include "WheelAnimalProcess.h"
namespace Orz
{
	


	
	
	class ProRun: public WheelAnimalProcess
	{
	public:

		
		ProRun(void):_time(0.f)
		{
			
			
		}
		virtual bool update(TimeType interval)
		{
		    _time += interval;
			if(_time > 1.0f)
				return false;
			return true;
		}
		virtual ~ProRun(void)
		{
			
		}	
		void clear(void)
		{
		
		}

	private:
		TimeType _time;
		
	};
	

	
	class AnimalProRun: public WheelAnimalProcess, public UpdateToEnable<AnimalProRun>
	{
	public:

		
		AnimalProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac):_time(0.f),_scene(scene),_ac(ac)
		{
			_as= scene->getSceneAnimation(SCENE_ANIMATION_0);
	
			_as->setEnabled(true);
			_as->setLoop(false);

		
		}
		void enable(void)
		{
			_scene->clearLight();
			_scene->addLight(WheelEnum::Red);
			_scene->addLight(WheelEnum::Green);
			_scene->addLight(WheelEnum::Yellow);
			_scene->addLight(WheelEnum::Blue);
			_scene->addLight(WheelEnum::DeepBlue);
		}
		virtual bool update(TimeType interval)
		{
			_update2enable();
			_as->addTime(interval);
			bool ret = _ac->getRise(30.0f)->update(interval);
			if(!_as->hasEnded() || ret)
				return true;
			return false;
		}
		virtual ~AnimalProRun(void)
		{
		  
		}
		void clear(void)
		{
			
			_scene->clearLight();
			_as->setEnabled(false);
		}
	private:
		TimeType _time;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		Ogre::AnimationState * _as;

		boost::shared_ptr<AnimalChange> _ac; 
		
	};
	

	//class AnimalProRun: public WheelAnimalProcess, public UpdateToEnable<AnimalProRun>
	//{
	//public:

	//	
	//	AnimalProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac):_time(0.f),_scene(scene),_ac(ac)
	//	{
	//		_as= scene->getSceneAnimation(SCENE_ANIMATION_0);
	//
	//		_as->setEnabled(true);
	//		_as->setLoop(false);

	//	
	//	}
	//	void enable(void)
	//	{
	//		std::cout<<"*****************************  ProRun88         enable  *********************"<<std::endl;
	//		_scene->clearLight();
	//		_scene->addLight(WheelEnum::Red);
	//		_scene->addLight(WheelEnum::Green);
	//		_scene->addLight(WheelEnum::Yellow);
	//		_scene->addLight(WheelEnum::Blue);
	//		_scene->addLight(WheelEnum::DeepBlue);
	//	}
	//	virtual bool update(TimeType interval)
	//	{
	//		_update2enable();
	//		_as->addTime(interval);
	//		bool ret = _ac->getRise()->update(interval);
	//		if(!_as->hasEnded() || ret)
	//			return true;
	//		return false;
	//	}
	//	virtual ~AnimalProRun(void)
	//	{
	//	  
	//	}
	//	void clear(void)
	//	{
	//		
	//		_scene->clearLight();
	//		_as->setEnabled(false);
	//	}
	//private:
	//	TimeType _time;
	//	boost::shared_ptr<WheelAnimalSceneObj> _scene;
	//	Ogre::AnimationState * _as;

	//	boost::shared_ptr<AnimalChange> _ac; 
	//	
	//};



}

#endif 