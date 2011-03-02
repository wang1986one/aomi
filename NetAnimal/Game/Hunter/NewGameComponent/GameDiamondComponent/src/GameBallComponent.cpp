#include "GameDiamondComponentStableHeaders.h"
#include "GameBallComponent.h"
#include "CGameBallInterface.h"
#include "MyMaterialInstance.h"
#include "particleUniverse/ParticleUniverseSystem.h"
#include <orz/View_OGRE3D/OgreRenderingQueuedListener.h>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
using namespace Orz;
class _UpdateInOgreRenderingQueued_Ball : public OgreRenderingQueuedListener
{
public:
	_UpdateInOgreRenderingQueued_Ball(GameBallComponent * animation):_animation(animation),_enable(false)
	{
		_isRotate = true;
		_frameDurationHistory.push_back(WORLD_UPDATE_INTERVAL);
	}
	virtual ~_UpdateInOgreRenderingQueued_Ball(void)
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
		if(_isRotate)
			_animation->_node->yaw(Ogre::Degree(pt)*400);
		_animation->updateRotate(pt);
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
	inline void setRotate(bool isR)
	{
		_isRotate=isR;
	}

private:
	GameBallComponent * _animation;
	bool _enable;
	std::deque<TimeType> _frameDurationHistory;
	bool _isRotate;
};

GameBallComponent::GameBallComponent(void):
_BallInterface(new CGameBallInterface),
_pos(0, 0, 0),_node(NULL),
_curTime(0.f),
_runAllTime(20),
stopTimePass(3),
isStop(false),
isThisRoundDisplayed(false)
{

	_BallInterface->load          = boost::bind(&GameBallComponent::load, this,  _1);
	_BallInterface->enable        = boost::bind(&GameBallComponent::enable,this , _1);
	_BallInterface->update        = boost::bind(&GameBallComponent::update, this , _1);
	_BallInterface->setNumber     = boost::bind(&GameBallComponent::setNumber,this,_1);
	_BallInterface->addNumber     = boost::bind(&GameBallComponent::addNumber,this,_1);

}
void GameBallComponent::setAngle(float angle)
{
	_node->resetOrientation();
	_node->yaw(Ogre::Degree(-angle));

}
bool GameBallComponent::enable(CGameBallInterface::STATE state)
{
	_curTime = 0;
	switch(state)
	{
	case CGameBallInterface::Hide:
		_BallInterface->update = boost::lambda::constant(false);
		_updateInOgreRenderingQueued_Ball->stop();
		_node->setVisible(false);
		break;
	case CGameBallInterface::Fatein:
		_BallInterface->update = boost::bind(&GameBallComponent::updateFatein, this , _1);
		_emi->setTransparency(1.0f);
		_node->setVisible(true);
		return true;
		break;
	case CGameBallInterface::Fateout:
		_BallInterface->update = boost::bind(&GameBallComponent::updateFateout, this , _1);
		_emi.reset(new MyMaterialInstance(bbset->getMaterial()));
		_emi->setTransparency(0.0f);
		return true;
		break;
	case CGameBallInterface::Rotate:
		_BallInterface->update = boost::bind(&GameBallComponent::update, this , _1);
		_updateInOgreRenderingQueued_Ball->run();
		_node->setVisible(true);
		return true;
		break;
	case CGameBallInterface::Stop:
		_BallInterface->update = boost::bind(&GameBallComponent::update, this , _1);
		_updateInOgreRenderingQueued_Ball->stop();

		return true;
		break;
	}
	return true;
}

bool GameBallComponent::updateRotate(TimeType time)
{
	Ogre::Degree degree=Ogre::Degree(_node->getOrientation().getYaw());
	if (degree>=Ogre::Degree(0) && degree<=Ogre::Degree(180))
	{
		isThisRoundDisplayed=false;
		return true;
	}
	if(isThisRoundDisplayed==false && isStop ==false && !
		_dequeNumber.empty() && degree>=Ogre::Degree(-100) && degree<Ogre::Degree(-88))
	{
		_updateInOgreRenderingQueued_Ball->setRotate(false);
		stopTimePass = 0;
		isStop = true;
		isThisRoundDisplayed = true;
		bbset->setMaterialName("newgame/BallSelno"+ Ogre::StringConverter::toString(_dequeNumber.front()));
	}
	else
	{
		if (stopTimePass <0.5)
		{
			stopTimePass+=time;
			if (stopTimePass>=0.5)
			{
				_updateInOgreRenderingQueued_Ball->setRotate(true);
				_dequeNumber.pop_front();
				isStop=false;
				return false;//Í£Ö¹×´Ì¬½áÊø£¬·µ»Øfalse
			}
		}
	}

	return  true;
}
bool GameBallComponent::updateFatein(TimeType time)
{
	_curTime += time;
	if (_curTime>3.f)
	{
		_curTime= 0.f;
		_emi->setTransparency(0.f);
		enable(CGameBallInterface::Rotate);
		return false;
	}
	else
	{
		_emi->setTransparency(1-(_curTime/3.f));
	}
	return true;
}
bool GameBallComponent::updateFateout(TimeType time)
{
	_curTime += time;
	if (_curTime>0.5f)
	{
		_emi->setTransparency(1.f);
		_BallInterface->update = boost::bind(&GameBallComponent::update, this , _1);
		_node->setVisible(false);
		return false;
	}
	else
	{
		_emi->setTransparency(_curTime/0.5f);
	}
	return true;
}
bool GameBallComponent::update(TimeType time)
{
	return false;
}
bool GameBallComponent::updatesetNumber(TimeType time)
{
	return false;
}
void GameBallComponent::setNumber(int Num)
{
	bbset->setMaterialName("newgame/Ballno"+ Ogre::StringConverter::toString(Num));

}


GameBallComponent::~GameBallComponent(void)
{

}

bool GameBallComponent::load(Ogre::SceneNode * node)
{
	//Ball = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("Ball", "sphere.mesh");
	//Ball->setMaterialName("newgame/no1");

	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();

	_pos = node->getPosition()+ Ogre::Vector3(0, 350 , 0);
	_node = sm->getRootSceneNode()->createChildSceneNode(_pos);
	ballnode=_node->createChildSceneNode(Ogre::Vector3(80,0,0));
	//ballnode->attachObject(Ball);
	ballnode->setScale(0.6f,0.6f,0.6f);
	_updateInOgreRenderingQueued_Ball.reset(new _UpdateInOgreRenderingQueued_Ball(this));
	_node->setVisible(false);
	bbset = sm->createBillboardSet("BBSet",1);
	ballnode->attachObject(bbset);
	bbset->setMaterialName("newgame/Ballno0");
	bbset->setDefaultDimensions(256,256);
	bbset->setBillboardOrigin(Ogre::BBO_CENTER);
	bb = bbset->createBillboard(Vector3(0,  0,  0));

	_emi.reset(new MyMaterialInstance(Ogre::MaterialManager::getSingleton().getByName("newgame/Ballno0")));
	_emi->setTransparency(1.f);
	return true;
}
ComponentInterface * GameBallComponent::_queryInterface(const TypeInfo & info)
{
	if(info == TypeInfo(typeid(CGameBallInterface)))
		return _BallInterface.get();
	return NULL;
}
void GameBallComponent::addNumber(int n)
{
	_dequeNumber.push_back(n);
}