#include "NewGameSceneComponentStableHeaders.h"
#include "NewGameSceneComponent.h"
#include "COgreSceneLoaderInterface.h"
#include "COgreCCSInterface.h"
#include "DotSceneLoader.h"
#include <orz/View_OGRE3D/OgreRenderingQueuedListener.h>
#include "fish.h"
#include "ParticleUniverse/ParticleUniverseSystemManager.h"
#include "ParticleUniverse/ParticleUniverseSystem.h"
namespace Orz
{

	class _UpdateInOgreRenderingQueued_Scene : public OgreRenderingQueuedListener
	{
	public:
		_UpdateInOgreRenderingQueued_Scene(NewGameSceneComponent * animation):_animation(animation),_enable(false)
		{
			_fish = new fish();
			_frameDurationHistory.push_back(WORLD_UPDATE_INTERVAL);
		}
		virtual ~_UpdateInOgreRenderingQueued_Scene(void)
		{
			if(_fish!=NULL)
				delete _fish;
		}
		inline bool run(void)
		{

			Orz::OgreGraphicsManager::getSingleton().addRenderingQueuedListener(this);
			_enable = true;
			return true;
		}
		inline TimeType getExactLastFrameDuration(TimeType t)
		{
			if (t > 0.200f)
		 {
			 t = _frameDurationHistory.back(); 
		 }
			return t;

		}

		inline TimeType getPredictedFrameDuration () const
		{
			TimeType totalFrameTime = 0;

			std::deque<TimeType>::const_iterator it;
			for (it = _frameDurationHistory.begin(); it != _frameDurationHistory.end(); ++it)
				totalFrameTime += *it;
			return totalFrameTime/_frameDurationHistory.size();
		}

		void addToFrameHistory (TimeType t)
		{
			_frameDurationHistory.push_back (t);
			if (_frameDurationHistory.size () > (unsigned int) 20)
				_frameDurationHistory.pop_front ();
		}
		virtual bool update(TimeType interval)
		{
			TimeType t = getExactLastFrameDuration(interval);
			addToFrameHistory(t);
			TimeType pt = getPredictedFrameDuration();
			//_enable = _animation->updateSceneAnimation(pt);
			_animation->updateSceneAnimation(pt/2);
			_fish->update(pt);
			return  true;
		}
		inline bool isEnable(void)
		{
			return _enable;
		}
		inline void stop(void)
		{
			Orz::OgreGraphicsManager::getSingleton().removeRenderingQueuedListener(this);

		}
	private:
		NewGameSceneComponent * _animation;
		bool _enable;
		std::deque<TimeType> _frameDurationHistory;
		Orz::fish* _fish;

	};


}

using namespace Orz;

