#include "GameDiamondComponentStableHeaders.h"
#include "GameDiamondComponent.h"
#include "CGameDiamondInterface.h"
#include "EntityMaterialInstance.h"
#include "CGameDiamondMoreWinderInterface.h"
#include "ParticleUniverse/ParticleUniverseSystemManager.h"
#include "ParticleUniverse/ParticleUniverseSystem.h"
#include "ParticleUniverse/ParticleUniversePrerequisites.h"
#include "ParticleUniverse/ParticleAffectors/ParticleUniverseColourAffector.h"
#include <orz/View_OGRE3D/OgreRenderingQueuedListener.h>
//#include "CCSBasicCameraModes.h"
using namespace Orz;
class _UpdateInOgreRenderingQueued_Diamond : public OgreRenderingQueuedListener
{
public:
	_UpdateInOgreRenderingQueued_Diamond(GameDiamondComponent * animation):_animation(animation),_enable(false)
	{
		_frameDurationHistory.push_back(WORLD_UPDATE_INTERVAL);
	}
	virtual ~_UpdateInOgreRenderingQueued_Diamond(void)
	{
	}
	inline bool run(void)
	{
		if(!_enable)
		{
			Orz::OgreGraphicsManager::getSingleton().addRenderingQueuedListener(this);
			_enable = true;
			return true;
		}
		return false;
	}
	inline TimeType getExactLastFrameDuration(TimeType t)
	{
		if (t > 0.200f)
		{
			t = _frameDurationHistory.back(); 
		}
		return t;
	}

	inline TimeType getPredictedFrameDuration () const
	{
		TimeType totalFrameTime = 0;

		std::deque<TimeType>::const_iterator it;
		for (it = _frameDurationHistory.begin(); it != _frameDurationHistory.end(); ++it)
			totalFrameTime += *it;
		return totalFrameTime/_frameDurationHistory.size();
	}

	void addToFrameHistory (TimeType t)
	{
		_frameDurationHistory.push_back (t);
		if (_frameDurationHistory.size () > (unsigned int) 20)
			_frameDurationHistory.pop_front ();
	}
	virtual bool update(TimeType interval)
	{
		TimeType t = getExactLastFrameDuration(interval);
		addToFrameHistory(t);
		TimeType pt = getPredictedFrameDuration();
		//_enable = _animation->updateSceneAnimation(pt);
		_animation->updateFloat(pt);
		return  true;
	}
	inline bool isEnable(void)
	{
		return _enable;
	}
	inline void stop(void)
	{
		Orz::OgreGraphicsManager::getSingleton().removeRenderingQueuedListener(this);
		_enable = false;

	}

private:
	GameDiamondComponent * _animation;
	bool _enable;
	std::deque<TimeType> _frameDurationHistory;
};
GameDiamondComponent::GameDiamondComponent(void):_diamondInterface(new CGameDiamondInterface),_pos(0, 0, 0),_node(NULL),_currTime(0.f)
{
	_dirDiaAni = 1;
	degree = 0;
	_diamondInterface->load = boost::bind(&GameDiamondComponent::load, this,  _1);
	_diamondInterface->enable = boost::bind(&GameDiamondComponent::enable,this , _1);
	_diamondInterface->setDiamondColour = boost::bind(&GameDiamondComponent::setDiamondColour,this , _1,_2,_3);
	_diamondInterface->setAnimal = boost::bind(&GameDiamondComponent::setAnimal,this,_1);
	_diamondInterface->reset = boost::bind(&GameDiamondComponent::reset,this);
	_moreWinner = ComponentFactories::getInstance().create("GameDiamondMoreWinder");
	_updateInOgreRenderingQueued_Diamond.reset(new _UpdateInOgreRenderingQueued_Diamond(this));
}

void GameDiamondComponent::reset(void)
{
	_node->setPosition(_pos);
	for(int i=0;i<6;i++)
	{
		_DiaAnimationState[i]->setEnabled(true);
		_DiaAnimationState[i]->setTimePosition(0.f);
	}
	for (int i=0;i<4;i++)
	{
		_entAnimals[i]->setVisible(false);
	}
	setDiamondColour(0.4f,0.7f,1.0f);
	emiSetTransparency(1.f);
	_system->stopFade();
}
bool GameDiamondComponent::enable(CGameDiamondInterface::STATE state)
{
	_currTime = 0;
	_updateInOgreRenderingQueued_Diamond->stop();
	switch(state)
	{
	case CGameDiamondInterface::Float:
		_updateInOgreRenderingQueued_Diamond->run();
		_diamondInterface->update = boost::bind(&GameDiamondComponent::update, this , _1);
		return true;
		break;
	case CGameDiamondInterface::Fatein:
		_diamondInterface->update = boost::bind(&GameDiamondComponent::updateFatein, this , _1);
		degree = 0;
		_node ->resetOrientation();
		emiSetTransparency(1.0f);
		return true;
		break;
	case CGameDiamondInterface::Fateout:
		_diamondInterface->update = boost::bind(&GameDiamondComponent::updateFateout, this , _1);
		emiSetTransparency(0.f);
		return true;
		break;
	case CGameDiamondInterface::Open:
		//在此加入打开钻石的音效
		_system->stop();
		_dirDiaAni = 1;
		_diamondInterface->update = boost::bind(&GameDiamondComponent::updateOpenOrClose, this , _1);
		return true;
		break;
	case CGameDiamondInterface::Close:
		_dirDiaAni = -1;
		for(int i=0;i<6;i++)
		{
			_DiaAnimationState[i]->setTimePosition(1.333/2);
		}
		for(int i=0;i<4;i++)
		{
			_entAnimals[i]->setVisible(false);
		}
		_diamondInterface->update = boost::bind(&GameDiamondComponent::updateOpenOrClose, this , _1);
		return true;
		break;
	case CGameDiamondInterface::OpenstateRotate:
		_diamondInterface->update = boost::bind(&GameDiamondComponent::updateOpenstateRotate, this,_1);
		return true;
		break;
	}
	return true;
}

