#include "GameDiamondComponentStableHeaders.h"
#include "GameColourComponent.h"
#include "CGameColourInterface.h"
#include "EntityMaterialInstance.h"
#include <orz/View_OGRE3D/OgreRenderingQueuedListener.h>

using namespace Orz;
class _UpdateInOgreRenderingQueued_Colour : public OgreRenderingQueuedListener
{
public:
	_UpdateInOgreRenderingQueued_Colour(GameColourComponent * animation):_animation(animation),_enable(false)
	{
		_frameDurationHistory.push_back(WORLD_UPDATE_INTERVAL);
	}
	virtual ~_UpdateInOgreRenderingQueued_Colour(void)
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

private:
	GameColourComponent * _animation;
	bool _enable;
	std::deque<TimeType> _frameDurationHistory;
};
GameColourComponent::GameColourComponent(void):
_ColourInterface(new CGameColourInterface)
{

	_ColourInterface->load          = boost::bind(&GameColourComponent::load, this,  _1);
	_ColourInterface->enable        = boost::bind(&GameColourComponent::enable,this , _1);
	_ColourInterface->update        = boost::bind(&GameColourComponent::update, this , _1);
	_ColourInterface->setColour     = boost::bind(&GameColourComponent::setColour,this,_1,_2,_3);
	_ColourInterface->reset         = boost::bind(&GameColourComponent::reset,this);

}
bool GameColourComponent::enable(CGameColourInterface::STATE state)
{
	_curTime = 0;
	switch(state)
	{
	case CGameColourInterface::Fatein:
		_ColourInterface->update = boost::bind(&GameColourComponent::updateFatein, this , _1);
		for (int i=0;i<_emi.size();i++)
		{
			_emi[i]->setTransparency(1.f);
		}
		_node->setVisible(true);
		return true;
		break;
	case CGameColourInterface::Fateout:
		_ColourInterface->update = boost::bind(&GameColourComponent::updateFateout, this , _1);

		for (int i=0;i<_emi.size();i++)
		{
			_emi[i]->setTransparency(0.f);
		}
		return true;
		break;
	case CGameColourInterface::Rotate:
		_ColourInterface->update = boost::lambda::constant(false);
		_updateInOgreRenderingQueued_Colour->run();
		_node->setVisible(true);
		return true;
		break;
	case CGameColourInterface::Stop:
		_ColourInterface->update = boost::lambda::constant(false);
			_updateInOgreRenderingQueued_Colour->stop();
		return true;
		break;
	}
	return true;
}

bool GameColourComponent::updateRotate(TimeType time)
{
	_node->yaw(Ogre::Degree(-time)*20);
	for (int i=0;i<4;i++)
	{
		_nodeQuan[i]->yaw(Ogre::Degree(time));
	}
	return  true;
}
bool GameColourComponent::updateFatein(TimeType time)
{
	_curTime += time;
	if (_curTime>0.5f)
	{
		for (int i=0;i<_emi.size();i++)
		{
			_emi[i]->setTransparency(0.f);
		}
		enable(CGameColourInterface::Rotate);
		return false;
	}
	else
	{
		for (int i=0;i<_emi.size();i++)
		{
			_emi[i]->setTransparency(1-(_curTime/0.5f));
		}
	}
	return true;
}
bool GameColourComponent::updateFateout(TimeType time)
{
	_curTime += time;
	if (_curTime>0.5f)
	{
		for (int i=0;i<_emi.size();i++)
		{
			_emi[i]->setTransparency(1.f);
		}
		_ColourInterface->update = boost::bind(&GameColourComponent::update, this , _1);
		_node->setVisible(false);
		return false;
	}
	else
	{
		for (int i=0;i<_emi.size();i++)
		{
			_emi[i]->setTransparency(_curTime/0.5f);
		}
	}
	return true;
}
bool GameColourComponent::update(TimeType time)
{
	return false;
}
bool GameColourComponent::updatesetColour(TimeType time)
{
	return false;
}
void GameColourComponent::setColour(float r,float g,float b)
{
	for (int i=0;i<_emi.size();i++)
	{
		Ogre::MaterialPtr mat=Orz::OgreGraphicsManager::getSingleton().getSceneManager()
			->getEntity("quan"+Ogre::StringConverter::toString(i))->getSubEntity(0)->getMaterial();
	mat->setSelfIllumination(r,g,b);
	mat->setAmbient(0,0,0);
	mat->setDiffuse(0,0,0,0);
	}
}


GameColourComponent::~GameColourComponent(void)
{

}

bool GameColourComponent::load(Ogre::SceneNode * node)
{
	float quanDis=150;//È¦ÀëÖÐÐÄ¾àÀë
	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	_node = node->createChildSceneNode("quan",Ogre::Vector3(0,95,0));
	_node->setVisible(false);
	//_node->setScale(10,10,10);
	_nodeQuan[0]= _node->createChildSceneNode("nodeQuan0",Ogre::Vector3(quanDis,0,0));
	_nodeQuan[1]= _node->createChildSceneNode("nodeQuan1",Ogre::Vector3(0,0,-quanDis));
	_nodeQuan[2]= _node->createChildSceneNode("nodeQuan2",Ogre::Vector3(-quanDis,0,0));
	_nodeQuan[3]= _node->createChildSceneNode("nodeQuan3",Ogre::Vector3(0,0,quanDis));
	Ogre::Entity* ent;

	for (int i=0;i<4;i++)
	{
		ent=sm->createEntity("quan"+Ogre::StringConverter::toString(i),"youyongquan.mesh");
		_nodeQuan[i]->attachObject(ent);
		_nodeQuan[i]->setScale(15,15,15);
		_emi[i].reset(new EntityMaterialInstance(ent));
		_emi[i]->setTransparency(1.f);
	}
	_updateInOgreRenderingQueued_Colour.reset(new _UpdateInOgreRenderingQueued_Colour(this));
	reset();
	return true;
}
ComponentInterface * GameColourComponent::_queryInterface(const TypeInfo & info)
{
	if(info == TypeInfo(typeid(CGameColourInterface)))
		return _ColourInterface.get();
	return NULL;
}

void GameColourComponent::reset(void)
{
	_node->resetOrientation();
	_node->setVisible(false);
	for (int i=0;i<4;i++)
	{
		_nodeQuan[i]->resetOrientation();
	}
	setColour(0.7,0.7,1);
}