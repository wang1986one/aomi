#include "NetWheelDirectorStableHeaders.h"
#include "DUI/DUI.h"
#include <CEGUI/cegui.h>
#include <orz/Toolkit_Base/LogSystem.h>

#include "GSMInterface.h"
#include "DUI/Dan.h"
#include "DUI/Dan2.h"
using namespace Orz;
template<> DUI* Singleton<DUI>::_singleton = NULL;

 
DUI::DUI(ComponentPtr dataServer, GSMInterface * gsm)
{
	using namespace CEGUI;
	CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
	CEGUI::SchemeManager::getSingleton().create("VanillaSkin.scheme");
	ImagesetManager::getSingleton().create("UI4.imageset");
	//ImagesetManager::getSingleton().create("UI1.imageset");
	//ImagesetManager::getSingleton().create("UI2.imageset");
	//ImagesetManager::getSingleton().create("UI3.imageset");
	//
	//CEGUI::System::getSingleton().setGUISheet(CEGUI::WindowManager::getSingleton().loadWindowLayout("AnimalUI.layout"));
	//CEGUI::System::getSingleton().updateWindowContainingMouse();

	_dan.reset(new Dan(this, dataServer, gsm));
	_dan2.reset(new Dan2(this));

}
DUI::~DUI(void)
{
	
}

bool DUI::update(TimeType i)
{
	_dan->update(i);
	return true;
}


void DUI::updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{

	//if(_listener)
	//	_listener->updateUIData(  p0,   p1,   p2,   p3,   p4,   p5,   p6,   p7,   p8);
}
void DUI::uploadPassword(int password)
{
	//if(_listener)
	//	_listener->uploadPassword(password);
}
void DUI::setMenuDataVisible(bool visible)
{
	if(visible)
		_dan->show();
	else
		_dan->hide();
}
void DUI::menuResult(bool result)
{
	_dan->result(result);
}

void DUI::writeMenuXY(int x, int y, unsigned long n)
{
	_dan->write(x, y, Ogre::StringConverter::toString(n));
}

void DUI::setSetupVisible(bool show)
{
	if(show)
	{
		_dan2->show();
	}else
	{
		_dan2->hide();
	}
}
void  DUI::setupResult(bool ret)
{
	_dan2->result(ret);
}


void DUI::bao_zhang_ma(const std::string & n)
{
	_dan2->bao_zhang_ma(n);
}
	

void DUI::setDanData(int i, int data)
{
	_dan2->setDan2Data(i, data);
}