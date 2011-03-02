
#ifndef __Orz_RotateAnimalProcess_h__
#define __Orz_RotateAnimalProcess_h__

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

	class RotateAnimalProRun: public WheelAnimalProcess, public UpdateToEnable<RotateAnimalProRun>
	{
	public:
		RotateAnimalProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac);
		void enable(void);
		virtual bool update(TimeType interval);
		virtual ~RotateAnimalProRun(void);
		void clear(void);
	private:
		TimeType _time;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		
		boost::shared_ptr<AnimalChange> _ac; 
		
		SoundPlayerPtr _RotateAnimalProRunMusic;
		//bool _ProRunMusicIsEnd;
		//bool _isMusicPlaying;

	};


//////////////////////////////////////////////////////////////////////
	class RotateAnimalGameRotate: public WheelAnimalProcess, public UpdateToEnable<RotateAnimalGameRotate>
	{
	public:

		RotateAnimalGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
			boost::shared_ptr<AnimalChange> ac,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			int winner,
			float nAngle,
			float rAngle
			);
		virtual ~RotateAnimalGameRotate(void);
		void enable(void);
		virtual bool update(TimeType interval/*********/);
		void clear(void);

		//virtual void resetRotate(void);
		//virtual Ogre::Degree getRotateAngle(void);
		
	private:

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;
		boost::shared_ptr<AnimalChange> _ac;
		Ogre::AnimationState * _as;
		int _winner;
		
		bool _isContiue;
		SoundPlayerPtr RotateAnimalGameRotateMusic;

	};

//////////////////////////////////////////////////////////////////////////////

class RotateAnimalShowWinner: public WheelAnimalProcess
	{
	public:


		RotateAnimalShowWinner(boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, ObjectLightsPtr objLights, float nAngle);
		virtual ~RotateAnimalShowWinner(void);

		//virtual void winner(const Ogre::Degree & angle);
		virtual bool update(TimeType interval/*********/);
		virtual void clear(void);
		
	private:
		boost::shared_ptr<WinnerAnimationNoMove> _winnerAnim;
		
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
	
		Ogre::AnimationState * _animation;
		int _winner;
		bool _playanimtion;
		int _n;
		ObjectLightsPtr _objLights;
		float _nAngle;
		std::vector<int> _ns;

		//SoundPlayerPtr RotateAnimalShowWinnerMusic;
		bool ShowWinnerMusicIsEnd;

	};


//////////////////////////////////////////////////////////////////////////

class RotateAnimalPlayAnimation: public WheelAnimalProcess, public UpdateToEnable<RotateAnimalPlayAnimation>
	{
	public:
		RotateAnimalPlayAnimation();
		virtual ~RotateAnimalPlayAnimation(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};

///////////////////////////////////////////////////////////////////////

	class RotateAnimalProcess5: public WheelAnimalProcess, public UpdateToEnable<RotateAnimalProcess5>
	{
	public:


		RotateAnimalProcess5();
		virtual ~RotateAnimalProcess5(void);
		void enable(void);
		bool update(Orz::TimeType interval);
		void clear(void);
	private:
		TimeType _time;
	};


/////////////////////////////////////////////////////////////////////////////

class ProcessFactoryAllAnimal:public ProcessFactory
	{

	public :
		ProcessFactoryAllAnimal(
			
			 
			boost::shared_ptr<WheelAnimalSceneObj> scene,
			boost::shared_ptr<AnimalChange> ac,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			ObjectLightsPtr objLights
			);
		~ProcessFactoryAllAnimal(void);
		Process0Ptr createProcess0(void) ;
		ProcessPtr createProcess1(void);
		ProcessPtr createProcess2(void);
		ProcessPtr createProcess3(void);
		ProcessPtr createProcess4(void);
		//ProcessPtr createProcess5(void);
	private:
		boost::shared_ptr<AnimalChange> _ac;   
		boost::shared_ptr<RotateAnimation> _needle;			 
		boost::shared_ptr<RotateAnimation> _rotate;
	};


///////////////////////////////////////////////////////////////////
}

#endif