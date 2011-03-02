#include "TasksStableHeaders.h"
#include "ITask.h"
using namespace Orz;

ITask::~ITask(void){}
ITask::ITask(void):_isEnable(false),_isUpdate(false)
{
}
bool ITask::enable(void)
{
	if(!_isEnable)
	{
		_isEnable = true;
		_isUpdate = true;
		TaskSet::iterator it;
		bool ret = doEnable();
		for(it = _tasks.begin(); it != _tasks.end(); ++it)
		{
			ret = ret && (*it)->enable();//当一个为false的返回值之后，其他的都不会被执行
		}
		
		return ret;
	}
	return false;
}


void ITask::disable(void)
{

	
	_isEnable = false;
	TaskSet::reverse_iterator it;
	
	for(it = _tasks.rbegin(); it != _tasks.rend(); ++it)
	{
		 (*it)->disable();
	}

	doDisable();
	
	
	
}
bool ITask::update(TimeType interval)
{
	
	if(_isEnable)
	{
		
		if(_isUpdate)
		{
			TaskSet::iterator it;
			bool ret = doUpdate(interval);
			for(it = _tasks.begin(); it != _tasks.end(); ++it)
			{
				ret = (*it)->update(interval) || ret;
			}
			if(ret)
			{
				return true;
			}
			_isUpdate = false;
		}
		
		if(_nextTask)
		{
			if(!_nextTask->isEnable())
				_nextTask->enable();
			return _nextTask->update(interval);
		}
	}
	return false;
}
void ITask::compose(TaskPtr task)
{
	if(_isEnable)
	{
		task->enable();
	}
	_tasks.push_back(task);
}


void ITask::push_back(TaskPtr task)
{
	if(_nextTask)
	{
		_nextTask->compose(task);
	}
	else
	{
		
		_nextTask = task;//.push_back(task);
		
	}
}

void ITask::clear(void)
{
	_tasks.clear();
	_nextTask.reset();
}
void ITask::remove(TaskPtr task)
{
	_tasks.erase(std::remove(_tasks.begin(),_tasks.end(), task),_tasks.end()); 
	if(_nextTask == task)
	{
		_nextTask.reset();
	}else
	{
		_nextTask->remove(task);
	}

	TaskSet::iterator it;
	for(it = _tasks.begin(); it != _tasks.end(); ++it)
	{
		(*it)->remove(task);//当一个为false的返回值之后，其他的都不会被执行
	}
}
bool ITask::isEnable(void)
{
	return _isEnable;
}
//private:
//	virtual bool doEnable(void) = 0;
//	virtual void doDisable(void) = 0;
//	virtual bool doUpdate(TimeType interval) = 0;
//
//	std::vector<TaskPtr> _tasks;
//	TaskPtr _nextTask;
//	bool _isEnable;