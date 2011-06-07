
#include "SanControllerBaseStableHeaders.h"
#include "SanProcessComponent.h"
#include "CSanProcessInterface.h"
#include "CGameActionInterface.h"
using namespace Orz;

SanProcessComponent::SanProcessComponent(void):_processInterface(new CSanProcessInterface())
{
	_processInterface->addObject = boost::bind(&SanProcessComponent::addObject, this, _1);
	_processInterface->enableProcess = boost::bind(&SanProcessComponent::enableProcess, this, _1, _2);
	_processInterface->disableProcess = boost::bind(&SanProcessComponent::disableProcess, this);
	_processInterface->update= boost::bind(&SanProcessComponent::update, this, _1);

}
SanProcessComponent::~SanProcessComponent(void)
{

}


void SanProcessComponent::enableProcess(SanProcess process,  ReferenceCount::Referenced rc)
{
	ComponentList::iterator it;
	for(it = _objects.begin(); it != _objects.end(); ++it)
	{
		CGameActionInterface * action =  (*it)->queryInterface<CGameActionInterface>();
		if(action)
		{
			if(action->activate(process))
			{
				action->enable();
				_actions.push_back(action);
			}
		}
	}

	_referenced = rc;
	
}


bool SanProcessComponent::update(TimeType i)
{

	bool ret = false;
	ActionList::iterator it;
	for(it = _actions.begin(); it != _actions.end(); ++it)
	{
		bool r = (*it)->update(i);
		ret = r || ret;
	}
	if(!ret)
		_referenced.reset();
	return ret;
}
void SanProcessComponent::disableProcess(void)
{

	ActionList::iterator it;
	for(it = _actions.begin(); it != _actions.end(); ++it)
	{
		(*it)->disable();
	}
	_actions.clear();
	_referenced.reset();
}
ComponentInterface * SanProcessComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(CSanProcessInterface)))
		return _processInterface.get();
	return NULL;
}


void SanProcessComponent::addObject(ComponentPtr comp)
{
	_objects.push_back(comp);
}
