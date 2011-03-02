#ifndef __Orz_ComputeWinner__
#define __Orz_ComputeWinner__

#include "CSanProcessInterface.h"
#include "CGameBaseInterface.h"
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

	ComputeWinner::ComputeWinner(void):_needle(0), _rotate(0), _light(0), _winner(0)
	{

	}
	ComputeWinner::~ComputeWinner(void)
	{

	}
	unsigned int ComputeWinner::getTotal(void) const
	{
		return 24;
	}

	void ComputeWinner::compute(int n, int light, int excursion)
	{
		n = (n+getTotal()-excursion)%getTotal();
		light = (light+getTotal()-excursion)%getTotal();
		_winner = n;
		int quan = rand()%2 + 4;
		int quan2 = rand()%2 + 6;
		int cha = (_winner - light+getTotal())%getTotal();
		_light = (_winner - cha+getTotal())%getTotal();
		_rotate = static_cast<float>(quan2 * getTotal() + cha);
		_needle = static_cast<float>(quan * getTotal() + _light);
	}


	float ComputeWinner::getNeedle(void) const
	{
		return _needle;
	}
	float ComputeWinner::getRotate(void) const
	{
		return _rotate;

	}
	int ComputeWinner::getLight(void) const
	{
		return _light;

	}

}

#endif