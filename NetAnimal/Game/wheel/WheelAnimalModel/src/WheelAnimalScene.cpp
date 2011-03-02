
#include "WheelAnimalModelStableHeaders.h"
#include "WheelAnimalGame.h"
#include "WheelEvents.h"
#include "WheelAnimalUI.h"
#include "WheelGameInterface.h"
#include "WheelAnimalScene.h"
using namespace Orz;
WheelAnimalScene::WheelAnimalScene(const std::string & name):Scene(name)
{
	
	ORZ_LOG_NORMAL_MESSAGE("Create a WheelAnimalScene Object;");
}
WheelAnimalScene::~WheelAnimalScene(void)
{
	
	ORZ_LOG_NORMAL_MESSAGE("Destroy a WheelAnimalScene Object;");
}


void WheelAnimalScene::doExecute(Event * evt)
{
	_controller->notice(evt);
	//_processManager->notice(evt);
}








void WheelAnimalScene::doEnable(void)
{
	WheelUIInterfacePtr ui(new WheelAnimalUI());
	WheelGameInterface::getSingleton().active(ui);
	_controller.reset(new WheelAnimalGame());
	enableUpdate();
	setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());
}
void WheelAnimalScene::doDisable(void)
{
	WheelGameInterface::getSingleton().active(WheelUIInterfacePtr());
	/*_processManager.reset();*/
	_controller.reset();

}
void WheelAnimalScene::doFrame(unsigned int step)
{
	_controller->update(step* WORLD_UPDATE_INTERVAL);
//	_scene->update(0.015f);
}










///////////////////////////////
class WheelAnimalSceneFactory: public IFactory<Scene>
{
public:

	virtual const std::string & getTypeName() const
	{
		static const std::string name("WheelScene");
		return name;
	}
	virtual pointer_type createInstance(const std::string& instanceName = IDManager::BLANK, parameter_type parameter = NULL)
	{
		return pointer_type(new WheelAnimalScene(instanceName));
	}
};


Orz::SceneFactoryPtr sf(new WheelAnimalSceneFactory());
extern "C" void dllStartPlugin(void)
{

	GameFactories::getInstance().addFactory(sf.get()); 
}

extern "C" void dllStopPlugin(void)
{
	GameFactories::getInstance().removeFactory(sf.get()); 
}
