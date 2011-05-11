
#ifndef __Orz_TableUpdate_h__
#define __Orz_TableUpdate_h__

#include "WheelAnimalControllerConfig.h"
#include "Something.h"

#include "WheelAnimalSceneObj.h"
#include "ObjectLights.h"
#include "WheelAnimalProcess.h"
#include "WinnerAnimation.h"
#include "ColorChange.h"
#include "ProcessFactory.h"
namespace Orz
{

	/////////////////////////////////Ô¤Ðý×ª¹ý³Ì/////////////////////////////////////////////

	class TableUpdate
	{
	public:
		TableUpdate(boost::shared_ptr<WheelAnimalSceneObj> scene):_scene(scene),_n(0),_i()
		{

			for(int i = 0; i<24; i++)
			{
				_actionList.push_back(std::make_pair(0.1f *i,boost::bind(&WheelAnimalSceneObj::setTable, _scene.get(), i, _1)));
			}

			reset(0);

		}

		void reset(int n)
		{
			_n = n;
			_it = _actionList.begin();
			_allTime = 0.f;
			_i = 0;

		}
		bool update(TimeType interval)
		{
			if( _it == _actionList.end())
				return false;
			_allTime+=interval;
			while(_it->first <=_allTime)
			{
				if(_i != _n)
				{

					int randTable = rand() % 30;
					if(randTable >7)
					{
						randTable = -1;
					}
					_it->second(randTable);
				}else
				{
					_it->second(Orz::WinData::getInstance().getTable());
				}
				++_it;
				++_i;
				if( _it == _actionList.end())
					return false;
			}

			return true;
		}
	private:
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		typedef boost::function<void (int i)> ActionFunction;
		typedef std::vector<std::pair<Orz::TimeType, ActionFunction> > ActionList;
		ActionList _actionList;
		ActionList::iterator _it;
		Orz::TimeType _allTime;
		int _n;
		int _i;
	};


	typedef  boost::shared_ptr<TableUpdate> TableUpdatePtr;

}

#endif