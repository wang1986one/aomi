#include "WheelAnimalControllerStableHeaders.h"
#include "WinnerAnimation.h"


using namespace Orz;




WinnerAnimation::WinnerAnimation(const std::string & name, Ogre::SceneNode * start, const Ogre::SceneNode * end):_anim(NULL)
{

	using namespace Ogre;

	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	// set up spline animation of node
	_anim = sm->createAnimation(name, 4);
	//// Spline it for nice curves
	_anim->setInterpolationMode(Animation::IM_LINEAR);
	//// Create a track to animate the camera's node
	_track = _anim->createNodeTrack(0, start);

	TransformKeyFrame* key = _track->createNodeKeyFrame(0); // startposition
	key->setTranslate(start->getPosition());
	key->setRotation(start->getOrientation());
	key->setScale(Ogre::Vector3(1.f, 1.f,1.f));
	
	key = _track->createNodeKeyFrame(0.1f);
	key->setTranslate(start->getPosition());
	key->setRotation(start->getOrientation());	  
	key->setScale(Ogre::Vector3(1.3f, 1.3f,1.3f));
	
	key = _track->createNodeKeyFrame(0.2f);
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
	key->setScale(Ogre::Vector3(1.f, 1.f,1.f));
														 
	key = _track->createNodeKeyFrame(0.5f);
	key->setTranslate(start->getPosition());
	key->setRotation(start->getOrientation());
	key->setScale(Ogre::Vector3(1.1f, 1.1f,1.1f));

	key = _track->createNodeKeyFrame(0.6f);
	key->setTranslate(start->getPosition());
	key->setRotation(start->getOrientation());
	key->setScale(Ogre::Vector3(1.f, 1.f,1.f));



	Ogre::Vector3 begin_point = start->getPosition()+Ogre::Vector3(0, 300, 0);
	Ogre::Vector3 end_point = end->getPosition()+Ogre::Vector3(0, 200, 0);


	key = _track->createNodeKeyFrame(1.5f); 
	key->setTranslate(begin_point);
	key->setRotation(start->getOrientation());
	
   

	key = _track->createNodeKeyFrame(4);
	key->setTranslate(end_point);
	key->setRotation(end->getOrientation());
	

	//// Create a new animation state to track this
	_animState = sm->createAnimationState(name);
	_animState->setEnabled(true);
	_animState->setLoop(false);

	reset();
}
void WinnerAnimation::play()
{
	
	//_track->setAssociatedNode(node);
	_animState->setEnabled(true);
	_animState->setTimePosition(0.f);

}
void WinnerAnimation::reset()
{
	_animState->setEnabled(true);
	_animState->setTimePosition(0.0f);
	//_time = 0.f;
}
bool WinnerAnimation::update(TimeType interval)
{
	
	_animState->addTime(interval);
	
	if(_animState->hasEnded())
	{	
		
		
		return false;
	}
	
	return true;
}
WinnerAnimation::~WinnerAnimation(void)
{
	reset();
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimationState(_anim->getName());
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimation(_anim->getName());
}







////////////////////////////





WinnerAnimationNoMove::WinnerAnimationNoMove(const std::string & name, Ogre::SceneNode * start):_anim(NULL)
{

	using namespace Ogre;

	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	// set up spline animation of node
	_anim = sm->createAnimation(name, 0.7f);
	//// Spline it for nice curves
	_anim->setInterpolationMode(Animation::IM_LINEAR);
	//// Create a track to animate the camera's node
	_track = _anim->createNodeTrack(0, start);

	TransformKeyFrame* key = _track->createNodeKeyFrame(0); // startposition
	key->setTranslate(start->getPosition());
	key->setRotation(start->getOrientation());
	key->setScale(Ogre::Vector3(1.f, 1.f,1.f));
	
	key = _track->createNodeKeyFrame(0.1f);
	key->setTranslate(start->getPosition());
	key->setRotation(start->getOrientation());	  
	key->setScale(Ogre::Vector3(1.3f, 1.3f,1.3f));
	
	key = _track->createNodeKeyFrame(0.2f);
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
	key->setScale(Ogre::Vector3(1.f, 1.f, 1.f));




	

	//// Create a new animation state to track this
	_animState = sm->createAnimationState(name);
	_animState->setEnabled(true);
	_animState->setLoop(false);

	reset();
}
void WinnerAnimationNoMove::play()
{
	
	_animState->setTimePosition(0.f);
	//_track->setAssociatedNode(node);
	_animState->setEnabled(true);

}
void WinnerAnimationNoMove::reset()
{
	_animState->setTimePosition(0.0f);
	//_time = 0.f;
}
bool WinnerAnimationNoMove::update(TimeType interval)
{
	
	_animState->addTime(interval);
	if(_animState->hasEnded())
	{
		return false;
	}
	
	return true;
}
WinnerAnimationNoMove::~WinnerAnimationNoMove(void)
{
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimationState(_anim->getName());
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->destroyAnimation(_anim->getName());
}


