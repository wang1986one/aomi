/* 
树林 的粒子系统 有问题
*/

#include "SanModelBaseStableHeaders.h"
#include "SanUI.h"
#include "ui/WeiShuWu.h"
#include "ui/Time.h"
#include "ui/Money.h"
#include <WheelGobal/WinData.h>
#include <WheelGobal/WheelData.h>


#include "CLogoInterface.h"
#include "CEndUIInterface.h"
#include "ui/UIList.h"
using namespace Orz;

template<> SanUI* Singleton<SanUI>::_singleton = NULL;
SanUI::SanUI():_logoInterface(NULL),_endUIInterface(NULL)
{
	using namespace CEGUI;
	CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
	ImagesetManager::getSingleton().create("sanui1.imageset");
	ImagesetManager::getSingleton().create("sanall.imageset");
	CEGUI::System::getSingleton().setGUISheet(CEGUI::WindowManager::getSingleton().loadWindowLayout("san_main.layout"));
	CEGUI::System::getSingleton().updateWindowContainingMouse();
	_weiShuWu.reset(new WeiShuWu());
	_time.reset(new Time());;
	_money.reset(new Money());
	_logo = Orz::ComponentFactories::getInstance().create("LogiUI");
	_end = Orz::ComponentFactories::getInstance().create("EndUI");
	_list.reset(new UIList());
	_list->draw();
	setStartUIVisible(false);

}
SanUI::~SanUI(void)
{

}
void SanUI::setTheTime(int second)//设置时间
{
	_time->show(second);
}
void SanUI::setMenuDataVisible(bool visible)//设置木记录数据的显示
{

}
void SanUI::setSetupVisible(bool visible)//设置设置界面的显示
{

}
void SanUI::menuResult(bool result)
{

}
void SanUI::writeMenuXY(int x, int y, unsigned long n)//写入目录数据
{

}
void SanUI::setLogoShow(bool visible)//设置logo是否显示
{	
	if( _logoInterface  == NULL)
	{
		if(visible)
		{
			_logoInterface = _logo->queryInterface<CLogoInterface>();
			_logoInterface->load();
			_logoInterface->show();
		}
	}
	else
	{
		if(!visible)
		{
			_logoInterface->hide();
			_logoInterface->unload();
			_logoInterface = NULL;
		}
	}
}
void SanUI::setStartUIVisible(bool visible)//设置开始UI是否显示
{
	if(visible)
	{
		CEGUI::WindowManager::getSingleton().getWindow("main/list")->show();
	}
	else
		CEGUI::WindowManager::getSingleton().getWindow("main/list")->hide();

}
void SanUI::setEndUIVisible(bool visible)//设置结束UI是否显示
{
	if( _endUIInterface  == NULL)
	{
		if(visible)
		{
			_endUIInterface = _end->queryInterface<CEndUIInterface>();

			int n = WinData::getInstance().getRate(0);//, WinData::getInstance().getAnimalItem());

			if( WinData::getInstance().getWinMode() == WheelEnum::DOUBLE)
			{
				n *= 2;

			}
			else if( WinData::getInstance().getWinMode() == WheelEnum::TREBLE)
			{
				n *= 3;

			}
			///WinData::getInstance().getWinMode()///////////////
			_endUIInterface->setMultiplaying(n);
			_endUIInterface->load(CEndUIInterface::Type(WinData::getInstance().getType()), CEndUIInterface::Soldier(WinData::getInstance().getLightColor()), CEndUIInterface::Country(WinData::getInstance().getWinner()), CEndUIInterface::Normal);
			_endUIInterface->show();

		}
	}
	else
	{
		if(!visible)
		{
			_endUIInterface->hide();
			_endUIInterface->unload();
			_endUIInterface = NULL;
		}
	}
}
void SanUI::runWinner(void)//转 “魏蜀吴”
{

	//WinData data;
	//data.load();
	_weiShuWu->reset();
	_weiShuWu->run(WinData::getInstance().getWinner());
}
void SanUI::addBottom(void)// 设置新的胜利者
{
	//WinData::getInstance().load();
	_list->add(/*WinData::getInstance()*/);
}
void SanUI::update(TimeType interval)//更新ui
{
	_weiShuWu->update(interval);
	_money->update(interval);
	if(_logoInterface)
		_logoInterface->update(interval);
	//if(_endUIInterface)
	//	_endUIInterface->update(interval);
}
