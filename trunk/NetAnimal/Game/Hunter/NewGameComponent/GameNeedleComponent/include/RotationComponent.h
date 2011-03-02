#ifndef __Orz_RotationComponent__
#define __Orz_RotationComponent__
#include "CRotationInterface.h"
namespace Ogre
{
class SceneNode;
}

namespace Orz
{
class CRotationInterface;
class _UpdateInOgreRenderingQueued;
class  RotationComponent: public Component//Ðý×ª×é¼þ
{
	friend class _UpdateInOgreRenderingQueued;
public :
	RotationComponent(void);
	virtual ~RotationComponent(void);
private:
	
	ComponentInterface * _queryInterface(const TypeInfo & info);
	
	boost::scoped_ptr<CRotationInterface> _rotationInterface;




  
	void _play2(std::pair<float, float> & startAllDegree, TimeType allTime);
	bool update(TimeType interval);

	float interpolation(float value);
	float time2Degree(TimeType time);
	void  setAngle(float degree);
	float getAngle(void) const;


	static std::pair<float, float> getStartAll(float start, float end);


	void reset(float angle);
		
	void _play(float allDegree, TimeType allTime);
	void play(float startDegree, float allDegree, TimeType allTime);

	

private:
	
	bool init(Ogre::SceneNode * node,  CRotationInterface::DIRECTION direction, float offset);

	
	bool _implUpdate(TimeType interval);

	float _startDegree;
	float _endDegree;
	TimeType _allTime;
    TimeType _curTime;
	float _angle;
	float _curAngle;
	float _offsetAngle;

	Ogre::SceneNode * _node;
	
	int _direction;
	
	boost::scoped_ptr<_UpdateInOgreRenderingQueued> _update;
};



}
#endif