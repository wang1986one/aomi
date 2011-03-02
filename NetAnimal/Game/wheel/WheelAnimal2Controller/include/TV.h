#ifndef __Orz_TV_h__
#define __Orz_TV_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"

class OSMScene;
namespace Orz
{
	class TV 
	{
	public:
		TV(Ogre::SceneNode * sn);
		virtual ~TV(void);
		SomethingRise * getRise(float speed);
		void clear(void);
		void setNumber(int i = 1);
	private:
		Ogre::SceneNode * _sn;
		boost::shared_ptr<OSMScene> _osm;
		SomethingRisePtr _rise;

		
	};




}
#endif