NewGameSceneComponent::NewGameSceneComponent(void):
_interface(new CNewGameSceneInterface()),
_dotSceneLoader(new Ogre::DotSceneLoader()),
isSettingLights(false),
_psRain(NULL),
bbset(NULL),
bb(NULL),
StormTime(0),
_psGold(NULL),
_curTime(0),
_isUpdateFeiting(false)
{
	_updateInOgreRenderingQueued.reset(new _UpdateInOgreRenderingQueued_Scene(this));
	_interface->load                  =  boost::bind(&NewGameSceneComponent::load,this);
	_interface->unload                =  boost::bind(&NewGameSceneComponent::unload,this);
	_interface->update                =  boost::bind(&NewGameSceneComponent::update,this,_1);
	_interface->getSceneNode          =  boost::bind(&NewGameSceneComponent::getSceneNode,this); 
	_interface->getHelper             =  boost::bind(&NewGameSceneComponent::getHelper,this,_1);
	_interface->setLights             =  boost::bind(&NewGameSceneComponent::setLights,this,_1,_2);
	_interface->moveCamera_win        =  boost::bind(&NewGameSceneComponent::moveCamera_win,this,_1,_2);
	_interface->resetCam              =  boost::bind(&NewGameSceneComponent::resetCam,this);
	_interface->reset                 =  boost::bind(&NewGameSceneComponent::reset,this);
	_interface->setOneLight           =  boost::bind(&NewGameSceneComponent::setOneLight,this,_1,_2);
	_interface->enableLightningStorm  =  boost::bind(&NewGameSceneComponent::enableLightningStorm,this,_1);
	_interface->enableSpitGold        =  boost::bind(&NewGameSceneComponent::enableSpitGold,this,_1);
	_interface->enableGoldWineffect   =  boost::bind(&NewGameSceneComponent::enableGoldWineffect,this,_1,_2);
	_interface->setAmbientLight       =  boost::bind(&NewGameSceneComponent::setAmbientLight,this,_1,_2,_3);

	_interface->glitter               =  boost::bind(&NewGameSceneComponent::glitter, this, _1);
	_setLightsPassTime = 0; 
	currentlight = 0;
	settedlights = 0;
	_Colour[CNewGameSceneInterface::Red] = "r";
	_Colour[CNewGameSceneInterface::Green]= "g";
	_Colour[CNewGameSceneInterface::Yellow]="y";
	_Colour[CNewGameSceneInterface::Red_H] = "rh";
	_Colour[CNewGameSceneInterface::Green_H]= "gh";
	_Colour[CNewGameSceneInterface::Yellow_H]="yh";
	_Colour[CNewGameSceneInterface::Black]="black";

	_coinLoop = Orz::ISoundManager::getSingleton().createPlayer("coin_loop.wav");
	_coinLoop->load();

}

NewGameSceneComponent::~NewGameSceneComponent(void)
{
	_coinLoop->unload();
}
ComponentInterface * NewGameSceneComponent::_queryInterface(const TypeInfo & info)
{
	if (info==TypeInfo(typeid(CNewGameSceneInterface)))
	{
		return _interface.get();
	}
	return NULL;
}

