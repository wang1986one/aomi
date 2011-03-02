#include "CodingComponentStableHeaders.h"
#include "CodingComponent.h"
#include "CodingFormatComponent.h"
#include "ET299Component.h"
#include "SenselockComponent.h"
#include "DataServerComponent.h"
#include "CRC16ZmodemComponent.h"
using namespace Orz;

extern "C" void dllStartPlugin(void)
{
	Orz::ComponentFactories::getInstance()
		.addFactory("Coding", boost::factory<CodingComponent *>())
		.addFactory("Format", boost::factory<CodingFormatComponent *>())
		.addFactory("ET299", boost::factory<ET299Component *>())
		.addFactory("Senselock", boost::factory<SenselockComponent*>())
		.addFactory("CRC16", boost::factory<CRC16ZmodemComponent*>())
		.addFactory("DataServer", boost::factory<DataServerComponent*>());

	
}

extern "C" void dllStopPlugin(void)
{
	
	Orz::ComponentFactories::getInstance()
		.removeFactory("Coding")
		.removeFactory("Format")
		.removeFactory("ET299")
		.removeFactory("Senselock")
		.removeFactory("CRC16")
		.removeFactory("DataServer");
}

