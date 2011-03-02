#include "WheelAnimalControllerStableHeaders.h"
#include "TV.h"
#include "ThirdParty/Ofusion/OgreOSMScene.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
using namespace Orz;


TV::TV(Ogre::SceneNode * sn):_sn(sn)
{
	_osm.reset(new OSMScene(OgreGraphicsManager::getSingleton().getSceneManager(), OgreGraphicsManager::getSingleton().getRenderWindow()));
	_osm->initialise("zp_dianshi.osm");
	_osm->createScene(_sn);
	_sn->scale(Ogre::Vector3(6.5f, 6.5f, 6.5f));
	_sn->setVisible(false);
	setNumber(0);
}
void TV::clear(void)
{
	
	_sn->setVisible(false);
	if(_rise)
		_rise->clear();
}


void TV::setNumber(int i)
{
	OSMScene::EntityList& entities = _osm->getEntityList();
	OSMScene::EntityList::iterator it = entities.begin();
	for(; it != entities.end(); ++it)
	{
		if((*it)->getName() == "zp_dianshi_ziti")
			(*it)->setMaterialName("zp_dianshi_ziti" + Ogre::StringConverter::toString(i));
		
	}
}

SomethingRise * TV::getRise(float speed)
{
	_sn->setVisible(true);
	if(!_rise)
		_rise.reset(new SomethingRise(150, speed, _sn));

	return _rise.get();
}

TV::~TV(void)
{

}