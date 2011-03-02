#ifndef __Orz_UnitTest_WheelGameTest__
#define __Orz_UnitTest_WheelGameTest__
#include "UnitTestConfig.h"
#include "WheelGame.h"
#include "KeyEngineDecorator.h"
#include "WheelEngine.h"
#include "WheelClock.h"
#include <orz/Toolkit_Base/EventSystem.h>
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(WheelDirectorTest)
{
	using namespace Orz;

	//WheelDirector director;
	/*EventWorld world;
	Engine engine(&world);
	KeyToMessage k2m(&engine);
	SingleChipToMessage s2m(&engine);*/
	/*CEGUIManager::getSingleton().mouseEvent(false);
	CEGUIManager::getSingleton().keyEvent(true);*/

	//LogicConfiger::LogicFacadePtr logic(new LogicConfiger::LogicFacade());
	//LogicConfiger::ManualBuilder builder;

	//builder.addPlugin("Model_Base");
	//builder.addPlugin("WheelDirector");
	//builder.setTheater("TheaterBase","main");
	//builder.addDirector("WheelDirector","Wheel");
	//builder.setActiveDirector("Wheel");

	//logic->building(builder);
	//if(logic->load(EventWorld::MULTI_THREAD))
	//{
	//	UnitTestEnvironmen::system->run();
	//	logic->unload();
	//}
}


BOOST_AUTO_TEST_CASE(WheelControllerTest)
{
	using namespace Orz;
	//WheelGame game;
	EventWorld world;
	//WheelGameInterfacePtr game(new WheelGame(&world));
	WheelEngineInterfacePtr engine(new KeyEngineDecorator(WheelEngineInterfacePtr(new WheelEngine(&world))));
	WheelGame mediator(&world, HardwarePtr(new Hardware()),engine, WheelClockPtr(new WheelClock()));
	UnitTestEnvironmen::test_log->str("");
	mediator.received();
	{
		std::string result("call Hardware::received(bool isReceived)\n");
		UnitTestCompare comp(UnitTestEnvironmen::test_log->str(), result);
		comp.compare(UnitTestCompare::hide_sucessful);
	}
	
	UnitTestEnvironmen::test_log->str("");
	/*WheelClock clock();
	clock.setSecond(12);

	{
		std::string result("call Hardware::answerTime(int second)\n");
		UnitTestCompare comp(UnitTestEnvironmen::test_log->str(), result);
		comp.compare(UnitTestCompare::hide_sucessful);
	}*/
	//call Hardware::received(bool isReceived)
	//WheelUIInterfacePtr engine(new TestEngine());
	//game._register(engine);
	//mediator.active(game);
	//mediator.active(engine);

	/*EventWorld world;
	Engine engine(&world);
	KeyToMessage k2m(&engine);
	SingleChipToMessage s2m(&engine);*/
	
	UnitTestEnvironmen::system->run();
}

//____________________________________________________________________________//


#endif