#include "WheelAnimalControllerStableHeaders.h"
//#include "Animal_AnimalManagerImpl.h"
//#include <orz/View_OGRE3D/OgreGraphicsManager.h>
//
//#include "WheelDB.h"
//using namespace Orz;
//
//
//Animal_AnimalManagerImpl::Animal_AnimalManagerImpl(void)
//{
//
//
//}
//Animal_AnimalManagerImpl::~Animal_AnimalManagerImpl(void)
//{
//
//
//}
//
//
//std::string Animal_AnimalManagerImpl::getMeshName(WheelEnum::AnimalType type)
//{
//	 if(type.second == WheelEnum::PEOPLE)
//	{
//		switch(type.first)
//		{
//		case WheelEnum::TYPE0:
//			return "lion01.mesh";
//		case WheelEnum::TYPE1:
//			return "coney01.mesh";
//		case WheelEnum::TYPE2:
//			return "monkey01.mesh";
//		case WheelEnum::TYPE3:
//			return "panda.mesh";
//		}
//	}
//
//	if(type.second == WheelEnum::KING)
//	{
//		switch(type.first)
//		{
//		case WheelEnum::TYPE0:
//			return "lion_jin.mesh";
//		case WheelEnum::TYPE1:
//			return "coney01_jin.mesh";
//		case WheelEnum::TYPE2:
//			return "monkey01_jin.mesh";
//		case WheelEnum::TYPE3:
//			return "panda_jin.mesh";
//		}
//		
//	}
//	return "cube.mesh";
//}
//
//
////��ͨʨ��
//void Animal_AnimalManagerImpl::insertAnimationLion(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("lion_zj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//	animState = ent->getAnimationState("lion_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState("lion_zj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//}
//
////��ͨ����
//void Animal_AnimalManagerImpl::insertAnimationRabbit(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("coney_dj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//    animState = ent->getAnimationState("coney_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState("coney01_zj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//
//
//}
//
////��ͨ����
//void Animal_AnimalManagerImpl::insertAnimationMonkey(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("monkey_dj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//	animState = ent->getAnimationState("monkey_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState("monkey_zj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//
//}
//
////��ͨ��è
//void Animal_AnimalManagerImpl::insertAnimationPanda(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("panda_dj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//	animState = ent->getAnimationState("panda_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState("panda_zj");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//
//}
//
//
////�ƽ�ʨ��
//void Animal_AnimalManagerImpl::insertAnimationLionBoss(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("lion_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//	animState = ent->getAnimationState("lion_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState(WHEEL_DB(lion_jin));
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//
//}
//
////�ƽ�����
//void Animal_AnimalManagerImpl::insertAnimationRabbitBoss(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("coney_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//	animState = ent->getAnimationState("coney_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState(WHEEL_DB(coney_jin));
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//
//}
//
////�ƽ����
//void Animal_AnimalManagerImpl::insertAnimationMonkeyBoss(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("monkey_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//	animState = ent->getAnimationState("monkey_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState(WHEEL_DB(monkey_jin));
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//
//}
//
////�ƽ���è
// void Animal_AnimalManagerImpl::insertAnimationPandaBoss(AnimalPtr ani)
//{
//	//����
//	Ogre::Entity * ent  =  ani->getEntity();
//	Ogre::AnimationState* animState = NULL;
//
//	animState = ent->getAnimationState("panda_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION1, animState);
//
//	//��ֹ
//	animState = ent->getAnimationState("panda_jin_bd");
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION2, animState);
//
//	//ʤ��
//	animState = ent->getAnimationState(WHEEL_DB(panda_jin));
//	animState->setEnabled(false);
//	animState->setLoop(true);
//	ani->insertAnimation(WheelEnum::ACTION3, animState);
//
//}
//
//
//AnimalPtr Animal_AnimalManagerImpl::createAnimal(WheelEnum::AnimalType type, Ogre::SceneNode * sn)
//{
//
//	static int id = 0;
//	Ogre::Entity * ent = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("animal"+Ogre::StringConverter::toString(++id), getMeshName(type));
//
//	Ogre::SceneNode * node = sn->createChildSceneNode(Ogre::Vector3(0.0f, 30.f, 0.f));
//
//	//����ģ�͵Ĵ�С
//	node->scale(6.0f, 6.0f, 6.0f);
//
//	node->attachObject(ent);
//	node->yaw(Ogre::Radian(Ogre::Math::PI));
//
//	AnimalPtr ani(new Animal(type,node, ent));
//
//	if(type.second == WheelEnum::PEOPLE)
//	{
//		switch(type.first)
//		{
//		case WheelEnum::TYPE0:
//			insertAnimationLion(ani);
//			break;
//		case WheelEnum::TYPE1:
//			insertAnimationRabbit(ani);	
//			break;
//		case WheelEnum::TYPE2:
//			insertAnimationMonkey(ani);
//			break;
//		case WheelEnum::TYPE3:
//			insertAnimationPanda(ani);   
//			break;
//		}
//	}
//
//	if(type.second == WheelEnum::KING)
//	{
//		switch(type.first)
//		{
//		case WheelEnum::TYPE0:
//			insertAnimationLionBoss(ani);   
//			break;
//		case WheelEnum::TYPE1:
//			insertAnimationRabbitBoss(ani);	
//			break;
//		case WheelEnum::TYPE2:
//			insertAnimationMonkeyBoss(ani);   
//			break;
//		case WheelEnum::TYPE3:
//			insertAnimationPandaBoss(ani);   
//			break;
//		}
//	}
//	return ani;
//
//}