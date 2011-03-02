#ifndef __Orz_Bonus__
#define __Orz_Bonus__
#include <boost/multi_array.hpp>
#include <iostream>
#include <CEGUI/cegui.h>
#include "Number.h"

#include "WheelAnimalControllerConfig.h"
namespace Orz
{
	class Bonus
	{
	public:
		Bonus(void);
		~Bonus(void);

		void update(TimeType i);
		void setBonus(int bonus);
		void clear(void);
	private:
		TimeType _time;
		Number _number;
		int _bonus;
	};
}


#endif