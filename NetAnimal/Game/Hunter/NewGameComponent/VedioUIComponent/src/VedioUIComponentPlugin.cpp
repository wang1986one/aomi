#include "VedioUIComponentStableHeaders.h"
#include "VedioUIComponent.h"
using namespace Orz;


extern "C" void dllStartPlugin(void)
{

	ComponentFactories::getInstance()
		.addFactory("VedioUI", boost::factory<VedioUIComponent*>());



}

extern "C" void dllStopPlugin(void)
{
}
