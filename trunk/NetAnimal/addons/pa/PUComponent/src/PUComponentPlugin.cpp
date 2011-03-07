#include "PUComponentStableHeaders.h"
#include "PUComponent.h"
using namespace Orz;


extern "C" void dllStartPlugin(void)
{

	ComponentFactories::getInstance().addFactory("PUComponent", boost::factory<PUComponent*>());

	
}

extern "C" void dllStopPlugin(void)
{

	ComponentFactories::getInstance().removeFactory("PUComponent");
}
