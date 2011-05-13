#ifndef __Orz_WheelClock_h__
#define __Orz_WheelClock_h__	


#include "WheelControllerConfig.h"
#include "WheelClockListener.h"
namespace Orz
{
	class _OrzNetWheelControlleExport WheelClock
	{
	public:
		WheelClock(void);
		void reset(void);
		~WheelClock(void);

		//获取剩余时间
		int getLastSecond(void) const;

		//获取当前时间
		int getSecond(void) const;

		//获取总时间
		int getAllSecond(void) const;

		//设置当前时间
		void setSecond(int second);

		//设置总时间
		void setAllSecond(int allSecond);

		void setListener(WheelClockListener * listener);
		
		void update(TimeType interval);
	private:
		void changeClock();
		int _second;
		int _allSecond;
		WheelClockListener * _callback;
		TimeType _pass;
	};

	typedef boost::shared_ptr<WheelClock > WheelClockPtr;
}

#endif

