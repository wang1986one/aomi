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
		///�õ���������
		virtual WheelEnum::AnimalType getAnimalType(int n);
		/// �������������ʱ�򣬹�������Ӧö��
		virtual void OnCameraCreate(Ogre::Camera* pCamera, TiXmlElement* pCameraDesc);
		///������ʵ���ʱ�򣬹�������Ӧö��
		virtual void OnEntityCreate(Ogre::Entity *pEntity, TiXmlElement* pEntityDesc);   
		///�������������ʱ�򣬹�������Ӧö��
		virtual void OnHelperCreated(Ogre::SceneNode* pHelper, TiXmlElement* pHelperDesc);
	    ///�õ�������Ӧ������
		virtual std::string getSceneAnimationName(SceneItemMark mark);
		
		virtual bool hasSceneAnimationName(SceneItemMark mark);
		
		
		//��ʾ�⻷
		virtual void showBaseLight(int n, WheelEnum::LIGHT_COLOR id, bool show = true);
	private:
		boost::array<WheelEnum::AnimalType, 24> _types;

	};

}


#endif