
#include "MyWheelDirectorStableHeaders.h"
#include "WheelDirector.h"
#include "WheelGame.h"
#include "logic/AllLogic.h"
#include "WheelClock.h"
#include "KeyEngineDecorator.h"
#include "WheelEngine.h"
#include "WheelEvents.h"
#include "EntityLoader.h"
#include "AutoEngineDecorator.h"
#include "MyHardware.h"
#include "MyHardwareEngineDecorator.h"
#include "MyHardwareCode.h"
#include "WinData.h"
#include "DUI/DUI.h"
#include "TableComponent.h"
#include "TableComponentKey.h"
#include "DataServerInterface.h"
#include "LockInterface.h"
#include "DataCentreInterface.h"
#include "WheelData.h"
#include "GSMInterface.h"
using namespace Orz;
WheelDirector::WheelDirector(const std::string & name/* , const std::string & xmlFile*/):Director(name)
{
	
	ORZ_LOG_NORMAL_MESSAGE("Create a WheelDirector Object;");
	//ORZ_LOG_NORMAL_MESSAGE(xmlFile);
	/*if(&xmlFile != &IDManager::BLANK)
	{
		_loader.reset(new EntityLoader());
		_loader->loadFromXML(xmlFile);
	}*/
	//_code.reset(new MyHardwareCode());
}
WheelDirector::~WheelDirector(void)
{
	
	ORZ_LOG_NORMAL_MESSAGE("Destroy a WheelDirector Object;");
}
#ifdef _GAME1
	
	void WheelDirector::enableScene(int i)
	{

		WheelData::getInstance().setLions(i);
		std::string name = "WheelScene2";
		bool second = true;
		ComponentPtr comp = Orz::ComponentFactories::getInstance().create("DataCentre");
		DataCentreInterface * data =comp->queryInterface<DataCentreInterface>();
		data->setHasTable(second);
		_scene = Orz::GameFactories::getInstance().createScene(name);
		Ogre::ConfigFile cf;
		cf.load(name + ".cfg");

		Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
		Ogre::String sec, type, arch;

		// go through all specified resource groups
		while (seci.hasMoreElements())
		{
			sec = seci.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
			Ogre::ConfigFile::SettingsMultiMap::iterator i;

			// go through all resource paths
			for (i = settings->begin(); i != settings->end(); i++)
			{
				type = i->first;
				arch = i->second;


				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);

			}
			

		}

		{
			const Ogre::ResourceGroupManager::LocationList  & list = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList("sound");

			Orz::ISoundManager::getSingleton().setResourcesPath((*list.begin())->archive->getName());
		}
		
		Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup(name);
		getWorld()->comeIn(_scene);
	}
#else
		

	void WheelDirector::enableScene(const std::string & name, bool second)
	{
		ComponentPtr comp = Orz::ComponentFactories::getInstance().create("DataCentre");
		DataCentreInterface * data =comp->queryInterface<DataCentreInterface>();
		data->setHasTable(second);
		_scene = Orz::GameFactories::getInstance().createScene(name);
		Ogre::ConfigFile cf;
		cf.load(name + ".cfg");

		Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
		Ogre::String sec, type, arch;

		// go through all specified resource groups
		while (seci.hasMoreElements())
		{
			sec = seci.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
			Ogre::ConfigFile::SettingsMultiMap::iterator i;

			// go through all resource paths
			for (i = settings->begin(); i != settings->end(); i++)
			{
				type = i->first;
				arch = i->second;


				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);

			}
			

		}

		{
			const Ogre::ResourceGroupManager::LocationList  & list = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList("sound");

			Orz::ISoundManager::getSingleton().setResourcesPath((*list.begin())->archive->getName());
		}
		
		Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup(name);
		getWorld()->comeIn(_scene);
	}

#endif
void WheelDirector::doExecute(Event * evt)
{
	switch(WheelEvents::getMsg(evt))
	{

		
	case WheelEvents::ASK_TIME:
		_logic.process_event(LogicEvent::AskTime());
		break;
	case WheelEvents::SET_TIME:
		_logic.process_event(LogicEvent::SetTime(evt->getData<int>()));
		break;
	case WheelEvents::RESET_GAME:
		_logic.process_event(LogicEvent::ResetGame());
		break;


	}
}








