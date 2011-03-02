#ifndef __Orz_ScoreBouns_h__
#define __Orz_ScoreBouns_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
#include "WheelEnum.h"
#include <boost/random.hpp>
namespace Orz
{
	
	class ScoreBouns;
	typedef boost::shared_ptr<ScoreBouns> ScoreBounsPtr;
	class _OrzMyWheelControlleExport ScoreBouns
	{
	public:
		int getBounsAmount(int feedback, int total, float percent) const;
		bool isBounsAmount(int bouns) const;
		//WinDataPrototypePtr getWinData(WinDataPrototypePtr) const;
	//public:
	//	ScoreBouns(void);
	//	~ScoreBouns(void);
	//	std::pair<int, bool> calculate()
	//	std::pair<int, WinDataPrototypePtr> getWinner(const Winner & w, int prize) const;
	////	int calculate(WheelEnum::WINNER winner, int n = 1) const;
	//	//int getOverride(WheelEnum::WINNER winner) const;
	//	float getOdds(WheelEnum::WINNER winner) const;
	//	
	//	void reset(void){}
	//private:
	//	std::vector<WinDataPrototype> _golds;
		
	};

	
}

#endif

