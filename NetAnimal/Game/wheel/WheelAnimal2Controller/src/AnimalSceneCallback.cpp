#include "WheelAnimalControllerStableHeaders.h"
#include "AnimalSceneCallback.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
//#include "WheelDB.h"
#include <boost/regex.hpp>

const boost::regex expression("new_zp_zikz");
const boost::regex expression2("new_zp_dzkz([0-9]+)");
const boost::regex expression5("zp_cj_erci([0-9]+)");


const boost::regex expression4("dr([0-9]+)");
const boost::regex expression3("zp_cj_sans([0-9]+)");

using namespace Orz;

bool AnimalSceneCallback::check(bool fill)
{

	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();

	if(!getCamera(SCENE_CAMERA))
	{
		ORZ_LOG_ERROR_MESSAGE("Can't find Camera01");
		if(fill)
		{
			Ogre::Camera * camera =  sm->createCamera("Camera01_");
			sm->getRootSceneNode()->attachObject(camera);
			push_back(SCENE_CAMERA,camera);
		}


	}
	if(!getSceneNode(NEEDLE))
	{

		ORZ_LOG_ERROR_MESSAGE("Can't find new_zp_zikz");
		push_back(SceneItemMark(NEEDLE), sm->getRootSceneNode()->createChildSceneNode());
	}


	for(int i = 0; i< 24; ++i)
	{
		if(!getSceneNode(SceneItemMark(BASE_0+i)))
		{

			ORZ_LOG_ERROR_MESSAGE("new_zp_dzkz([0-9]+)");
			push_back(SceneItemMark(BASE_0+i), sm->getRootSceneNode()->createChildSceneNode());

		}


	}

	// ,
	//BASE_1,
	//BASE_2,
	//BASE_3,
	//BASE_4,
	//BASE_5,
	//BASE_6,
	//BASE_7,
	//BASE_8,
	//BASE_9,
	//BASE_10,
	//BASE_11,
	//BASE_12,
	//BASE_13,
	//BASE_14,
	//BASE_15,
	//BASE_16,
	//BASE_17,
	//BASE_18,
	//BASE_19,
	//BASE_20,
	//BASE_21,
	//BASE_22,
	//BASE_23,
	return false;
}
bool AnimalSceneCallback::hasSceneAnimationName(SceneItemMark mark)
{
	/*
	switch(mark)
	{
	case SCENE_ANIMATION_0:
	return WHEEL_HAS(zp_zjdakai);
	break;
	case SCENE_ANIMATION_1:
	return WHEEL_HAS(zp_waiweihuaban);
	break;
	case SCENE_ANIMATION_3:		 
	return WHEEL_HAS(zp_waiweihuabanshow);
	break;
	case SCENE_ANIMATION_4:
	return WHEEL_HAS(zp_ptj1);	
	break;
	}*/

	return true;
}
std::string AnimalSceneCallback::getSceneAnimationName(SceneItemMark mark)
{
	switch(mark)
	{
	case SCENE_ANIMATION_0:
		return "zp_zjdakai";
		break;
	case SCENE_ANIMATION_1:
		return "zp_waiweihuaban";
		break;
	case SCENE_ANIMATION_3:		 
		return "zp_waiweihuabanshow";
		break;
	case SCENE_ANIMATION_4:
		return "zp_ptj1";	
		break;
	}

	return NULL;
}

