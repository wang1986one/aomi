#ifndef __Orz_WinEffect_h__
#define __Orz_WinEffect_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"
#include "WheelAnimalSceneObj.h"
#include "WheelAnimalProcess.h"
class OSMScene;
namespace Orz
{
	class WinEffect: public UpdateToEnable<WinEffect>
	{
	public:
		enum Effect
		{
			
			None = 0,
			Effect1 = 1,
			Effect2 = 2,
			Effect3 = 4,
			Effect4 = 8
		};
	public:
		WinEffect(boost::shared_ptr<WheelAnimalSceneObj> scene);
		virtual ~WinEffect(void);
		void enable(void);
		bool update(TimeType i);
		void show(Effect effect);
		void clear(void);
		void hideEffect();
		void setupTrailStars(void);

	private:
		boost::shared_ptr<OSMScene> _osm;
		Ogre::AnimationState * _animation;
		Ogre::SceneNode * _leyuan_tx_caitiao;
		Ogre::SceneNode * _leyuan_tx_bluehua;
		Ogre::SceneNode * _leyuan_tx_caijinyanhua1;
		Ogre::SceneNode * _leyuan_tx_caijinyanhua2;
		Ogre::SceneNode * _zp_ptj1a;
		Ogre::SceneNode * _zp_ptj1b;

		
		
		Ogre::AnimationState * _sceneAnimation;
		Ogre::AnimationState * _starAnimation;
		int _effect;
		bool _billboardIsload;
				
	};

	
	typedef boost::shared_ptr<WinEffect> WinEffectPtr;
}
#endif