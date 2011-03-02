
#ifndef __Orz_GlodProcess_h__
#define __Orz_GlodProcess_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"
#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
#include "WheelAnimalProcess.h"
#include "ProcessFactory.h"
#include "WinnerAnimation.h"
#include "ColorChange.h"
//#include "WheelUI.h"

namespace Orz
{

class GlodProRun: public WheelAnimalProcess, public UpdateToEnable<GlodProRun>
	{
	public:

		
		GlodProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac);
		virtual bool update(TimeType interval);
		virtual ~GlodProRun(void);
		virtual void enable(void);
		void clear(void);
	private:
		TimeType _time;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<AnimalChange> _ac;
		SoundPlayerPtr _GlodProRunMusic;
		bool _GlodProRunIsEnd;
		bool _GlodProRunIsPlaying;
		

	};

///////////////////////////////////////////////////////////////////////////////////////////////
	class GlodShowWinner: public WheelAnimalProcess, public UpdateToEnable<GlodShowWinner>
	{
	public:


		GlodShowWinner(boost::shared_ptr<WheelAnimalSceneObj> scene, WinEffectPtr effect, int winner, const Ogre::Degree & angle);

		virtual ~GlodShowWinner(void);
		void clear();
		virtual bool update(TimeType interval/*********/);
		virtual void enable(void);
	private:
		boost::shared_ptr<WinnerAnimation> _winnerAnim;

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		Ogre::SceneNode * _end; 
		Ogre::AnimationState * _animation;
		int _winner;

		Ogre::AnimationState * _camAnimation;

		boost::shared_ptr<OSMScene> _osm;	
		 ;
		WinEffectPtr _effect; 

	};






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	class GlodPlayAnimation: public WheelAnimalProcess,public UpdateToEnable<GlodPlayAnimation>
	{
	public:


		GlodPlayAnimation( boost::shared_ptr<WheelAnimalSceneObj> scene, GoldPtr gold, int winner);
		virtual ~GlodPlayAnimation(void);
		void clear(void);
		void enable(void);
		bool update(Orz::TimeType interval);
	private:
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		int _winner;
		TimeType _time;
		GoldPtr _gold;

		 ;
	};


////////////////////////////////////////////////////////////////////////////////////////////////////////////


	class RotateAnimation;
	class GlodGameRotate: public WheelAnimalProcess , public UpdateToEnable<GlodGameRotate>
	{
	public:
		GlodGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			int nAngle,
			int rAngle
			);
		virtual ~GlodGameRotate(void);
		virtual void enable(void);
		virtual bool update(TimeType interval/*********/);
		void clear(void);
	private:

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;

		SoundPlayerPtr _GlodGameRotateMusic;
		

	};

	////////////////////////////////////////////////////////////////////////////

	class GlodProcess5: public WheelAnimalProcess, public UpdateToEnable<GlodProcess5>
	{
	public:


		GlodProcess5();
		virtual ~GlodProcess5(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

	class ProcessFactoryGold:public ProcessFactory
	{

	public:
		ProcessFactoryGold(
			 
			boost::shared_ptr<WheelAnimalSceneObj> scene,
			WinEffectPtr effect,
			GoldPtr gold,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			ObjectLightsPtr objLights
			);
		virtual ~ProcessFactoryGold(void)   ;
		Process0Ptr createProcess0(void);
		ProcessPtr createProcess1(void)	;
		ProcessPtr createProcess2(void)	 ;
		ProcessPtr createProcess3(void)	;
		ProcessPtr createProcess4(void);
		/*ProcessPtr createProcess5(void);*/
	private:
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;	
		boost::shared_ptr<AnimalChange> _ac;  
		GoldPtr _gold;
		WinEffectPtr _effect;

	};


}

#endif