#ifndef __Orz_GameBaseComponent__
#define __Orz_GameBaseComponent__
#include "CGameBaseInterface.h"
namespace Ogre
{
class SceneNode;
class Entity;
}
namespace Orz
{   

	
class CGameBaseInterface;
class  GameBaseComponent: public Component//Õ‚»¶
{ 
public :
	GameBaseComponent(void);
	virtual ~GameBaseComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);
	
 bool setColor(int id, CGameBaseInterface::LIGHT_COLOR color);
	boost::scoped_ptr<CGameBaseInterface> _baseInterface;
	bool load(int id, Ogre::SceneNode * node);
	Ogre::SceneNode * getSceneNode(int id);
	bool init(Ogre::SceneNode * node);
	Ogre::SceneNode * _node;
	boost::array<Ogre::SceneNode *, 24> _nodes;
	boost::array<Ogre::SceneNode *, 24> _nodes2;
	boost::array<Ogre::Entity *, 24> _entities;
	boost::array<Ogre::Entity *, 24> _entities2;
};
}
#endif