bool GameDiamondComponent::updateFloat(TimeType time)
{
	_currTime += time;
	if (_currTime>3.0e+38)
	{
		_currTime = 0;
	}
	_node->setPosition(_pos + Ogre::Vector3(0, Ogre::Math::Sin(_currTime * 3.14)*20 , 0));
	return false;
}
bool GameDiamondComponent::updateFatein(TimeType time)
{
	_node->setPosition(_pos);
	_currTime += time;
	if (_currTime>0.5f)//淡入过程为0.5秒
	{
		_system->start();
		emiSetTransparency(0.f);
		return false;
	}
	else
	{
		emiSetTransparency(1.f-(_currTime/0.5f));
	}
	return true;
}
bool GameDiamondComponent::updateFateout(TimeType time)
{
	_currTime += time;
	if (_currTime>0.5f)//淡出过程为0.5秒
	{
		emiSetTransparency(1.f);
		_system->stopFade();
		return false;
	}
	else
	{
		emiSetTransparency(_currTime/0.5f);
	}
	return true;
}
bool GameDiamondComponent::updateOpenOrClose(TimeType time)
{
	_currTime += time;
	static const TimeType HALF_TIME = 1.333f/2.f;
	if (_currTime>HALF_TIME)//动画总时间是(1.333/2)
	{
		if(_dirDiaAni==1)
		{
			_currTime = 0;
			_entAnimals[0]->setVisible(true);
			_emiAnimal->setTransparency(1);
			_diamondInterface->update = boost::bind(&GameDiamondComponent::updateDisplayAnimal,this,_1);
			return true;
		}
		else
		{
			_system->start();
			for(int i=0;i<6;i++)
			{
				_DiaAnimationState[i]->setEnabled(false);
			}
			enable(CGameDiamondInterface::Float);

		}


		return false;
	}
	_node->setPosition(_pos + Ogre::Vector3(0, 100.f * (_dirDiaAni*_currTime/HALF_TIME), 0));

	_DasAddtime(time*_dirDiaAni);
	return true;
}
bool GameDiamondComponent::updateOpenstateRotate(TimeType time)
{
	degree+= time*100;
	static int i = 1;
	if(degree>=360)
	{
		degree=0;
		/*int a=(int)Ogre::Math::RangeRandom(0,3.4);*/
		changeAnimal((CGameDiamondInterface::ANIMALS)(i));
		//在这里可以加入变化动物的音效
		i++;
		i %= 4;
	}
	_node->yaw(Ogre::Degree(time*100));

	
	return true;
}

bool GameDiamondComponent::updateDisplayAnimal(TimeType time)
{
	_currTime += time;
	if (_currTime>0.5f)//淡入过程为0.5秒
	{
		_emiAnimal->setTransparency(0);
		//_diamondInterface->update = boost::bind(&GameDiamondComponent::updateOpenstateRotate,this,_1);
		return false;
	}
	else
	{
		_emiAnimal->setTransparency(1.f-(_currTime/0.5f));
	}
	//加入钻石旋转音效并检测音效
	return true;
}
bool GameDiamondComponent::update(TimeType time)
{
	return false;
}
GameDiamondComponent::~GameDiamondComponent(void)
{

}


