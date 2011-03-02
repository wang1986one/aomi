#include "WheelAnimalControllerStableHeaders.h"
#include "RotateAnimation.h"

#include <orz/View_OGRE3D/OgreRenderingQueuedListener.h>
using namespace Ogre;
namespace Orz
{
class _UpdateInOgreRenderingQueued : public OgreRenderingQueuedListener
{
public:
	_UpdateInOgreRenderingQueued(RotateAnimation * animation):_animation(animation),_enable(false)
	{
		_frameDurationHistory.push_back(WORLD_UPDATE_INTERVAL);
	}
	virtual ~_UpdateInOgreRenderingQueued(void)
	{
	}
	inline bool run(void)
	{
		
		Orz::OgreGraphicsManager::getSingleton().addRenderingQueuedListener(this);
		_enable = true;
		return true;
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
		_enable = _animation->_implUpdate(pt);

		return  true;
	}
	inline bool isEnable(void)
	{
		return _enable;
	}
	inline void stop(void)
	{
		Orz::OgreGraphicsManager::getSingleton().removeRenderingQueuedListener(this);
		
	}
private:
	RotateAnimation * _animation;
	bool _enable;
	std::deque<TimeType> _frameDurationHistory;
};
}

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
std::pair<float, float> RotateAnimation::getStartAll(float start, float end)
{
	return std::make_pair(sub360(start), getAll(start,end));
}
RotateAnimation::RotateAnimation(const std::string & name,Ogre::SceneNode * sn, Ogre::SceneManager * sm,  bool direction):_node(NULL),_angle(0),_curAngle(0.f),_direction(1),_offsetAngle(0.f)
{
	_update.reset(new _UpdateInOgreRenderingQueued(this));
	std::cout<<"RotateAnimation::RotateAnimation"<<std::endl;
	using namespace Ogre;

	//_offsetAngle = offset;
	_node = sn;
	_direction = (direction)? 1: -1;

	_firstUpdate = false;

	
}
//Ogre::AnimationState* RotateAnimation::getAnimState(void)
//{
//	return _animState;
//}


bool RotateAnimation::update(TimeType interval)
{
	/*_curTime += interval;
	setAngle(time2Degree(_curTime));
	
	return _curTime < _allTime;*/

	if(_firstUpdate)
	{
		_firstUpdate = false;
		_update->run();
	}
	bool ret = _update->isEnable();
	if(!ret)
	{
		/*if(_rotationInterface->_callback)
			_rotationInterface->_callback(_curAngle, true);*/
		_update->stop();
	}
	return ret;
}
RotateAnimation::~RotateAnimation(void)
{
}

bool RotateAnimation::_implUpdate(TimeType interval)
{
	static TimeType at = 0.f;
	at += interval;
	if(at > (3600.f *24.f))
	{
		_curTime+=interval;
	}
	_curTime += interval;
	setAngle(time2Degree(_curTime));
	return _curTime < _allTime;
}
void RotateAnimation::reset(float angle)
{
	_startDegree = angle;
	_endDegree = angle;
	setAngle(angle);
}


//float RotateAnimation::getAngle(void)
//{
//	return _animState->getTimePosition();
//}
void RotateAnimation::setAngle(float angle)
{

	//_animState->setTimePosition(angle);
	_curAngle = angle;
	Quaternion q;
	q.FromAngleAxis( Ogre::Radian(Degree(angle * _direction)),Vector3::UNIT_Y);
	/*if(_rotationInterface->_callback)   
		_rotationInterface->_callback(angle, false);*/
	
	_node->setOrientation(q);
}


float RotateAnimation::getAngle(void) const
{/*
		std::cout<<"RotateAnimation::RotateAnimation"<<std::endl;
	return _animState->getTimePosition();*/
	return _curAngle  + _offsetAngle;
}
//
//void RotateAnimation::play(float allDegree, TimeType allTime)
//{
//	_allDegree = allDegree;
//	_allTime = allTime;
//	_curTime = 0;
//	_angle = 0;
//}

void RotateAnimation::play(float allDegree, TimeType allTime)
{
	play(_endDegree, allDegree, allTime);
}
void RotateAnimation::play(float startDegree, float allDegree, TimeType allTime)
{
	
	
	_startDegree = startDegree;
	_endDegree = startDegree + allDegree;
	_allTime = allTime;
	_curTime = 0;
	_angle = startDegree;
	_firstUpdate = true;
	//_timer->start(0.01f);
}

float RotateAnimation::interpolation(float value)
{
	
	float newvalue = (value * Ogre::Math::PI) - (Ogre::Math::PI/2);
	return (Ogre::Math::Sin(newvalue) +1.f)/2.f;
}	

float RotateAnimation::time2Degree(TimeType time)
{
	if(time > _allTime || _allTime == 0)
		return _endDegree;
	return interpolation(time/_allTime) * (_endDegree - _startDegree) +_startDegree;
}