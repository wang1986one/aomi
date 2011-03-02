#ifndef __Orz_UnitTest_TasksUT__
#define __Orz_UnitTest_TasksUT__
#include "TasksUnitTestConfig.h"
#include "ITask.h"
namespace Orz
{
class Task12: public ITask
{
private:
	bool doEnable(void)
	{
		_i = 0;
		return true;
	}
	bool doUpdate(TimeType interval)
	{
	
		_i++;
		std::cout<<_i;
		return _i<=3;
	}
	void doDisable(void)
	{
	
	}
private:
	int _i;
};
}
BOOST_AUTO_TEST_CASE(TasksUT)
{
	using namespace Orz;
	TaskPtr task(new Task12());
	task->compose(TaskPtr(new Task12));
	task->push_back(TaskPtr(new Task12));
	task->enable();
	while(task->update(1))
	{
	
	}
	task->disable();

}

#endif