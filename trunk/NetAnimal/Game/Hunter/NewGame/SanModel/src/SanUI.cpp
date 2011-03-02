/* 
���� ������ϵͳ ������
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
void SanUI::setTheTime(int second)//����ʱ��
{
	_time->show(second);
}
void SanUI::setMenuDataVisible(bool visible)//����ľ��¼���ݵ���ʾ
{

}
void SanUI::setSetupVisible(bool visible)//�������ý������ʾ
{

}
void SanUI::menuResult(bool result)
{

}
void SanUI::writeMenuXY(int x, int y, unsigned long n)//д��Ŀ¼����
{

}
void SanUI::setLogoShow(bool visible)//����logo�Ƿ���ʾ
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
void SanUI::setStartUIVisible(bool visible)//���ÿ�ʼUI�Ƿ���ʾ
{
	if(visible)
	{
		CEGUI::WindowManager::getSingleton().getWindow("main/list")->show();
	}
	else
		CEGUI::WindowManager::getSingleton().getWindow("main/list")->hide();

}
void SanUI::setEndUIVisible(bool visible)//���ý���UI�Ƿ���ʾ
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
void SanUI::runWinner(void)//ת ��κ���⡱
{

	//WinData data;
	//data.load();
	_weiShuWu->reset();
	_weiShuWu->run(WinData::getInstance().getWinner());
}
void SanUI::addBottom(void)// �����µ�ʤ����
{
	//WinData::getInstance().load();
	_list->add(/*WinData::getInstance()*/);
}
void SanUI::update(TimeType interval)//����ui
{
	_weiShuWu->update(interval);
	_money->update(interval);
	if(_logoInterface)
		_logoInterface->update(interval);
	//if(_endUIInterface)
	//	_endUIInterface->update(interval);
}
