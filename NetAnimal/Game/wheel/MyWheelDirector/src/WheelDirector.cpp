
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
#include "F5TableComponent.h"
#include "F5TableComponentKey.h"
#include "DataServerInterface.h"
#include "LockInterface.h"
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

void WheelDirector::enableScene(const std::string & name, bool second)
{
	WinData::getInstance().setSecondWinner(second);
	_scene = Orz::GameFactories::getInstance().createScene(name);
	// load resource paths from config file
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

			//Ogre::ResourceGroupManager::getSingleton().addResourceLocation("D:/Test", "FileSystem", "General");
		}
		

	}

	{
		const Ogre::ResourceGroupManager::LocationList  & list = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList("sound");

		Orz::ISoundManager::getSingleton().setResourcesPath((*list.begin())->archive->getName());
	}
	
	Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup(name);
	getWorld()->comeIn(_scene);
}

void WheelDirector::doExecute(Event * evt)
{
	switch(WheelEvents::getMsg(evt))
	{

		
	case WheelEvents::CLICK_BUTTON:
		{
			intX2 intx2 = evt->getData<intX2>();
			_logic.process_event(LogicEvent::ClickButton(intx2.get<0>(), intx2.get<1>()));
		}
		break;
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
	//enableScene("WheelScene");
	
	EventWorld * world = getWorld();
	
	WheelEngineInterfacePtr wheelEngine(new WheelEngine(getWorld()));
	_autoEngine.reset(new MyHardwareEngineDecorator(wheelEngine));

	WheelClockPtr clock(new WheelClock());
	boost::function< void (const std::string & , bool) > fun = boost::bind(&WheelDirector::enableScene, this, _1, _2);
	_game.reset(new WheelGame(world, _autoEngine, clock, fun));

	
	_logic.init(_game.get());
	_ui.reset(new DUI(_game->getDataServer()));
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

	if(evt.getKey() == Orz::KC_F5)
	{
		_logic.process_event(LogicEvent::Dan1());
	}
	if(evt.getKey() == Orz::KC_F6)
	{
		_logic.process_event(LogicEvent::Dan2());
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
		.addFactory("F5Table", boost::factory<F5TableComponent *>())
		.addFactory("F5TableKey", boost::factory<F5TableComponentKey *>());
}

extern "C" void dllStopPlugin(void)
{
	GameFactories::getInstance().removeFactory(df.get()); 

	
	Orz::ComponentFactories::getInstance()
		.removeFactory("F5Table")
		.removeFactory("F5TableKey");
}
