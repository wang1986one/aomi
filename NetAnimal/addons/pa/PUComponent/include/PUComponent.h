#ifndef __Orz_PUComponent__
#define __Orz_PUComponent__
namespace Ogre
{
class SceneNode;
}

namespace ParticleUniverse
{
	class ParticleSystem;
}
namespace Orz
{
class CParticleInterface;
class PUComponent: public Component
{
	 
public :
	PUComponent(void);
	virtual ~PUComponent(void);
private:
	bool enable(const std::string & name , Ogre::SceneNode * node);
	void disable(void);
	bool update(TimeType i);
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);
	boost::scoped_ptr<CParticleInterface> _interface;

	
	ParticleUniverse::ParticleSystem* _system ;
};



}
#endif