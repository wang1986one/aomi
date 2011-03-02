
#include "NewGameComponentsStableHeaders.h"	
#include "AnimalProcessComponent.h"	

#include "COgreEntityInterface.h"	
#include "CGameActionInterface.h"	
#include "CAnimalProcessInterface.h"	
#include "COgreAnimationInterface.h"

using namespace Orz;


void AnimalProcessComponent::callback(int times)
{
	if(times >= 1)
	switch(_type.first)
	{
	case 0:
	Orz::ISoundManager::getSingleton().quickPlay("Panda.wav");
		break;

	case 1:
	Orz::ISoundManager::getSingleton().quickPlay("tiger.wav");
		break;

	case 2:
	Orz::ISoundManager::getSingleton().quickPlay("elephant.wav");
		break;

	case 3:
	Orz::ISoundManager::getSingleton().quickPlay("crocodile.wav");
		break;

	}
}
AnimalProcessComponent::AnimalProcessComponent(void):_isWinner(false),_actionInterface(new CGameActionInterface),_animalInterface(new CAnimalProcessInterface),_type()
{
	_entityComp = ComponentFactories::getInstance().create("OgreEntity");

	COgreAnimationInterface * animation = _entityComp->queryInterface< COgreAnimationInterface >();
	animation->_callback = boost::bind(&AnimalProcessComponent::callback, this, _1);

	_actionInterface->activate = boost::bind(&AnimalProcessComponent::activate, this, _1);
	_animalInterface->setIsWinner =  boost::bind(&AnimalProcessComponent::setWinner, this, _1);
	_animalInterface->init =  boost::bind(&AnimalProcessComponent::init, this, _1, _2);
	_animalInterface->getType =  boost::bind(&AnimalProcessComponent::getType, this);
	

	//	typedef boost::function<void (int, Ogre::SceneNode *)> InitFunction;
	//	typedef boost::function<void (ComponentPtr comp)> SetIsWinnerFunction;
	//public:
	//	InitFunction init;
	//	SetIsWinnerFunction setIsWinner;
}
AnimalProcessComponent::~AnimalProcessComponent(void)
{

}
ComponentInterface * AnimalProcessComponent::_queryInterface(const TypeInfo & info)
{
	if(info == TypeInfo(typeid(CAnimalProcessInterface)))
		return _animalInterface.get();
	if(info == TypeInfo(typeid(CGameActionInterface)))
		return _actionInterface.get();


	return NULL;
}
bool no_update(TimeType i)
{
	return false;
}

bool AnimalProcessComponent::activate(SanProcess process)
{


	if(process == PROCESS_START)
	{

	if(this->_type.second == Orz::AnimalEnum::KING)
		return false;
		COgreAnimationInterface * animation = _entityComp->queryInterface< COgreAnimationInterface >();
		_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "idel", 0);
		_actionInterface->disable = animation->disable;
		_actionInterface->update = animation->update;
		return true;
	}	

	if(process == PROCESS_END)
	{
		return false;
	}	
	//
	//if(process == PROCESS_RUN)
	//{
	//	COgreAnimationInterface * animation = _entityComp->queryInterface< COgreAnimationInterface >();
	//	_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "play", 3);
	//	_actionInterface->disable = animation->disable;
	//	_actionInterface->update = animation->update;
	//	return true;
	//}	

	if(process == PROCESS_PLAY && _isWinner)
	{
		COgreAnimationInterface * animation = _entityComp->queryInterface< COgreAnimationInterface >();
		if(_type.first != 3)
			_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "play", 3);
		else
			_actionInterface->enable = boost::bind(&COgreAnimationInterface::enable, animation, "idel", 3);
		_actionInterface->disable = animation->disable;
		_actionInterface->update = animation->update;
		return true;
	}	
	return false;
}

bool AnimalProcessComponent::init(AnimalEnum::ANIMAL_TYPE type, Ogre::SceneNode * node)
{
	_type = type;
	static int i = 0;

	COgreEntityInterface * entity = _entityComp->queryInterface<COgreEntityInterface>();
	switch(type.first)
	{
	case 0:
		entity->load(boost::lexical_cast<std::string>(i++)+"Animal", "Panda.mesh", node);
		entity->getSceneNode()->setScale(Ogre::Vector3::UNIT_SCALE * 2.3f);
		break;
	case 1:
		entity->load(boost::lexical_cast<std::string>(i++)+"Animal", "Tiger.mesh", node);
		entity->getSceneNode()->setScale(Ogre::Vector3::UNIT_SCALE * 2.3f);
		break;
	case 2:
		entity->load(boost::lexical_cast<std::string>(i++)+"Animal", "Elephant.mesh", node);
		break; 
	case 3:
		entity->load(boost::lexical_cast<std::string>(i++)+"Animal", "Crocodile.mesh", node);
		break;
	}
	if(type.second == Orz::AnimalEnum::KING)
	{
		entity->getEntity()->setMaterialName("Ogre/Earring");
	}
	entity->getSceneNode()->translate(0,10, 0);
	return true;
}

AnimalEnum::ANIMAL_TYPE AnimalProcessComponent::getType(void) const
{
	return _type;
	/*= type;
	static int i = 0;

	COgreEntityInterface * entity = _entityComp->queryInterface<COgreEntityInterface>();
	entity->load(boost::lexical_cast<std::string>(i++)+"Animal", "OgreHead.mesh", node);


	return true;*/
}
void AnimalProcessComponent::setWinner(bool isWinner)
{
	_isWinner = isWinner;
}