#include "SanControllerBaseStableHeaders.h"

#include "OgreDotSceneLoaderComponent.h"
#include "OgreCCSComponent.h"
#include "ZhugeLiangComponent.h"
#include "OgreNodeDebuggerComponent.h"
#include "WheelPlaceComponent.h"
#include "SanProcessComponent.h"
#include "SanArmyComponent.h"
#include "SanSceneComponent.h"
#include "OgreEntityComponent.h"
#include "OgrePlayerComponent.h"
#include "OgreResourceComponent.h"
using namespace Orz;



extern "C" void dllStartPlugin(void)
{

	ComponentFactories::getInstance()
		.addFactory("OgreEntity", boost::factory<OgreEntityComponent*>())
		.addFactory("OgrePlayer", boost::factory<OgrePlayerComponent*>())
		.addFactory("OgreResource", boost::factory<OgreResourceComponent*>())
		.addFactory("OgreDotSceneLoader", boost::factory<OgreDotSceneLoaderComponent*>())
		.addFactory("OgreNodeDebugger", boost::factory<OgreNodeDebuggerComponent*>())
		.addFactory("OgreCCS", boost::factory<OgreCCSComponent*>())
		.addFactory("WheelPlace", boost::factory<WheelPlaceComponent*>())
		.addFactory("SanProcess", boost::factory<SanProcessComponent*>())
		
		.addFactory("SanScene", boost::factory<SanSceneComponent*>());
}

extern "C" void dllStopPlugin(void)
{

	ComponentFactories::getInstance()
		.removeFactory("OgreEntity")
		.removeFactory("OgrePlayer")
		.removeFactory("OgreResource")
		.removeFactory("OgreDotSceneLoader")
		.removeFactory("OgreNodeDebugger")
		.removeFactory("OgreCCS")
		.removeFactory("WheelPlace")
		.removeFactory("SanProcess")
		.removeFactory("SanScene");
}
