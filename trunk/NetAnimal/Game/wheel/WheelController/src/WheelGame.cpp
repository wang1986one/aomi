#include "WheelControllerStableHeaders.h"




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
void WheelGame::updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{
	_hardware->setup(p0, p1, p2, p3, p4, p5, p6, p7, p8);
}
WheelGame::WheelGame(EventWorld * world,  SetupUIPtr setupUI,  HardwarePtr hardware, WheelEngineInterfacePtr engine, WheelClockPtr clock):_world(world),_setupUI(setupUI),_hardware(hardware), _engine(engine), _clock(clock)
{
	_engine->addListener(this);
	_clock->setListener(this);
	_setupUI->addListener(this);
}
void WheelGame::addBottomToUI(void)
{
	_ui->addBottom();
}

//	///得到单件引用
//WheelGame& WheelGame::getSingleton(void)
//{
//	return static_cast<WheelGame&>(WheelGameInterface::getSingleton());
//}
//
//	///得到单件指针
//WheelGame* WheelGame::getSingletonPtr(void)
//{
//	return static_cast<WheelGame* >(WheelGameInterface::getSingletonPtr());
//}

/////////////////////////////

void WheelGame::menuResult(bool result)
{

	//_ui->menuResult(result);
	_setupUI->menuResult(result);
}
void WheelGame::actionOne(void)
{
	_hardware->actionOne();
}
void WheelGame::actionTwo(void)
{
	_hardware->actionOne();
}
void WheelGame::actionThree(void)
{
	_hardware->actionOne();
}
bool WheelGame::canAction(void)
{
	return (_clock->getLastSecond() >=2 && _clock->getAllSecond() - _clock->getLastSecond()>= 1);
}
void WheelGame::answerState(unsigned char state)
{
	_hardware->answerState(state);
}


void WheelGame::setLogoShow(bool show)
{
	_ui->setLogoShow(show);
}
void WheelGame::setAllSecond(int second)
{
	_clock->setAllSecond(second);
}
void WheelGame::setSetupVisible(bool visible)
{
	
	//_ui->setSetupVisible(visible);
	_setupUI->setSetupVisible(visible);
}
void WheelGame::setMenuDataVisible(bool visible)
{
	
	_engine->refreshMenuData();
	//_ui->setMenuDataVisible(visible);
	_setupUI->setMenuDataVisible(visible);
	
}

void WheelGame::push_data(int id, ACCOUNTS_ITEM item, unsigned long data)
{
	//_ui->writeMenuXY(int(item) -1,id,data);
	_setupUI->writeMenuXY(int(item) -1,id,data);
}
void WheelGame::push_total(ACCOUNTS_ITEM item, unsigned long data )
{
	/*_ui*/_setupUI->writeMenuXY(int(item) -1,9,data);
}


void WheelGame::uploadPassword(int password)
{
	_hardware->pushPassword(password);
}
void WheelGame::received(void)
{
	_hardware->received(true);
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
	_setupUI->update(interval);
}
void WheelGame::answerTime(void)
{
	_hardware->answerTime(_clock->getLastSecond());
}
//
//ProcessPtr WheelGame::createProcess(Event::message_type enable,  Event::message_type disable, TimeType minTime, TimeType maxTime)
//{
//	return ProcessPtr(new Process(_world, enable, disable, minTime, maxTime));
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