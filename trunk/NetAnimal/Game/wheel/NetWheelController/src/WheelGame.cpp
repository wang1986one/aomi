#include "NetWheelControllerStableHeaders.h"
#include <orz/View_SingleChip/SingleChipManager.h>

#include "GSMInterface.h"
#include "F5TableInterface.h"
#include "WheelGame.h"
#include "WheelUIInterface.h"
#include "WheelEngineInterface.h"
#include "PoolInterface.h"
#include "DataServerInterface.h"
#include "LockInterface.h"
#include "CommunicateInterface.h"
#include "GameGSMInterface.h"
#include "GSMInterface.h"
using namespace Orz;

//
//WheelGame::~WheelGame(void)
//{
//
//}
//
//
//WheelGame::WheelGame(EventWorld * world,  WheelEngineInterfacePtr engine, WheelClockPtr clock, EnableSceneFunction  enableSceneFunction):
//_world(world), 
//_clock(clock), 
//_enableSceneFunction(enableSceneFunction),
//_select(NULL)
//{
//	_table = Orz::ComponentFactories::getInstance().create("Table");
//	_clock->setListener(this);
//	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
//
//	_select = (Ogre::OverlayContainer*)om.createOverlayElement( "Panel", "3in1");
//#ifdef _GAME1
//	_select->setMaterialName("Material_3in12");
//#else
//	_select->setMaterialName("Material_3in1");
//#endif
//	_select->setMetricsMode(Ogre::GMM_RELATIVE);
//	_select->setWidth(1);
//	_select->setHeight(1);
//	_select->hide();
//	getOverlay()->add2D(_select);
//
//
//
//
//}
//void WheelGame::setSelectVisible(bool visible)
//{
//	if(visible)
//		_select->show();
//	else
//		_select->hide();
//}
////Ogre::Overlay * WheelGame::getOverlay(void)
//{
//	Ogre::Overlay *  overlay = NULL;
//	static std::string overlayName("getOverlay");
//	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
//	overlay = om.getByName(overlayName);
//
//	if(!overlay)
//	{
//		overlay = om.create(overlayName);
//		overlay->setZOrder(0);
//		overlay->show();
//	}
//	return overlay;
//}
//void WheelGame::addBottomToUI(void)
//{
//	_ui->addBottom();
//}
//void WheelGame::setLogoShow(bool show)
//{
//	_ui->setLogoShow(show);
//}
//void WheelGame::setAllSecond(int second)
//{
//	_clock->setAllSecond(second);
//}
//
//void WheelGame::clockChanged(int second)
//{
//
//	_ui->setTheTime(second);
//	answerTime();
//
//}
//
//
//void WheelGame::resetClock(void)
//{
//	_clock->reset();
//
//}
//
//void WheelGame::updateClock(TimeType interval)
//{
//	_clock->update(interval);
//}
//
//
//void WheelGame::update(TimeType interval)
//{
//	_ui->update(interval);
//}
//int WheelGame::answerTime(void)
//{
//	return _clock->getLastSecond();
//}
//
//Ogre::Overlay * WheelGame::getOverlay(void)
//{
//	Ogre::Overlay *  overlay = NULL;
//	static std::string overlayName("getOverlay");
//	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
//	overlay = om.getByName(overlayName);
//
//	if(!overlay)
//	{
//		overlay = om.create(overlayName);
//		overlay->setZOrder(0);
//		overlay->show();
//	}
//	return overlay;
//}
//
//
//
//void  WheelGame::setEndUIVisible(bool visible)
//{
//	_ui->setEndUIVisible(visible);
//}
//void WheelGame::setStartVisible(bool visible)
//{
//	_ui->setStartVisible(visible);
//}
//EventWorld * WheelGame::getWorld(void) const
//{
//	return _world;
//}
//
//void WheelGame::runWinner(void)
//{
//	_ui->runWinner();
//}
//
//#ifdef _GAME1
//void WheelGame::enableScene(int i)
//{
//	if(_enableSceneFunction)
//		_enableSceneFunction(i);
//}
//#else
//
//void WheelGame::enableScene(const std::string & name, bool second)
//{
//	if(_enableSceneFunction)
//		_enableSceneFunction(name, second);
//}
//#endif
