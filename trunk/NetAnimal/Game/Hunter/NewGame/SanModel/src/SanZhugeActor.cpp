#include "SanModelBaseStableHeaders.h"
#include "SanZhugeActor.h"
#include "CSanProcessInterface.h"
#include "COgreEntityInterface.h"
using namespace Orz;
SanZhugeActor::SanZhugeActor(const std::string & name, parameter_type pt):Actor(name),_update(NULL)
{
	_pos = Orz::VariantData<Ogre::Vector3>::get((*pt)["pos"]);
	_scale = Orz::VariantData<Ogre::Vector3>::get((*pt)["scale"]);
	_radian = Orz::VariantData<float>::get((*pt)["radian"]);//nvl["radian"] = Orz::VariantData<float>::set(0.f);
	_process = Orz::VariantData<ComponentPtr>::get((*pt)["process"]);//nvl["radian"] = Orz::VariantData<float>::set(0.f);
}
SanZhugeActor::~SanZhugeActor(void)
{
	
}


///���أ������ڴ�����Ϣ����
void SanZhugeActor::doExecute(Event * evt)
{
	
}


///���أ������ڽ�����Ϣ�������
void SanZhugeActor::doEnable(void)
{
	_zhuge = ComponentFactories::getInstance().create("SanZhuGe");
	COgreEntityInterface * entity = _zhuge->queryInterface<COgreEntityInterface>();

	Ogre::SceneNode *sn =  entity->getSceneNode();
	sn->setPosition(_pos);
	sn->setScale(_scale);
	sn->yaw(Ogre::Radian(_radian));


	_process
		->queryInterface<CSanProcessInterface>()
		->addObject(_zhuge);
	setChannel(Orz::EventChannel::create().clear());

}


///���أ��������뿪��Ϣ�������
void SanZhugeActor::doDisable(void)
{
	_zhuge.reset();
}

///���أ������ڸ��µ���
void SanZhugeActor::doFrame(unsigned int step)
{
	
}