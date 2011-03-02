#include "WheelAnimalControllerStableHeaders.h"
#include "AnimalManagerDB.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>

//#include "WheelDB.h"
using namespace Orz;




std::string AnimalManagerDB::getMeshName(WheelEnum::AnimalType type)
{
	 if(type.second == WheelEnum::PEOPLE)
	{
		switch(type.first)
		{
		case WheelEnum::LION:
			return "lion01.mesh";
		case WheelEnum::RABBIT:
			return "coney01.mesh";
		case WheelEnum::MONKEY:
			return "monkey01.mesh";
		case WheelEnum::PANDA:
			return "panda.mesh";
		}
	}

	if(type.second == WheelEnum::KING)
	{
		switch(type.first)
		{
		case WheelEnum::LION:
			return "lion_jin.mesh";
		case WheelEnum::RABBIT:
			return "coney01_jin.mesh";
		case WheelEnum::MONKEY:
			return "monkey01_jin.mesh";
		case WheelEnum::PANDA:
			return "panda_jin.mesh";
		}
		
	}
	return "cube.mesh";
}


//��ͨʨ��
void AnimalManagerDB::insertAnimationLion(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("lion_zj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
	animState = ent->getAnimationState("lion_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("lion_zj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);
}

//��ͨ����
void AnimalManagerDB::insertAnimationRabbit(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("coney_dj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
    animState = ent->getAnimationState("coney_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("coney01_zj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);


}

//��ͨ����
void AnimalManagerDB::insertAnimationMonkey(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("monkey_dj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
	animState = ent->getAnimationState("monkey_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("monkey_zj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);

}

//��ͨ��è
void AnimalManagerDB::insertAnimationPanda(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("panda_dj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
	animState = ent->getAnimationState("panda_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("panda_zj");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);

}


//�ƽ�ʨ��
void AnimalManagerDB::insertAnimationLionBoss(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("lion_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
	animState = ent->getAnimationState("lion_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("lion_jin");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);

}

//�ƽ�����
void AnimalManagerDB::insertAnimationRabbitBoss(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("coney_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
	animState = ent->getAnimationState("coney_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("coney_jin");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);

}

//�ƽ����
void AnimalManagerDB::insertAnimationMonkeyBoss(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("monkey_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
	animState = ent->getAnimationState("monkey_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("monkey_jin");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);

}

//�ƽ���è
 void AnimalManagerDB::insertAnimationPandaBoss(AnimalPtr ani)
{
	//����
	Ogre::Entity * ent  =  ani->getEntity();
	Ogre::AnimationState* animState = NULL;

	animState = ent->getAnimationState("panda_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION1, animState);

	//��ֹ
	animState = ent->getAnimationState("panda_jin_bd");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION2, animState);

	//ʤ��
	animState = ent->getAnimationState("panda_jin");
	animState->setEnabled(false);
	animState->setLoop(true);
	ani->insertAnimation(WheelEnum::ACTION3, animState);

}


AnimalPtr AnimalManagerDB::createAnimal(WheelEnum::AnimalType type, Ogre::SceneNode * sn)
{

	static int id = 0;
	Ogre::Entity * ent = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("animal"+Ogre::StringConverter::toString(++id), getMeshName(type));

	if(type.second == WheelEnum::KING)
	{
		switch(type.first)
		{
		case WheelEnum::PANDA:
			ent->setMaterialName("panda_jin");
			break;
		case WheelEnum::MONKEY:
			ent->setMaterialName("monkey_jin");
			break;
		case WheelEnum::RABBIT:
			ent->setMaterialName("coney_jin");
			break;
		case WheelEnum::LION:
			ent->setMaterialName("lion_jin");
			break;
		
		}
	}
	Ogre::SceneNode * node = sn->createChildSceneNode(Ogre::Vector3(0.0f, 15.f, 0.f));

	//����ģ�͵Ĵ�С
	node->scale(3.5f, 3.5f, 3.5f);

	node->attachObject(ent);
	node->yaw(Ogre::Radian(Ogre::Math::PI));

	AnimalPtr ani(new Animal(type,node, ent));

	if(type.second == WheelEnum::PEOPLE)
	{
		switch(type.first)
		{
		case WheelEnum::LION:
			insertAnimationLion(ani);
			break;
		case WheelEnum::RABBIT:
			insertAnimationRabbit(ani);	
			break;
		case WheelEnum::MONKEY:
			insertAnimationMonkey(ani);
			break;
		case WheelEnum::PANDA:
			insertAnimationPanda(ani);   
			break;
		}
	}

	if(type.second == WheelEnum::KING)
	{
		switch(type.first)
		{
		case WheelEnum::LION:
			insertAnimationLionBoss(ani);   
			break;
		case WheelEnum::RABBIT:
			insertAnimationRabbitBoss(ani);	
			break;
		case WheelEnum::MONKEY:
			insertAnimationMonkeyBoss(ani);   
			break;
		case WheelEnum::PANDA:
			insertAnimationPandaBoss(ani);   
			break;
		}
	}
	return ani;

}