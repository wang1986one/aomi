#include "GameNeedleComponentStableHeaders.h"
#include "GameFlowerComponent.h"
#include "COgreEntityInterface.h"
#include "COgreAnimationInterface.h"
using namespace Orz;

GameFlowerComponent::GameFlowerComponent(void):_flowerInterface(new CGameFlowerInterface)
{
	_flowerInterface->load = boost::bind(&GameFlowerComponent::load, this,  _1);

	_flowerInterface->enable = boost::bind(&GameFlowerComponent::enable, this,  _1);
	_flowerInterface->reset = boost::bind(&GameFlowerComponent::reset, this);


	for (int i=0;i<_entityComp.size();i++)
	{
		_entityComp[i] = ComponentFactories::getInstance().create("OgreEntity");
	}




	_colours.push_back(Ogre::ColourValue(1, 1, 1));
	_colours.push_back(Ogre::ColourValue(1, 0.5f, 0.5f));
	_colours.push_back(Ogre::ColourValue(0.5f, 1, 0.5f));
	_colours.push_back(Ogre::ColourValue(0.5f, 0.5f, 1));
}

GameFlowerComponent::~GameFlowerComponent(void) 
{

}


bool GameFlowerComponent::enable(CGameFlowerInterface::Action action)
{

	_currTime = 0.f;
	switch(action)
	{
	case CGameFlowerInterface::RunColor:
		{
			_flowerInterface->update = boost::bind(&GameFlowerComponent::update, this,  _1);
		}
		break;
	case CGameFlowerInterface::SetRed:
			flowerlight->setMaterialName("guan_red");
		break;
	case CGameFlowerInterface::SetYellow:
			flowerlight->setMaterialName("guan_yellow");
		break;
	case CGameFlowerInterface::SetGreen:
			flowerlight->setMaterialName("guan_green");
		break;
	case CGameFlowerInterface::GoUp:
		{
			COgreAnimationInterface * ai;
			for (int i=0;i<_entityComp.size();i++)
			{
				ai= _entityComp[i]->queryInterface<COgreAnimationInterface>();
					ai->enable("idel",1);
			}
			_flowerInterface->update = boost::bind(&GameFlowerComponent::updateGoUp, this,  _1);
		}
		break;


	}
	return true;
}
bool GameFlowerComponent::update(TimeType i)
{
	if(_currTime >= _colours.size() )
	{
		_currTime -= _colours.size();
	}


	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	int floor = Ogre::Math::IFloor(_currTime);
	int ceil = Ogre::Math::ICeil(_currTime);

	if(ceil == floor)
	{ 
		sm->setAmbientLight(_colours.at(ceil));
	}else
	{
		Ogre::ColourValue begin = _colours.at(floor);
		Ogre::ColourValue end;// = _colours.at(ceil);
		if(ceil == _colours.size())
		{
			end = *_colours.begin();
		}else
		{
			end = _colours.at(ceil);
		}
		float alpha = _currTime - float(floor);

		Ogre::ColourValue c = begin*(1 - alpha)+ end* alpha;

		sm->setAmbientLight(c);
	}
	_currTime += i;

	return false;
}
bool GameFlowerComponent::updateGoUp(TimeType i)
{
		COgreAnimationInterface* ai;
		if(_currTime>0.67)
		{
			flowerlight->setVisible(true);
			//enable(CGameFlowerInterface::RunColor);
			return false;
		}
		else
		{
			for (int j=0;j<_entityComp.size();j++)
			{
				ai= _entityComp[j]->queryInterface<COgreAnimationInterface>();
					ai->update(i);
			}
		}
		_currTime+=i;
		return true;
}
void GameFlowerComponent::reset(void)
{
	COgreAnimationInterface * ai;
	ai= _entityComp[0]->queryInterface<COgreAnimationInterface>();

		flowerlight->setVisible(false);

	for(int i=0;i<_entityComp.size();i++)
	{
		ai= _entityComp[i]->queryInterface<COgreAnimationInterface>();
			ai->disable();
	}


}
bool GameFlowerComponent::load(Ogre::SceneNode * node)
{

	COgreEntityInterface * entity;
	for (int i=0;i<_entityComp.size();i++)
	{
		entity= _entityComp[i]->queryInterface<COgreEntityInterface>();
		entity->load("Flower"+Ogre::StringConverter::toString(i), "zzf0"+Ogre::StringConverter::toString(i)+".mesh", node->createChildSceneNode(Ogre::Vector3(0, -0 , 0)));
	}
	flowerlight = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("hualight1","hualight.mesh");
	node->createChildSceneNode(Ogre::Vector3(0, -0 , 0))->attachObject(flowerlight);
	flowerlight->setVisible(false);
	return true;
}
ComponentInterface * GameFlowerComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(CGameFlowerInterface)))
		return _flowerInterface.get();
	return NULL;

}
