#ifndef __Orz_NeedleAllColorWinTask__
#define __Orz_NeedleAllColorWinTask__

#include "ITask.h"
#include "CSanProcessInterface.h"
#include "CGameFlowerInterface.h"
#include "CGameActionInterface.h"

#include "CGameColourInterface.h"
#include "CGameNeedleInterface.h"

namespace Orz
{



	class NeedleAllColorWinTask :public ITask
	{
	public:
		NeedleAllColorWinTask(CGameColourInterface * cInterface,CGameNeedleInterface * gInterface, CNeedleProcessInterface * nInterface)
			:_cInterface(cInterface),_gInterface(gInterface),_nInterface(nInterface)
		{

			_colours.push_back(Ogre::ColourValue(0.8f, 0.2f, 0.2f));
			_colours.push_back(Ogre::ColourValue(1, 0.4f, 0.4f));

			
			_colours.push_back(Ogre::ColourValue(0.2f, 0.8f, 0.2f));
			_colours.push_back(Ogre::ColourValue(0.4f, 1, 0.4f));

			
			_colours.push_back(Ogre::ColourValue(0.6f, 0.6f, 0.1f));
			_colours.push_back(Ogre::ColourValue(0.8f, 0.8f, 0.2f));
	
			
		}
	private:

		bool doEnable(void)
		{
			switch(WinData::getInstance().getLightColor())
			{
			case Orz::WheelEnum::Red:
				_color = 0;
				break;
			case Orz::WheelEnum::Green:
				_color = 1;
				break;
			case Orz::WheelEnum::Yellow:
				_color = 2;
				break;
			
			}
			_allTime = 0.f;
			_n = -1;
			return true;
		}
		void doDisable(void)
		{
			_cInterface->reset();
			_gInterface->setLeafVisible(true);
		}

		bool doUpdate(TimeType i)
		{
			_allTime += i* 2;
			int n = int(_allTime) ;


			if(n != _n)
			{

				Ogre::ColourValue c = _colours.at(n%2 + (_color *2));
				_cInterface->setColour(c.r, c.g, c.b);
				_n = n;
			}

			return _allTime < 22.f;
		}


		CGameColourInterface * _cInterface;
		CGameNeedleInterface * _gInterface;
		CNeedleProcessInterface * _nInterface;
		int _color;
		std::vector<Ogre::ColourValue> _colours;
		TimeType _allTime;
		int _n;
	};



}


#endif