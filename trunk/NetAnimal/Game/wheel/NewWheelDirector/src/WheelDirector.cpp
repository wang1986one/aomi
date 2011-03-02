
#include "NewWheelDirectorStableHeaders.h"
#include "WheelDirector.h"
#include "WheelGame.h"
#include "logic/AllLogic.h"
#include "WheelClock.h"
#include "KeyEngineDecorator.h"
#include "WheelEngine.h"
#include "WheelEvents.h"
#include "EntityLoader.h"
#include "AutoEngineDecorator.h"
#include "NewHardware.h"
#include "NewHardwareEngineDecorator.h"
#include "NewHardwareCode.h"
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
	_scene = Orz::GameFactories::getInstance().createScene("WheelScene");
	_code.reset(new NewHardwareCode());
}
WheelDirector::~WheelDirector(void)
{
	
	ORZ_LOG_NORMAL_MESSAGE("Destroy a WheelDirector Object;");
}


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
	case WheelEvents::HOW_WINNER:
		_logic.process_event(LogicEvent::HowWin());
		break;
	case WheelEvents::FIND_SC:
		_logic.process_event(LogicEvent::FindSC());
		break;

	case WheelEvents::RESET_GAME:
		_logic.process_event(LogicEvent::ResetGame());
		break;


	}
}








void WheelDirector::doEnable(void)
{

	//_mediator.reset(new WheelMediator());
	
	EventWorld * world = getWorld();
	//NewHardwarePtr hardware(new NewHardware());
	WheelEngineInterfacePtr wheelEngine(new WheelEngine(getWorld()));
	//WheelEngineInterfacePtr keyEngine(new KeyEngineDecorator(wheelEngine));
	WheelEngineInterfacePtr engine(new NewHardwareEngineDecorator(wheelEngine));
	//_autoEngine.reset(new AutoEngineDecorator(wheelEngine));
	WheelClockPtr clock(new WheelClock());
	_game.reset(new WheelGame(world, /*hardware,*/ engine, clock));
	getWorld()->comeIn(_scene);
	//getWorld()->comeIn(_autoEngine);

	//_game->doEnable(getWorld());
	_logic.init(_game.get());

	enableUpdate();
}
void WheelDirector::doDisable(void)
{
	getWorld()->goOut(_scene);
//	getWorld()->goOut(_autoEngine);
	_autoEngine.reset();
	_logic.shutdown();
	_game.reset();
}
void WheelDirector::doFrame(unsigned int step)
{
	_code->update();
	_game->update(step* WORLD_UPDATE_INTERVAL);
	_logic.update(step* WORLD_UPDATE_INTERVAL);
}










///////////////////////////////
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
		/*if(parameter)
		{
			NameValueList::iterator it = (*parameter).find("XML_FILE");
			if(it != parameter->end())
				return pointer_type(new WheelDirector(instanceName, VariantData<std::string>::get(it->second)));
		}*/
		
		return pointer_type(new WheelDirector(instanceName));
	}
};


Orz::DirectorFactoryPtr df(new WheelDirectorFactory());
extern "C" void dllStartPlugin(void)
{

	GameFactories::getInstance().addFactory(df.get()); 
}

extern "C" void dllStopPlugin(void)
{
	GameFactories::getInstance().removeFactory(df.get()); 
}