// 载入默认的场景
bool Orz::NewGameSceneComponent::load(void)
{

	sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();

	_node =  sm->getRootSceneNode()->createChildSceneNode();


	_dotSceneLoader->parseDotScene("onlyscene_ogre_model.scene", "HunterScene", sm, _node);

	BOOST_FOREACH(nodeProperty np,_dotSceneLoader->nodeProperties)
	{
		std::cout<<np.nodeName<<std::endl;
	}
	
	sm->setAmbientLight(Ogre::ColourValue());
	sm->setSkyBox(true,"Examples/CloudyNoonSkyBox");

	mCamera=Orz::OgreGraphicsManager::getSingleton().getCamera();

	camNode = sm->getRootSceneNode()->createChildSceneNode();
	camNode->attachObject(mCamera);
	camNode->setPosition(-2.23259f,785.108f,964.198f);
	camNode->setOrientation(Ogre::Quaternion(0.952338f,-0.3053f,0.00124852f,0.000394359f));


	mCamera->setPosition(0,0,0); 
	mCamera->setOrientation(Ogre::Quaternion());
	moveCamera_win_lookat = sm->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,243.f,0));//未用
	_RotationNode=_node->createChildSceneNode();
	Ogre::SceneNode * temp;
	for(int i=0 ;i<24;i++)
	{
		bool ret = sm->hasSceneNode("animal0");
		temp=sm->getSceneNode("animal"+Ogre::StringConverter::toString(i));
		Animalnode[i]=_RotationNode->createChildSceneNode(temp->getPosition(),
			temp->getOrientation());
	}


	anim = sm->createAnimation("CameraTrack", 150);
	anim->setInterpolationMode(Ogre::Animation::IM_SPLINE);

	Ogre::NodeAnimationTrack* track = anim->createNodeTrack(0, camNode);
	Ogre::TransformKeyFrame * mykeyframe;

	mykeyframe = track->createNodeKeyFrame(0);
	mykeyframe->setTranslate(Ogre::Vector3(-2.23259f,785.108f,964.198f));
	mykeyframe->setRotation(Ogre::Quaternion(0.952338f,-0.3053f,0.00124852f,0.000394359f));
	mykeyframe=track->createNodeKeyFrame(10);
	mykeyframe->setTranslate(Ogre::Vector3(0,387,589));
	mykeyframe->setRotation(Ogre::Quaternion(1,0,0,0));

	mCamAnimState = sm->createAnimationState("CameraTrack");
	mCamAnimState ->setLoop(false);


	mCamera->setAutoTracking(false);
	setupSceneAnimation();
	_updateInOgreRenderingQueued->run();
	Ogre::Entity* ent = sm->createEntity("water_wav","water.mesh");
	ent->setMaterialName("water_wav");
	sm->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,92.6f,0))->attachObject(ent);
	for (int i=0;i<24;i++)
	{
		_lights[i] = CNewGameSceneInterface::Black;
	}
	Ogre::SceneNode* _nodeP = _node->createChildSceneNode("rain",Ogre::Vector3(0,100,0)); 
	//_nodeGold=sm->getRootSceneNode()->createChildSceneNode("gold",Ogre::Vector3(-540, -100, -150));吐金的位置
	_nodeGold=sm->getRootSceneNode()->createChildSceneNode("gold",Ogre::Vector3(0,0, 50));

	//_nodeFeiting=sm->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,1017.04f,-2546.1f));
	//_nodeFeiting->setScale(150,150,150);
	//_nodeFeiting->setOrientation(0.7071f, 0.00308532f, -0.7071f, 0.00308532f);
	_nodeFeiting=sm->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(726,750,-1540));
	_nodeFeiting->setScale(40,40,40);
	ent=sm->createEntity("planeqq","planeqq.mesh");
	_nodeFeiting->attachObject(ent);
	Ogre::SceneNode* _nodefeitingNum = _nodeFeiting->createChildSceneNode(Ogre::Vector3(-1.5,0,0));
	//_nodefeitingNum->setOrientation(0.976296f, 0, -0.21644f, 0);
	ent=sm->createEntity("feitingNum","feitingNum.mesh");
	_nodefeitingNum->attachObject(ent);
	_nodeFeiting->setVisible(false);

	//Ogre::Plane * plane=Ogre::
	//	Ogre::Mesh* p=Ogre::MeshManager::createPlane("planeqq","general","",512,512);
	//bbsetQQ = sm->createBillboardSet("bbsetQQ",1);
	//bbsetQQ->setMaterialName("qiqiuBB");
	//bbsetQQ->setDefaultDimensions(512,512);
	//bbQQ = bbsetQQ->createBillboard(0,0,-500);
	//Ogre::SceneNode* _nodesubFeiting = _nodeFeiting->createChildSceneNode();
	//_nodesubFeiting->setInheritScale(false);
	//_nodesubFeiting->setScale(1.5,1.5,1.5);
	//_nodesubFeiting->attachObject(bbsetQQ);


	Ogre::Light * light = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createLight();
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDiffuseColour(1,1,1);
	light->setDirection(Ogre::Vector3::UNIT_X);
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->attachObject(light);
	return true;
}

// 卸载场景
void Orz::NewGameSceneComponent::unload(void)
{
}

