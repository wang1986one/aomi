
#ifndef __Orz_TVShow_h__
#define __Orz_TVShow_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"
#include "RotateAnimation.h"
#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
#include "WheelAnimalProcess.h"
#include "ProcessFactory.h"
#include "WinnerAnimation.h"
#include "WMHardwareInterface.h"
#include "TV.h"
namespace Orz
{


	class TVShowWinner: public WheelAnimalProcess, public UpdateToEnable<TVShowWinner>
	{
	public:


		TVShowWinner(  boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<TV> tv, int winner,
			boost::shared_ptr<RotateAnimation> needle, 
			boost::shared_ptr<RotateAnimation> rotate, ObjectLightsPtr objectLights);

		virtual ~TVShowWinner(void);

		virtual void enable(void);
		void clear();
		virtual bool update(TimeType interval = 0.015f);
		
	private:

		void up(int winner, WheelEnum::LIGHT_COLOR color);
		int needleRotate(AnimalEnum::ANIMAL_TYPE at, WheelEnum::LIGHT_COLOR color);

		boost::shared_ptr<WinnerAnimationNoMove> _winnerAnim;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		int _winner;
		WheelEnum::LIGHT_COLOR _color;
		boost::shared_ptr<RotateAnimation> _needle;
		boost::shared_ptr<RotateAnimation> _rotate;
		int _winNumber;
		int _all;
		ObjectLightsPtr _objectLights;
		std::vector<int> _clear; 
		boost::shared_ptr<TV>  _tv; 
		AnimalEnum::ANIMAL_ITEM _ai;
		ComponentPtr _hardwareComp;
		
		ScoreInterface::WinPrototypePtr _prototype;// _scoreComp;
		WMHardwareInterface * _hardware;

	};




////////////////////////////////////////////////////////////////////////////////

	class TVProRun: public WheelAnimalProcess
	{
	public:


		TVProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<TV> tv);
		virtual bool update(TimeType interval);
		virtual ~TVProRun(void);
		void clear(void);


	private:
		boost::shared_ptr<TV>  _tv;
		TimeType _time;
		
		SoundPlayerPtr _TVProRunMusic;
		bool _TVProRunIsEnd;
		bool _TVProRunIsPlaying;


	};


/////////////////////////////////////////////////////////////////////////////////////////////
	class TVGameRotate: public WheelAnimalProcess, public UpdateToEnable<TVGameRotate>
	{
	public:
		TVGameRotate(  boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<TV> tv,
			boost::shared_ptr<RotateAnimation> needle, 
			boost::shared_ptr<RotateAnimation> rotate, 
			float nAngle,
			float rAngle);
		virtual ~TVGameRotate(void);
		virtual void enable(void);
		virtual bool update(TimeType interval = 0.015f);
		virtual void clear(void);


	private:
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;
		boost::shared_ptr<TV> _tv;
		
		TimeType _downTime;
		float _isDown;
		Ogre::AnimationState * _as;
		bool _isContinue;
		SoundPlayerPtr _TVGameRotateMusic;

	};



////////////////////////////////////////////////////////////////
	class ProcessFactoryTV: public ProcessFactory
	{
	public:
		ProcessFactoryTV(
			 
			boost::shared_ptr<WheelAnimalSceneObj> scene,
			boost::shared_ptr<TV> tv,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			ObjectLightsPtr objLights
			);

		virtual ~ProcessFactoryTV(void)   ;
		Process0Ptr createProcess0(void);
		ProcessPtr createProcess1(void)	;
		ProcessPtr createProcess2(void)	 ;
		ProcessPtr createProcess3(void)	;
		ProcessPtr createProcess4(void);
	/*	ProcessPtr createProcess5(void);*/
	private:
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;		
		boost::shared_ptr<TV> _tv;
		/*
		WheelEnum::WinMode _mode;
		 WheelEnum::LIGHT_COLOR _color;*/
	};


////////////////////////////////////////////////////////////////////////////////

	class TVPlayAnimation: public WheelAnimalProcess, public UpdateToEnable<TVPlayAnimation>
	{
	public:


		TVPlayAnimation();
		virtual ~TVPlayAnimation(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};

///////////////////////////////////////////////////////////////////////
		
	class TVProcess5: public WheelAnimalProcess, public UpdateToEnable<TVProcess5>
	{
	public:


		TVProcess5();
		virtual ~TVProcess5(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};

}

#endif