#ifndef __Orz_WheelData_h__
#define __Orz_WheelData_h__
#include "WheelDataConfig.h"
#include "WheelEnum.h"
namespace Orz
{
	class _OrzWheelDataConfigExport WheelData
	{
	public:
		
		typedef boost::tuple<WheelEnum::WIN_MODE, AnimalEnum::ANIMAL_TYPE, WheelEnum::LIGHT_COLOR> WheelMsg;

		static WheelData & getInstance(void);
		static WheelData * getInstancePtr(void);
		const WheelMsg & getWheelMsg(WheelEnum::HARDWARE_WIN_MODE) const;
	private:
		
		typedef std::map<WheelEnum::HARDWARE_WIN_MODE, WheelMsg> WheelMap;

		WheelData(void);
		WheelMap _wheelMap;
		
		
	};
}
#endif