//调整动物的位置还有类型
AnimalSceneCallback::AnimalSceneCallback(int lions)
{
	_types[0] = WheelEnum::AnimalType(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	_types[1] = WheelEnum::AnimalType(Orz::WheelEnum::PANDA, Orz::WheelEnum::PEOPLE);
	_types[2] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[3] = WheelEnum::AnimalType(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);
	_types[4] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);

	_types[5] = WheelEnum::AnimalType(Orz::WheelEnum::LION, Orz::WheelEnum::KING);
	_types[6] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[7] = WheelEnum::AnimalType(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);


	if(lions >= 6)
	{
		_types[8] = WheelEnum::AnimalType(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	}else
	{
		_types[8] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	}

	_types[9] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[10] = WheelEnum::AnimalType(Orz::WheelEnum::MONKEY, Orz::WheelEnum::KING);
	_types[11] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);




	_types[12] = WheelEnum::AnimalType(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	_types[13] = WheelEnum::AnimalType(Orz::WheelEnum::PANDA, Orz::WheelEnum::PEOPLE);
	_types[14] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[15] = WheelEnum::AnimalType(Orz::WheelEnum::MONKEY, Orz::WheelEnum::KING);
	_types[16] = WheelEnum::AnimalType(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	_types[17] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[18] = WheelEnum::AnimalType(Orz::WheelEnum::PANDA, Orz::WheelEnum::PEOPLE);
	_types[19] = WheelEnum::AnimalType(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);


	if(lions >= 5)
	{
		_types[20] = WheelEnum::AnimalType(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	}else
	{
		_types[20] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	}

	_types[21] = WheelEnum::AnimalType(Orz::WheelEnum::PANDA, Orz::WheelEnum::KING);
	_types[22] = WheelEnum::AnimalType(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[23] = WheelEnum::AnimalType(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);



}
AnimalSceneCallback::~AnimalSceneCallback(void)
{


}
WheelEnum::AnimalType AnimalSceneCallback::getAnimalType(int n)
{
	assert(n <24&& n>=0);
	return _types[n];

}


void AnimalSceneCallback::OnCameraCreate(Ogre::Camera* pCamera, rapidxml::xml_node<>* pCameraDesc)
{

	//std::cout<<pCamera->getName()<<std::endl;
	if(pCamera->getName() == "Camera01" )
	{
		push_back(SCENE_CAMERA, pCamera);
	}
}
void AnimalSceneCallback::OnEntityCreate(Ogre::Entity *pEntity, rapidxml::xml_node<>* pEntityDesc)
{



	boost::cmatch what;
	std::string name = pEntity->getName();
	if(regex_match(name.c_str(), what, expression3))
	{
		int id = Ogre::StringConverter::parseInt(what[1].str());
		push_back(SceneItemMark(LIGHT_0+id), pEntity);
	}else if(regex_match(name.c_str(), what,  expression4))
	{
		int id = Ogre::StringConverter::parseInt(what[1].str());
		push_back(SceneItemMark(BASE_0+id), pEntity);

	}else if(regex_match(name.c_str(), what,  expression5))
	{
		int id = Ogre::StringConverter::parseInt(what[1].str());
		push_back(SceneItemMark(TABLE_0+id), pEntity);
	}
}
void AnimalSceneCallback::OnHelperCreated(Ogre::SceneNode* pHelper, rapidxml::xml_node<>* pHelperDesc)
{
	boost::cmatch what;

	std::string name = pHelper->getName();
	if(regex_match(name.c_str(), what,  expression))
	{

		Ogre::Node::ChildNodeIterator it =   pHelper->getChildIterator();


		/** full access to the current  iterator */
		//IteratorType& current(){return mCurrent;}
		while(it.hasMoreElements())
		{
			ORZ_LOG_NORMAL_MESSAGE(it.current()->second->getName());
			Ogre::Real degree = 0;
			it.current()->second->yaw(Ogre::Degree(degree));
			it.moveNext();
		}
		push_back(SceneItemMark(NEEDLE), pHelper);


	}else if(regex_match(name.c_str(), what,  expression2))
	{
		int id = Ogre::StringConverter::parseInt(what[1].str());
		push_back(SceneItemMark(BASE_0+id), pHelper);
	}

}


void AnimalSceneCallback::showBaseLight(int n, WheelEnum::LIGHT_COLOR id, bool show)
{
	Ogre::SceneNode  * sn = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getSceneNode("ring"+Ogre::StringConverter::toString(n));//->setVisible(true);
	Ogre::Entity * et = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getEntity("ring"+Ogre::StringConverter::toString(n)); 
	if(show)
	{
		switch(id)
		{
		case WheelEnum::Green:
			getEntity(SceneItemMark(BASE_0+n))->getSubEntity(0)->setMaterialName("zhuanpanquan1_green");
			et->setMaterialName("zp_dwdzgh");
			break;
		case WheelEnum::Red:
			getEntity(SceneItemMark(BASE_0+n))->getSubEntity(0)->setMaterialName("zhuanpanquan1_red");
			et->setMaterialName("zp_dwdzgh_red");
			break;
		case WheelEnum::Yellow:
			Ogre::Entity * ent = getEntity(SceneItemMark(BASE_0+n));
			Ogre::SubEntity* se = ent->getSubEntity(0);
			se->setMaterialName("zhuanpanquan1_yellow");
			et->setMaterialName("zp_dwdzgh_yellow");
			break;
		}
		sn->setVisible(true);
	}else 
	{
		sn->setVisible(false);
		getEntity(SceneItemMark(BASE_0+n))->getSubEntity(0)->setMaterialName("Material_#980/dizuose");

	}
}