// 更新场景
bool Orz::NewGameSceneComponent::update(TimeType updatetime)
{	
	return false;
}
bool Orz::NewGameSceneComponent::updateMoveCamera_win(TimeType updatetime)
{	

	_camPassedTime+=updatetime;
	mCamAnimState->setEnabled(true);
	if (_camPassedTime>=_camPasstime)
	{
		mCamAnimState->setEnabled(false);
		if (_camDirection==CNewGameSceneInterface::Farward)
		{
			camNode->setPosition(0,387,589);
			camNode->setOrientation(Ogre::Quaternion(1,0,0,0));

		}
		else
		{
			camNode->setPosition(-2.23259f,785.108f,964.198f);
			camNode->setOrientation(Ogre::Quaternion(0.952338f,-0.3053f,0.00124852f,0.000394359f));
		}
		_interface->update =  boost::bind(&NewGameSceneComponent::update,this,_1);
		return false;
	}
	mCamAnimState->addTime((_camDirection?-1:1)*updatetime*10/_camPasstime);
	return true;
}
bool Orz::NewGameSceneComponent::updateSetlights(TimeType updatetime)
{	
	//updateSceneAnimation(updatetime);
	if(isSettingLights==true)
	{
		_setLightsPassTime+=updatetime;

		currentlight=floor(_setLightsPassTime/(_setLightsAlltime/23));
		if(currentlight==24)
		{
			isSettingLights=false;
			return false;
		}
		if(currentlight!=settedlights)//如果当前灯与已换色的灯数量不符，就按应该换色的数量全部换上材质
		{
			for(int i=0;i<=currentlight;i++)
			{
				setOneLight(currentlight);
			}
		}
		else
		{
			setOneLight(currentlight);
		}

		return true;

	}
	return false;
}
Ogre::SceneNode * Orz::NewGameSceneComponent::getSceneNode(void) const
{

	return	_node;

}

// //获取场景运动物体的节点
Ogre::SceneNode* Orz::NewGameSceneComponent::getHelper(CNewGameSceneInterface::HELPERS helper)
{
	if (helper>=0 && helper<24)
	{
		return Animalnode[(int)helper];
	} 
	if(helper==CNewGameSceneInterface::Helper24)
		return _RotationNode;
	else
		if(helper==24)
			return _RotationNode;
		else
			return NULL;
}
//设置灯的颜色
Ogre::SceneNode*  Orz::NewGameSceneComponent::setLights(const boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> & lights, TimeType time)
{
	isSettingLights=true;
	_setLightsAlltime=time;
	_setLightsPassTime=0;
	_lights=lights;
	currentlight=0;
	settedlights=0;
	_interface->update =  boost::bind(&NewGameSceneComponent::updateSetlights,this,_1);
	return NULL;
}

void Orz::NewGameSceneComponent::setOneLight(int curlight,bool highlight)
{
	if(highlight==true)
		sm->getEntity("light"+Ogre::StringConverter::toString(curlight+1))->
		setMaterialName("ps_"+_Colour[_lights[(CNewGameSceneInterface::LIGHT_COLOR)curlight]]+"h");
	else
	{
		sm->getEntity("light"+Ogre::StringConverter::toString(curlight+1))->
			setMaterialName("ps_"+_Colour[_lights[(CNewGameSceneInterface::LIGHT_COLOR)curlight]]);
	}
	settedlights++;
}

void Orz::NewGameSceneComponent::moveCamera_win(CNewGameSceneInterface::CAM_DIRECTION camDirection,TimeType passtime)
{
	_camPasstime=passtime;
	_camDirection=camDirection;
	_camPassedTime = 0;
	if (_camDirection==CNewGameSceneInterface::Backoff)
	{
		mCamAnimState->setTimePosition(10);
	}
	else
	{
		mCamAnimState->setTimePosition(0);
	}

	_interface->update =  boost::bind(&NewGameSceneComponent::updateMoveCamera_win,this,_1);
}

void Orz::NewGameSceneComponent::resetCam(void)
{
	camNode->setPosition(-2.23259f,785.108f,964.198f);
	camNode->setOrientation(Ogre::Quaternion(0.952338f,-0.3053f,0.00124852f,0.000394359f));
	mCamera->setPosition(0,0,0);
	mCamera->setOrientation(Ogre::Quaternion());
}

void Orz::NewGameSceneComponent::reset(void)
{
	resetCam();
	for (int i=0;i<24;i++)
	{
		setOneLight(i);
	}
}
void Orz::NewGameSceneComponent::setupSceneAnimation(void)
{
	Ogre::Entity* ent = sm->getEntity("cao5");
	Ogre::AnimationState* ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao10");
	ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao11");
	ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao12");
	ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao13");
	ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao14");
	ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao17");
	ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao21");
	ans=ent->getAnimationState("idel");	
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("cao29");
	ans=ent->getAnimationState("idel");	
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("hua26");
	ans=ent->getAnimationState("idel");	
	_SceneAnimation.push_back(ans);
	ent = sm->getEntity("hua27");
	ans=ent->getAnimationState("idel");
	_SceneAnimation.push_back(ans);

	for(uint i=0;i<_SceneAnimation.size();i++)
	{
		_SceneAnimation[i]->setLoop(true);
		_SceneAnimation[i]->setEnabled(true);
	}
}

