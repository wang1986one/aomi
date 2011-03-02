#include "WheelAnimalControllerStableHeaders.h"
#include "ObjectLights.h"
//using namespace Orz;
//
//const unsigned int ObjectLights::_size = 24;
//
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
/////创建函数，传递进来场景指针，用于调配
//ObjectLights::ObjectLights(boost::shared_ptr<WheelAnimalSceneObj> scene):_scene(scene)//_i(0)
//{
//	_init();
//}
//
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
//
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
//
//
//
//boost::array<int, 24> & ObjectLights::getLights(void)
//{
//	return _lights;
//}
//
//int ObjectLights::size(void) const
//{
//	return _size;
//}