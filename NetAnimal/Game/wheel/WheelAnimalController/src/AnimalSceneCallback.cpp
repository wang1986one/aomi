#include "WheelAnimalControllerStableHeaders.h"
#include "AnimalSceneCallback.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
//#include "WheelDB.h"
#include <boost/regex.hpp>

const boost::regex expression("new_zp_zikz");
const boost::regex expression2("new_zp_dzkz([0-9]+)");
const boost::regex expression4("dr([0-9]+)");
const boost::regex expression3("zp_cj_sans([0-9]+)");

using namespace Orz;

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
AnimalSceneCallback::AnimalSceneCallback(void)
{
	_types[0] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::PANDA, Orz::WheelEnum::PEOPLE);
	_types[1] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[2] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::LION, Orz::WheelEnum::KING);
	_types[3] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);

	_types[4] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::PANDA, Orz::WheelEnum::PEOPLE);
	_types[5] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);
	_types[6] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	_types[7] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::MONKEY, Orz::WheelEnum::KING);

	_types[8] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::PANDA, Orz::WheelEnum::PEOPLE);
	_types[9] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[10] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	_types[11] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);

	_types[12] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[13] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);
	_types[14] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::PANDA, Orz::WheelEnum::KING);
	_types[15] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);

	_types[16] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);
	_types[17] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::RABBIT, Orz::WheelEnum::PEOPLE);
	_types[18] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	_types[19] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::RABBIT, Orz::WheelEnum::KING);  

	_types[20] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::PANDA, Orz::WheelEnum::PEOPLE);
	_types[21] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);
	_types[22] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::LION, Orz::WheelEnum::PEOPLE);
	_types[23] = WheelEnum::ANIMAL_TYPE(Orz::WheelEnum::MONKEY, Orz::WheelEnum::PEOPLE);

}
AnimalSceneCallback::~AnimalSceneCallback(void)
{


}
WheelEnum::ANIMAL_TYPE AnimalSceneCallback::getAnimalType(int n)
{
	assert(n <24&& n>=0);
	return _types[n];

}


void AnimalSceneCallback::OnCameraCreate(Ogre::Camera* pCamera, TiXmlElement* pCameraDesc)
{

	//std::cout<<pCamera->getName()<<std::endl;
	if(pCamera->getName() == "Camera01" )
	{
		push_back(SCENE_CAMERA, pCamera);
	}
}
void AnimalSceneCallback::OnEntityCreate(Ogre::Entity *pEntity, TiXmlElement* pEntityDesc)
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

	}
}
void AnimalSceneCallback::OnHelperCreated(Ogre::SceneNode* pHelper, TiXmlElement* pHelperDesc)
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
			getEntity(SceneItemMark(BASE_0+n))->getSubEntity(1)->setMaterialName("zhuanpanquan1_green");
			et->setMaterialName("zp_dwdzgh");
			break;
		case WheelEnum::Red:
			getEntity(SceneItemMark(BASE_0+n))->getSubEntity(1)->setMaterialName("zhuanpanquan1_red");
			et->setMaterialName("zp_dwdzgh_red");
			break;
		case WheelEnum::Yellow:
			Ogre::Entity * ent = getEntity(SceneItemMark(BASE_0+n));
				Ogre::SubEntity* se = ent->getSubEntity(1);
				se->setMaterialName("zhuanpanquan1_yellow");
			et->setMaterialName("zp_dwdzgh_yellow");
			break;
		}
		sn->setVisible(true);
	}else 
	{
		sn->setVisible(false);
		getEntity(SceneItemMark(BASE_0+n))->getSubEntity(1)->setMaterialName("Material_#369/07_-_Default");
		
	}
}


