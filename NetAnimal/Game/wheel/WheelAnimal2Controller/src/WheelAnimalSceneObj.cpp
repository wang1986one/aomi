#include "WheelAnimalControllerStableHeaders.h"
#include "WheelAnimalSceneObj.h"
#include "BaseSceneImpl.h"
#include "ThirdParty/Ofusion/OgreOSMScene.h"
#include <OGRE/Ogre.h>
using namespace Orz;


WheelAnimalSceneObj::WheelAnimalSceneObj(Ogre::SceneManager* pSceneMgr, Ogre::RenderWindow* win):_osm(new OSMScene(pSceneMgr, win)),_sn(NULL)  ,_cameraSn(NULL),_anim(NULL)	,
_animState(NULL),_theTime(0.f),_colorN(0),_senceNode(NULL)
{

	
	/*
		Ogre::AnimationState * _nullAnimationState; 
		Ogre::SceneNode * _nullSceneNode;	 
		Ogre::Entity * _nullEntity;*/


}
WheelAnimalSceneObj::~WheelAnimalSceneObj(void)
{

}
void WheelAnimalSceneObj::load(const std::string & filename)
{

	//Ogre::ru  * s =  Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0, 0 ,0));
	
	//导入场景资源
	_impl = BaseSceneImpl::create(_osm, filename);

	//创建总场景节点
	_senceNode = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode();

	//创建场景
	_osm->createScene(_senceNode);
	_senceNode->setVisible(true);

	//s->setVisible(false);
	/*_impl->getCamera(SCENE_CAMERA)->setPosition(Ogre::Vector3(-98.851, 164.283, 237.886));
	_impl->getCamera(SCENE_CAMERA)->setOrientation(Ogre::Quaternion(0.999578, -0.0192806, -0.0226839));*/

	//创建摄像机的节点
	_cameraSn = OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(); 
	
	//获取场景的摄像机
	Ogre::Camera * camera = _impl->getCamera(SCENE_CAMERA);


	//创建摄像机的节点并设置它的位置
	_cameraSn = camera->getParentSceneNode()->createChildSceneNode(Ogre::Vector3(0.f, 164.283f, 237.886f));
	
	
	//_cameraSn->setPosition(Ogre::Vector3(-98.851, 164.283, 237.886));
	//_cameraSn->setOrientation(Ogre::Quaternion(0.999578, -0.0192806, -0.0226839));
	//camera->detatchFromParent();   

	//脱离原有的节点
	camera->detachFromParent();

	//摄像机绑定在节点上
	_cameraSn->attachObject(_impl->getCamera(SCENE_CAMERA));
	
	//创建场景的中心节点
	Ogre::SceneNode * sn =  getBaseCenter()->createChildSceneNode(Ogre::Vector3(0, 100,0));

	//setAutoTracking可以让你的摄像机总是盯着你场景中的某一个节点
	//方法中第一个参数确定是否打开自动跟踪，在任何一帧渲染之前都可以重新设置它。
	//二个参数是被跟踪节点得指针，除非你第一个参数是false（这时候可以用NULL），否则你必须确定调用的时候指针指向的节点必须有效
	camera->setAutoTracking(true, sn);
//	std::cout<<_camera->getPosition()<<"!"<<_camera->getOrientation()<<std::endl;



	//获取场景管理器
	 Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();

	// set up spline animation of node
	 //定义动画，指定动画的名称及长度（这里为4秒）
	_anim = sm->createAnimation("Cam_", 4);

	//// Spline it for nice curves
	// // 指定动画关键帧之间的插值方式（包括线性插值和样条插值）
	_anim->setInterpolationMode(Ogre::Animation::IM_LINEAR);

	//定义动画的一个动画轨迹，并指定这个轨迹是作用到_cameraSn节点上的
	//// Create a track to animate the camera's node
	Ogre::NodeAnimationTrack * track = _anim->createNodeTrack(0, _cameraSn);
											
	 // 定义动画轨迹包含的关键帧，下面定义了3个关键帧，加上起始帧
	// 4个关健帧形成了一个曲线的动画
	Ogre::TransformKeyFrame* key = track->createNodeKeyFrame(0); // startposition
	key->setTranslate(Ogre::Vector3(0.f, 0.3f, 237.886f));

	 key = track->createNodeKeyFrame(3); // startposition
	key->setTranslate(Ogre::Vector3(0.f, 0.3f, 237.886f));

	
	key = track->createNodeKeyFrame(4);
	key->setTranslate(Ogre::Vector3(0.f, -80.f, -400.f));

   //////////////////////////////////
	
	//定义动画的一个动画轨迹，并指定这个轨迹是作用到创建场景的中心节点sn上的
	track = _anim->createNodeTrack(1, sn);
	key = track->createNodeKeyFrame(0); // startposition
	key->setTranslate(Ogre::Vector3(0, 0,0));

	
	key = track->createNodeKeyFrame(3); // startposition
	key->setTranslate(Ogre::Vector3(0, 0,0));

	
	key = track->createNodeKeyFrame(4);
	key->setTranslate(Ogre::Vector3(0, 200,0));										  


	//// Create a new animation state to track this

	//定义AnimationState类的对象，它和刚才定义的动画类相对应。设置动画的状态为启用：
	_animState = sm->createAnimationState("Cam_");
	_animState->setEnabled(true);// 启用该动画
	_animState->setLoop(false);
	/*	Ogre::MaterialPtr material = Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("Material_#11/lanseshuijing"));
	material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("shuijing-lv.dds");*/
}
  
