#ifndef __Orz_SanUI__
#define __Orz_SanUI__

#include <WheelGobal/WheelUIInterface.h>
#include <WheelGobal/WinData.h>
namespace Orz

{

	class CLogoInterface;
	class CEndUIInterface;
	class WeiShuWu;
	class Time;
	class Money;
	class UIList;
	class SanUI: public WheelUIInterface, public Singleton<SanUI>
	{
	public:
		SanUI();
		virtual ~SanUI(void);
	private:
		virtual void setTheTime(int second);
		virtual void setMenuDataVisible(bool visible);
		virtual void setSetupVisible(bool visible);
		virtual void menuResult(bool result);
		virtual void writeMenuXY(int x, int y, unsigned long n);
		virtual  void setLogoShow(bool show);
		virtual void setStartUIVisible(bool visible);
		virtual void setEndUIVisible(bool visible);
		virtual void runWinner(void);
		virtual void addBottom(void);
		virtual void update(TimeType interval);
	private:

		boost::scoped_ptr<WeiShuWu> _weiShuWu;
		boost::scoped_ptr<Time> _time;
		boost::scoped_ptr<Money> _money;
		
		boost::scoped_ptr<UIList> _list;
		
		ComponentPtr _logo;
		ComponentPtr _end;

		CLogoInterface * _logoInterface;
		CEndUIInterface * _endUIInterface;
	};

	/*extern char const SanDirectorType[]= "SanDirector";
	typedef Orz::GameFactory<Director, SanDirector, SanDirectorType> SanDirectorFactory;*/
};
#endif