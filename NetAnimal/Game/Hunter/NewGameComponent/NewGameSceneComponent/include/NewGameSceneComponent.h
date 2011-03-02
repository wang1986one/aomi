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
	Ogre::SceneNode * _node;//���������Ľ��
	Ogre::SceneNode * _RotationNode;//������ת�ý��
	Ogre::SceneNode * Animalnode[24];
	boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24>  _lights;
	TimeType _setLightsAlltime;//�������еƵ�ʱ��
	TimeType _setLightsPassTime;//������ɫ��ʼ�󾭹�������ʱ��
	TimeType StormTime;
	TimeType OpenMouthTime;
	TimeType _camPasstime;
	TimeType _camPassedTime;
	TimeType _curTime;
	bool isSettingLights;
	int currentlight;//��ǰ�Ƶ�λ��
	int settedlights;//�Ѿ���ɫ�ĵƵ�����
	std::vector<Ogre::AnimationState*> _SceneAnimation;
	boost::array<Ogre::AnimationState*,2> _teethAnimation;
	boost::array<Ogre::MaterialPtr,24> _matLights;
	boost::array<Ogre::String,7> _Colour;
	boost::scoped_ptr<_UpdateInOgreRenderingQueued_Scene> _updateInOgreRenderingQueued;
	ParticleUniverse::ParticleSystem * _psRain;
	ParticleUniverse::ParticleSystem * _psGold;
	Ogre::BillboardSet* bbset;
	Ogre::Billboard* bb;
	Ogre::BillboardSet* bbsetQQ;//���򹫸��
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
	Ogre::SceneNode* _nodeFeiting;//��ͧ��λ��
	bool _isUpdateFeiting;//�Ƿ���·�ͧλ��
private:
	// ����Ĭ�ϵĳ���
	bool load(void);
	// ж�س���
	void unload(void);
	// ���³���
	bool update(TimeType updatetime);
	void setAmbientLight(float r,float g,float b);
	bool updateMoveCamera_win(TimeType updatetime);
	bool updateSetlights(TimeType updatetime);
	void moveCamera_win(CNewGameSceneInterface::CAM_DIRECTION camDirection,TimeType passtime);
	bool updateStorm(TimeType updatetime);
	bool updateGoldWin(TimeType updatetime);

	void resetCam(void);
	void reset(void);//���ó���
	void enableLightningStorm(bool enable);
	void enableSpitGold(bool enable){}//��ʱ����
	void enableGoldWineffect(bool enable,int Number);

	// //��ȡ�����˶�����Ľڵ�
	Ogre::SceneNode* getHelper(CNewGameSceneInterface::HELPERS helper);
	Ogre::SceneNode* setLights(const boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> & lights, TimeType time);
	//�趨ĳ���Ƶ���ɫ,����Ӹ������2����Ϊ"true"
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