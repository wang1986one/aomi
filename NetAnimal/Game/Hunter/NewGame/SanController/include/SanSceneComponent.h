#ifndef __Orz_SanSceneComponent__
#define __Orz_SanSceneComponent__
#include "SanControllerConfig.h"	
#include "CSanProcessInterface.h"
namespace Ogre
{
class SceneNode;
}
namespace CCS
{
class FixedCameraMode;
}
namespace ParticleUniverse
{
	class ParticleSystem;
}

//ParticleUniverse::ParticleSystemManager* mParticleSystemManager = NULL; 


namespace Orz
{
class CGameActionInterface;
class CSanSceneInterface;


class   SanSceneComponent: public Component
{
	 
public :
	SanSceneComponent(void);
	virtual ~SanSceneComponent(void);
private:
	bool activate(SanProcess process);
	bool load(const std::string & gName);
	virtual ComponentInterface * _queryInterface(const TypeInfo & info) const;
	Ogre::SceneNode * getSceneNode(void) const;

	//bool enableParticle(const std::string & name, Ogre::SceneNode * node);
	//bool updateParticle(TimeType i);
	//void disableParticle(void);

	ComponentPtr _dotSceneComp;
	ComponentPtr _ccsComp;
//	ComponentPtr _pComp;
	//ComponentPtr _debugger;
	boost::scoped_ptr<CSanSceneInterface> _interface;
	boost::scoped_ptr<CGameActionInterface> _actionInterface;
	boost::scoped_ptr<CCS::FixedCameraMode> _fixed;
	Ogre::SceneNode * _node;
	ParticleUniverse::ParticleSystem* _system ;
	ComponentPtr _particleComp;
	
};



}
#endif