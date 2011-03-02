#ifndef __Orz_ScoreWinner_h__
#define __Orz_ScoreWinner_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
#include "WheelEnum.h"
#include <boost/random.hpp>
namespace Orz
{
	
	class ScoreWinner;
	typedef boost::shared_ptr<ScoreWinner> ScoreWinnerPtr;
	class _OrzMyWheelControlleExport ScoreWinner
	{
	public:
		class Winner
		{
		public:
			inline Winner(void)
			{
				reset();
			}
			inline void set(WheelEnum::WINNER winner, int i)
			{
				_set[winner] = i;
			}
			inline void reset(void)
			{
				
				std::fill_n( _set, 3, 0);
			}
			
			inline void push(WheelEnum::WINNER winner)
			{
				_set[winner] = _set[winner] + 1;
			}
			inline int get(WheelEnum::WINNER winner) const 
			{
				return _set[winner];
			}
			
			inline void sum(const ScoreWinner::Winner & winner)
			{
				for(int i=0; i<3; ++i)
				{
					_set[i] += winner._set[i];
				}
			}
			int getTotal(void) const
			{
				int all = 0;
				for(int i=0; i<3; ++i)
				{
					all += _set[i];// += animal._set[i];
				}
				return all;
			}
		private:
			int _set[3];
		};
	public:
		ScoreWinner(void);
		~ScoreWinner(void);
		std::pair<int, WheelEnum::WINNER> getWinner(const Winner & w, int prize) const;
	//	int calculate(WheelEnum::WINNER winner, int n = 1) const;
		int getOverride(WheelEnum::WINNER winner) const;
		float getOdds(WheelEnum::WINNER winner) const;
		WheelEnum::WINNER  getOddsWinner() const;
		void reset(void){}
	private:
		
	};

	
}

#endif

