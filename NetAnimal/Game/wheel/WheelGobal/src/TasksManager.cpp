#include "WheelGobalStableHeaders.h"
#include "TasksManager.h"
#include <orz/Toolkit_Base/Exception.h>

using namespace Orz;
//
//
//TasksManager::TasksManager(void):_time(0.f)
//{
//
//}
//TasksManager::~TasksManager(void)
//{
//
//}
//void TasksManager::addTask(TimeType time,TaskType task)
//{
//	_queue.push(TaskPair(time, task));
//}
//
//
//void TasksManager::reset(void)
//{
//	_time = 0.f;
//	while(!_queue.empty())
//		_queue.pop();
//}
//void TasksManager::update(TimeType interval)
//{
//	_time += interval;
//	if(_queue.empty())
//		return;
//
//	TaskPair task = _queue.top();
//	while(task.first <= _time)
//	{
//	
//		_queue.pop();
//		task.second();
//		task = _queue.top();
//	}
//	
//}