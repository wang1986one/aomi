#include "JsComponentStableHeaders.h"
#include "JsComponent.h"
using namespace Orz;



extern "C" void dllStartPlugin(void)
{
	ComponentFactories::getInstance()
		.addFactory("Js", boost::factory<JsComponent*>());
}

extern "C" void dllStopPlugin(void)
{

	ComponentFactories::getInstance()
		.removeFactory("Js");
}
