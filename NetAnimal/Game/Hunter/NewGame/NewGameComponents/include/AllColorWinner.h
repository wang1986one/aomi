#ifndef __Orz_AllColorWinner__
#define __Orz_AllColorWinner__

#include "CSanProcessInterface.h"
#include "CGameBaseInterface.h"
#include "CGameFlowerInterface.h"
#include "CNeedleProcessInterface.h"
//#include "NeedleOpenTask.h"
#include <WheelGobal/WheelData.h>
namespace Orz
{

	class AllColorWinner : public ITask
	{
	public:



		AllColorWinner(CGameRotationInterface * ratation, CNeedleProcessInterface * nInterface, CGameBaseInterface * bInterface):
		  _rotation(ratation),_currTime(0.f),_translate(NULL),_nInterface(nInterface),_bInterface(bInterface)
		{
		
		}
		
		bool doEnable(void)
		{	

		//	WinData::getInstance().load();
			
			_ai = WinData::getInstance().getAnimalItem();
			_translate = _nInterface->getTranslateInterface();

			const CGameTranslateInterface::ColorList  & clist= _translate->getColorList();


			_set.clear();
			for(size_t i=0; i<clist.size(); ++i)
			{
				if(clist.at(i) == (CGameBaseInterface::LIGHT_COLOR)_ai.second)
				{
					_set.insert(i);
				}
			
			}



			_base = _translate->getType();
			_color= _translate->getColor();
			_rotation->winner(_translate->getType(), false);
			_bInterface->setColor(_base, (CGameBaseInterface::LIGHT_COLOR)_ai.second);
			
			_update =  boost::bind(&AllColorWinner::fUpdate, this, _1);
			return true;
		
		}
		
		bool updateFlower(TimeType i)
		{
			bool ret = _flower->update(i);
			if(!ret)
			{
				_update = boost::bind(&AllColorWinner::update, this, _1);
			}
			return true;
		}
		bool fUpdate(TimeType i)
		{
			bool ret = _rotation->update(i);
			if(!ret)
			{
				do
				{
					_base++;
					_color++;
					_color %= 24;
					_base %= 24;
					if(_base == _translate->getType())
					{
						_update = boost::lambda::constant(false);
						return false;
					}
				}
				while(_set.find(_color) == _set.end() || _translate->getAnimalList().at(_base).second == AnimalEnum::KING);

				{
					
					_rotation->winner(_base, false);
					_bInterface->setColor(_base, (CGameBaseInterface::LIGHT_COLOR)_ai.second);
				}
			}
			return true;
		}

		bool doUpdate(TimeType i)
		{
			
			return _update(i);
		}
		void doDisable(void)
		{

		}

	private:
		int _base;
		int _color;
		AnimalEnum::ANIMAL_ITEM _ai;
		TimeType _currTime;
		CGameTranslateInterface * _translate;
		CGameRotationInterface * _rotation;
		std::set<int> _set;

		boost::function<bool (TimeType)> _update;
		CGameFlowerInterface * _flower;
		CNeedleProcessInterface * _nInterface;
		CGameBaseInterface * _bInterface;
		

	};

}
#endif