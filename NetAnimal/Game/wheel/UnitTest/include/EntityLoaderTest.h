#ifndef __Orz_UnitTest_EntityLoaderTest__
#define __Orz_UnitTest_EntityLoaderTest__
#include "UnitTestConfig.h"
#include "EntityLoader.h"
#include <orz/Toolkit_Base/EventSystem.h>
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(EntityLoaderTest)
{
	using namespace Orz;
	EventWorld world;
	//
	//EntityLoader loader;
	//EntityPtr entity(new Entity("ABC"));
	//loader.addEntity(entity);
	//loader.loadScene("Type", "name");
	//loader.loadActor("Type", "name");
	//loader.loadFromXML("UnitTest.xml");
	//loader.enable(&world);

	//loader.disable();
	//loader.removeAll();
	
	PluginsManager::getSingleton().loadPlugin("WheelDirector");
	NameValueList p;
	p["XML_FILE"] = VariantData<std::string>::set(std::string("UnitTest.xml"));
	Orz::DirectorPtr dp = GameFactories::getInstance().createDirector("WheelDirector", "director", &p);
	world.init();
	world.comeIn(dp);

	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	world.goOut(dp);
	world.shutdown();
	/*("WheelEntity.xml");
	loader.enable();
	loader.disable();*/
	//WheelDirector director;
}
	

//____________________________________________________________________________//


#endif