void Orz::NewGameSceneComponent::updateSceneAnimation(TimeType time)
{
	for(uint i=0;i<_SceneAnimation.size();i++)
	{
		_SceneAnimation[i]->addTime(time);
	}
	_curTime+=time;
	if (_curTime>3.0e+38)
	{
		_curTime = 0;
	}
	if(_isUpdateFeiting==true)
	_nodeFeiting->setPosition(Ogre::Vector3(726,750,-1540) + 
		Ogre::Vector3(0, Ogre::Math::Sin(_curTime * 3.14*1/*速度*/)*30/*幅度*/ , 0));
}

void Orz::NewGameSceneComponent::enableLightningStorm(bool enable)
{
	ParticleUniverse::ParticleSystemManager * particleSystemManager = 
		ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	//不论开始或停止都要销毁
	if (_psRain!=NULL)
	{
		particleSystemManager->destroyParticleSystem(_psRain,sm);
		_psRain = NULL;
		/*	sm->destroyBillboardSet("BBSet");
		bbset=NULL;
		bb=NULL;*/
	}

	if (enable == true)
	{
		_psRain = particleSystemManager->createParticleSystem("rain", "newgame_rain", sm); 
		Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getSceneNode("rain")->attachObject(_psRain);
		_psRain->start();

		//bbset = sm->createBillboardSet("BBSet",1);
		//Orz::OgreGraphicsManager::getSingleton().getSceneManager()->
		//	getRootSceneNode()->attachObject(bbset);
		//bbset->setMaterialName("storm");
		//bbset->setDefaultDimensions(256,400);
		//bbset->setBillboardOrigin(Ogre::BillboardOrigin::BBO_BOTTOM_CENTER);
		//bb = bbset->createBillboard(Vector3(0,  250,  0));
		//StormTime = 0;
		//_interface->update =  boost::bind(&NewGameSceneComponent::updateStorm,this,_1);
		_interface->update = boost::lambda::constant(false);
	}
}
bool NewGameSceneComponent::goGlitter(int i)
{
	this->setOneLight(i, true);
	return false;
}
void NewGameSceneComponent::glitter(int i)
{
	if(_timer)
	{
		_timer->stop();
		_timer.reset();
	}

	std::cout<<"ps_"+_Colour[_lights[(CNewGameSceneInterface::LIGHT_COLOR)i]]+"a"<<std::endl;
	sm->getEntity("light"+Ogre::StringConverter::toString(i+1))->
		setMaterialName("ps_"+_Colour[_lights[(CNewGameSceneInterface::LIGHT_COLOR)i]]+"a");

	_timer = ITimerManager::getSingleton().createTimer(boost::bind<bool>(&NewGameSceneComponent::goGlitter, this, i));
	_timer->start(10.f,1, 0.6f);
}
bool Orz::NewGameSceneComponent::updateStorm(TimeType updatetime)
{
	StormTime += updatetime;
	if (StormTime>2)
	{
		_interface->update=  boost::bind(&NewGameSceneComponent::update,this,_1);
		bbset->setVisible(false);
		StormTime=0;
		return true;
	}
	return false;
}
bool Orz::NewGameSceneComponent::updateGoldWin(TimeType updatetime)
{

	return false;
}
//OpenMouthTime+=updatetime;
//if (OpenMouthTime>5)
//{
//	ParticleUniverse::ParticleSystemManager * particleSystemManager = 
//		ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
//	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();
//	_psGold = particleSystemManager->createParticleSystem("Gold", "newgame_gold", sm); 
//	_nodeGold->attachObject(_psGold);
//	_psGold->start();
//	_interface->update=  boost::bind(&NewGameSceneComponent::update,this,_1);
//	//return true;
//}
//_teethAnimation[0]->addTime(updatetime/4);
//_teethAnimation[1]->addTime(updatetime/4);