bool GameDiamondComponent::load(Ogre::SceneNode * node)
{
	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	//_pos = node->getPosition()+ Ogre::Vector3(0, 200 , 0);
	_node = sm->getRootSceneNode()->createChildSceneNode(node->getPosition()+ Ogre::Vector3(0, 200 , 0));//->createChildSceneNode();
	_node->setScale(0.8f,0.8f,0.8f);
	_node = _node->createChildSceneNode();
	_pos = _curPos=_node->getPosition();
	Ogre::Entity * diamond = NULL;

	CGameDiamondMoreWinderInterface * moreWinner = _moreWinner->queryInterface<CGameDiamondMoreWinderInterface>();
	for(int i=0;i<6;i++)
	{
		diamond = sm->createEntity("diamond"+Ogre::StringConverter::toString(i+1), "zuanshi" + Ogre::StringConverter::toString(i+1) + ".mesh");
		_node->attachObject(diamond);
		diamond->setMaterialName("Sapphire");
		moreWinner->init(_node);
		moreWinner->addEntity(i, diamond);
		_emi[i].reset(new EntityMaterialInstance(diamond));
		_DiaAnimationState[i]=diamond->getAnimationState("idel");
		_DiaAnimationState[i]->setLoop(false);
		_DiaAnimationState[i]->setEnabled(true);
	}


	ParticleUniverse::ParticleSystemManager * particleSystemManager = 
		ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 

	_system = particleSystemManager->createParticleSystem("gem", "newgame_gemlight", Orz::OgreGraphicsManager::getSingleton().getSceneManager()); 
	Ogre::SceneNode* _nodePs = _node->createChildSceneNode(Ogre::Vector3(0,100,0));
	_nodePs->attachObject(_system); 
	_system->start();
	loadAnimals();
	setDiamondColour(0.4f,0.7f,1.0f);
	return true;
}
ComponentInterface * GameDiamondComponent::_queryInterface(const TypeInfo & info)
{

	if(info == TypeInfo(typeid(CGameDiamondInterface)))
		return _diamondInterface.get();
	if(info == TypeInfo(typeid(CGameDiamondMoreWinderInterface)))
		return  _moreWinner->_queryInterface(info);

	return NULL;

}


void GameDiamondComponent::emiSetTransparency(Ogre::Real trans)
{
	for (boost::array<boost::scoped_ptr<EntityMaterialInstance>,6>::iterator it=_emi.begin();
		it!=_emi.end();it++)
	{
		(*it)->setTransparency(trans);
	}
	//for(int i=0;i<6;i++)
	//{
	//	_emi[i]->setTransparency(trans);
	//}
}
void GameDiamondComponent::_DasAddtime(TimeType time)
{
	for(int i=0;i<6;i++)
	{
		_DiaAnimationState[i]->addTime(time);
	}
}
void GameDiamondComponent::setDiamondColour(float r,float g,float b)
{
	Ogre::MaterialPtr mat=Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getEntity("diamond1")
		->getSubEntity(0)->getMaterial();

	mat->setSelfIllumination(r,g,b);
	mat->setAmbient(0,0,0);
	mat->setDiffuse(0,0,0,0);
	ParticleUniverse::ColourAffector* ca= static_cast<ParticleUniverse::ColourAffector*>(_system->getTechnique(0)->getAffector(0));
	ParticleUniverse::ColourAffector::ColourMapIterator cmit=ca->_findNearestColourMapIterator(0.8);
	(*cmit).second = Ogre::ColourValue(r,g,b);
}
void GameDiamondComponent::changeAnimal(CGameDiamondInterface::ANIMALS animal)
{
	for (int i=0;i<4;i++)
	{
		_entAnimals[i]->setVisible(false);
	}
	_entAnimals[(int)animal]->setVisible(true);
}
void GameDiamondComponent::setAnimal(CGameDiamondInterface::ANIMALS animal)
{
	for (int i=0;i<4;i++)
	{
		_entAnimals[i]->setVisible(false);
	}
	_entAnimals[(int)animal]->setVisible(true);
	_node->resetOrientation();
	degree=0;
	_diamondInterface->update = boost::bind(&GameDiamondComponent::update, this,_1);
}
void GameDiamondComponent::loadAnimals()
{
	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	//载入动物
	_nodeAnimal = _node->createChildSceneNode(Ogre::Vector3(0,0,0));
	_nodeAnimal->setInheritScale(false);
	Ogre::SceneNode* tempnode;
	_entAnimals[CGameDiamondInterface::Panda] = sm->createEntity("SelectAnimal_Panda","Panda.mesh");
	tempnode = _nodeAnimal->createChildSceneNode();
	tempnode->attachObject(_entAnimals[CGameDiamondInterface::Panda] );
	tempnode ->setScale(2.3f,2.3f,2.3f);
	_entAnimals[CGameDiamondInterface::Crocodile] = sm->createEntity("SelectAnimal_Crocodile","Crocodile.mesh");
	tempnode = _nodeAnimal->createChildSceneNode();
	tempnode->attachObject(_entAnimals[CGameDiamondInterface::Crocodile] );
	_entAnimals[CGameDiamondInterface::Elephant] = sm->createEntity("SelectAnimal_Elephant","Elephant.mesh");
	tempnode = _nodeAnimal->createChildSceneNode();
	tempnode->attachObject(_entAnimals[CGameDiamondInterface::Elephant] );
	_entAnimals[CGameDiamondInterface::Tiger] = sm->createEntity("SelectAnimal_Tiger","Tiger.mesh");
	tempnode = _nodeAnimal->createChildSceneNode();
	tempnode->attachObject(_entAnimals[CGameDiamondInterface::Tiger] );
	tempnode ->setScale(2.3f,2.3f,2.3f);
	for (int i=0;i<4;i++)
	{
		_entAnimals[i]->setVisible(false);
	}
	_emiAnimal.reset(new EntityMaterialInstance(_entAnimals[0]));
	_emiAnimal->setTransparency(1);

}