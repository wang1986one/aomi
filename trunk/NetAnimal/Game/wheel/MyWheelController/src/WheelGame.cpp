#include "MyWheelControllerStableHeaders.h"




#include "WheelGame.h"
#include "WheelUIInterface.h"
#include "WheelEngineInterface.h"
using namespace Orz;

WheelGame::~WheelGame(void)
{
}
//void WheelGame::askForData(void)
//{
//
//}
//void WheelGame::updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
//{
//	_hardware->setup(p0, p1, p2, p3, p4, p5, p6, p7, p8);
//}
WheelGame::WheelGame(EventWorld * world,  WheelEngineInterfacePtr engine, WheelClockPtr clock, boost::function< void (const std::string & , bool) >  enableSceneFunction):
_world(world), 
_engine(engine), 
_clock(clock), 
_enableSceneFunction(enableSceneFunction),
_select(NULL)
{
	//_engine->addListener(this);
	_clock->setListener(this);
	//_dataServer =  Orz::ComponentFactories::getInstance().create("DataServer");
	_jsComp = Orz::ComponentFactories::getInstance().create("Js");
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();

	_select = (Ogre::OverlayContainer*)om.createOverlayElement( "Panel", "3in1");
	_select->setMaterialName("Material_3in1");
	_select->setMetricsMode(Ogre::GMM_RELATIVE);
	_select->setWidth(1);
	_select->setHeight(1);
	_select->hide();
	getOverlay()->add2D(_select);
	_num = 0;
}


Orz::ComponentPtr WheelGame::getJs(void) const
{
	return _jsComp;
}
void WheelGame::addBottomToUI(void)
{
	_ui->addBottom();
}
void WheelGame::setSelectVisible(bool visible)
{/*
	if(visible)
		_select->show();
	else*/
		_select->hide();
}

void WheelGame::setLogoShow(bool show)
{
	_ui->setLogoShow(show);
}
void WheelGame::setAllSecond(int second)
{
	_clock->setAllSecond(second);
}

void WheelGame::clockChanged(int second)
{
	
	_ui->setTheTime(second);
	answerTime();
	
}

void WheelGame::resetClock(void)
{
	_clock->reset();

}

void WheelGame::updateClock(TimeType interval)
{
	_clock->update(interval);
}


void WheelGame::update(TimeType interval)
{
	_ui->update(interval);
}
int WheelGame::answerTime(void)
{
	return _clock->getLastSecond();
}

int WheelGame::addAndGetNum()
{
	++_num;
	return _num;
}
Ogre::Overlay * WheelGame::getOverlay(void)
{
	Ogre::Overlay *  overlay = NULL;
	static std::string overlayName("getOverlay");
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	overlay = om.getByName(overlayName);

	if(!overlay)
	{
		overlay = om.create(overlayName);
		overlay->setZOrder(0);
		overlay->hide();
	}
	return overlay;
}


//ComponentPtr WheelGame::getDataServer(void)
//{
//	return _dataServer;
//}




void  WheelGame::setEndUIVisible(bool visible)
{
	_ui->setEndUIVisible(visible);
}
void WheelGame::setStartUIVisible(bool visible)
{
	_ui->setStartUIVisible(visible);
}
EventWorld * WheelGame::getWorld(void) const
{
	return _world;
}


	
void WheelGame::runWinner(void)
{
	_ui->runWinner();
}



void WheelGame::enableScene(const std::string & name, bool second)
{
	if(_enableSceneFunction)
		_enableSceneFunction(name, second);
}