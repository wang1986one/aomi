#ifndef __Orz_BiggerAnimation__
#define __Orz_BiggerAnimation__

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
	class BiggerAnimation
	{
	public:
		BiggerAnimation(const std::string & name, Ogre::SceneNode * start)
		{
			using namespace Ogre;
			Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
			_start = start;
			
			

			Orz::ISoundManager::getSingleton().quickPlay("sucess.wav");
			// set up spline animation of node
			_anim = sm->createAnimation(name, 2.0f);
			//// Spline it for nice curves
			_anim->setInterpolationMode(Animation::IM_LINEAR);
			//// Create a track to animate the camera's node
			_track = _anim->createNodeTrack(0, start);

			TransformKeyFrame* key = _track->createNodeKeyFrame(0); // startposition
			key->setTranslate(start->getPosition());
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(1.f, 1.f,1.f));


			key = _track->createNodeKeyFrame(0.1f);
			key->setTranslate(start->getPosition()+ Ogre::Vector3(0, 100, 150));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(1.0f, 1.0f,1.0f));

			

			key = _track->createNodeKeyFrame(0.2f);
			key->setTranslate(start->getPosition()+ Ogre::Vector3(0, 100, 200));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(1.0f, 1.0f,1.0f));




			/*key = _track->createNodeKeyFrame(0.2f);
			key->setTranslate(start->getPosition());
			key->setRotation(start->getOrientation());	 
			key->setScale(Ogre::Vector3(1.f, 1.f,1.f));

			key = _track->createNodeKeyFrame(0.3f); 
			key->setTranslate(start->getPosition());
			key->setRotation(start->getOrientation());   
			key->setScale(Ogre::Vector3(1.2f, 1.2f,1.2f));

			key = _track->createNodeKeyFrame(0.4f); 
			key->setTranslate(start->getPosition());
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(1.f, 1.f, 1.f));

			key = _track->createNodeKeyFrame(0.5f);
			key->setTranslate(start->getPosition());
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(1.1f, 1.1f, 1.1f));

			key = _track->createNodeKeyFrame(0.6f);
			key->setTranslate(start->getPosition());
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(1.f, 1.f, 1.f));*/

			
			key = _track->createNodeKeyFrame(0.4f);
			key->setTranslate(start->getPosition() + Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(1.f, 1.f,1.f));




			key = _track->createNodeKeyFrame(0.6f);
			key->setTranslate(start->getPosition() + Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(2.3f, 2.3f,2.3f));


			
			key = _track->createNodeKeyFrame(0.8f);
			key->setTranslate(start->getPosition()+ Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation() );
			key->setScale(Ogre::Vector3(1.8f, 1.8f,1.8f));

			
			key = _track->createNodeKeyFrame(0.9f);
			key->setTranslate(start->getPosition() + Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(2.1f, 2.1f,2.1f));

			key = _track->createNodeKeyFrame(1.0f);
			key->setTranslate(start->getPosition() + Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(2.0f, 2.0f,2.0f));



			key = _track->createNodeKeyFrame(2.0f);
			key->setTranslate(start->getPosition() + Ogre::Vector3(0, 0, 300));
			key->setRotation(start->getOrientation());
			key->setScale(Ogre::Vector3(2.f, 2.f,2.f));



			//// Create a new animation state to track this
			_animState = sm->createAnimationState(name);
			_animState->setEnabled(true);
			_animState->setLoop(false);

			reset();	
		}
		void play(void)
		{
			Orz::ISoundManager::getSingleton().quickPlay("diamond_big.wav");
			_animState->setTimePosition(0.f);
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
	


			return !_animState->hasEnded();
		}
		~BiggerAnimation(void)
		{
			
			Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimationState(_anim->getName());
			Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimation(_anim->getName());
		}

	private:
		Ogre::Animation * _anim;
		Ogre::NodeAnimationTrack * _track;
		Ogre::AnimationState* _animState;

		Ogre::SceneNode *_start;
	};

}
#endif