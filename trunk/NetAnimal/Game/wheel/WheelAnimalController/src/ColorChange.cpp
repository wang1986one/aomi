#include "WheelAnimalControllerStableHeaders.h"
								

#include "ColorChange.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include "ThirdParty/Ofusion/OgreOSMScene.h"
using namespace Orz;
ColorChange::ColorChange(Ogre::SceneNode * node):_node(node)
{

		
	_osm.reset(new OSMScene(OgreGraphicsManager::getSingleton().getSceneManager(), OgreGraphicsManager::getSingleton().getRenderWindow()));
	_osm->initialise("xuanzhuangdeng.osm");
	_osm->createScene(_node);
	_animation = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createAnimationState("leyuan_tx_ufolightdz");
	_animation->setEnabled(true);	 
	clear();
	
}
void ColorChange::clear(void)
{
	OSMScene::EntityList& entities = _osm->getEntityList();
	OSMScene::EntityList::iterator it = entities.begin();
	for(; it != entities.end(); ++it)
	{
		if((*it)->getName() == "leyuan_tx_ufolight")
			(*it)->setMaterialName("leyuan_tx_ufolight");
		else
			(*it)->setMaterialName("xuanzhuandeng1");
	
	}
	_node->setVisible(false);
	if(_rise)
		_rise->clear();
}
SomethingRise * ColorChange::getRise(float speed)
{
	_node->setVisible(true);
	if(!_rise)
		_rise.reset(new SomethingRise(300, speed, _node));

	return _rise.get();
}
void ColorChange::update(TimeType interval)
{
	_animation->addTime(interval);
}
void ColorChange::stop( WheelEnum::LIGHT_COLOR color)
{
	OSMScene::EntityList& entities = _osm->getEntityList();
	OSMScene::EntityList::iterator it = entities.begin();
	std::string m1,m2;
	if(color == Orz::WheelEnum::Yellow)
	{
		m1 = "xuanzhuandeng_y";
		m2 = "leyuan_tx_ufolight_y";
	}
	else if(color == Orz::WheelEnum::Green)
	{
		m1 = "xuanzhuandeng_g";	  
		m2 = "leyuan_tx_ufolight_g";
	}	else if(color == Orz::WheelEnum::Red)
	{
		m1 = "xuanzhuandeng_r";	 
		m2 = "leyuan_tx_ufolight_r";
	}
	for(; it != entities.end(); ++it)
	{
		if((*it)->getName() == "leyuan_tx_ufolight")
			(*it)->setMaterialName(m2);
		else
			(*it)->setMaterialName(m1);
		std::cout<<(*it)->getName()<<std::endl;
	}
}