#ifndef __Orz_StepAnimation__
#define __Orz_StepAnimation__

#include <orz/Toolkit_Base/ToolkitBaseAllInclude.h>
#include <orz/Framework_Base/FrameworkBaseAllInclude.h>
#include <Ogre/Ogre.h>
#include <CEGUI/CEGUI.h>
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include <orz/Toolkit_Component_Task/Component/ComponentInterface.h>	
#include <orz/Toolkit_Component_Task/Component/Component.h>	
#include <orz/Toolkit_Component_Task/Component/ComponentFactories.h>
namespace Orz
{
	class StepAnimation
	{
		typedef boost::function<void (int i)> CallbackFunction;
	public:
		CallbackFunction _callback;
	public:
		StepAnimation(const std::string & name, Ogre::SceneNode * start, int step)
		{
			_diamonLoop = Orz::ISoundManager::getSingleton().createPlayer("diamond_loop.wav");
			_diamonLoop->load();
			_step =step;

			_n = 0;
			using namespace Ogre;
			Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
			_start = start;



			Ogre::Quaternion q1,q2;

			q1.FromAngleAxis(Ogre::Radian(Ogre::Math::PI / 3 * step), Ogre::Vector3::UNIT_Y);
			q2.FromAngleAxis(Ogre::Radian(Ogre::Math::PI / 3 * (step+1)), Ogre::Vector3::UNIT_Y);


			// set up spline animation of node
			_anim = sm->createAnimation(name, 0.5f);
			//// Spline it for nice curves
			_anim->setInterpolationMode(Animation::IM_LINEAR);
			//// Create a track to animate the camera's node
			_track = _anim->createNodeTrack(0, start);

			TransformKeyFrame* key = NULL;

			key =_track->createNodeKeyFrame(0.f); // startposition
			key->setTranslate(start->getPosition() + Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(2.f, 2.f,2.f));
			key->setRotation(q1);

			key =_track->createNodeKeyFrame(0.5f); // startposition
			key->setTranslate(start->getPosition() + Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(2.f, 2.f,2.f));
			key->setRotation(q2);


			//	key = _track->createNodeKeyFrame(1.f);
			//	key->setTranslate(start->getPosition());
			//	//key->setRotation(q0);

			//	key = _track->createNodeKeyFrame(2.f);
			//	key->setTranslate(start->getPosition());
			////	key->setRotation(q1);
			//	
			//	key = _track->createNodeKeyFrame(6.f);
			//	key->setTranslate(start->getPosition());
			//	key->setRotation(q2);

			//// Create a new animation state to track this
			_animState = sm->createAnimationState(name);
			_animState->setEnabled(true);
			_animState->setLoop(false);

			reset();	
		}
		void play(void)
		{

			_animState->setTimePosition(0.f);
			_diamonLoop->play(-1);
			//_track->setAssociatedNode(node);
			_animState->setEnabled(true);

		}
		void reset(void)
		{
			_animState->setTimePosition(0.0f);
			//_time = 0.f;
		}
		bool update(TimeType interval = 0.015f)
		{

			_animState->addTime(interval);
			TimeType  pos = _animState->getTimePosition();

			int i = int(pos * 2);
			if(i > _n)
			{
				_n = i;
				if(_callback)
				{
					_callback(_step);
				}
			}
			if(_animState->hasEnded())
			{
				_diamonLoop->stop();
				Orz::ISoundManager::getSingleton().quickPlay("diamond_get.wav");
				return false;
			}
			return true;
		}
		~StepAnimation(void)
		{
			_diamonLoop->unload();
			Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimationState(_anim->getName());
			Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimation(_anim->getName());
		}

	private:
		Ogre::Animation * _anim;
		Ogre::NodeAnimationTrack * _track;
		Ogre::AnimationState* _animState;
		int _n;
		int _step;
		Ogre::SceneNode *_start;
		Orz::SoundPlayerPtr _diamonLoop; 

	};

}
#endif