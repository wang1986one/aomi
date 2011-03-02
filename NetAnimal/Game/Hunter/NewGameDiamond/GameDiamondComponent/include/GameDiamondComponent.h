#ifndef __Orz_GameDiamondComponent__
#define __Orz_GameDiamondComponent__
#include "CGameDiamondInterface.h"
namespace Ogre
{
class SceneNode;
}
class EntityMaterialInstance;
namespace ParticleUniverse
{
	class ParticleSystemManager;
	class ParticleUniverseSystem;
	class ParticleSystem;
}
class _UpdateInOgreRenderingQueued_Diamond;

namespace Orz
{
class CGameDiamondInterface;
class  GameDiamondComponent: public Component
{ 

public :
	friend _UpdateInOgreRenderingQueued_Diamond;
	GameDiamondComponent(void);
	virtual ~GameDiamondComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);

	boost::scoped_ptr<CGameDiamondInterface> _diamondInterface;
	bool load(Ogre::SceneNode * node);

	boost::array<boost::scoped_ptr<EntityMaterialInstance>,6> _emi;
    boost::scoped_ptr<EntityMaterialInstance> _emiAnimal;
	void emiSetTransparency(Ogre::Real trans);
	void changeAnimal(CGameDiamondInterface::ANIMALS animal);//��ת�в��ϱ任����
	void setAnimal(CGameDiamondInterface::ANIMALS animal);//ѡ��ĳ������
	void loadAnimals();

	bool enable(CGameDiamondInterface::STATE state);
	bool update(TimeType time);
	bool updateFloat(TimeType time);
	bool updateFatein(TimeType time);
	bool updateFateout(TimeType time);
	bool updateOpenOrClose(TimeType time);//_dirDiaAni�����ִ򿪻����
	bool updateOpenstateRotate(TimeType time);
	bool updateDisplayAnimal(TimeType time);

	void reset(void);

	Ogre::Vector3 _pos;
	Ogre::Vector3 _curPos;
	Ogre::SceneNode * _node;
	Ogre::SceneNode * _nodeAnimal;
	boost::array<Ogre::Entity* ,4> _entAnimals;
	TimeType _currTime;
	ParticleUniverse::ParticleSystem * _system;
	boost::array<Ogre::AnimationState*,6> _DiaAnimationState;
	float degree;//360ΪһȦ,��¼��ʯ�Ͷ�����ת�ĽǶ�

	void _DasAddtime(TimeType time);
	int _dirDiaAni;//��ʯ�򿪺��϶����ķ���1Ϊ�򿪣�-1Ϊ����
	void setDiamondColour(float r,float g,float b);

	ComponentPtr _moreWinner;
	boost::scoped_ptr<_UpdateInOgreRenderingQueued_Diamond> _updateInOgreRenderingQueued_Diamond;
};
}
#endif
