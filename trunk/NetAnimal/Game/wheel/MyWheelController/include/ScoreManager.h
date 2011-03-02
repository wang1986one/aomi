#ifndef __Orz_ScoreManager_h__
#define __Orz_ScoreManager_h__	


#include "WheelControllerConfig.h"
#include "WheelEnum.h"
#include "WinData.h"
#include "CoinPool.h"
#include "ScoreData.h"
#include "SCMData.h"
#include "WinDataPrototype.h"
#include "ScoreBouns.h"

#include <boost/random.hpp>
#include "ScoreStrategy.h"
namespace Orz
{



	class _OrzMyWheelControlleExport ScoreManager
	{
	public:
		ScoreManager(void):_strategy(new ScoreStrategyNomal()),_canButton(false)
		{
			size_t size = Orz::SingleChipManager::getSingleton().getSCMAmount();
			_scmDatas.resize(8);
		}
		~ScoreManager(void)
		{

		}

		inline void ready(void)
		{	
			for(size_t i = 0; i< _scmDatas.size(); ++i)
			{
				_scmDatas.at(i).clear();
			}
			_strategy->ready(_data);
			_canButton = true;
		}
		inline void clickButton(int id, int button)
		{
			if(!_canButton || id < 0 ||size_t( id) >= _scmDatas.size())
				return;

			_scmDatas.at(id).clickButton(button);
		}



		inline void go(void)
		{

			_canButton = false;
			
			_strategy->go(_data, _scmDatas);

		}
		inline void rebate(void)
		{
			BOOST_FOREACH(const SCMData & data, _scmDatas)
			{
				std::cout<<_strategy->rebate(data)<<std::endl;
			}
			
			
		}
		ScoreStrategy  * getStrategy(void)
		{
			return _strategy.get();
		}

		static ScoreManager & getInstance(void);
		static ScoreManager * getInstancePtr(void);
	private:
		ScoreData _data;
		ScoreStrategyPtr _strategy;
		SCMDataList _scmDatas;
		bool _canButton;
	};


}

#endif

