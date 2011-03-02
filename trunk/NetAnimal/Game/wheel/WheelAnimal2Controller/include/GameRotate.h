#ifndef __Orz_Tutorial_GameRotate_h__
#define __Orz_Tutorial_GameRotate_h__
#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalProcess.h"
namespace Orz
{
	
	
	
	
    class WheelAnimalSceneObj;
	class RotateAnimation;
	class AnimalChange;
	class GameRotate: public WheelAnimalProcess , public UpdateToEnable<GameRotate>
	{
	public:
		GameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			float nAngle,
			float rAngle
			);
		virtual ~GameRotate(void);
		virtual void enable(void);
		virtual bool update(TimeType interval/*********/);
		void clear(void);
	private:

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;	 
	

	};
	

	class AnimalGameRotate: public WheelAnimalProcess, public UpdateToEnable<AnimalGameRotate>
	{
	public:

		AnimalGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
			boost::shared_ptr<AnimalChange> ac,
			boost::shared_ptr<RotateAnimation> needle,
			boost::shared_ptr<RotateAnimation> rotate,
			int winner,
			float nAngle,
			float rAngle
			);
		virtual ~AnimalGameRotate(void);
		void enable(void);
		virtual bool update(TimeType interval/*********/);
		void clear(void);

		//virtual void resetRotate(void);
		//virtual Ogre::Degree getRotateAngle(void);
		
	private:

		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		boost::shared_ptr<RotateAnimation> _rotate;
		boost::shared_ptr<RotateAnimation> _needle;
		boost::shared_ptr<AnimalChange> _ac;
		int _winner;

	};
	



}

#endif 