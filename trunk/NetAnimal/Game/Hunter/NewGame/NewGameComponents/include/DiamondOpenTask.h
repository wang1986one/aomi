#ifndef __Orz_DiamondOpenTask__
#define __Orz_DiamondOpenTask__

#include "CSanProcessInterface.h"
#include "CGameBaseInterface.h"
#include "CGameActionInterface.h"


namespace Orz
{



	class DiamondOpenTask
	{
	public:
		DiamondOpenTask(void):_actionInterface(NULL),_diamond(NULL), _currTime(0.f)
		{
		
		}
		~DiamondOpenTask(void)
		{
		
		}
		bool enable(SanProcess process , CGameActionInterface * actionInterface, CGameDiamondInterface * diamond)
		{
			_diamond = diamond;
			_currTime = 0.f;
			_actionInterface = actionInterface;
			
			switch(process)
			{
			case PROCESS_PRORUN:
				_actionInterface->update = boost::bind(&DiamondOpenTask::update, this, _1);
				_actionInterface->disable = boost::bind(&DiamondOpenTask::disable, this);
				_diamond->enable(CGameDiamondInterface::Open);
			
				return true;
				break;
			case PROCESS_RUN:
				_actionInterface->update = boost::bind(&DiamondOpenTask::update, this, _1);
				_actionInterface->disable = boost::bind(&DiamondOpenTask::disable, this);
				_diamond->enable(CGameDiamondInterface::OpenstateRotate);
				
				return true;
				break;
			}
			return false;
			
		}
		bool win(CGameActionInterface * actionInterface, AnimalEnum::TYPE type, CGameDiamondInterface * diamond)
		{
		
			diamond->setAnimal(CGameDiamondInterface::ANIMALS(type));
			return false;
		}
		bool update(TimeType time)
		{

			_currTime += time;
			bool ret = _diamond->update(time);
			
		
			return _currTime < 2.f;
		}
		void disable(void)
		{

		}
	private:
		CGameActionInterface * _actionInterface;
		CGameDiamondInterface * _diamond;
		TimeType _currTime;
	};

	

}

#endif