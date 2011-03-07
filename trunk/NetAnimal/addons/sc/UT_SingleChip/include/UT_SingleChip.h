#ifndef __Orz_Test_OrzAR_h__
#define __Orz_Test_OrzAR_h__
#include "config.h"
#include <iostream>

#include <orz/Framework_Base/FrameworkBase.h>
#include <orz/Framework_Base/System.h>
#include <orz/Toolkit_Base/TimerManager.h>
#include <orz/Toolkit_Base/DynLibManager.h>
#include <orz/Toolkit_Base/LogManager.h>
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include <orz/View_CEGUI/CEGUIManager.h>
#include <orz/View_OIS/OISInputManager.h>
#include <orz/View_Fmod/FmodSoundManager.h>
#include <orz/Toolkit_Base/Singleton.h>
#include <boost/property_tree/detail/rapidxml.hpp>
#include <Ogre/Ogre.h>


class Listener_:public Orz::SingleChipListener
{
public:
	virtual void read(boost::circular_buffer<unsigned char> & data)
	{
		std::cout<<1<<std::endl;
	}
	virtual void readFromSCM(unsigned int id, unsigned char c)
	{
		std::cout<<id<<":"<<unsigned int(c)<<std::endl;
	}
};
BOOST_AUTO_TEST_SUITE( SingleChipManager_ts )

struct F {
	F() {
		using namespace Orz;
		system.reset(new SystemList<boost::mpl::list<SimpleTimerManager, OgreGraphicsManager, SingleChipManager, OISInputManager> >());

	}
	~F() { }


	Orz::SystemPtr system;
};


//#if TRACKER_SINGLE

BOOST_FIXTURE_TEST_CASE(simple, F)
{


	using namespace rapidxml;

	Orz::SystemInterface::getSingleton().setParame<std::string>("SingleChip_Port", std::string("COM1"));
	Orz::SystemInterface::getSingleton().setParame<int>("SingleChip_BaudRate", 9600);
	Listener_ l;

	if(system->init())
	{
		unsigned char c = 0;
		{
			using namespace Ogre;
			DataStreamPtr pStream;

			pStream = ResourceGroupManager::getSingleton().openResource( "sc.xml", "xml" );





			String data = pStream->getAsString();

			xml_document<> doc;
			doc.parse<0>(&data[0]);
			rapidxml::xml_node<> *node = doc.first_node("single-chips");
			Orz::SingleChipManager::getSingleton().loadXML(node);

			Orz::SingleChipManager::getSingleton().addListener(0,&l);
			Orz::SingleChipManager::getSingleton().addListener(1,&l);

		}
		//boost::shared_ptr<OgreNewtRunning>  runing(new OgreNewtRunning());

		//Orz::TimerPtr timer(new Orz::Timer("DemoRuning", boost::bind(&OgreNewtRunning::update, runing.get() )));
		//	timer->start(WORLD_UPDATE_INTERVAL);

		system->run();



		//runing.reset();

		system->shutdown();
	}




}

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE_END()

#endif
