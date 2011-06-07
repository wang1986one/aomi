#ifndef __Orz_WheelAnimalUI_h__
#define __Orz_WheelAnimalUI_h__	

#include "DanListener.h"
#include "WheelAnimalControllerConfig.h"
#include "WheelUIInterface.h"
#include "WheelEnum.h"
#include <orz/Toolkit_Base/FSMLogic.h>
namespace Orz
{
	class Bonus;
	class Banker;
	class Time;
	class List;
	class WinBg;
	class Logo;
	//class Dan;
	class TVUI;
	class Light;
	/*class Dan2;*/
	class _OrzWheelAnimal2ControllerExport WheelAnimalUI: public WheelUIInterface/*, public DanListener*/, public Singleton<WheelAnimalUI>
	{
	public:
		virtual void setTheTime(int second);
		
		virtual void setLogoShow(bool show);
		virtual void setStartVisible(bool visible);
		virtual void setEndUIVisible(bool visible);
		virtual void runWinner(void);
		virtual void update(TimeType interval);
		virtual void addBottom(void);

		WheelAnimalUI(void);
		virtual ~WheelAnimalUI(void);


				
		bool updateLight(TimeType i);
		void clearLight(void);
		void x3(void);

		void x2(void);

		void setWinnerShow(bool show);
		void setGold(int gold );
		void showTVUI(bool show);
		void addTVUI(WheelEnum::AnimalItem item);


		
	/*	virtual void updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
		virtual void uploadPassword(int password);

		virtual void setMenuDataVisible(bool visible);
		virtual void menuResult(bool result);
		virtual void writeMenuXY(int x, int y, unsigned long n);

		
		void setSetupVisible(bool show);
		void setupResult(bool ret);
		void bao_zhang_ma(const std::string & n);
		void setDanData(int i, int data);*/
	private:
	//	typedef std::map<std::pair<WheelEnum::AnimalType, WheelEnum::LIGHT_COLOR>, int> UIMap;
	//	UIMap _uiMap;
		boost::scoped_ptr<Time> _time;
		boost::scoped_ptr<Logo> _logo;
		boost::scoped_ptr<List> _list;
		boost::scoped_ptr<Banker> _banker;
		boost::scoped_ptr<Bonus> _bonus;
		boost::scoped_ptr<TVUI> _TVUI;
		boost::scoped_ptr<WinBg> _winBg;
		/*boost::scoped_ptr<Dan> _dan;
		boost::scoped_ptr<Dan2> _dan2;*/
		boost::scoped_ptr<Light> _light;/*	*/
		
	};

	typedef boost::shared_ptr< WheelAnimalUI> WheelAnimalUIPtr;
}

#endif


