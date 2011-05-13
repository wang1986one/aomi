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

		//��ȡʣ��ʱ��
		int getLastSecond(void) const;

		//��ȡ��ǰʱ��
		int getSecond(void) const;

		//��ȡ��ʱ��
		int getAllSecond(void) const;

		//���õ�ǰʱ��
		void setSecond(int second);

		//������ʱ��
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

