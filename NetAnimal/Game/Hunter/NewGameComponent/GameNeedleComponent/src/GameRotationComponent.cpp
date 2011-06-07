#include "GameNeedleComponentStableHeaders.h"
#include "GameRotationComponent.h"
#include "COgreCCSInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameRotationInterface.h"
#include "CNewGameSceneInterface.h"
#include "CGameBaseInterface.h"
#include "CRotationInterface.h"
#include "WinnerAnimation.h"
using namespace Orz;



inline float sub360(float value)
{
	while(value>=360.f)
	{
		value-=360.f;
	}
	return value;
}


inline float getAll(float start, float end)
{
	start = sub360(start);
	if(start >= end)
	{
		return end +360 - start;
	}else
		return end - start;
}
inline std::pair<float, float> getStartAll(float start, float end)
{
	return std::make_pair(sub360(start), getAll(start,end));


}


bool GameRotationComponent::winner(int id, bool move)
{


	CGameBaseInterface * base = _baseComp->queryInterface<CGameBaseInterface>();
	_winnerAnimation.reset();
	static int i=0; 
	i++;

	Ogre::Quaternion q;
	q.FromAngleAxis( Ogre::Radian(Ogre::Degree(-_base * 15.f)),Ogre::Vector3::UNIT_Y);
	_node->setOrientation(q);
	
	if(move)
	{
		_winnerAnimation.reset(new WinnerAnimation("test"+boost::lexical_cast<std::string>(i%2), base->getSceneNode(id), _node));
	}
	else
	{
		_winnerAnimation.reset(new WinnerAnimationNoMove("test"+boost::lexical_cast<std::string>(i%2), base->getSceneNode(id)));
	}
	_winnerAnimation->play();
	_gameRotationInterface->update = boost::bind(&GameRotationComponent::winnerUpdate, this,  _1);
	return true;

}


bool GameRotationComponent::winnerUpdate(TimeType i)
{
	return _winnerAnimation->update(i);
}
GameRotationComponent::GameRotationComponent(void):_gameRotationInterface(new CGameRotationInterface),_needleNode(NULL),_baseNode(NULL),_node(NULL)
{


	_needleComp = Orz::ComponentFactories::getInstance().create("GameNeedle");
	_needleRotationComp = Orz::ComponentFactories::getInstance().create("Rotation");
	_baseComp = Orz::ComponentFactories::getInstance().create("GameBase");
	_baseRotationComp = Orz::ComponentFactories::getInstance().create("Rotation");


	_gameRotationInterface->init = boost::bind(&GameRotationComponent::init, this,  _1);
	_gameRotationInterface->play = boost::bind(&GameRotationComponent::play, this,  _1, _2, _3, _4);
	//_gameRotationInterface->play2 = boost::bind(&GameRotationComponent::play2, this,  _1, _2, _3, _4);
	_gameRotationInterface->winner = boost::bind(&GameRotationComponent::winner, this,  _1, _2);
	_gameRotationInterface->reset = boost::bind(&GameRotationComponent::reset, this);

	_base = 0;
	_needle = 0;
}


void GameRotationComponent::reset(void)
{
	if(_winnerAnimation)
		_winnerAnimation->reset();
}
bool GameRotationComponent::play(int needle, TimeType needleTime, int base, TimeType baseTime)
{
	CRotationInterface * rotation =NULL;

	rotation = _needleRotationComp->queryInterface<CRotationInterface>();
	rotation->play2(getStartAll(_needle* 15.f, needle * 15.f), needleTime);

	rotation = _baseRotationComp->queryInterface<CRotationInterface>();
	rotation->play2(getStartAll(_base*15.f, base * 15.f), baseTime);
	_base = base;
	_needle = needle;


	_gameRotationInterface->update = boost::bind(&GameRotationComponent::update, this,  _1);
	return true;
}

//bool GameRotationComponent::play(std::pair<int, int> & needle, TimeType needleTime, std::pair<int, int> & base, TimeType baseTime)
//{
//	CRotationInterface * rotation =NULL;
//
//	rotation = _needleRotationComp->queryInterface<CRotationInterface>();
//	rotation->play(needle.first*15.f, needle.second*15.f, needleTime);
//	
//	rotation = _baseRotationComp->queryInterface<CRotationInterface>();
//	rotation->play(base.first*15.f, base.second*15.f, baseTime);
//
//	return true;
//}
bool GameRotationComponent::update(TimeType i)
{
	CRotationInterface * rotation =NULL;

	rotation = _needleRotationComp->queryInterface<CRotationInterface>();
	bool needle = rotation->update(i);

	rotation = _baseRotationComp->queryInterface<CRotationInterface>();

	bool base = rotation->update(i);

	return base || needle;
}

bool GameRotationComponent::init(ComponentPtr sceneComp)
{
	CNewGameSceneInterface *  scene = sceneComp->queryInterface<CNewGameSceneInterface>();
	if(!scene)
		return false;
	CGameNeedleInterface * needle = _needleComp->queryInterface<CGameNeedleInterface>();



	_needleNode = scene->getHelper(CNewGameSceneInterface::Helper24)->createChildSceneNode();
	_baseNode = scene->getHelper(CNewGameSceneInterface::Helper24)->createChildSceneNode();
	_node = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(_baseNode->getPosition());

	needle->load(_needleNode);



	CRotationInterface * rotation = _needleRotationComp->queryInterface<CRotationInterface>();
	rotation->init(_needleNode, CRotationInterface::Clockwise, 90.f);
	rotation->reset(0.f);



	CGameBaseInterface * base = _baseComp->queryInterface<CGameBaseInterface>();


	base->init(_baseNode);


	for(int i = 0; i< 24; ++i)
	{
		base->load(i, scene->getHelper(CNewGameSceneInterface::HELPERS(i)));
	}



	rotation = _baseRotationComp->queryInterface<CRotationInterface>();
	rotation->init(_baseNode, CRotationInterface::Eastern, 0.f);
	rotation->reset(0.f);


	return true;
}
GameRotationComponent::~GameRotationComponent(void)
{

}


ComponentInterface * GameRotationComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(CGameRotationInterface)))
		return _gameRotationInterface.get();
	if(info == TypeInfo(typeid(CGameBaseInterface)))
		return _baseComp->_queryInterface(info);
	if(info == TypeInfo(typeid(CRotationInterface)))
	{
		return _needleRotationComp->_queryInterface(info);
	}

	return _needleComp->_queryInterface(info);

}
