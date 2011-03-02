#ifndef __Orz_NoneRunTask__
#define __Orz_NoneRunTask__

#include "ITask.h"
#include "CSanProcessInterface.h"
#include "CGameFlowerInterface.h"
#include "CGameActionInterface.h"
#include "ComputeWinner.h"

namespace Orz
{



	class NoneRunTask :public ITask
	{
	public:
		NoneRunTask(CNeedleProcessInterface * nInterface, CGameRotationInterface * rInterface):
		  _nInterface(nInterface), _rInterface(rInterface)
		{}
	private:
		
		bool doEnable(void)
		{

			ComputeWinner compute;
			compute.compute(_nInterface->getBase(), _nInterface->getColor(), 6);


			_rInterface->play(compute.getNeedle(), 12.f,compute.getRotate(), 17.f);

			return true;
		}
		void doDisable(void)
		{
			
		}

		bool doUpdate(TimeType i)
		{
			return _rInterface->update(i);
		}
	private:
		CNeedleProcessInterface * _nInterface;
		CGameRotationInterface * _rInterface;
	};



}

#endif