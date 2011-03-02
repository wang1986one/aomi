#include "WheelAnimalControllerStableHeaders.h"
#include "Gold.h"
#include "ThirdParty/Ofusion/OgreOSMScene.h"
using namespace Orz;
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
Gold::Gold(Ogre::SceneNode * node):_sn(node)
{
	_sn->scale(1.5f,1.5f,1.5f);
	_sn->translate(10.f, 40.f, -30.f);
	_osm.reset(new OSMScene(OgreGraphicsManager::getSingleton().getSceneManager(), OgreGraphicsManager::getSingleton().getRenderWindow()));
	_osm->initialise("gold.osm");
	_osm->createScene(_sn);
	_animation = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createAnimationState("leyuan_tx_caijin");
	_animation->setEnabled(true);	
	_animation->setLoop(true);	


	//_osm2.reset(new OSMScene(OgreGraphicsManager::getSingleton().getSceneManager(), OgreGraphicsManager::getSingleton().getRenderWindow()));
	//
	//_osm->initialise("gold.osm");
	//_osm->createScene(_sn);

	_materials.push_back( Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("leyuan_tx_caijin_shuzi04")));
	_materials.push_back( Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("leyuan_tx_caijin_shuzi03")));
	_materials.push_back( Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("leyuan_tx_caijin_shuzi02")));
	_materials.push_back( Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("leyuan_tx_caijin_shuzi01")));
	_materials.push_back( Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("leyuan_tx_caijin_shuzi00")));
	_number[0] = "leyuan_tx_caijin_shuzi0.png";
	_number[1] = "leyuan_tx_caijin_shuzi1.png";
	_number[2] = "leyuan_tx_caijin_shuzi2.png";
	_number[3] = "leyuan_tx_caijin_shuzi3.png";
	_number[4] = "leyuan_tx_caijin_shuzi4.png";
	_number[5] = "leyuan_tx_caijin_shuzi5.png";
	_number[6] = "leyuan_tx_caijin_shuzi6.png";
	_number[7] = "leyuan_tx_caijin_shuzi7.png";
	_number[8] = "leyuan_tx_caijin_shuzi8.png";
	_number[9] = "leyuan_tx_caijin_shuzi9.png";
	hide();
}

Gold::~Gold(void)
{
	
}

void Gold::setNumber(int i)
{
	std::vector<Ogre::MaterialPtr>::iterator it;
	for(it = _materials.begin(); it != _materials.end(); ++it)
	{
		(*it)->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(_number[i%10]);
		i/=10;
	}
}
void Gold::clear(void)
{
	_animation->setTimePosition(0.f);
}
void Gold::show(void)
{
	_sn->setVisible(true);
}
void Gold::hide(void)
{
	_sn->setVisible(false);
}

void Gold::update(TimeType interval)
{
	_animation->addTime(interval);
}