void WheelDirector::doEnable(void)
{
	
	Orz::IInputManager::getSingleton().addKeyListener(this);
	
	EventWorld * world = getWorld();
	
	WheelEngineInterfacePtr wheelEngine(new WheelEngine(getWorld()));
	_autoEngine.reset(new MyHardwareEngineDecorator(wheelEngine));

	WheelClockPtr clock(new WheelClock());
#ifdef _GAME1
	WheelGame::EnableSceneFunction fun = boost::bind(&WheelDirector::enableScene, this, _1);
#else
	WheelGame::EnableSceneFunction fun = boost::bind(&WheelDirector::enableScene, this, _1, _2);
#endif
	_game.reset(new WheelGame(world, _autoEngine, clock, fun));

	
	_logic.init(_game.get());
	_ui.reset(new DUI(_game->getDataServer(), _game->getGSM()->queryInterface<GSMInterface>()));
 	getWorld()->comeIn(_autoEngine);


	_keyTable = Orz::ComponentFactories::getInstance().create("F5TableKey");
	


	enableUpdate();
	ComponentPtr dataServer = _game->getDataServer();
	DataServerInterface * data =dataServer->queryInterface<DataServerInterface>();
	data->load();
	LockInterface * lock = dataServer->queryInterface<LockInterface>();
	lock->print();
	
}
bool WheelDirector::onKeyPressed(const KeyEvent & evt)
{


	switch(evt.getKey())
	{
	case Orz::KC_F1:
			
		_logic.process_event(LogicEvent::F1());
		break;
	case Orz::KC_F2:
			
		_logic.process_event(LogicEvent::F2());
		break;
	case Orz::KC_F3:
			
		_logic.process_event(LogicEvent::F3());
		break;
	case Orz::KC_F5:
			
		_logic.process_event(LogicEvent::Dan1());
		break;
	case Orz::KC_F6:
			
		_logic.process_event(LogicEvent::Dan2());
		break;
	}


	return false;
}
bool WheelDirector::onKeyReleased(const KeyEvent & evt)
{
	
	return false;
}


void WheelDirector::doDisable(void)
{
	_keyTable.reset();
	Orz::IInputManager::getSingleton().removeKeyListener(this);
	if(_scene)
	{
		getWorld()->goOut(_scene);
		_scene.reset();
	}
	getWorld()->goOut(_autoEngine);
	_autoEngine.reset();
	_logic.shutdown();
	_game.reset();
	
	_ui.reset();	
}
void WheelDirector::doFrame(unsigned int step)
{
	_ui->update(step* WORLD_UPDATE_INTERVAL);
	_game->update(step* WORLD_UPDATE_INTERVAL);
	_logic.update(step* WORLD_UPDATE_INTERVAL);
}










/////////////////////////ScoreManager//////
class WheelDirectorFactory: public IFactory<Director>
{
public:

	virtual const std::string & getTypeName() const
	{
		static const std::string name("WheelDirector");
		return name;
	}
	virtual pointer_type createInstance(const std::string& instanceName = IDManager::BLANK, parameter_type parameter = NULL)
	{
		
		return pointer_type(new WheelDirector(instanceName));
	}
};


Orz::DirectorFactoryPtr df(new WheelDirectorFactory());
extern "C" void dllStartPlugin(void)
{

	GameFactories::getInstance().addFactory(df.get()); 
	Orz::ComponentFactories::getInstance()
		.addFactory("Table", boost::factory<TableComponent *>())
		.addFactory("F5TableKey", boost::factory<TableComponentKey *>());
}

extern "C" void dllStopPlugin(void)
{
	GameFactories::getInstance().removeFactory(df.get()); 

	
	Orz::ComponentFactories::getInstance()
		.removeFactory("Table")
		.removeFactory("F5TableKey");
}
