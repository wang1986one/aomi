
#ifndef __Orz_NoneProcess_h__
#define __Orz_NoneProcess_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"
#include "RotateAnimation.h"
#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
#include "WheelAnimalProcess.h"
#include "WinnerAnimation.h"
#include "ColorChange.h"
#include "ProcessFactory.h"
namespace Orz
{
	class NoneProRun: public WheelAnimalProcess , public UpdateToEnable<NoneProRun>
	{
	public:

		NoneProRun(void);
		virtual bool update(TimeType interval);
		virtual ~NoneProRun(void);
		void clear(void);
		virtual void enable(void);
	private:
		TimeType _time;
		
		SoundPlayerPtr _NoneGameRotateMusic;

	};


//////////////////////////////////////////////////////////////////////


	class NoneGameRotate: public WheelAnimalProcess , public UpdateToEnable<NoneGameRotate>
	{
	public:
		NoneGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			int nAngle,
			int rAngle
			);
		virtual ~NoneGameRotate(void);
		virtual void enable(void);
		virtual bool update(TimeType interval/*********/);
		void clear(void);
	private:

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;	 
		SoundPlayerPtr _NoneGameRotateMusic;

	};


//////////////////////////////////////////////////////////////////////////////

	class NoneShowWinner: public WheelAnimalProcess, public UpdateToEnable<NoneShowWinner>
	{
	public:


		NoneShowWinner(  boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & rAngle,  float nAngle);
		void enable(void);
		virtual ~NoneShowWinner(void);
		void clear();
		virtual bool update(TimeType interval/*********/);

	private:
		boost::shared_ptr<WinnerAnimation> _winnerAnim;

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		Ogre::SceneNode * _end; 
		Ogre::AnimationState * _animation;
		int _winner;
		
		Ogre::AnimationState * _camAnimation;
		float _nAngle;
		SoundPlayerPtr _NoneGameMusic;
	};


//////////////////////////////////////////////////////////////////////////

	class NonePlayAnimation: public WheelAnimalProcess,public UpdateToEnable<NonePlayAnimation>
	{
	public:


		NonePlayAnimation(boost::shared_ptr<WheelAnimalSceneObj> scene,  WinEffectPtr effect , int winner);
		virtual ~NonePlayAnimation(void);
		void clear(void);
		void enable(void);
		bool update(Orz::TimeType interval);
	private:
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		int _winner;
		TimeType _time;
		WinEffectPtr _effect;
		SoundPlayerPtr _NonePlayAnimationMusic;
	};


/////////////////////////////////////////////////////////////////////////////


	class RotateAnimation;
	class ProcessFactoryNone:public ProcessFactory
	{
	public :
		ProcessFactoryNone(
			 
			boost::shared_ptr<WheelAnimalSceneObj> scene,
			WinEffectPtr effect,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			ObjectLightsPtr objLights
			);

		virtual ~ProcessFactoryNone(void);
		Process0Ptr createProcess0(void);
		ProcessPtr createProcess1(void);
		ProcessPtr createProcess2(void);
		ProcessPtr createProcess3(void);
		ProcessPtr createProcess4(void);
	/*	ProcessPtr createProcess5(void);*/
	private:
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;	
		WinEffectPtr _effect;

	};

////////////////////////////////////////////////////////////////////////////

	class NoneProcess4: public WheelAnimalProcess, public UpdateToEnable<NoneProcess4>
	{
	public:


		NoneProcess4();
		virtual ~NoneProcess4(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};
}

#endif