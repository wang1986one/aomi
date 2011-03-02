#include "NewGameComponentsStableHeaders.h"
#include "SceneProcessComponent.h"
#include "AnimalProcessComponent.h"
#include "DiamondProcessComponent.h"
#include "DiscProcessComponent.h"
#include "NeedleProcessComponent.h"
#include "GameTranslateComponent.h"
#include "UIProcessComponent.h"
//disc
//needle
using namespace Orz;



extern "C" void dllStartPlugin(void)
{

	ComponentFactories::getInstance()
		.addFactory("SceneProcess", boost::factory<SceneProcessComponent*>())
		.addFactory("AnimalProcess", boost::factory<AnimalProcessComponent*>())
		.addFactory("DiamondProcess", boost::factory<DiamondProcessComponent*>())
		.addFactory("NeedleProcess", boost::factory<NeedleProcessComponent*>())
		.addFactory("GameTranslate", boost::factory<GameTranslateComponent*>())
		.addFactory("UIProcess", boost::factory<UIProcessComponent*>());
}

extern "C" void dllStopPlugin(void)
{

	//ComponentFactories::getInstance()
	//	.removeFactory("SceneProcess");
}
