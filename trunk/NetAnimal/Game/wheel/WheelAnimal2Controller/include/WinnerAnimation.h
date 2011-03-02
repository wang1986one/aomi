#ifndef __Orz_WinnerAnimation_h__
#define __Orz_WinnerAnimation_h__

#include "WheelAnimalControllerConfig.h"

#include <Ogre/Ogre.h>
namespace Orz
{
	class WinnerAnimation
	{
	public:
		WinnerAnimation(const std::string & name, Ogre::SceneNode * start, const Ogre::SceneNode * end);
		void play(void);
		void reset(void);
		bool update(TimeType interval/*********/);
		~WinnerAnimation(void);
	private:
		Ogre::Animation * _anim;
		Ogre::NodeAnimationTrack * _track;
		Ogre::AnimationState* _animState;
	};


	class WinnerAnimationNoMove
	{
	public:
		WinnerAnimationNoMove(const std::string & name, Ogre::SceneNode * start);
		void play(void);
		void reset(void);
		bool update(TimeType interval/*********/);
		~WinnerAnimationNoMove(void);
	private:
		Ogre::Animation * _anim;
		Ogre::NodeAnimationTrack * _track;
		Ogre::AnimationState* _animState;
	};
}


#endif
