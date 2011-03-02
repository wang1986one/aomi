#ifndef __Orz_Tutorial_ShowWinner_h__
#define __Orz_Tutorial_ShowWinner_h__
#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalProcess.h"
#include "ObjectLights.h"
#include "WinData.h"
namespace Orz
{
	
	
	
	
    class WheelAnimalSceneObj;
	class WinnerAnimation;
	class WinnerAnimationNoMove;
	class ShowWinner: public WheelAnimalProcess, public UpdateToEnable<ShowWinner>
	{
	public:


		ShowWinner(boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & angle);
		void enable(void);
		virtual ~ShowWinner(void);
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

	class AnimalShowWinner: public WheelAnimalProcess
	{
	public:


		AnimalShowWinner(boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, ObjectLightsPtr objLights, float nAngle);
		virtual ~AnimalShowWinner(void);

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

	};
	

}

#endif 