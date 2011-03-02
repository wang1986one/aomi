#ifndef __Orz_RotateAnimation_h__
#define __Orz_RotateAnimation_h__	  
#include "WheelAnimalControllerConfig.h"
#include <Ogre/Ogre.h>
namespace Orz
{
	class _UpdateInOgreRenderingQueued;
	class RotateAnimation
	{
	public:
		RotateAnimation(const std::string & name,Ogre::SceneNode * sn, Ogre::SceneManager * sm,  bool direction);
		Ogre::AnimationState* getAnimState(void);

	
		inline void play(std::pair<float, float> startAllDegree, TimeType allTime)
		{
			play(startAllDegree.first, startAllDegree.second, allTime);
		}
		bool update(TimeType interval/*********/);
		~RotateAnimation(void);

		float interpolation(float value);
		/*float getAllDegree(void) const 
		{
			return _allDegree;
		}*/
		
		float time2Degree(TimeType time);
		//float getAngle(void);
		void setAngle(float degree);
		float getAngle(void) const;


		static std::pair<float, float> getStartAll(float start, float end);

		bool _implUpdate(TimeType interval);
	private:
		void reset(float angle);
		
		void play(float allDegree, TimeType allTime);
		void play(float startDegree, float allDegree, TimeType allTime);



		float _startDegree;
		float _endDegree;
		TimeType _allTime;
		TimeType _curTime;
		float _angle;
		float _curAngle;
		float _offsetAngle;

		Ogre::SceneNode * _node;
		
		int _direction;
		bool _firstUpdate;
		

		
		boost::scoped_ptr<_UpdateInOgreRenderingQueued> _update;
	};
}


#endif
