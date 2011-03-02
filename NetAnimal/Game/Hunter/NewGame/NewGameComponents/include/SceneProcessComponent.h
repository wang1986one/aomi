#ifndef __Orz_SceneProcessComponent__
#define __Orz_SceneProcessComponent__
#include "CSanProcessInterface.h"
#include "CNewGameSceneInterface.h"

namespace ParticleUniverse
{
	class ParticleSystem;
}
namespace Orz
{

class CGameActionInterface;
class  SceneProcessComponent: public Component
{
	 
public :
	SceneProcessComponent(void);
	virtual ~SceneProcessComponent(void);
private:
	
	ComponentInterface * _queryInterface(const TypeInfo & info);
	ComponentPtr _sceneComponent;
	bool activate(SanProcess process);
	boost::scoped_ptr<CGameActionInterface> _actionInterface;
	bool enable(void);
	void disable(void);
	bool update(TimeType i);


	
	bool winEnable(CNewGameSceneInterface::CAM_DIRECTION camDirection, TimeType passtime, TimeType time, bool effect = false);
	//void winDisable(void);
	bool winUpdate(TimeType time);
	TimeType _time;
	
	SoundPlayerPtr _light;
	SoundPlayerPtr _rain;

private:

	bool playEnable(void);
	void playDisable(void);

	ParticleUniverse::ParticleSystem * _system;

	
bool enableLighting();

};



}
#endif