void WheelAnimalSceneObj::setTable(int n, int table)
{
	std::cout<<n<<":"<<table<<std::endl;

	Ogre::Entity *  ent = getEntity(SceneItemMark(TABLE_0+n));
	if(ent)
		return ent->setMaterialName(_impl->getTable(table));
}

void WheelAnimalSceneObj::setTableLiang(int n, int table)
{
	std::cout<<n<<":"<<table<<std::endl;

	Ogre::Entity *  ent = getEntity(SceneItemMark(TABLE_0+n));
	if(ent)
		return ent->setMaterialName(_impl->getTableLiang(table));
}

void WheelAnimalSceneObj::setTableAn(int n, int table)
{
	std::cout<<n<<":"<<table<<std::endl;

	Ogre::Entity *  ent = getEntity(SceneItemMark(TABLE_0+n));
	if(ent)
		return ent->setMaterialName(_impl->getTableAn(table));
}

  
void WheelAnimalSceneObj::setLight(int n, int light)
{
	Ogre::Entity *  ent = getEntity(SceneItemMark(LIGHT_0+n));
	if(ent)
		return ent->setMaterialName(_impl->getLight(light));
}

void WheelAnimalSceneObj::setLightLiang(int n, int light)
{
	Ogre::Entity *  ent = getEntity(SceneItemMark(LIGHT_0+n));
	if(ent)
		return ent->setMaterialName(_impl->getLightLiang(light));
}

void WheelAnimalSceneObj::setLightAn(int n, int light)
{
	Ogre::Entity *  ent = getEntity(SceneItemMark(LIGHT_0+n));
	if(ent)
		return ent->setMaterialName(_impl->getLightAn(light));
}

void WheelAnimalSceneObj::showSence(bool show, bool show1)
{
	_senceNode->setVisible(show,show1);
}
		
Ogre::Camera * WheelAnimalSceneObj::getCamera(SceneItemMark mark)
{
   return _impl->getCamera(mark);
}
Ogre::SceneNode * WheelAnimalSceneObj::getSceneNode(SceneItemMark mark)
{
   return _impl->getSceneNode(mark);
}
Ogre::Entity * WheelAnimalSceneObj::getEntity(SceneItemMark mark)
{
   return _impl->getEntity(mark);
}


Ogre::SceneNode * WheelAnimalSceneObj::getNeedle(void)
{
	return getSceneNode(NEEDLE);
}	

Ogre::Vector3 WheelAnimalSceneObj::getCenterPoint(void)
{
	return getNeedle()->getPosition();
}
				
Ogre::Camera * WheelAnimalSceneObj::getCamera(void)
{
	return getCamera(SCENE_CAMERA);
}
Ogre::SceneNode * WheelAnimalSceneObj::getBase(int n)
{
	return getSceneNode(SceneItemMark(BASE_0+n));
}


void WheelAnimalSceneObj::showBaseLight(int n, WheelEnum::LIGHT_COLOR id, bool show)
{
	_impl->showBaseLight(n, id,  show);
}
AnimalManagerPtr WheelAnimalSceneObj::getAnimalManager(void) const
{
	return _impl->getAnimalManager();
}

