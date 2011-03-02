#include "GameDiamondComponentStableHeaders.h"
#include "GameDiamondMoreWinderComponent.h"
#include "CGameDiamondMoreWinderInterface.h"
#include "BiggerAnimation.h"
#include "RunAnimation.h"
#include "StepAnimation.h"
#include <orz/View_OGRE3D/OgreRenderingQueuedListener.h>

#include "CRotationInterface.h"
namespace Orz
{

	class Updater : public OgreRenderingQueuedListener
	{

		typedef boost::function<bool (TimeType)> UpdateFunction;
		typedef boost::function<void (void)> ResetFunction;
	public:
		Updater(void):_enable(false)
		{
			_frameDurationHistory.push_back(WORLD_UPDATE_INTERVAL);
		}
		virtual ~Updater(void)
		{
		}
		inline bool run(UpdateFunction uf)
		{

			if(!_enable)
			{
				_uf = uf;
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

		inline TimeType getPredictedFrameDuration (void) const
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

			if(_uf)
			{
				bool ret = _uf(pt);
				if(!ret)
				{
					_uf.clear();

				}
			}
			return true;
		}
		inline bool isEnable(void)
		{
			return _enable;
		}

		inline void stop(void)
		{
			if(_enable)
			{
				Orz::OgreGraphicsManager::getSingleton().removeRenderingQueuedListener(this);
				_uf.clear();
				_enable = false;
			}
		}
	private:
		bool _enable;
		std::deque<TimeType> _frameDurationHistory;
		UpdateFunction _uf;
	};

}

using namespace Orz;

inline int GetNumber(int i)
{
	switch(i)
	{
	case 0:
		return 0;
	case 1:
		return /*4;*/3;
	case 2:
		return /*5;*/4;
	case 3:
		return /*1;*/5;
	case 4:
		return /*2;*/1;
	case 5:
		return /*3;*/2;

	}

	return 11;

}


GameDiamondMoreWinderComponent::GameDiamondMoreWinderComponent(void):_moreWinnerInterface(new CGameDiamondMoreWinderInterface),_updater(new Updater),_number(0),_step(0)
{
	_moreWinnerInterface->init = boost::bind(&GameDiamondMoreWinderComponent::init, this,  _1);
	_moreWinnerInterface->addEntity = boost::bind(&GameDiamondMoreWinderComponent::addEntity, this,  _1, _2);
	_moreWinnerInterface->bigger = boost::bind(&GameDiamondMoreWinderComponent::bigger, this);
	_moreWinnerInterface->reset = boost::bind(&GameDiamondMoreWinderComponent::reset, this);
	_moreWinnerInterface->run = boost::bind(&GameDiamondMoreWinderComponent::run, this, _1);
	_moreWinnerInterface->step = boost::bind(&GameDiamondMoreWinderComponent::step, this);
	_moreWinnerInterface->stop = boost::bind(&GameDiamondMoreWinderComponent::stop, this);


	for(int i =0 ; i<12; i++)
	{
		std::string mname = "diamond"+boost::lexical_cast<std::string>(i);
		//ent->setMaterialName(mname);
		Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(mname);

		material->setSelfIllumination(1.0f,1.0f,1.0f);
		material->setAmbient(0,0,0);
	
		material->setDiffuse(0,0,0,0);
	}
	//_rotationComp = Orz::ComponentFactories::getInstance().create("Rotation");

}

void GameDiamondMoreWinderComponent::stop(void)
{

	_updater->stop();
}
bool GameDiamondMoreWinderComponent::run(int i)
{
	reset();
	_number = i;
	_runAnimation.reset(new RunAnimation("bigger", _node));
	_runAnimation->_callback = boost::bind(&GameDiamondMoreWinderComponent::runNumber, this, _1);
	_runAnimation->play();
	_updater->run(boost::bind(&RunAnimation::update,_runAnimation.get(), _1));

	//CRotationInterface * rotation =NULL;
	/*rotation = _rotationComp->queryInterface<CRotationInterface>();
	rotation->init(_node, CRotationInterface::Clockwise, 0);
	rotation->play(360, 3);

	rotation->update(0.015);*/
	return true;
}

bool GameDiamondMoreWinderComponent::step(void)
{
	if(_step < _number)
	{

		_reset();
		_stepAnimation.reset(new StepAnimation("step", _node, _step));
		_stepAnimation->_callback = boost::bind(&GameDiamondMoreWinderComponent::stepNumber, this, _1);
		_stepAnimation->play();

		_updater->run(boost::bind(&StepAnimation::update,_stepAnimation.get(), _1));
		_step ++;
		return true;
	}
	else

	{
		return false;
	}
}
bool GameDiamondMoreWinderComponent::bigger(void)
{

	reset();
	_biggerAnimation.reset(new BiggerAnimation("bigger", _node));

	_biggerAnimation->play();
	_updater->run(boost::bind(&BiggerAnimation::update,_biggerAnimation.get(), _1));
	return true;
}

void GameDiamondMoreWinderComponent::stepNumber(int i)
{
	int n = _number - i-3;
	if(n >= 0)
		_entitys.at(GetNumber((3 + i) %6))->setMaterialName("diamond"+boost::lexical_cast<std::string>(n));
}
void GameDiamondMoreWinderComponent::runNumber(int i)
{
	if(i >= 84)
	{
		int n = _number- (i - 84) +3;
		n = (n+12)%12;
		_entitys.at(GetNumber((3 + i) %6))->setMaterialName("diamond"+boost::lexical_cast<std::string>(n));
		//if(i == 90)
		//{
		//	std::string mname = "diamond"+boost::lexical_cast<std::string>(_number);
		//	//ent->setMaterialName(mname);
		//	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(mname);

		//	material->setSelfIllumination(0.7f,0.4f,1.0f);
		//	material->setAmbient(0,0,0);
		//}
	}
	else
	{
		_entitys.at(GetNumber((3 + i) %6))->setMaterialName("diamond"+boost::lexical_cast<std::string>(rand()%12));
	}//std::cout<<i<<std::endl;
}

void GameDiamondMoreWinderComponent::_reset(void)
{
	
	if(_stepAnimation)
	{
		_stepAnimation->reset();

	}
	if(_biggerAnimation)
	{
		_biggerAnimation->reset();

	}
	if(_runAnimation)
	{
		_runAnimation->reset();
	}
	_node->setPosition(_pos);
	_updater->stop();
	_stepAnimation.reset();
	_biggerAnimation.reset();
	_runAnimation.reset();
}


void GameDiamondMoreWinderComponent::reset(void)
{
	
	_reset();
	for(int i = 0 ; i<6; ++i)
	{
		_entitys.at(i)->setMaterialName("Sapphire");
	}
	_node->setScale(Ogre::Vector3::UNIT_SCALE);
	
	_step = 0;
}


GameDiamondMoreWinderComponent::~GameDiamondMoreWinderComponent(void)
{
	
}

ComponentInterface * GameDiamondMoreWinderComponent::_queryInterface(const TypeInfo & info)
{

	if(info == TypeInfo(typeid(CGameDiamondMoreWinderInterface)))
		return _moreWinnerInterface.get();
	return NULL;

}



bool GameDiamondMoreWinderComponent::init(Ogre::SceneNode * node)
{
	_node = node;
	_pos = _node->getPosition();
	return true;
}
bool GameDiamondMoreWinderComponent::addEntity(int i, Ogre::Entity * ent)
{
	_entitys.at(i) = ent;
	/*std::string mname = "diamond"+boost::lexical_cast<std::string>(GetNumber(i));
	ent->setMaterialName(mname);
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(mname);

	material->setSelfIllumination(0.4f,0.7f,1.0f);
	material->setAmbient(0,0,0);*/
	return true;
}



