
#include "SanControllerBaseStableHeaders.h"

#include "OgreCCSComponent.h"
#include "COgreCCSInterface.h"
#include "CCSCameraControlSystem.h"
#include "CCSFreeCameraMode.h"
#include "CUpdateInterface.h"

using namespace Orz;
//KeyListenerWithRecord::KeyListenerWithRecord(void)
//{
//
//}
//KeyListenerWithRecord::KeyListenerWithRecord(void)
//{
//
//}
//	virtual bool KeyListenerWithRecord::doKeyPressed(const MouseEvent & evt);
//	virtual bool KeyListenerWithRecord::doKeyReleased(const MouseEvent & evt);
//
//	virtual bool KeyListenerWithRecord::onKeyPressed(const KeyEvent & evt);
//	virtual bool KeyListenerWithRecord::onKeyReleased(const KeyEvent & evt);
//	std::bitse<KC_MEDIASELECT+1> _keyMap;
//}
OgreCCSComponent::OgreCCSComponent(void):_ccsInterface(new COgreCCSInterface()),_ccs(),_freeCameraMode(),_updateInterface(new CUpdateInterface()),
_KC_A(false),
_KC_D(false),
_KC_UP(false),
_KC_W(false),
_KC_DOWN(false),
_KC_S(false),
_KC_PGUP(false),
_KC_PGDOWN(false),
_KC_RIGHT(false),
_KC_LEFT(false)
{
	_ccs.reset(new CCS::CameraControlSystem(Orz::OgreGraphicsManager::getSingleton().getSceneManager(), "CameraControlSystem", Orz::OgreGraphicsManager::getSingleton().getCamera()));
	_freeCameraMode.reset(new CCS::FreeCameraMode(_ccs.get()));
	//_ccs->registerCameraMode("Free",camMode9);
	_freeCameraMode->setMoveFactor(30);
	_ccs->setCurrentCameraMode(_freeCameraMode.get());
	_updateInterface->update = boost::bind(&OgreCCSComponent::update,this, _1); 
	_ccsInterface->print = boost::bind(&OgreCCSComponent::printCameras,this); 
	_ccsInterface->getCCS = boost::bind(&OgreCCSComponent::getCCS,this); 

		
	IInputManager::getSingleton().addKeyListener(this);
	IInputManager::getSingleton().addMouseListener(this);
}

CCS::CameraControlSystem * OgreCCSComponent::getCCS(void)
{
	return _ccs.get();
}
		
bool OgreCCSComponent::update(TimeType interval)
{

	if(_KC_A)
		_freeCameraMode->goLeft();
	if(_KC_D)
		_freeCameraMode->goRight();
	if(_KC_UP ||_KC_W )
		_freeCameraMode->goForward();
	if(_KC_DOWN || _KC_S)
		_freeCameraMode->goBackward();
	if(_KC_PGUP)
		_freeCameraMode->goUp();
	if(_KC_PGDOWN)
		_freeCameraMode->goDown();
	if(_KC_RIGHT)
		_freeCameraMode->yaw(-1);
	if(_KC_LEFT)
		_freeCameraMode->yaw(1);




	_ccs->update(interval);

	return true;
}

bool OgreCCSComponent::onMousePressed(const MouseEvent & evt)
{

	return false;
}
///通知鼠标释放事件
bool OgreCCSComponent::onMouseReleased(const MouseEvent & evt)
{

	return false;
}
///通知鼠标移动事件
bool OgreCCSComponent::onMouseMoved(const MouseEvent & evt)
{ 

	if(_ccs->getCurrentCameraMode() == _freeCameraMode.get())
	{

		_freeCameraMode->yaw(evt.getX());
		_freeCameraMode->pitch(evt.getY());
	}
	return false;

}

///通知键盘按下事件
bool OgreCCSComponent::onKeyPressed(const KeyEvent & evt)
{

	switch(evt.getKey())
	{
	case KC_A:
		_KC_A = true;
		break;

	case KC_D:
		_KC_D = true;
		break;
	case KC_UP:
		_KC_UP= true;
		break;
	case KC_W:
		_KC_W = true;
		break;
	case KC_DOWN:
		_KC_DOWN = true;
		break;
	case KC_S:
		_KC_S= true;
		break;
	case KC_PGUP:
		_KC_PGUP = true;
		break;
	case KC_PGDOWN:
		_KC_PGDOWN = true;
		break;
	case KC_RIGHT:
		_KC_RIGHT = true;
		break;

	case KC_LEFT:
		_KC_LEFT = true;
		break;

	case Orz::KC_BACK:
		printCameras();
		break;
	}



	return false;
};


void OgreCCSComponent::printCameras(void)
{
      /*      Ogre::Vector3 getCameraPosition() { return mCameraPosition; }
            Ogre::Quaternion getCameraOrientation() { return mCameraOrientation; }*/

	ORZ_LOG_NOTIFICATION_MESSAGE("Camera Message:" + boost::lexical_cast<std::string>(_ccs->getCameraPosition()) +boost::lexical_cast<std::string>(_ccs->getCameraOrientation()));//<<"Camera Message:"<<_ccs->getCameraPosition()<<;
}
///通知键盘释放事件
bool OgreCCSComponent::onKeyReleased(const KeyEvent & evt)
{

	switch(evt.getKey())
	{
	case KC_A:
		_KC_A = false;
		break;
	case KC_D:
		_KC_D = false;
		break;
	case KC_UP:
		_KC_UP= false;
		break;
	case KC_W:
		_KC_W = false;
		break;
	case KC_DOWN:
		_KC_DOWN = false;
		break;
	case KC_S:
		_KC_S= false;
		break;
	case KC_PGUP:
		_KC_PGUP = false;
		break;
	case KC_PGDOWN:
		_KC_PGDOWN = false;
		break;
	case KC_RIGHT:
		_KC_RIGHT = false;
		break;
	case KC_LEFT:
		_KC_LEFT = false;
		break;


	}

	return false;
}
OgreCCSComponent::~OgreCCSComponent(void)
{
	_ccs->deleteAllCameraModes();

	IInputManager::getSingleton().removeMouseListener(this);
	IInputManager::getSingleton().removeKeyListener(this);
}


ComponentInterface * OgreCCSComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(COgreCCSInterface)))
	{
		return _ccsInterface.get();
	}
	else if(info == TypeInfo(typeid(CUpdateInterface)))
	{
		return _updateInterface.get();
	}
	return NULL;
}