#ifndef __Orz_NeedleAllColorRunTask__
#define __Orz_NeedleAllColorRunTask__

#include "ITask.h"
#include "CSanProcessInterface.h"
#include "CGameFlowerInterface.h"
#include "CGameActionInterface.h"

#include "CGameColourInterface.h"
#include "CGameNeedleInterface.h"

namespace Orz
{



	class NeedleAllColorRunTask :public ITask
	{
	public:
		NeedleAllColorRunTask(CGameColourInterface * cInterface,CGameNeedleInterface * gInterface )
			:_cInterface(cInterface),_gInterface(gInterface)
		{


					
			_colours.push_back(Ogre::ColourValue(0.3f, 0.3f, 1.0f));
			_colours.push_back(Ogre::ColourValue(1, 0.3f, 0.3f));
			_colours.push_back(Ogre::ColourValue(0.3f, 1, 0.3f));
			_colours.push_back(Ogre::ColourValue(0.8f, 0.8f, 0.2f));
			
		}
	private:

		bool doEnable(void)
		{

			_currTime = 0.f;
			_gInterface->setLeafVisible(false);
			_cInterface->enable(CGameColourInterface::Fatein);
			return true;
		}
		void doDisable(void)
		{
			_cInterface->enable(CGameColourInterface::Stop);
		}

		bool doUpdate(TimeType i)
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
				_cInterface->setColour(c.r, c.g, c.b);
				//sm->setAmbientLight(c);
			}
			_currTime += i;


			return _cInterface->update(i);
		}


		CGameColourInterface * _cInterface;
		CGameNeedleInterface * _gInterface;

		
		TimeType _currTime;
		std::vector<Ogre::ColourValue> _colours;
	};



}

#endif