#ifndef __Orz_ObjectLights_h__
#define __Orz_ObjectLights_h__

#include "WheelAnimalControllerConfig.h"
#include "WheelAnimalSceneObj.h"
#include "WheelAnimalProcess.h"
#include "WinData.h"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/global_fun.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <iostream>
#include <string>
using namespace boost::multi_index;

/* A name record consists of the given name (e.g. "Charlie")
* and the family name (e.g. "Brown"). The full name, calculated
* by name_record::name() is laid out in the "phonebook order"
* family name + given_name.
*/
namespace Orz
{

	struct TheLight
	{
		TheLight(int id, Orz::WheelEnum::LIGHT_COLOR color, int table = -1)
		{
			static int i = 0;
			_id = id;
			_random = rand();
			_color = color;
			_table = table;

		}
		int id(void) const
		{
			return _id;
		}

		int random(void) const
		{
			return _random;
		}
		int table(void) const
		{
			return _table;
		}

		int randomID(void) const
		{
			return _randomID;
		}
		void setRandomID(int id) const
		{
			_randomID = id;
		}
		Orz::WheelEnum::LIGHT_COLOR color(void) const
		{
			return _color;
		}
	private:
		Orz::WheelEnum::LIGHT_COLOR _color;
		int _table;

		int _id;
		int _random;
		mutable int _randomID;
	};


	/* multi_index_container with indices based on name_record::name()
	* and name_record_length().
	* See Compiler specifics: Use of const_mem_fun_explicit and
	* mem_fun_explicit for info on BOOST_MULTI_INDEX_CONST_MEM_FUN.
	*/

	typedef multi_index_container<
		TheLight,
		indexed_by<
		ordered_unique<
		BOOST_MULTI_INDEX_CONST_MEM_FUN(TheLight,int,id)
		>,


		ordered_non_unique<
		BOOST_MULTI_INDEX_CONST_MEM_FUN(TheLight,int,random)
		>
		>
	> TheLightSet;


	class ObjectLights 
	{


	public:
		bool push(WheelEnum::LIGHT_COLOR color,int table = -1)
		{

			_set.insert(TheLight(_set.size(),color, table));

			int i = 0;
			for(nth_index<TheLightSet,1>::type::iterator it1=get<1>(_set).begin();
				it1!=get<1>(_set).end();++it1)
			{
				it1->setRandomID(i++);
			}


			return true;
		}
		///创建函数，传递进来场景指针，用于调配
		ObjectLights(boost::shared_ptr<WheelAnimalSceneObj> scene):_scene(scene)
		{
			clear();
		}

		virtual int getRandomLight(WheelEnum::LIGHT_COLOR color)
		{

			int table =  Orz::WinData::getInstance().getSecondWinnerId();
			for(TheLightSet::iterator it=_set.begin();it!=_set.end();++it)
			{
				if(it->color() == color && it->table() == table)
					return it->randomID();
			}
			return -1;
		}
		virtual ~ObjectLights(void)
		{

		}

		//设置模式
		//virtual void setMode(LightMode mode);
		void clear(void)
		{
			_set.clear();
			//std::fill(_lights.begin(), _lights.end(), WheelEnum::Red);
		}
		//unsigned int getNumber(WheelEnum::LIGHT_COLOR color);


		//inline std::pair<int, int> getYellowGreen(LightMode mode);
		//boost::array<int, 24> & getLights(void);
		//inline int size(void) const;
		WheelEnum::LIGHT_COLOR getLight(int i) const
		{

			int n=0;
			for(nth_index<TheLightSet,1>::type::iterator it1=get<1>(_set).begin();
				it1!=get<1>(_set).end();++it1)
			{
				if(n == i)
					return it1->color();
				n++;
			}
			return WheelEnum::LIGHT_COLOR(rand()%3);
		}


		int getTable(int i) const
		{

			int n=0;
			for(nth_index<TheLightSet,1>::type::iterator it1=get<1>(_set).begin();
				it1!=get<1>(_set).end();++it1)
			{
				if(n == i)
					return it1->table();
				n++;
			}
			return -1;
		}

		
		void setLight(int i)
		{
			_scene->setLight(i, getLight(i));
		}
		void setLightLiang(int i)
		{
			_scene->setLightLiang(i, getLight(i));
		}
		void setLightAn(int i)
		{
			_scene->setLightAn(i, getLight(i));
		}
		void setTable(int i)
		{
			_scene->setTable(i, getTable(i));
		}
		void setTableLiang(int i)
		{
			_scene->setTableLiang(i, getTable(i));
		}
		void setTableAn(int i)
		{
			_scene->setTableAn(i, getTable(i));
		}

		
	private:  

		//const static unsigned int _size;
		//std::map<int, Ogre::Entity *> _lights;
		//
		
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		//boost::array<int, 24> _lights;

		TheLightSet _set;
		//float _i;

	};
	typedef boost::shared_ptr<ObjectLights> ObjectLightsPtr;
}
#endif