#ifndef __Orz_ZhugeLiangComponent__
#define __Orz_ZhugeLiangComponent__
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
class CGameActionInterface;
class  ZhugeLiangComponent: public Component
{
private:
	
public :

	ZhugeLiangComponent(void);
	virtual ~ZhugeLiangComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);

	ComponentPtr _playerComp;
	bool activate(SanProcess process); 
	boost::scoped_ptr<CGameActionInterface> _actionInterface;
	//ComponentPtr _dotSceneLoader;
	
};
}
#endif