#ifndef __Orz_NeedleOpenTask__
#define __Orz_NeedleOpenTask__

#include "CSanProcessInterface.h"
#include "CGameFlowerInterface.h"
#include "CGameActionInterface.h"


namespace Orz
{



	class NeedleOpenTask
	{
	public:
		NeedleOpenTask(void):_actionInterface(NULL),_flower(NULL)
		{

		}
		~NeedleOpenTask(void)
		{

		}
		bool enable( CGameActionInterface * actionInterface, WheelEnum::LIGHT_COLOR color, CGameFlowerInterface * flower)
		{
			_flower = flower;
			switch(color)
			{
			case WheelEnum::Red:
				flower->enable(CGameFlowerInterface::SetRed);
				break;
			case WheelEnum::Green:
				flower->enable(CGameFlowerInterface::SetGreen);
				break;
			case WheelEnum::Yellow:
				flower->enable(CGameFlowerInterface::SetYellow);
				break;
			}

			flower->enable(CGameFlowerInterface::GoUp);
			_actionInterface->update = boost::bind(&NeedleOpenTask::update, this, _1);
			_actionInterface->disable = boost::bind(&NeedleOpenTask::disable, this);
			return true;

		}

		bool update(TimeType time)
		{

			bool ret = _flower->update(time);

			return ret;
		}
		void disable(void)
		{

		}
	private:
		CGameActionInterface * _actionInterface;
		CGameFlowerInterface * _flower;
	};



}

#endif