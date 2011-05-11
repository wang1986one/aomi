#ifndef __Orz_WheelData_h__
#define __Orz_WheelData_h__
#include "WheelGobalConfig.h"
#include "WheelEnum.h"
namespace Orz
{
	class _OrzWheelGobalExport WheelData
	{
	public:
		WheelData(void);
		~WheelData(void);
		static WheelData & getInstance(void);
		static WheelData * getInstancePtr(void);

		int getLions(void) const;
		void setLions(int lions);
	private:
		int _lions;
	};
	//class TVListMap;
	//typedef boost::shared_ptr<TVListMap> TVListMapPtr;
	//class _OrzWheelGobalExport WheelData_
	//{
	//public:
	//	


	//public:
	//	
	//	typedef boost::tuple<WheelEnum::WIN_MODE, WheelEnum::AnimalType, WheelEnum::LIGHT_COLOR> WheelMsg;

	//	static WheelData_ & getInstance(void);
	//	static WheelData_ * getInstancePtr(void);
	//	const WheelMsg & getWheelMsg(WheelEnum::HARDWARE_WIN_MODE mode) const;
	//	int getOverride(WheelEnum::AnimalItem ai) ;
	//	void setRate(WheelEnum::RATE rate);

	//	
	//	bool hasTVNext(WheelEnum::HARDWARE_WIN_MODE mode, WheelEnum::AnimalItem ai, size_t i);
	//	WheelEnum::AnimalItem getTVNext(WheelEnum::HARDWARE_WIN_MODE mode,  WheelEnum::AnimalItem ai, size_t i);
	//private:
	//	
	//	typedef std::map<WheelEnum::HARDWARE_WIN_MODE, WheelMsg> WheelMap;

	//	WheelData_(void);
	//	WheelMap _wheelMap;
	//	
	//	typedef std::map<WheelEnum::AnimalItem, int> RateMap;
	//	typedef boost::array<RateMap, 6> RateMapArray;
	//	RateMapArray _rates;

	//	
	//	boost::array<TVListMapPtr, 5> _tvListMap;
	//	WheelEnum::RATE _rate;
	//	
	//};
}
#endif