#include "SanConfig.h"
#include <tinyxml/tinyxml.h>

#include <orz/Toolkit_Base/EventSystem/EventWorldUpdate.h>
void LoadSingleChipPort(void)
{
	
	TiXmlDocument document("SingleChip.xml");
	document.LoadFile();
	TiXmlElement* port = document.FirstChildElement("SingleChip_Port");
	std::string COM_N("COM4");
	if(port)
	{

		const std::string * value = port->Attribute(std::string("value"));
		if(value)
			COM_N = *value;
	}
	Orz::SystemInterface::getSingleton().setParame<std::string>("SingleChip_Port", COM_N);
}
#if 0
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main()
#endif
{


	using namespace Orz;
	//建立系统层（View）                             计时器，            Ogre图形管理       , CEGUI管理器   OIS管理器        音频管理器        插件管理器      单片机管理器
	SystemPtr system(new SystemList<boost::mpl::list<AsioTimerManager, OgreGraphicsManager, CEGUIManager, OISInputManager, FmodSoundManager, PluginsManager, SingleChipManager, EventWorldUpdate> >());

	//创建一个逻辑的外观
	LogicConfiger::LogicFacadePtr logic(new LogicConfiger::LogicFacade());


	CEGUIManager::getSingleton().mouseEvent(false);
	CEGUIManager::getSingleton().keyEvent(true);


	//构建一个builder 
	LogicConfiger::ManualBuilder builder;
	
	
	
	

//	const std::string * type = root->Attribute(TYPE);
	


	//增加两个个动态插件
	builder.addPlugin("SanController");
	builder.addPlugin("Model_Base");
	builder.addPlugin("MyWheelDirector");
	builder.addPlugin("WheelAnimal2Model");
	builder.addPlugin("SanModel");
	builder.addPlugin("NewGameComponents");
	builder.addPlugin("NewGameSceneComponent");
	builder.addPlugin("GameNeedleComponent");
	builder.addPlugin("GameDiamondComponent");
	builder.addPlugin("VedioUIComponent");

	builder.addPlugin("CodingComponent");
	builder.addPlugin("MyJobComponent");
	//设置大厅
	builder.setTheater("TheaterBase","main");


	//NameValueList p;
	//p["XML_FILE"] = VariantData<std::string>::set(std::string("GameConfig.xml"));
	builder.addDirector("WheelDirector","wheel"/*, p*/);
	builder.setActiveDirector("wheel");
	logic->building(builder);

	//SystemInterface::getSingleton().setParame<int>("SingleChip_BaudRate", 19200);
	//LoadSingleChipPort();//
	SystemInterface::getSingleton().setParame<bool>("SILENT", true);
	SystemInterface::getSingleton().setParame<bool>(SystemParame::SystemUpdateFilter, true);
	SystemInterface::getSingleton().setParame<unsigned int>(SystemParame::SystemUpdateFilterCount, 20);



	try
	{
		if(system->init())
		{

			

		/*	using namespace Ogre;
			DataStreamPtr pStream;

			pStream = ResourceGroupManager::getSingleton().openResource( "sc.xml", "xml" );


			
			using namespace rapidxml;


			String data = pStream->getAsString();

			xml_document<> doc;
			doc.parse<0>(&data[0]);
			rapidxml::xml_node<> *node = doc.first_node("single-chips");*/
		/*	Orz::SingleChipManager::getSingleton().loadXML(node);
			{
				const Ogre::ResourceGroupManager::LocationList  & list = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList("sound");
		
				Orz::ISoundManager::getSingleton().setResourcesPath((*list.begin())->archive->getName());
			}*/
			if(logic->load(EventWorld::Parameter()))
			{
				system->run();
				logic->unload();
			}

			system->shutdown();
		}
	}
	catch(std::exception & e)
	{
		ORZ_LOG_CRITICAL_MESSAGE(e.what());
	}
}
