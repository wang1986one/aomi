#ifndef __Orz_RunMoreWinner__
#define __Orz_RunMoreWinner__

#include "CSanProcessInterface.h"
#include "CGameBaseInterface.h"
#include "CNeedleProcessInterface.h"
#include "TVUI.h"
#include <WheelGobal/WheelData.h>
namespace Orz
{

	class RunMoreWinner
	{
	public:
		RunMoreWinner(ComponentPtr rotationComponent):_rotationComponent(rotationComponent),_currTime(0.f),_interface(NULL),_translate(NULL),_process(NULL)
		{
			_rotation  = _rotationComponent->queryInterface<CGameRotationInterface>();

		}
		void setMoreWinner(CNeedleProcessInterface * process, CGameActionInterface * actionInterface, CGameTranslateInterface * translate)
		{
			_process = process;

			_winNumber = WinData::getInstance().size() -1;// - Orz::WheelEnum::ONE + 1;
			_interface = actionInterface;
			_translate = translate;
			_interface->enable =  boost::bind(&RunMoreWinner::enable, this);

			_interface->disable =  boost::bind(&RunMoreWinner::disable, this);
			_mode = WinData::getInstance().getWinMode();
			_ai = WinData::getInstance().getAnimalItem(0);
		}
		bool enable(void)
		{	

		
			_n = 0;
			AnimalEnum::ANIMAL_ITEM ai =WinData::getInstance().getAnimalItem(_n);// Orz::WheelData::getInstance().getTVNext(_mode, _ai, _n);
			_translate->random((CNewGameSceneInterface::LIGHT_COLOR)ai.second ,AnimalEnum::ANIMAL_TYPE(ai.first, AnimalEnum::PEOPLE));


			//CGameRotationInterface * gameRotation = _rotationComponent->queryInterface<CGameRotationInterface>();
			ComputeWinner compute;

			compute.compute(_translate->getType(), _translate->getColor(), 6);

			UI::TVUI::getSingleton().show();
			_rotation->play(compute.getNeedle(), 12.f,compute.getRotate(), 17.f);

			_interface->update =  boost::bind(&RunMoreWinner::updateRun, this, _1);

			return true;

		}
		bool updateRun(TimeType i)
		{
			bool ret = _rotation->update(i);
			if(ret == false)
			{
				CGameBaseInterface * base = _rotationComponent->queryInterface<CGameBaseInterface>();
				AnimalEnum::ANIMAL_ITEM ai =  WinData::getInstance().getAnimalItem(_n);//Orz::WheelData::getInstance().getTVNext(_mode, _ai, _n);
				base->setColor(_translate->getType(), (CGameBaseInterface::LIGHT_COLOR)ai.second);

				UI::TVUI::getSingleton().add(ai);
				

				++_n;

				_rotation->winner(_translate->getType(), false);_interface->update =  boost::bind(&RunMoreWinner::updateWin, this, _1);
			}
			return true;
		}
		bool updateWin(TimeType i)
		{
			bool ret = _rotation->update(i);

			if(!ret)
			{

				if(_n <= _winNumber)
				{

					
					if(_process->_numberCallback)
					{
						_process->_numberCallback(_winNumber - _n +1);
					}

					AnimalEnum::ANIMAL_ITEM ai = WinData::getInstance().getAnimalItem(_n);//Orz::WheelData::getInstance().getTVNext(_mode, _ai, _n);
					_translate->random((CNewGameSceneInterface::LIGHT_COLOR)ai.second ,AnimalEnum::ANIMAL_TYPE(ai.first, AnimalEnum::PEOPLE));

					ComputeWinner compute;

					compute.compute(_translate->getType(), _translate->getColor(), 6);

					_rotation->play(compute.getNeedle(), 12.f,compute.getRotate(), 17.f);
					_interface->update =  boost::bind(&RunMoreWinner::updateRun, this, _1);

				}else
					return false;
			}
			return true;
		}
		void disable(void)
		{
			
			UI::TVUI::getSingleton().hide();
		}

	private:
		int _n;
		int _winNumber;
		AnimalEnum::ANIMAL_ITEM _ai;
		ComponentPtr _rotationComponent;
		TimeType _currTime;
		CGameActionInterface *  _interface;
		CGameTranslateInterface * _translate;
		CGameRotationInterface * _rotation;
		CNeedleProcessInterface * _process;
		Orz::WheelEnum::WIN_MODE _mode;

	};

}
#endif