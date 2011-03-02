#ifndef __Orz_AllAnimalWinner__
#define __Orz_AllAnimalWinner__

#include "CSanProcessInterface.h"
#include "CGameBaseInterface.h"

#include <WheelGobal/WheelData.h>
namespace Orz
{

	class AllAnimalWinner
	{
	public:
		AllAnimalWinner(ComponentPtr rotationComponent):_rotationComponent(rotationComponent),_currTime(0.f),_interface(NULL),_translate(NULL)
		{
			_rotation  = _rotationComponent->queryInterface<CGameRotationInterface>();

		}
		void setWinner(CGameActionInterface * actionInterface, CGameTranslateInterface * translate)
		{
			
			_interface = actionInterface;
			_translate = translate;
			_interface->enable =  boost::bind(&AllAnimalWinner::enable, this);
			_interface->disable =  boost::bind(&AllAnimalWinner::disable, this);
		
			_ai = WinData::getInstance().getAnimalItem();
			const CGameTranslateInterface::AnimalList  & tlist= translate->getAnimalList();

			_set.clear();
			for(size_t i=0; i<tlist.size(); ++i)
			{
				if(tlist.at(i) == AnimalEnum::ANIMAL_TYPE(_ai.first, AnimalEnum::PEOPLE))
				{
					_set.insert(i);
				}
			
			}
		}
		bool enable(void)
		{	


			

			
			_base = _translate->getType();
			_color= _translate->getColor();
			CGameBaseInterface * base = _rotationComponent->queryInterface<CGameBaseInterface>();
			_rotation->winner(_translate->getType(), false);
			base->setColor(_base, (CGameBaseInterface::LIGHT_COLOR)_ai.second);
			
			_interface->update =  boost::bind(&AllAnimalWinner::update, this, _1);
			return true;
		
		}
	
		bool update(TimeType i)
		{
			bool ret = _rotation->update(i);
			if(!ret)
			{
				do
				{
					_base++;
					_color++;
					_color %=24;
					_base %= 24;
					if(_base == _translate->getType())
					{
						_interface->update = boost::lambda::constant(false);
						return false;
					}
				}
				while(_set.find(_base) == _set.end());

				{
					
					const CGameTranslateInterface::ColorList  & clist= _translate->getColorList();
					_rotation->winner(_base, false);
					CGameBaseInterface * base = _rotationComponent->queryInterface<CGameBaseInterface>();
					base->setColor(_base,  (Orz::CGameBaseInterface::LIGHT_COLOR)clist.at(_color));
				}
			}
			return true;
		}
		void disable(void)
		{

		}

	private:
		int _base;
		int _color;
		AnimalEnum::ANIMAL_ITEM _ai;
		ComponentPtr _rotationComponent;
		TimeType _currTime;
		CGameActionInterface *  _interface;
		CGameTranslateInterface * _translate;
		CGameRotationInterface * _rotation;
		std::set<int> _set;
	};

}
#endif