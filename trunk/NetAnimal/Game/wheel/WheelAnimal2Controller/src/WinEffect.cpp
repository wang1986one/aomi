#include "WheelAnimalControllerStableHeaders.h"
#include "WinEffect.h"
#include "ThirdParty/Ofusion/OgreOSMScene.h"
#include "Ogre/OgreRibbonTrail.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
//#include "WheelDB.h"
using namespace Orz;

inline static void GetNode(Ogre::SceneNode ** node, /*WheelEnum e,*/const std::string & name, boost::shared_ptr<WheelAnimalSceneObj> scene)
{
	if(OgreGraphicsManager::getSingleton().getSceneManager()->hasSceneNode(name))
	{
		(*node) = OgreGraphicsManager::getSingleton().getSceneManager()->getSceneNode(name);
	}else
	{
		(*node) = OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode();
	}
}
WinEffect::WinEffect(boost::shared_ptr<WheelAnimalSceneObj> scene):_effect(0),_billboardIsload(false)
{


	GetNode(&_leyuan_tx_caitiao, "leyuan_tx_caitiao",scene);
	GetNode(&_leyuan_tx_bluehua, "leyuan_tx_bluehua",scene);
	GetNode(&_leyuan_tx_caijinyanhua1, "leyuan_tx_caijinyanhua1",scene);
	GetNode(&_leyuan_tx_caijinyanhua2, "leyuan_tx_caijinyanhua2",scene);
	GetNode(&_zp_ptj1a, "zp_ptj1a",scene);
	GetNode(&_zp_ptj1b, "zp_ptj1b",scene);
	
	

	_sceneAnimation = scene->getSceneAnimation(SCENE_ANIMATION_1);
	_starAnimation = scene->getSceneAnimation(SCENE_ANIMATION_4);
	
	_sceneAnimation->setLoop(false);	
	_sceneAnimation->setEnabled(true);
	
	
	_starAnimation->setLoop(true);
	_starAnimation->setEnabled(true);

	clear();
}


void WinEffect::show(Effect effect)
{
	_effect |= effect;
}

void WinEffect::hideEffect()
{
	_leyuan_tx_caitiao->setVisible(false);

	_leyuan_tx_bluehua->setVisible(false);

	_leyuan_tx_caijinyanhua1->setVisible(false);

	_leyuan_tx_caijinyanhua2->setVisible(false);

	_zp_ptj1a->setVisible(false);

	_zp_ptj1b->setVisible(false);
}



void WinEffect::clear(void)
{

	
	Ogre::MaterialPtr material = Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("Standard_7"));
	material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("guang.bmp");

	_leyuan_tx_caitiao->setVisible(false);

	_leyuan_tx_bluehua->setVisible(false);

	_leyuan_tx_caijinyanhua1->setVisible(false);

	_leyuan_tx_caijinyanhua2->setVisible(false);

	_zp_ptj1a->setVisible(false);

	_zp_ptj1b->setVisible(false);
	
	
	_sceneAnimation->setEnabled(true);
	_sceneAnimation->setTimePosition(0.f);

	_starAnimation->setEnabled(true);
	_starAnimation->setTimePosition(0.f);

	_effect = 0;
	_reset();
}

//ÐÇÐÇ×·Î²ÌØÐ§
void WinEffect::setupTrailStars(void)
{

		Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();

	/*	Ogre::Vector3 dir(-1, -1, 0.5);
		dir.normalise();
		Ogre::Light* l = sm->createLight("light1");
		l->setType(Ogre::Light::LT_DIRECTIONAL);
		l->setDirection(dir);*/

		Ogre::NameValuePairList pairList;
		pairList["numberOfChains"] = "2";
		pairList["maxElements"] = "50";
		
		Ogre::RibbonTrail* trail = static_cast<Ogre::RibbonTrail*>(sm->createMovableObject("1","RibbonTrail", &pairList));
		trail->setMaterialName("Examples/LightRibbonTrail");
		trail->setTrailLength(600);

		Ogre::RibbonTrail* trail2 = static_cast<Ogre::RibbonTrail*>(sm->createMovableObject("2","RibbonTrail", &pairList));
		trail2->setMaterialName("Examples/LightRibbonTrail");
		trail2->setTrailLength(600);


		sm->getRootSceneNode()->createChildSceneNode()->attachObject(trail);
		sm->getRootSceneNode()->createChildSceneNode()->attachObject(trail2);


		trail->setInitialColour(0, 1.0f,1.0f, 0.1f);
		trail->setColourChange(0, 1.0f, 1.0f, 1.0f, 1.0f);
		trail->setInitialWidth(0, 80);
		trail->setWidthChange(0,135);
		trail->addNode(_zp_ptj1a);

		trail2->setInitialColour(0, 1.0f, 1.0f, 0.1f);
		trail2->setColourChange(0, 1.0f, 1.0f, 1.0f, 1.0f);
		trail2->setInitialWidth(0, 80);
		trail2->setWidthChange(0,135);
		trail2->addNode(_zp_ptj1b);

		//// Add light
		//Ogre::Light* l1 = sm->createLight("l1");
		//l1->setDiffuseColour(trail->getInitialColour(0));
		//_zp_ptj1a->attachObject(l1);

		//// Add billboard
		//Ogre::BillboardSet* bbs = sm->createBillboardSet("bb", 1);
		//bbs->createBillboard(Ogre::Vector3::ZERO, trail->getInitialColour(0));
		//bbs->setMaterialName("Examples/Flare");
		//_zp_ptj1a->attachObject(bbs);


		//// Add light
		//Ogre::Light* l2 = sm->createLight("l2");
		//l2->setDiffuseColour(trail->getInitialColour(0));
		//_zp_ptj1b->attachObject(l2);

		//// Add billboard
		//Ogre::BillboardSet* bbs2 = sm->createBillboardSet("bb2", 1);
		//bbs2->createBillboard(Ogre::Vector3::ZERO, trail->getInitialColour(0));
		//bbs2->setMaterialName("Examples/Flare");
		//_zp_ptj1b->attachObject(bbs2);

}


void WinEffect::enable(void)
{
	if(_effect & Effect4)
	{
	
		_sceneAnimation->setEnabled(true);   
		_sceneAnimation->setTimePosition(0.f);
	
	
		_leyuan_tx_caijinyanhua1->setVisible(true);
	
		_leyuan_tx_caijinyanhua2->setVisible(true);
		Ogre::MaterialPtr material = Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("Standard_7"));
		material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("black.png");
	}
	if(_effect & Effect2)
	{
			_leyuan_tx_caitiao->setVisible(true);
	}	
	if(_effect & Effect3)
	{
			_leyuan_tx_bluehua->setVisible(true);
	}

	if(_effect & Effect1)
	{
		if(_billboardIsload == false)
		{
			setupTrailStars();
			_billboardIsload = true;
		}
		_starAnimation->setEnabled(true);
		_starAnimation->setTimePosition(0.f);

		
		_zp_ptj1a->setVisible(true);
		_zp_ptj1b->setVisible(true);

		
	}
}



bool WinEffect::update(TimeType interval)
{

	_update2enable();
	if(_effect & Effect4)
	{
		_sceneAnimation->addTime(interval);
		return !_sceneAnimation->hasEnded();
	}

	
	if(_effect & Effect1)
	{
		_starAnimation->addTime(interval);
	}
	//_sn->yaw(Ogre::Radian(1.f));
  //  _animation->addTime(interval);
	return false;
}
WinEffect::~WinEffect(void)
{
	
}
