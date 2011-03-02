#include "WheelScene.h"
#include "WheelGame.h"
#include "logic/AllLogic.h"
#include "WheelClock.h"
#include "WheelMediator.h"
#include "KeyEngineDecorator.h"
#include "WheelEngine.h"
#include "WheelEvents.h"
using namespace Orz;
WheelScene::WheelScene(const std::string & name):Director(name)
{
	
	ORZ_LOG_NORMAL<<"Create a WheelScene Object;";
}
WheelScene::~WheelScene(void)
{
	
	ORZ_LOG_NORMAL<<"Destroy a WheelScene Object;";
}


void WheelScene::doExecute(Event * evt)
{
}








void WheelScene::doEnable(void)
{

}
void WheelScene::doDisable(void)
{
}
void WheelScene::doFrame(void)
{

}










///////////////////////////////
class WheelSceneFactory: public IFactory<Scene>
{
public:

	virtual const std::string & getTypeName() const
	{
		static const std::string name("WheelScene");
		return name;
	}
	virtual pointer_type createInstance(const std::string& instanceName = IDManager::BLANK, parameter_type parameter = NULL)
	{
		return pointer_type(new WheelScene(instanceName));
	}
};


Orz::SceneFactoryPtr sf(new WheelSceneFactory());
extern "C" void dllStartPlugin(void)
{

	GameFactories::getInstance().addFactory(sf.get()); 
}

extern "C" void dllStopPlugin(void)
{
	GameFactories::getInstance().removeFactory(sf.get()); 
}
