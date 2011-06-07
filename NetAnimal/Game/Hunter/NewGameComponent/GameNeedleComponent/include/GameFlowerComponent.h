#ifndef __Orz_GameFlowerComponent__
#define __Orz_GameFlowerComponent__

#include "CGameFlowerInterface.h"
namespace Ogre
{
class SceneNode;
}
namespace Orz
{
class CGameFlowerInterface;
class COgreAnimationInterface;
class  GameFlowerComponent: public Component
{ 
public:
	GameFlowerComponent(void);
	virtual ~GameFlowerComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info) const;

	boost::scoped_ptr<CGameFlowerInterface> _flowerInterface;
	bool load(Ogre::SceneNode * node);




	
	bool enable(CGameFlowerInterface::Action action);	
	bool update(TimeType i);
	bool updateGoUp(TimeType i);
	void reset(void);
	

	boost::array<ComponentPtr,5> _entityComp;	
	TimeType _currTime;
	std::vector<Ogre::ColourValue> _colours;
	Ogre::Entity * flowerlight;
};
}
#endif