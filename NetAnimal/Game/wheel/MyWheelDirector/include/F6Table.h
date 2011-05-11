#ifndef __Orz_F6Table_h__
#define __Orz_F6Table_h__
#include "F6TableInterface.h"
#include <boost/multi_array.hpp>	
namespace Orz
{
	class F6Table
	{
	public:
		bool setDataIndex(F6TableInterface::ITEM item, int data);
		int getDataIndex(F6TableInterface::ITEM item) const;
		int getData(F6TableInterface::ITEM item) const;
		void save(void);
		void load(void);

		static F6Table & getInstance(void);
		static F6Table * getInstancePtr(void);

	private:
		F6Table(void);
		typedef std::map<F6TableInterface::ITEM, int> F6Map;
		F6Map _f6Data;
	};
}


#endif
