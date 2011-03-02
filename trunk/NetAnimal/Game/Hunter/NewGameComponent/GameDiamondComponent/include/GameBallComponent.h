#ifndef __Orz_GameBallComponent__
#define __Orz_GameBallComponent__
#include "CGameBallInterface.h"
class _UpdateInOgreRenderingQueued_Ball;
namespace Ogre
{
class SceneNode;
}
namespace ParticleUniverse
{
class ParticleUniverseSystem;
}

class MyMaterialInstance;
namespace Orz
{
class CGameBallInterface;
class  GameBallComponent: public Component
{ 
public :
	friend _UpdateInOgreRenderingQueued_Ball;
	GameBallComponent(void);
	virtual ~GameBallComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);

	boost::scoped_ptr<CGameBallInterface> _BallInterface;
	bool load(Ogre::SceneNode * node);

	boost::scoped_ptr<MyMaterialInstance> _emi;

	bool enable(CGameBallInterface::STATE state);
	bool update(TimeType time);
	bool updateFatein(TimeType time);
	bool updateFateout(TimeType time);
	bool updateRotate(TimeType time);
	bool updatesetNumber(TimeType time);
	void addNumber(int n);
	void setNumber(int Num);//设定显示的数字0-9
	void setAngle(float angle);
	Ogre::SceneNode* ballnode;
	TimeType stopTimePass;
	bool isStop;
	bool isThisRoundDisplayed;
	Ogre::Vector3 _pos;
	Ogre::SceneNode * _node;
	TimeType _curTime;
	TimeType _runAllTime;
	Ogre::Entity * Ball;
	Ogre::BillboardSet* bbset;
	Ogre::Billboard* bb;
	std::deque<UINT> _dequeNumber;
	ParticleUniverse::ParticleUniverseSystem * psystem;
	boost::scoped_ptr<_UpdateInOgreRenderingQueued_Ball> _updateInOgreRenderingQueued_Ball;
};
}
#endif
