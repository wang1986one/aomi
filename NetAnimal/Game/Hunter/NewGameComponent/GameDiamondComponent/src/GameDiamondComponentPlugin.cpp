#include "GameDiamondComponentStableHeaders.h"
#include "GameDiamondComponent.h"
#include "GameBallComponent.h"
#include "GameDiamondMoreWinderComponent.h"
#include "GameColourComponent.h"
using namespace Orz;


extern "C" void dllStartPlugin(void)
{

	ComponentFactories::getInstance()
		.addFactory("GameDiamond", boost::factory<GameDiamondComponent*>())
		.addFactory("GameBall",boost::factory<GameBallComponent*>())
		.addFactory("GameDiamondMoreWinder",boost::factory<GameDiamondMoreWinderComponent*>())
		.addFactory("GameColour",boost::factory<GameColourComponent*>());

}

extern "C" void dllStopPlugin(void)
{
}
