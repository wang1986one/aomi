#include "SanControllerBaseStableHeaders.h"
//#include "SanArmyComponent.h"
//
//#include "CGameActionInterface.h"
//#include "AllCInterface.h"
//using namespace Orz;
//SanArmyComponent::SanArmyComponent(void):_actionInterface(new CGameActionInterface()),_isWinner(false),_armyInterface(new CSanArmyInterface())
//{
//	_playerComp = ComponentFactories::getInstance().create("OgrePlayer");
//
//
//
//	static int i = 0;
//	
//	COgreEntityInterface * entity = _playerComp->queryInterface<COgreEntityInterface>();
//	entity->load(boost::lexical_cast<std::string>(i++)+"Army", "Body_ZGL.mesh"/*, sn*/);
//	
//	entity->setDefaultAnimation("idel");
//
//	_actionInterface->activate = boost::bind(&SanArmyComponent::activate, this, _1);
//
//	_armyInterface->setWinner =  boost::bind(&SanArmyComponent::setWinner, this, _1);
//}
//
//void SanArmyComponent::setWinner(bool isWinner)
//{
//	_isWinner = isWinner;
//}
//bool SanArmyComponent::activate(SanProcess process, SanWinMode winMode)
//{
//	if(process == PROCESS_START)
//	{
//		COgreAnimationInterface * animation = _playerComp->queryInterface< COgreAnimationInterface >();
//		_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "idel", 0);
//		_actionInterface->disable = animation->disable;
//		_actionInterface->update = animation->update;
//		return true;
//	}	
//
//
//	if(process == PROCESS_WIN && _isWinner)
//	{
//		COgreAnimationInterface * animation = _playerComp->queryInterface< COgreAnimationInterface >();
//		_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "win", 1);
//		_actionInterface->disable = animation->disable;
//		_actionInterface->update = animation->update;
//		return true;
//	}	
//	return false;
//}
//SanArmyComponent::~SanArmyComponent(void)
//{
//	
//}
//ComponentInterface * SanArmyComponent::_queryInterface(const TypeInfo & info)
//{
//	if(info == TypeInfo(typeid(CGameActionInterface)))
//	{
//		return _actionInterface.get();
//	}else if(info == TypeInfo(typeid(CSanArmyInterface)))
//	{
//		return _armyInterface.get();
//	}
//	return _playerComp->_queryInterface(info);
//}