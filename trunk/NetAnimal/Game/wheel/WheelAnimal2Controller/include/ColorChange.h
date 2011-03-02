																   
#ifndef __Orz_ColorChange_h__
#define __Orz_ColorChange_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"
	 
#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
#include "WheelAnimalProcess.h"
#include "WinnerAnimation.h"

class OSMScene;
namespace Orz
{

	class ColorChange
	{
	public:
		ColorChange(Ogre::SceneNode * node);
		void clear(void);
		SomethingRise * getRise(float speed);
		void update(TimeType interval);
		void stop(WheelEnum::LIGHT_COLOR color);
	private:
		Ogre::SceneNode * _node;
		SomethingRisePtr _rise;
		
		Ogre::AnimationState * _animation;
		boost::shared_ptr<OSMScene> _osm;	
	};

}

#endif