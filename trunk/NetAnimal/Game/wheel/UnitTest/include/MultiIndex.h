#ifndef __Orz_UnitTest_CoinPoolUT__
#define __Orz_UnitTest_CoinPoolUT__
#include "UnitTestConfig.h"
#include "SCMData.h"
#include "WinDataPrototype.h"
#include "WinData.h"

#if !defined(NDEBUG)
#define BOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING
#define BOOST_MULTI_INDEX_ENABLE_SAFE_MODE
#endif

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

struct TheLight
{
	TheLight(int id, Orz::WheelEnum::LIGHT_COLOR color, int table = -1)
	{
		static int i = 0;
		_id = id;
		_random = rand();

	}
	int id(void) const
	{
		return _id;
	}

	int random(void) const
	{
		return _random;
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
	ObjectLights(/*boost::shared_ptr<WheelAnimalSceneObj> scene*/)
	{
		clear();
	}

	virtual int getRandomLight(WheelEnum::LIGHT_COLOR color)
	{

		for(TheLightSet::iterator it=_set.begin();it!=_set.end();++it)
		{
			if(it->color() == color)
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
		return WheelEnum::Red;
	}
	/*void setLight(int i)
	{
	_scene->setLight(i, _lights[i]);
	}*/
private:  

	//const static unsigned int _size;
	//std::map<int, Ogre::Entity *> _lights;
	//	boost::shared_ptr<WheelAnimalSceneObj> _scene;
	//boost::array<int, 24> _lights;

	TheLightSet _set;
	//float _i;

};



//const unsigned int ObjectLights::_size = 24;

//bool ObjectLights::push(WheelEnum::LIGHT_COLOR color,int  table)
//{
//
//	/*int r = rand() % size();
//	for(int i = 0; i < size(); ++i)
//	{
//		int n = (r + i)%size();
//
//		if(_lights[n] == from && _lights[n] != to)
//		{
//			_lights[n] = to;
//			return true;
//		}
//		
//	}*/
//	return true;
//}
///创建函数，传递进来场景指针，用于调配
//ObjectLights::ObjectLights(/*boost::shared_ptr<WheelAnimalSceneObj> scene*/)//:_scene(scene)//_i(0)
//{
//	_init();
//}

//int ObjectLights::getRandomLight(WheelEnum::LIGHT_COLOR color)
//{
//	int r = rand() % size();
//	for(int i = 0; i < size(); ++i)
//	{
//		int n = (r + i)%size();
//
//		if(_lights[n] == color)
//		{
//			return n;
//		}
//		
//	}
//	 return -1;
//}
//ObjectLights::~ObjectLights(void)
//{
//}

//void ObjectLights::_init(void)
//{
//	std::fill(_lights.begin(), _lights.end(), WheelEnum::Red);
//}
//unsigned int ObjectLights::getNumber(WheelEnum::LIGHT_COLOR color)
//{
//	int ret = 0;
//	BOOST_FOREACH(int i, _lights)
//	{
//		if(i == color)
//			++ret;
//	}
//	return ret;
//}
//



//boost::array<int, 24> & ObjectLights::getLights(void)
//{
//	return _lights;
//}

//int ObjectLights::size(void) const
//{
//	return _size;
//}
BOOST_AUTO_TEST_CASE(MultiIndexUT)
{
	std::srand(time(NULL));
	TheLightSet ns;

	ns.insert(TheLight(0,Orz::WheelEnum::Red));
	ns.insert(TheLight(1,Orz::WheelEnum::Red));
	ns.insert(TheLight(2,Orz::WheelEnum::Yellow));
	ns.insert(TheLight(3,Orz::WheelEnum::Green));

	/* list the names in ns in phonebook order */

	std::cout<<"Phonenook order\n"
		<<"---------------"<<std::endl;
	for(TheLightSet::iterator it=ns.begin();it!=ns.end();++it){
		std::cout<<it->id()<<std::endl;
	}

	/* list the names in ns according to their length*/

	std::cout<<"\nLength order\n"
		<<  "------------"<<std::endl;
	for(nth_index<TheLightSet,1>::type::iterator it1=get<1>(ns).begin();
		it1!=get<1>(ns).end();++it1){
			std::cout<<it1->id()<<std::endl;
	}


	ObjectLights lights;
	lights.clear();
	lights.push(Orz::WheelEnum::Red);
	lights.push(Orz::WheelEnum::Yellow);
	lights.push(Orz::WheelEnum::Yellow);
	/////////////
	//	RunWinnerPtr rw(new RunWinner());
	/*rw->calculate(WheelEnum::Player, 1);
	rw->calculate(WheelEnum::Dealer, 1);*/
	//	rw->calculate(WheelEnum::Draw, 1);
	//	rw->getWinner(1,1,1,100);
	//
}

#endif