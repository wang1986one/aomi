#include "WheelAnimalControllerStableHeaders.h"
#include "ProcessFactory.h"
#include "ProRun.h"
#include "GameRotate.h"
#include "ShowWinner.h"
#include "DoubleProcess.h"
#include "GlodProcess.h"
#include "TVProcess.h"
using namespace Orz;
ProcessFactory::ProcessFactory( boost::shared_ptr<WheelAnimalSceneObj> scene, ObjectLightsPtr objLights):_scene(scene),_objLights(objLights)
{
	WheelEnum::ANIMAL_TYPE at = WinData::getInstance().getAnimalType();//Hardware::getSingleton().getWinnerAnimalType();
	_winner = scene->findRandomAnimal(at);
	_offset = objLights->getRandomLight(WinData::getInstance().getLightColor());

	ComputeWinner c;

	c.compute(_winner, _offset, 5);
	_rAngle = c.getRotate() *15;
	_nAngle = c.getNeedle() *15;

}

//ProcessFactory::ProcessFactory(WheelEnum::ANIMAL_TYPE at, WheelEnum::LIGHT_COLOR color, boost::shared_ptr<WheelAnimalSceneObj> scene, ObjectLightsPtr objLights):_scene(scene),_objLights(objLights)
//{
//	_winner = scene->findRandomAnimal(at);
//	_offset = objLights->getRandomLight(color);
//
//	ComputeWinner c;
//
//	c.compute(_winner, _offset, 5);
//	_rAngle = c.getRotate() *15;
//	_nAngle = c.getNeedle() *15;
//}
ProcessFactory::~ProcessFactory(void)
{

}

ProcessPtr ProcessFactory::createProcess(WheelAnimalProcess::PROCESS process)
{

	switch(process)
	{
	case WheelAnimalProcess::PROCESS1:
		return createProcess1();
	case WheelAnimalProcess::PROCESS2:
		return createProcess2();
	case WheelAnimalProcess::PROCESS3:
		return createProcess3();
	case WheelAnimalProcess::PROCESS4:
		return createProcess4();
	//case WheelAnimalProcess::PROCESS5:
	//	return createProcess5();
	
	}
	return ProcessPtr();
}



	





