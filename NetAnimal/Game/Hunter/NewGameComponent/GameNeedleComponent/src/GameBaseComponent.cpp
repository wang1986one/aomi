#include "GameNeedleComponentStableHeaders.h"
#include "GameBaseComponent.h"
#include "COgreSceneLoaderInterface.h"
#include "COgreCCSInterface.h"
#include "CGameBaseInterface.h"
//#include "CCSBasicCameraModes.h"
using namespace Orz;

GameBaseComponent::GameBaseComponent(void):_baseInterface(new CGameBaseInterface),_node(NULL)
{
	_baseInterface->load = boost::bind(&GameBaseComponent::load, this,  _1, _2);
	_baseInterface->getSceneNode = boost::bind(&GameBaseComponent::getSceneNode, this,  _1);
	_baseInterface->init = boost::bind(&GameBaseComponent::init, this,  _1);
	_baseInterface->setColor = boost::bind(&GameBaseComponent::setColor, this, _1, _2);


}
bool GameBaseComponent::setColor(int id, CGameBaseInterface::LIGHT_COLOR color)
{

	switch(color)
	{
	case CGameBaseInterface::Red:
		_entities2.at(id)->getSubEntity(1)->setMaterialName("t1_2r");
		break;
	case CGameBaseInterface::Yellow:
		_entities2.at(id)->getSubEntity(1)->setMaterialName("t1_2y");
		break;
	case CGameBaseInterface::Green:
		_entities2.at(id)->getSubEntity(1)->setMaterialName("t1_2g");
		break;
	case CGameBaseInterface::None:
		_entities2.at(id)->getSubEntity(1)->setMaterialName("t1_2");
		break;
	}
	return true;
	//_nodes.at(id)->
}

GameBaseComponent::~GameBaseComponent(void)
{

}

Ogre::SceneNode *  GameBaseComponent::getSceneNode(int id)
{
	if(id >= int(_nodes.size()))
		return _node;
	return _nodes2[id];
}


bool GameBaseComponent::load(int id, Ogre::SceneNode * node)
{

	if(!_node)
		return false;

	static int i = 0;

	Ogre::SceneNode * sn = _node->createChildSceneNode(node->getPosition(), node->getOrientation());
	Ogre::Entity * needle = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("base"+Ogre::StringConverter::toString(i), "D.mesh");
	sn->attachObject(needle);
	_nodes[id] = sn;
	_entities[id] = needle;


	
	_nodes2[id] =_node->createChildSceneNode(node->getPosition(), node->getOrientation());
	_entities2[id] =  Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("base_2"+Ogre::StringConverter::toString(i), "Z.mesh");;
	
	_nodes2[id]->attachObject(_entities2[id]);
	i++;
	return true;
}


bool GameBaseComponent::init(Ogre::SceneNode * node)
{
	_node = node;

	return true;
}
ComponentInterface * GameBaseComponent::_queryInterface(const TypeInfo & info) const
{

	if(info == TypeInfo(typeid(CGameBaseInterface)))
		return _baseInterface.get();
	return NULL;

}
