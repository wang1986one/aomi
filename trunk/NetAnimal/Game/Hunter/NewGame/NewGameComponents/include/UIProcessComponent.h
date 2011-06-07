#ifndef __Orz_UIProcessComponent__
#define __Orz_UIProcessComponent__
#include "UIProcessInterface.h"
#include <WheelGobal/WinData.h>
#include <CEGUI/cegui.h>
#include "CSanProcessInterface.h"
namespace Orz
{

	namespace UI
	{
		class Time;
		class Money;
		class UIList;
		class Banker;
		class WinBg;
		class Light;
		class TVUI;
		//boost::scoped_ptr<WinBg> _winBg;
	}
	class CGameActionInterface;
	class  UIProcessInterface;
	class  UIProcessComponent: public Component, public UIProcessInterface
	{

	public :
		UIProcessComponent(void);
		virtual ~UIProcessComponent(void);
	private:


		bool enableLogo(void);
		bool updateLogo(TimeType i);
		void disableLogo(void);

		virtual void setTheTime(int second);
		virtual void setMenuDataVisible(bool visible);
		virtual void setSetupVisible(bool visible);
		virtual void menuResult(bool result);
		virtual void writeMenuXY(int x, int y, unsigned long n);
		virtual void setLogoShow(bool show);
		virtual void setStartVisible(bool visible);
		virtual void setEndUIVisible(bool visible);
		virtual void runWinner(void);
		virtual void addBottom(void);
		virtual void update(TimeType interval);

		ComponentInterface * _queryInterface(const TypeInfo & info) const;
		boost::scoped_ptr<UI::Time> _time;
		boost::scoped_ptr<UI::Money> _money;
		boost::scoped_ptr<UI::UIList> _list;
		boost::scoped_ptr<UI::Banker> _banker;
		boost::scoped_ptr<UI::WinBg> _winBg;
		boost::scoped_ptr<UI::Light> _light;
		boost::scoped_ptr<UI::TVUI> _tvui;

		

		//ComponentPtr _vedio;

		SoundPlayerPtr _wait;
		SoundPlayerPtr _rotate;
		SoundPlayerPtr _bonus;

		
		boost::scoped_ptr<CGameActionInterface> _actionInterface;
		bool activate(SanProcess process);
	/*	TimeType _logo;
		TimeType _migic;*/

		bool _enable(void);
		bool _update(TimeType i);
		void _disable(void);
		TimeType _currTime;

		EventQueue _eventQueue;  
		CEGUI::Window * _logo;

	}; 



}
#endif