//void Orz::NewGameSceneComponent::enableSpitGold(bool enable)
//{
//	ParticleUniverse::ParticleSystemManager * particleSystemManager = 
//		ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
//	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();
//	//不论开始或停止都要销毁
//	if (_psGold!=NULL)
//	{
//		particleSystemManager->destroyParticleSystem(_psGold,sm);
//		_psGold = NULL;
//	}
//
//	if (enable == true)
//	{
//		Ogre::Entity* ent = sm->getEntity("yachi_s");
//		_teethAnimation[0] = ent->getAnimationState("open");
//		_teethAnimation[0]->setLoop(false);
//		_teethAnimation[0]->setEnabled(true);
//		ent = sm->getEntity("yachi_x");
//		_teethAnimation[1]=ent->getAnimationState("open");
//		_teethAnimation[1]->setLoop(false);
//		_teethAnimation[1]->setEnabled(true);
//		OpenMouthTime = 0;
//		_interface->update=  boost::bind(&NewGameSceneComponent::updateGoldWin,this,_1);
//	}
//	else
//	{
//		_teethAnimation[0]->setEnabled(false);
//		_teethAnimation[1]->setEnabled(false);
//	}
//}
void Orz::NewGameSceneComponent::enableGoldWineffect(bool enable,int Number)
{
	if(enable)
	{
		_coinLoop->play(-1);
		_coinLoop->setVolume(0.7f);
	}
	else
	{
		_coinLoop->stop();
	}
	ParticleUniverse::ParticleSystemManager * particleSystemManager = 
		ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
	Ogre::SceneManager* sm=Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	//不论开始或停止都要销毁
	if (_psGold!=NULL)
	{
		particleSystemManager->destroyParticleSystem(_psGold,sm);
		_psGold = NULL;

	}

	if (enable == true)
	{
		_psGold = particleSystemManager->createParticleSystem("Gold", "newgame_gold1", sm); 
		_nodeGold->attachObject(_psGold);
		_psGold->start();
		_nodeFeiting->setVisible(true);
		_nodeFeiting->setPosition(Ogre::Vector3(726,750,-1540));
		_isUpdateFeiting = true;
		//std::string strNum = (boost::lexical_cast<std::string>(Number));
		int n = Number;

		std::string pic("five0");
		for(int i =1 ; i<= 5 ; i++)
			//while(n!=0)
		{ 
			int m = (n%10);

			pic[4] = '0'+m;
			//以下是根据模型内部的顺序来，本来一句话可以解决问题的
			if(i<5)
			sm->getEntity("feitingNum")->getSubEntity(i)->setMaterialName(pic);
			else
			sm->getEntity("feitingNum")->getSubEntity(0)->setMaterialName(pic);
			n /= 10;
		}
		/*
		for (int i=5;i>0;i--)
		{
		if (5-i<strNum.size())
		{
		sm->getEntity("feiting")->getSubEntity(i)->getMaterial()->getTechnique(0)
		->getPass(0)->getTextureUnitState(0)->setTextureName(strNum.substr(5-i,1)+".tga");
		}
		else
		sm->getEntity("feiting")->getSubEntity(i)->getMaterial()->getTechnique(0)
		->getPass(0)->getTextureUnitState(0)->setTextureName("0.tga");


		}*/
		//_interface->update = boost::bind(&NewGameSceneComponent::updateGoldWin,this,_1);
	}
	else
	{
		_isUpdateFeiting = false;
		_nodeFeiting->setVisible(false);
	}
}
void Orz::NewGameSceneComponent::setAmbientLight(float r,float g,float b)
{
	sm->setAmbientLight(Ogre::ColourValue(r,g,b));
}
