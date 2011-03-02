#ifndef __Orz_NewGameSceneComponent__
#define __Orz_NewGameSceneComponent__

#include "CNewGameSceneInterface.h"
namespace ParticleUniverse
{
	class ParticleSystemManager;
	class ParticleUniverseSystem;
	class ParticleSystem;
}

namespace Ogre
{
	class DotSceneLoader;
	class BillboardSet;
	class Billboard;
}
namespace Orz
{
class CNewGameSceneInterface;
class COgreSceneLoaderInterface;
class COgreCCSInterface;
class _UpdateInOgreRenderingQueued_Scene;

class  NewGameSceneComponent: public Component
{ 
	friend class _UpdateInOgreRenderingQueued_Scene;
public :
	NewGameSceneComponent(void);
	virtual ~NewGameSceneComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);
	boost::scoped_ptr<CNewGameSceneInterface> _interface;
	Ogre::SceneNode * _node;//整个场景的结点
	Ogre::SceneNode * _RotationNode;//用于旋转用结点
	Ogre::SceneNode * Animalnode[24];
	boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24>  _lights;
	TimeType _setLightsAlltime;//更换所有灯的时间
	TimeType _setLightsPassTime;//更换灯色开始后经过的所有时间
	TimeType StormTime;
	TimeType OpenMouthTime;
	TimeType _camPasstime;
	TimeType _camPassedTime;
	TimeType _curTime;
	bool isSettingLights;
	int currentlight;//当前灯的位置
	int settedlights;//已经换色的灯的数量
	std::vector<Ogre::AnimationState*> _SceneAnimation;
	boost::array<Ogre::AnimationState*,2> _teethAnimation;
	boost::array<Ogre::MaterialPtr,24> _matLights;
	boost::array<Ogre::String,7> _Colour;
	boost::scoped_ptr<_UpdateInOgreRenderingQueued_Scene> _updateInOgreRenderingQueued;
	ParticleUniverse::ParticleSystem * _psRain;
	ParticleUniverse::ParticleSystem * _psGold;
	Ogre::BillboardSet* bbset;
	Ogre::Billboard* bb;
	Ogre::BillboardSet* bbsetQQ;//气球公告板
	Ogre::Billboard* bbQQ;
	Ogre::SceneNode * getSceneNode(void) const;
	Ogre::SceneManager * sm;
	Ogre::AnimationState* mCamAnimState;
	Ogre::SceneNode* moveCamera_win_lookat;
	Ogre::Camera* mCamera;
	Ogre::SceneNode* camNode;
	CNewGameSceneInterface::CAM_DIRECTION _camDirection;
	Ogre::Animation* anim;
	boost::scoped_ptr<Ogre::DotSceneLoader> _dotSceneLoader;
	Ogre::SceneNode* _nodeGold;
	Ogre::SceneNode* _nodeFeiting;//飞艇的位置
	bool _isUpdateFeiting;//是否更新飞艇位置
private:
	// 载入默认的场景
	bool load(void);
	// 卸载场景
	void unload(void);
	// 更新场景
	bool update(TimeType updatetime);
	void setAmbientLight(float r,float g,float b);
	bool updateMoveCamera_win(TimeType updatetime);
	bool updateSetlights(TimeType updatetime);
	void moveCamera_win(CNewGameSceneInterface::CAM_DIRECTION camDirection,TimeType passtime);
	bool updateStorm(TimeType updatetime);
	bool updateGoldWin(TimeType updatetime);

	void resetCam(void);
	void reset(void);//重置场景
	void enableLightningStorm(bool enable);
	void enableSpitGold(bool enable){}//暂时不用
	void enableGoldWineffect(bool enable,int Number);

	// //获取场景运动物体的节点
	Ogre::SceneNode* getHelper(CNewGameSceneInterface::HELPERS helper);
	Ogre::SceneNode* setLights(const boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> & lights, TimeType time);
	//设定某个灯的颜色,如果加高亮设第2参数为"true"
	void setOneLight(int curlight,bool highlight=false);

	void updateSceneAnimation(TimeType time);
	void setupSceneAnimation(void);

	void glitter(int i);
	bool goGlitter(int i);
	Orz::TimerPtr _timer;

	
	Orz::SoundPlayerPtr _coinLoop; 

};
}
#endif