Ogre::AnimationState * WheelAnimalSceneObj::getSceneAnimation(SceneItemMark mark)
{
	if(mark == SCENE_ANIMATION_2)
		return _animState;
	Ogre::AnimationState * ret =  _impl->getSceneAnimation(mark);
	if(ret)
		return _impl->getSceneAnimation(mark);
	return getNullAnimationState();
}


int WheelAnimalSceneObj::findRandomAnimal(WheelEnum::AnimalType & type)
{
	int r = rand();
	for(int i = 0 ; i< 24; ++i)
	{
		int n = (i+r)%24;
		AnimalPtr animal = getAnimal(n);
		if(animal->getType() == type)
		{ 
			return n;
		}
	}

	for(int i = 0 ; i< 24; ++i)
	{
		int n = (i+r)%24;
		AnimalPtr animal = getAnimal(n);
		if(animal->getType().first == type.first)
		{ 
			return n;
		}
	}

	return -1;
}

Ogre::SceneNode * WheelAnimalSceneObj::getBaseCenter()
{
	if(_sn == NULL)
	{
		_sn =  Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(getCenterPoint());
		//_sn->yaw(Ogre::Radian(Ogre::Math::PI));
		for(int i=0 ; i<(BASE_ALL-BASE_0); ++i)
		{
			Ogre::SceneNode * base = getBase(i);
			Ogre::Node * parent = base->getParent();
			Ogre::Vector3 p = base->getPosition();
			if(parent)
			{
				parent->removeChild(base);
			}
			base->translate(-getCenterPoint());
			_sn->addChild(base);
			Ogre::SceneManager * sm = OgreGraphicsManager::getSingleton().getSceneManager();
			Ogre::Entity * ent = sm->createEntity("ring"+Ogre::StringConverter::toString(i), "zp_dwdzgh.mesh");
			Ogre::SceneNode * node = base->createChildSceneNode("ring"+Ogre::StringConverter::toString(i),Ogre::Vector3(0.f, 10.f, 0.f));
			node->setScale(0.6f,0.6f,0.6f);
			node->attachObject(ent);
			Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getSceneNode("ring"+Ogre::StringConverter::toString(i))->setVisible(false);
		}
	}
	return _sn;
}


AnimalPtr WheelAnimalSceneObj::getAnimal(int n)
{
	return _impl->getAnimal(n);
}


void WheelAnimalSceneObj::addLight(WheelEnum::LIGHT_COLOR color)
{
	_lights.push_back(color);
}
void WheelAnimalSceneObj::clearLight(void)
{
	_lights.clear();
}


void WheelAnimalSceneObj::update(TimeType time)
{
	_theTime += time;
	while(_theTime>0.2f)
	{
		
		_theTime -= 0.2f;
		if(_lights.empty())
		{
			showLight(WheelEnum::DeepBlue);
			return;
		
		}
		if(_colorN >= _lights.size())
		{
			_colorN = 0;
		}
		showLight(_lights.at(_colorN));
		++_colorN;
	}
}


void WheelAnimalSceneObj::showLight(WheelEnum::LIGHT_COLOR color)
{
	Ogre::MaterialPtr material = Ogre::MaterialPtr(Ogre::MaterialManager::getSingleton().getByName("zp_cj_waiwei/shuijing-slan"));
	
	switch(color)
	{
	case WheelEnum::Red: 
		material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("shuijing-hong.dds");
		break;
	case WheelEnum::Yellow: 
		material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("shuijing-huang.dds");
		break;
	case WheelEnum::Green: 
		material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("shuijing-lv.dds");
		break;
	case WheelEnum::Blue: 
		material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("shuijing-lan.dds");
		break;
	case WheelEnum::DeepBlue: 
		material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("shuijing-slan.dds");
		break;
			
	}
	
}


Ogre::SceneNode * WheelAnimalSceneObj::getNullSceneNode(void)
{
	return _impl->getNullSceneNode();
}
Ogre::Entity * WheelAnimalSceneObj::getNullEntity(void)
{
	return _impl->getNullEntity();
}
Ogre::AnimationState * WheelAnimalSceneObj::getNullAnimationState(void)
{
	return _impl->getNullAnimationState();
}