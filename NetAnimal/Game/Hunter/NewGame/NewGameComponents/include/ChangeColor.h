#ifndef __Orz_ChangeColor__
#define __Orz_ChangeColor__

#include "CSanProcessInterface.h"
#include "CGameBaseInterface.h"

#include <WheelGobal/WheelData.h>
namespace Orz
{

	class ChangeColor
	{
	public:
		ChangeColor(void)
		{
		}
		void setWinner(CGameActionInterface * actionInterface)
		{
			
			_interface = actionInterface;
			_interface->enable =  boost::bind(&ChangeColor::enable, this);
			_interface->disable =  boost::bind(&ChangeColor::disable, this);
			_interface->update =  boost::bind(&ChangeColor::update, this,_1);
			
		}

		void push_back(const Ogre::ColourValue & colour)
		{
			_colours.push_back(colour);
		}
		bool enable(void)
		{	

			_currTime = 0.f;

			
			return true;
		
		}
	
		bool update(TimeType i)
		{


			if(_currTime >= _colours.size() )
			{
				_currTime -= _colours.size();
			}


			Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
			int floor = Ogre::Math::IFloor(_currTime);
			int ceil = Ogre::Math::ICeil(_currTime);

			if(ceil == floor)
			{
				sm->setAmbientLight(_colours.at(ceil));
			}else
			{
				Ogre::ColourValue begin = _colours.at(floor);
				Ogre::ColourValue end;// = _colours.at(ceil);
				if(ceil == _colours.size())
				{
					end = *_colours.begin();
				}else
				{
					end = _colours.at(ceil);
				}
				float alpha = _currTime - float(floor);

				Ogre::ColourValue c = begin*(1 - alpha)+ end* alpha;

				sm->setAmbientLight(c);
			}
			_currTime += i;

			return false;
		}
		void disable(void)
		{
			Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
			
			sm->setAmbientLight(*_colours.begin());
		}

	private:
		CGameActionInterface *  _interface;
		TimeType _currTime;
		std::vector<Ogre::ColourValue> _colours;
	};

}
#endif