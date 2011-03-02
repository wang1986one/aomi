#include "WheelAnimalControllerStableHeaders.h"
#include "WheelAnimalUI.h"
#include "WheelUIListener.h"
#include <CEGUI/cegui.h>
#include <orz/Toolkit_Base/LogSystem.h>

#include "UITime.h"
#include "Logo.h"
#include "TVUI.h"
#include "Banker.h"
#include "List.h"
#include "Bonus.h"
#include "WinBg.h"
#include "Light.h"
#include "BlackBoardSystem.h"
#include "DanListener.h"
using namespace Orz;
template<> WheelAnimalUI* Singleton<WheelAnimalUI>::_singleton = NULL;

void WheelAnimalUI::setTheTime(int second)
{
	_time->show(second);
}

void WheelAnimalUI::setLogoShow(bool show)
{

	if(show)
	{
		_logo->show();

	}
	else
	{
		_logo->hide();
	}
}

void WheelAnimalUI::addBottom(void)
{
	_list->add();
}
void WheelAnimalUI::setStartUIVisible(bool visible)
{
	if(visible)
	{
		_time->comeIn();
		_list->show();
	}
	else
	{
		_time->goOut();
		_list->hide();
	}
}
void WheelAnimalUI::setEndUIVisible(bool visible)
{
	if(visible)
	{
		_winBg->show();
	}
	else
	{
		_winBg->hide();
	}
}
void WheelAnimalUI::runWinner(void)
{

	
	WheelEnum::WINNER winner = WinData::getInstance().getWinner();// static_cast<WheelEnum::WINNER>(BlackBoardSystem::getInstance().read<int>(WheelEnum::WINNER_STR));
	_banker->play(winner);
}

WheelAnimalUI::WheelAnimalUI(void)
{
	using namespace CEGUI;
//	CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
	//CEGUI::SchemeManager::getSingleton().create("VanillaSkin.scheme");
	ImagesetManager::getSingleton().create("UI1.imageset");
	ImagesetManager::getSingleton().create("UI2.imageset");
	ImagesetManager::getSingleton().create("UI3.imageset");
	//ImagesetManager::getSingleton().create("UI4.imageset");
	CEGUI::System::getSingleton().setGUISheet(CEGUI::WindowManager::getSingleton().loadWindowLayout("AnimalUI.layout"));
	CEGUI::System::getSingleton().updateWindowContainingMouse();

	
	_time.reset(new Time());
	_logo.reset(new Logo());
	_banker.reset(new Banker());
	_list.reset(new List());
	_bonus.reset(new Bonus());
	_TVUI.reset(new TVUI());
	_winBg.reset(new WinBg());
	_light.reset(new Light());
	/*_dan.reset(new Dan(this));
	_dan2.reset(new Dan2(this));*/

}
WheelAnimalUI::~WheelAnimalUI(void)
{
	
}

bool WheelAnimalUI::updateLight(TimeType i)
{
	return _light->update(i);
}
void WheelAnimalUI::clearLight(void)
{
	return _light->clear();
}
void WheelAnimalUI::x3(void)
{
	_light->x3();
}
//void WheelAnimalUI::setSetupVisible(bool show)
//{
//	if(show)
//	{
//		_dan2->show();
//	}else
//	{
//		_dan2->hide();
//	}
//}
//void  WheelAnimalUI::setupResult(bool ret)
//{
//	_dan2->result(ret);
//}
//
//
//void WheelAnimalUI::bao_zhang_ma(const std::string & n)
//{
//	_dan2->bao_zhang_ma(n);
//}
//	
//
//void WheelAnimalUI::setDanData(int i, int data)
//{
//	_dan2->setDan2Data(i, data);
//}

	
void WheelAnimalUI::x2(void)
{
	_light->x2();
}

void WheelAnimalUI::update(TimeType interval)
{
	_time->update(interval);
	_bonus->update(interval);
	_banker->update(interval);
	_logo->update(interval);
	_winBg->update(interval);
}


void WheelAnimalUI::setWinnerShow(bool show)
{
	if(show)
		_banker->show();
	else
		_banker->hide();
}
void WheelAnimalUI::setGold(int gold )
{
	_bonus->setBonus(gold);
}
void WheelAnimalUI::showTVUI(bool show)
{
	if(show)
	{
		_TVUI->show();
	}
	else
	{
		_TVUI->hide();
	}
}

void WheelAnimalUI::addTVUI(WheelEnum::AnimalItem item)
{
	_TVUI->add(item);
}