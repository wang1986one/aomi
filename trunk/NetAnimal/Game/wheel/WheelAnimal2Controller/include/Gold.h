#ifndef __Orz_Gold_h__
#define __Orz_Gold_h__
#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalSceneObj.h"
#include "WheelAnimalProcess.h"
#include "WheelAnimalControllerConfig.h"
namespace Orz
{

	
	class Gold 
	{

	
	public:
	
		Gold(Ogre::SceneNode * node);
		virtual ~Gold(void);
		void show(void);
		void hide(void);
		void update(TimeType i);
		void clear(void);
		void setNumber(int i);
	private:
		boost::shared_ptr<OSMScene> _osm;
		Ogre::SceneNode * _sn;
		Ogre::AnimationState* _animation;
		std::vector<Ogre::MaterialPtr> _materials;
		boost::array<std::string, 10> _number;

	};


	
	typedef boost::shared_ptr<Gold> GoldPtr;

}

#endif