
#ifndef __Orz_AllColorProcess_h__
#define __Orz_AllColorProcess_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"
	 
#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
#include "WheelAnimalProcess.h"
#include "WinnerAnimation.h"
#include "ColorChange.h"
#include "ProcessFactory.h"
namespace Orz
{

/////////////////////////////////预旋转过程/////////////////////////////////////////////

	class ColorProRun: public WheelAnimalProcess, public UpdateToEnable<ColorProRun>
	{
	public:
		ColorProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<ColorChange> cc);
		virtual bool update(TimeType interval);
		virtual ~ColorProRun(void);
		void clear(void);
		void enable(void);
	private:
		TimeType _time;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		//Ogre::AnimationState * _as;
		boost::shared_ptr<ColorChange> _cc; 

		SoundPlayerPtr _allColorProRunMusic;
		bool _ProRunMusicIsEnd;
	};

//////////////////////////////////旋转过程//////////////////////////////////////////////////

    class RotateAnimation;

	class ColorGameRotate: public WheelAnimalProcess, public UpdateToEnable<ColorGameRotate>
	{
	public:
		ColorGameRotate(
			boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<ColorChange> cc,
			boost::shared_ptr<RotateAnimation> needle, 
			boost::shared_ptr<RotateAnimation> rotate, 
			int winner,
			float nAngle,
			float rAngle);
		virtual ~ColorGameRotate(void);
		virtual void enable(void);
		virtual bool update(TimeType interval/*********/);
		virtual void clear(void);
		
	private:

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;
		boost::shared_ptr<ColorChange>  _cc;
		Ogre::AnimationState * _as;
		int _winner;
		Orz::WheelEnum::LIGHT_COLOR _color;
		SoundPlayerPtr _allColorGameRotateMusic;

		bool _isContinue;
		
	};


///////////////////////////////////显示胜利者////////////////////////////////////////////////

	class ColorShowWinner: public WheelAnimalProcess, public UpdateToEnable<ColorShowWinner>
	{
	public:

		ColorShowWinner(boost::shared_ptr<WheelAnimalSceneObj> scene, ObjectLightsPtr objLights, int winner, int offset);
		virtual ~ColorShowWinner(void);
		virtual bool update(TimeType interval/*********/);
		virtual void clear(void);
		void enable(void);
	private:
		boost::shared_ptr<WinnerAnimationNoMove> _winnerAnim;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		Ogre::AnimationState * _animation;
		int _winner;
		bool _playanimtion;
		int _n;
		Orz::WheelEnum::LIGHT_COLOR _color;
		// ;
		ObjectLightsPtr _objLights;
		int _offset;
		std::vector<int> _ns;
	};



///////////////////////////////////播放送颜色的动作////////////////////////////////////////////////

	class ColorPlayAnimation: public WheelAnimalProcess, public UpdateToEnable<ColorPlayAnimation>
	{
	public:

		
		ColorPlayAnimation();
		virtual ~ColorPlayAnimation(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};

	
	////////////////////////////////////////////////////////////////////////////

	class ColorProcess5: public WheelAnimalProcess, public UpdateToEnable<ColorProcess5>
	{
	public:


		ColorProcess5();
		virtual ~ColorProcess5(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};

///////////////////////////////////送颜色的工厂////////////////////////////////////////////////
	
	class ProcessFactoryAllColor :public ProcessFactory
	{

	public :
		ProcessFactoryAllColor(
			
			 
			boost::shared_ptr<WheelAnimalSceneObj> scene,
			boost::shared_ptr<ColorChange> cc,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			ObjectLightsPtr objLights
			);
		~ProcessFactoryAllColor(void);
		Process0Ptr createProcess0(void) ;
		ProcessPtr createProcess1(void);
		ProcessPtr createProcess2(void);
		ProcessPtr createProcess3(void);
		ProcessPtr createProcess4(void);
	/*	ProcessPtr createProcess5(void);*/
	private:
		boost::shared_ptr<ColorChange> _cc;

		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;

		//WheelEnum::LIGHT_COLOR _color;
	};
}

#endif