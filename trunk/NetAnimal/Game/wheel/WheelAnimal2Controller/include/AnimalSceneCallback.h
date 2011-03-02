#ifndef __Orz_AnimalSceneCallback__
#define __Orz_AnimalSceneCallback__	
 
#include "WheelAnimalControllerConfig.h"
#include <Ogre/Ogre.h>
#include <Ogre/OgreSharedPtr.h>
#include <TinyXML/tinyxml.h>
#include "BaseSceneImpl.h"

#include "ThirdParty/Ofusion/IOSMSceneCallbacks.h"
using namespace Orz;

namespace Orz
{

	class AnimalSceneCallback: public BaseSceneImpl , public OSMSceneCallbacks// , public Ogre::SceneNode::Listener
	{

	public:
		AnimalSceneCallback(void);
		virtual ~AnimalSceneCallback(void);
		
		bool check(bool fill);
	private:
		///得到动画类型
		virtual WheelEnum::AnimalType getAnimalType(int n);
		/// 但创建摄像机的时候，关联到相应枚举
		virtual void OnCameraCreate(Ogre::Camera* pCamera, TiXmlElement* pCameraDesc);
		///当创建实体的时候，关联到相应枚举
		virtual void OnEntityCreate(Ogre::Entity *pEntity, TiXmlElement* pEntityDesc);   
		///当创建虚拟体的时候，关联到相应枚举
		virtual void OnHelperCreated(Ogre::SceneNode* pHelper, TiXmlElement* pHelperDesc);
	    ///得到动画对应的名称
		virtual std::string getSceneAnimationName(SceneItemMark mark);
		
		virtual bool hasSceneAnimationName(SceneItemMark mark);
		
		
		//显示光环
		virtual void showBaseLight(int n, WheelEnum::LIGHT_COLOR id, bool show = true);
	private:
		boost::array<WheelEnum::AnimalType, 24> _types;

	};

}


#endif