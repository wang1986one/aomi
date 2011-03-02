#ifndef __Orz_Tutorial_Process_h__
#define __Orz_Tutorial_Process_h__
#include "WheelAnimalControllerConfig.h"
#include "Animal.h"
namespace Orz
{
class Process0LightRunning;
class WheelAnimalProcess;
typedef boost::shared_ptr<Process0LightRunning> Process0Ptr;
typedef boost::shared_ptr<WheelAnimalProcess> ProcessPtr;

class ObjectLights;
template<class T>
class UpdateToEnable
{
protected:
	UpdateToEnable(void)
	{
		_reset();
	}
	void _reset(void)
	{
		_init =false;
	}
	void _update2enable(void)
	{
		if(!_init)
		{
			static_cast<T*>(this)->enable();
			_init = true;
		}
	}
private:
	bool _init;
};


class WheelAnimalProcess
{
public:
	enum PROCESS
	{
		PROCESS1,
		PROCESS2,
		PROCESS3,
		PROCESS4,
		PROCESS_ALL
	};
public:
	virtual ~WheelAnimalProcess(void)
	{}
	virtual void clear(void) = 0;
	virtual bool update(TimeType interval) = 0;
};
class  Process0LightRunning
{

public:
		
public:
    virtual bool  update(TimeType interval) = 0;


	virtual void setMode(WheelEnum::RATE mode) = 0;	
	virtual ObjectLights * getLights(void) = 0;	 
	virtual ~Process0LightRunning(void){}
};

	



}
#endif