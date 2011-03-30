
#include "WheelConfig.h"

#include <orz/Framework_Base/Logic.h>
#include <orz/Framework_Base/FrameworkBase.h>
#include <orz/View_CEGUI/CEGUIManager.h>
#include <orz/Toolkit_Base/EventSystem/EventWorldUpdate.h>

int main()
{
	using namespace Orz;
	SystemPtr system(new SystemList<boost::mpl::list<OgreGraphicsManager, CEGUIManager, OISInputManager, FmodSoundManager, PluginsManager, SingleChipManager, EventWorldUpdate> >());

	LogicConfiger::LogicFacadePtr logic(new LogicConfiger::LogicFacade());
	//LogicConfiger::ConfigerPtr logic(new LogicConfiger::Configer());


	CEGUIManager::getSingleton().mouseEvent(false);
	CEGUIManager::getSingleton().keyEvent(true);
	LogicConfiger::ManualBuilder builder;
	//boost::shared_ptr<LogicConfigerManualLoader>  loader(new LogicConfigerManualLoader());

	builder.addPlugin("Model_Base");
	builder.addPlugin("MyWheelDirector");
	builder.addPlugin("WheelAnimal2Model");
	builder.addPlugin("CodingComponent");
	builder.addPlugin("JsComponent");
	builder.addPlugin("MyJobComponent");
 
	/*builder.addPlugin("WheelAnimalModel");*/
	builder.setTheater("TheaterBase","main");
	/*
	NameValueList p;
	p["XML_FILE"] = VariantData<std::string>::set(std::string("UnitTest.xml"));*/
	builder.addDirector("WheelDirector","wheel");
	builder.setActiveDirector("wheel");
	//Orz::DirectorPtr dp = GameFactories::getInstance().createDirector("WheelDirector", "director", &p);
	logic->building(builder);

	//SystemInterface::getSingleton().setParame<std::string>("AomiUI_MediaDirectory", std::string("..\\..\\media\\animalUI"));
	SystemInterface::getSingleton().setParame<std::string>("SingleChip_Port", std::string("COM3"));
	SystemInterface::getSingleton().setParame<int>("SingleChip_BaudRate", 19200);
	SystemInterface::getSingleton().setParame<bool>("SILENT", true);
	//SystemInterface::getSingleton().setParame<bool>("w32_mouse", true);
	//SystemInterface::getSingleton().setParame<bool>("CEGUI_LOGO", true);

	//try
	//{
		if(system->init())
		{
			using namespace Ogre;
			DataStreamPtr pStream;

			pStream = ResourceGroupManager::getSingleton().openResource( "sc.xml", "xml" );


			
			using namespace rapidxml;


			String data = pStream->getAsString();

			xml_document<> doc;
			doc.parse<0>(&data[0]);
			rapidxml::xml_node<> *node = doc.first_node("single-chips");
			Orz::SingleChipManager::getSingleton().loadXML(node);

			if(logic->load(EventWorld::Parameter().multiThread(false).fixedStep(false)))
			{
				system->run();
				logic->unload();
			}

			system->shutdown();
		}
	//}
	//catch(std::exception & e)
	//{
	//	std::cout<<e.what();
	//	ORZ_LOG_CRITICAL_MESSAGE(e.what());
	//}
}
