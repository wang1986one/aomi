#ifndef __Orz_WheelUIInterface_h__
#define __Orz_WheelUIInterface_h__	


#include "WheelGobalConfig.h"
namespace Orz
{
	class WheelUIListener;
	class _OrzWheelGobalExport WheelUIInterface
	{
	public:
		/*void addListener(WheelUIListener * listener);
		void removeListener(WheelUIListener * listener);*/
		WheelUIInterface(void);
		virtual ~WheelUIInterface(void);
	public:
		virtual void setTheTime(int second) = 0;
	/*	virtual void setMenuDataVisible(bool visible) = 0;
		virtual void setSetupVisible(bool visible) = 0;
		virtual void menuResult(bool result) = 0;
		virtual void writeMenuXY(int x, int y, unsigned long n) = 0;*/
		virtual void setLogoShow(bool show) = 0;
		virtual void setStartUIVisible(bool visible) = 0;
		virtual void setEndUIVisible(bool visible) = 0;
		virtual void runWinner(void) = 0;
		
		virtual void addBottom(void) = 0;
		virtual void update(TimeType interval) = 0;
	protected:
		WheelUIListener * _listener;
	
	};
	class  _OrzWheelGobalExport WheelNullUI: public WheelUIInterface
	{
		
	public:
		virtual void setTheTime(int second);
	/*	virtual void setMenuDataVisible(bool visible);
		virtual void menuResult(bool result);
		virtual void writeMenuXY(int x, int y, unsigned long n);*/
		virtual void setLogoShow(bool show);
		virtual void setStartUIVisible(bool visible);
		virtual void setEndUIVisible(bool visible);
		virtual void runWinner(void);
		virtual void addBottom(void);
		virtual void update(TimeType interval);
		
		//virtual void setSetupVisible(bool visible);
	};

	
	typedef boost::shared_ptr<WheelUIInterface> WheelUIInterfacePtr;
}

#endif



