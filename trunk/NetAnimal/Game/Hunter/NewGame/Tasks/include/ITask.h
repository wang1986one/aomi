#ifndef __Orz_Tasks_ITask_h__
#define __Orz_Tasks_ITask_h__

#include "TasksConfig.h" 
namespace Orz
{
class ITask;
typedef boost::shared_ptr<ITask> TaskPtr;
class _OrzTasksExport ITask
{
private:
	typedef std::vector<TaskPtr> TaskSet;
public:
	
	bool enable(void);
	void disable(void);
	bool update(TimeType interval);
	virtual ~ITask(void);
	ITask(void);
	void compose(TaskPtr task);
	void push_back(TaskPtr task);
	void clear(void);
	void remove(TaskPtr task);
	bool isEnable(void);
private:
	virtual bool doEnable(void) = 0;
	virtual void doDisable(void) = 0;
	virtual bool doUpdate(TimeType interval) = 0;
	TaskSet _tasks;
	TaskPtr _nextTask;
	bool _isEnable;
	bool _isUpdate;
};

}

#endif