#include "SanControllerBaseStableHeaders.h"
#include "ZhugeLiangComponent.h"

#include "CGameActionInterface.h"
#include "AllCInterface.h"
using namespace Orz;
ZhugeLiangComponent::ZhugeLiangComponent(void):_actionInterface(new CGameActionInterface())
{
	_playerComp = ComponentFactories::getInstance().create("OgrePlayer");



	static int i = 0;


	COgreEntityInterface * entity = _playerComp->queryInterface<COgreEntityInterface>();
	entity->load(boost::lexical_cast<std::string>(i++)+"Zhuge", "Body_ZGL.mesh"/*, sn*/);
	
	entity->setDefaultAnimation("idel");

	_actionInterface->activate = boost::bind(&ZhugeLiangComponent::activate, this, _1);


}
bool enable()
{
 return true;
}

void disable()
{

}
bool update(TimeType)
{
	return true;
}

bool ZhugeLiangComponent::activate(SanProcess process)
{
	//if(process == PROCESS_START)
	//{
	//	COgreAnimationInterface * animation = _playerComp->queryInterface< COgreAnimationInterface >();
	//	_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "idel", 0);
	//	_actionInterface->disable = animation->disable;
	//	_actionInterface->update = animation->update;
	//	return true;
	//}	


	//if(process == PROCESS_PRORUN)
	//{
	//	COgreAnimationInterface * animation = _playerComp->queryInterface< COgreAnimationInterface >();
	//	_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "play", 1);
	//	_actionInterface->disable = animation->disable;
	//	_actionInterface->update = animation->update;
	//	return true;
	//}	

	//if(process == PROCESS_WIN)
	//{
	//	COgreAnimationInterface * animation = _playerComp->queryInterface< COgreAnimationInterface >();
	//	_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "win", 1);
	//	_actionInterface->disable = animation->disable;
	//	_actionInterface->update = animation->update;
	//	return true;
	//}	
	return false;
}
ZhugeLiangComponent::~ZhugeLiangComponent(void)
{
	
}
ComponentInterface * ZhugeLiangComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(CGameActionInterface)))
	{
		return _actionInterface.get();
	}
	return _playerComp->_queryInterface(info);
}