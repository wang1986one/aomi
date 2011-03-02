#ifndef __Orz_GameDiamondMoreWinderComponent__
#define __Orz_GameDiamondMoreWinderComponent__
//#include "CGameDiamondMoreWinderInterface.h"
namespace Ogre
{
	class SceneNode;
}


namespace Orz
{

	class BiggerAnimation;
	class RunAnimation;
	class StepAnimation;
	class CGameDiamondMoreWinderInterface;
	class Updater;
	class  GameDiamondMoreWinderComponent: public Component
	{ 
	public :
		GameDiamondMoreWinderComponent(void);
		virtual ~GameDiamondMoreWinderComponent(void);
	private:
		bool init(Ogre::SceneNode * node);
		bool addEntity(int i, Ogre::Entity * ent);

		bool bigger(void);
		bool step(void);
		void runNumber(int i);
		void stepNumber(int i);
		void _reset(void);
		void reset(void);
		void stop(void);
		ComponentInterface * _queryInterface(const TypeInfo & info);

		bool run(int num);
		boost::scoped_ptr<CGameDiamondMoreWinderInterface> _moreWinnerInterface;
		boost::scoped_ptr<BiggerAnimation> _biggerAnimation;
		boost::scoped_ptr<RunAnimation> _runAnimation;
		boost::scoped_ptr<StepAnimation> _stepAnimation;
		
		boost::scoped_ptr<Updater> _updater;

		boost::array<Ogre::Entity *, 6> _entitys;
		Ogre::SceneNode * _node;
		Ogre::Vector3 _pos;
		
		Ogre::Animation * _anim;
		Ogre::NodeAnimationTrack * _track;
		Ogre::AnimationState* _animState;
		int _number;
		int _step;
		//ComponentPtr _rotationComp;
		//typedef boost::function<bool (int)> RunFunction;
	};
}
#endif
