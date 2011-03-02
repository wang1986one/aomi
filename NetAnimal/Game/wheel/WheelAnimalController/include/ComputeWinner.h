#ifndef __Orz_ComputeWinner__
#define __Orz_ComputeWinner__	 
#include "WheelAnimalControllerConfig.h"
#include <boost/multi_array.hpp>
#include <iostream>



namespace Orz
{
class ComputeWinner
{
public:
	ComputeWinner(void);
	~ComputeWinner(void);
	unsigned int getTotal(void) const;
	void compute(int n, int light, int excursion);
	float getNeedle(void) const;
	float getRotate(void) const;
	int getLight(void) const;
	int getWinner(void) const;
public:
	float _needle;
	float _rotate;
	int _light;
	int _winner;
};

}


#endif