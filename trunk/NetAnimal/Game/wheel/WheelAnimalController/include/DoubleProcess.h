
#ifndef __Orz_DoubleProcess_h__
#define __Orz_DoubleProcess_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"

#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
#include "WheelAnimalProcess.h"
#include "WinnerAnimation.h"
#include "ColorChange.h"
//#include "WheelUI.h"
#include "ProcessFactory.h"

namespace Orz
{


	class DoubleProRun: public WheelAnimalProcess,  public UpdateToEnable<DoubleProRun>                                
	{
	public:
		DoubleProRun();
		void enable(void);
		virtual bool update(TimeType interval);
		virtual ~DoubleProRun(void);
		void clear(void);

	private:
		TimeType _time;
		 ;
		SoundPlayerPtr _DoubleProRunMusic;
		bool _DoubleProRunIsEnd;
		bool _DoubleProRunIsPlaying;

	};

	//////////////////////////////////////////////////////////////////////////////////////

	class DoubleShowWinner: public WheelAnimalProcess, public UpdateToEnable<DoubleShowWinner>
	{
	public:
		DoubleShowWinner(  boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & angle);
		void enable(void);
		virtual ~DoubleShowWinner(void);
		void clear();
		virtual bool update(TimeType interval/*********/);

	private:
		boost::shared_ptr<WinnerAnimation> _winnerAnim;

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		Ogre::SceneNode * _end; 
		Ogre::AnimationState * _animation;
		int _winner;
		 ;
		Ogre::AnimationState * _camAnimation;
	};


	/////////////////////////////////////////////////////////////////////////////////////

	class RotateAnimation;
	class DoubleGameRotate: public WheelAnimalProcess , public UpdateToEnable<DoubleGameRotate>
	{
	public:
		DoubleGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			int nAngle,
			int rAngle
			);
		virtual ~DoubleGameRotate(void);
		virtual void enable(void);
		virtual bool update(TimeType interval/*********/);
		void clear(void);
	private:

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;	 

		SoundPlayerPtr _DoubleGameRotateMusic;


	};


	/////////////////////////////////////////////////////////////////////////////////////////////

	class DoublePlayAnimation: public WheelAnimalProcess,public UpdateToEnable<DoublePlayAnimation>
	{
	public:


		DoublePlayAnimation(boost::shared_ptr<WheelAnimalSceneObj> scene,  WinEffectPtr effect , int winner);
		virtual ~DoublePlayAnimation(void);
		void clear(void);
		void enable(void);
		bool update(Orz::TimeType interval);

	private:
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		int _winner;
		TimeType _time;
		WinEffectPtr _effect;
		 ;
		SoundPlayerPtr _DoublePlayAnimationMusic;
	};

	////////////////////////////////////////////////////////////////////////////

	class DoubleProcess5: public WheelAnimalProcess, public UpdateToEnable<DoubleProcess5>
	{
	public:


		DoubleProcess5();
		virtual ~DoubleProcess5(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};
	//////////////////////////////////////////////////////////////////////////////////////////////
	class ProcessFactoryDouble:public ProcessFactory
	{

	public:
		ProcessFactoryDouble(
			 
			boost::shared_ptr<WheelAnimalSceneObj> scene,
			WinEffectPtr effect,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			ObjectLightsPtr objLights
			);
		virtual ~ProcessFactoryDouble(void);
		Process0Ptr createProcess0(void);
		ProcessPtr createProcess1(void)	;
		ProcessPtr createProcess2(void)	;
		ProcessPtr createProcess3(void);
		ProcessPtr createProcess4(void);
	/*	ProcessPtr createProcess5(void);*/
	private:
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;		
		boost::shared_ptr<AnimalChange> _ac;  

		WinEffectPtr _effect;
	};


}

#endif