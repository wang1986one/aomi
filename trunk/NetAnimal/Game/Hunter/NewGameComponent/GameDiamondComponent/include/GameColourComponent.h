#ifndef __Orz_GameColourComponent__
#define __Orz_GameColourComponent__
#include "CGameColourInterface.h"
class _UpdateInOgreRenderingQueued_Colour;
namespace Ogre
{
class SceneNode;
}
namespace ParticleUniverse
{
class ParticleUniverseSystem;
}

class EntityMaterialInstance;
namespace Orz
{
class CGameColourInterface;
class  GameColourComponent: public Component
{ 
public :
	friend _UpdateInOgreRenderingQueued_Colour;
	GameColourComponent(void);
	virtual ~GameColourComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info) const;

	boost::scoped_ptr<CGameColourInterface> _ColourInterface;
	bool load(Ogre::SceneNode * node);

	boost::array<boost::scoped_ptr<EntityMaterialInstance>,4> _emi;

	bool enable(CGameColourInterface::STATE state);
	bool update(TimeType time);
	bool updateFatein(TimeType time);
	bool updateFateout(TimeType time);
	bool updateRotate(TimeType time);
	bool updatesetColour(TimeType time);
	void setColour(float r,float g,float b);
	void reset(void);

	Ogre::SceneNode * _node;
	Ogre::SceneNode * _nodeQuan[4];
	TimeType _curTime;
	boost::scoped_ptr<_UpdateInOgreRenderingQueued_Colour> _updateInOgreRenderingQueued_Colour;
};
}
#endif
