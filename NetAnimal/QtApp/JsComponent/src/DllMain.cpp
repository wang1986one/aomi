#include "JsComponentStableHeaders.h"
#include "JsComponent.h"
#include "NetGameComponent.h"
using namespace Orz;



extern "C" void dllStartPlugin(void)
{
	ComponentFactories::getInstance()
		.addFactory("Js", boost::factory<JsComponent*>())
		.addFactory("WheelGame", boost::factory<NetGameComponent*>());
}

extern "C" void dllStopPlugin(void)
{

	ComponentFactories::getInstance()
		.removeFactory("Js")
		.removeFactory("WheelGame");
}
