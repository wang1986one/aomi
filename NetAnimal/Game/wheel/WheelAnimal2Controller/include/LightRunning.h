#ifndef __Orz_LightRunning_h__
#define __Orz_LightRunning_h__
#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
namespace Orz
{



	class LightRunning : public Process0LightRunning
	{

	public:
		LightRunning(boost::shared_ptr<ObjectLights> lights);
		virtual ObjectLights * getLights(void);
		virtual bool  update(TimeType interval/*, WheelAnimalSceneObj * scene*/);
		void init(void);

		virtual void setMode(WheelEnum::RATE mode);
		std::pair<int, int> getYellowGreen(WheelEnum::RATE mode);
	private:  
		TimeType _allTime;
		int _tick;
		bool _running;
		boost::shared_ptr<ObjectLights> _lights;


	};

}

#endif