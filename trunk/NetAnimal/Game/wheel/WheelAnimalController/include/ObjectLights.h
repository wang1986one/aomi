#ifndef __Orz_ObjectLights_h__
#define __Orz_ObjectLights_h__

#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalSceneObj.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	
	class ObjectLights 
	{

	
	public:
		bool push_random(WheelEnum::LIGHT_COLOR to, WheelEnum::LIGHT_COLOR from);
		///创建函数，传递进来场景指针，用于调配
		ObjectLights(boost::shared_ptr<WheelAnimalSceneObj> scene);

		virtual int getRandomLight(WheelEnum::LIGHT_COLOR color);
		virtual ~ObjectLights(void);
	    //设置模式
		//virtual void setMode(LightMode mode);
		void _init(void);
		unsigned int getNumber(WheelEnum::LIGHT_COLOR color);


		//inline std::pair<int, int> getYellowGreen(LightMode mode);
		boost::array<int, 24> & getLights(void);
		inline int size(void) const;
	    int getLight(int i) const
		{
			return _lights[i];
		}
		void setLight(int i)
		{
			  _scene->setLight(i, _lights[i]);
		}
	private:  
		
		const static unsigned int _size;
		//std::map<int, Ogre::Entity *> _lights;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::array<int, 24> _lights;
	
		//float _i;

	};


	
	typedef boost::shared_ptr<ObjectLights> ObjectLightsPtr;

}

#endif