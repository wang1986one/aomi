#ifndef __Orz_Tutorial_ProcessFactory_h__
#define __Orz_Tutorial_ProcessFactory_h__
#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalProcess.h"
#include "LightRunning.h"
#include "ComputeWinner.h"
#include "PlayAnimation.h"
#include "AnimalChange.h"
#include "WinEffect.h"
#include "TV.h"
#include "Gold.h"
namespace Orz
{
	class ProcessFactory
	{
	public:
		ProcessFactory(  boost::shared_ptr<WheelAnimalSceneObj> scene, ObjectLightsPtr objLights);

	//	ProcessFactory(WheelEnum::ANIMAL_TYPE at, WheelEnum::LIGHT_COLOR color, boost::shared_ptr<WheelAnimalSceneObj> scene, ObjectLightsPtr objLights);
		virtual ~ProcessFactory(void);
		virtual Process0Ptr createProcess0(void) = 0;

		virtual ProcessPtr createProcess(WheelAnimalProcess::PROCESS process);


		virtual ProcessPtr createProcess1(void) = 0;
		virtual ProcessPtr createProcess2(void) = 0;
		virtual ProcessPtr createProcess3(void) = 0;
		virtual ProcessPtr createProcess4(void) = 0;
	/*	virtual ProcessPtr createProcess5(void) = 0;*/
	protected:
		int _winner;
		int _offset;
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		ObjectLightsPtr _objLights;
		float _rAngle;
		float _nAngle;
		//Orz::WinData WinData::getSingleton();
	};

	////////////////////////////

	







	




	
	


}
#endif