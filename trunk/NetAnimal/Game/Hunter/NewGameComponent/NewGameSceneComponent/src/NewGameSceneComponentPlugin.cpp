#include "NewGameSceneComponentStableHeaders.h"
#include "NewGameSceneComponent.h"

using namespace Orz;


extern "C" void dllStartPlugin(void)
{

	ComponentFactories::getInstance()
		.addFactory("NewGameScene", boost::factory<NewGameSceneComponent*>());



}

extern "C" void dllStopPlugin(void)
{
	ComponentFactories::getInstance().removeFactory("NewGameScene");
}
