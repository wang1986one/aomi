#ifndef __Orz_SanProcessComponent__
#define __Orz_SanProcessComponent__
#include "SanControllerConfig.h"
#include "CSanProcessInterface.h"
#include <WheelGobal/WinData.h>
namespace Ogre
{
class SceneNode;
class Entity;
}

namespace Orz
{
class CSanProcessInterface;
class CGameActionInterface;
class  SanProcessComponent: public Component
{
public :
	SanProcessComponent(void);
	virtual ~SanProcessComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);
	
private:
	typedef std::vector<ComponentPtr> ComponentList;
	typedef std::vector<CGameActionInterface *> ActionList;
	void addObject(ComponentPtr comp);
	ComponentList _objects;
	ActionList _actions;
	boost::scoped_ptr<CSanProcessInterface> _processInterface;
	void enableProcess(SanProcess process,   ReferenceCount::Referenced rc);
	void disableProcess(void);
	bool update(TimeType i);

	ReferenceCount::Referenced _referenced;

};
}
#endif