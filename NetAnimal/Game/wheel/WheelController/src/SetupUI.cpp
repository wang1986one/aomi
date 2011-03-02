#include "WheelControllerStableHeaders.h"
#include "SetupUI.h"
#include "Dan.h"
#include "Dan2.h"
	
using namespace Orz;

SetupUI::SetupUI(void)
{
	
	using namespace CEGUI;
		CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
		CEGUI::SchemeManager::getSingleton().create("VanillaSkin.scheme");
		ImagesetManager::getSingleton().create("UI1.imageset");
		ImagesetManager::getSingleton().create("UI2.imageset");
		ImagesetManager::getSingleton().create("UI3.imageset");
		ImagesetManager::getSingleton().create("UI4.imageset");
	_dan.reset(new Dan(this));
	_dan2.reset(new Dan2(this));
}
SetupUI::~SetupUI(void)
{


}



void SetupUI::setSetupVisible(bool show)
{
	if(show)
	{
		_dan2->show();
	}else
	{
		_dan2->hide();
	}
}
void  SetupUI::setupResult(bool ret)
{
	_dan2->result(ret);
}


void SetupUI::bao_zhang_ma(const std::string & n)
{
	_dan2->bao_zhang_ma(n);
}
	

void SetupUI::setDanData(int i, int data)
{
	_dan2->setDan2Data(i, data);
}


void SetupUI::updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{

	if(_listener)
		_listener->updateUIData(  p0,   p1,   p2,   p3,   p4,   p5,   p6,   p7,   p8);
}
void SetupUI::uploadPassword(int password)
{
	if(_listener)
		_listener->uploadPassword(password);
}

void SetupUI::update(TimeType interval)
{
	_dan->update(interval);
	_dan2->update(interval);
}

void SetupUI::setMenuDataVisible(bool visible)
{
	if(visible)
		_dan->show();
	else
		_dan->hide();
}
void SetupUI::menuResult(bool result)
{
	_dan->result(result);
}
void SetupUI::writeMenuXY(int x, int y, unsigned long n)
{
	_dan->write(x, y, Ogre::StringConverter::toString(n));
}



void SetupUI::addListener(SetupUIListener * listener)
{
	_listener = listener;
}
void SetupUI::removeListener(SetupUIListener * listener)
{
	_listener = NULL;
}