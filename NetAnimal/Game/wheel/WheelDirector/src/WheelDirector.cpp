
#include "WheelDirectorStableHeaders.h"
#include "WheelDirector.h"
#include "WheelGame.h"
#include "logic/AllLogic.h"
#include "WheelClock.h"
#include "WheelMediator.h"
#include "KeyEngineDecorator.h"
#include "WheelEngine.h"
#include "WheelEvents.h"
#include "EntityLoader.h"
#include "HardwareEngineDecorator.h"
#include "AutoEngineDecorator.h"
#include "SetupUI.h"
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
	//case WheelEvents::SET_MODE:
	//	_logic.process_event(LogicEvent::SetMode());
	//	break;
	case WheelEvents::ASK_STATE:
		_logic.process_event(LogicEvent::AskState());
		break;
	case WheelEvents::COME_IN_MENU:
		_logic.process_event(LogicEvent::ComeInMenu());
		break;
	case WheelEvents::COME_IN_SETUP:
		_logic.process_event(LogicEvent::ComeInSetup());
		break;
	case WheelEvents::RESET_GAME:
		_logic.process_event(LogicEvent::ResetGame());
		break;
	case WheelEvents::DATA_MENU:
		_logic.process_event(LogicEvent::DataMenu());
		break;
	case WheelEvents::GO_OUT_MENU:
		_logic.process_event(LogicEvent::GoOutMenu());
		break;
	case WheelEvents::KEY_F5:
		_logic.process_event(LogicEvent::ActionTwo());
		break;
	case WheelEvents::KEY_F6:
		_logic.process_event(LogicEvent::ActionThree());
		break;
	case WheelEvents::KEY_F4:
		_logic.process_event(LogicEvent::ActionOne());
		break;
	case WheelEvents::HARDWARE_RETURN:
		_logic.process_event(LogicEvent::HardwareReturn(evt->getData<bool>()));
		break;

	}
}








void WheelDirector::doEnable(void)
{

	//_mediator.reset(new WheelMediator());
	
	EventWorld * world = getWorld();
	HardwarePtr hardware(new Hardware());
	WheelEngineInterfacePtr wheelEngine(new WheelEngine(getWorld()));
	WheelEngineInterfacePtr keyEngine(new KeyEngineDecorator(wheelEngine));
	//WheelEngineInterfacePtr engine(new HardwareEngineDecorator(keyEngine));
	_autoEngine.reset(new AutoEngineDecorator(wheelEngine));
	WheelClockPtr clock(new WheelClock());
	SetupUIPtr setup(new SetupUI());
	_game.reset(new WheelGame(world, setup, hardware, _autoEngine, clock));
	getWorld()->comeIn(_scene);
	getWorld()->comeIn(_autoEngine);

	//_game->doEnable(getWorld());
	_logic.init(_game.get());

	enableUpdate();
}
void WheelDirector::doDisable(void)
{
	getWorld()->goOut(_scene);
	getWorld()->goOut(_autoEngine);
	_autoEngine.reset();
	_logic.shutdown();
	_game.reset();
}
void WheelDirector::doFrame(unsigned int step)
{
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
