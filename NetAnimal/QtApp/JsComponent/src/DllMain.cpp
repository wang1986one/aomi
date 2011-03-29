#include "JsComponentStableHeaders.h"
#include "JsComponent.h"
using namespace Orz;



extern "C" void dllStartPlugin(void)
{
	ComponentFactories::getInstance()
		.addFactory("JsComponent", boost::factory<JsComponent*>());
}

extern "C" void dllStopPlugin(void)
{

	ComponentFactories::getInstance()
		.removeFactory("JsComponent");
}
