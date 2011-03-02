#include "GameNeedleComponentStableHeaders.h"
#include "GameNeedleComponent.h"
#include "GameBaseComponent.h"
#include "RotationComponent.h"
#include "GameRotationComponent.h"
#include "GameAnimalComponent.h"
#include "GameFlowerComponent.h"
using namespace Orz;


extern "C" void dllStartPlugin(void)
{

	ComponentFactories::getInstance()
		.addFactory("GameNeedle", boost::factory<GameNeedleComponent*>())
		.addFactory("Rotation", boost::factory<RotationComponent*>())
		.addFactory("GameBase", boost::factory<GameBaseComponent*>())
		.addFactory("GameFlower", boost::factory<GameFlowerComponent*>())
		.addFactory("GameRotation", boost::factory<GameRotationComponent*>());



}

extern "C" void dllStopPlugin(void)
{
	ComponentFactories::getInstance().removeFactory("GameNeedle");
}
