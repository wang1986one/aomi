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
	
}
#endif