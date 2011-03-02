#ifndef __Orz_WinnerAnimation_h__
#define __Orz_WinnerAnimation_h__
namespace ParticleUniverse
{
	class ParticleSystemManager;
	class ParticleUniverseSystem;
	class ParticleSystem;
}
namespace Orz
{
	class WinnerAnimationInterface
	{
	public:
		virtual void play(void) = 0;
		virtual void reset(void) = 0;
		virtual bool  update(TimeType interval) = 0;
		virtual ~WinnerAnimationInterface(void){}
	};
	class WinnerAnimation:public WinnerAnimationInterface
	{
	public:
		WinnerAnimation(const std::string & name, Ogre::SceneNode * start, const Ogre::SceneNode * end);
		void play(void);
		void reset(void);
		bool update(TimeType interval = 0.015f);
		~WinnerAnimation(void);
	private:
		Ogre::Animation * _anim;
		Ogre::NodeAnimationTrack * _track;
		Ogre::AnimationState* _animState;
		ParticleUniverse::ParticleSystemManager * particleSystemManager;
		ParticleUniverse::ParticleSystem * _system;
		//*_system1;
		Ogre::SceneNode *_start;
	};


	class WinnerAnimationNoMove:public WinnerAnimationInterface
	{
	public:
		WinnerAnimationNoMove(const std::string & name, Ogre::SceneNode * start);
		void play(void);
		void reset(void);
		bool update(TimeType interval = 0.015f);
		~WinnerAnimationNoMove(void);
	private:
		Ogre::Animation * _anim;
		Ogre::NodeAnimationTrack * _track;
		Ogre::AnimationState* _animState;
		ParticleUniverse::ParticleSystem * _system;
		
		ParticleUniverse::ParticleSystemManager * particleSystemManager;
		Ogre::SceneNode *_start;
	};
}


#endif
