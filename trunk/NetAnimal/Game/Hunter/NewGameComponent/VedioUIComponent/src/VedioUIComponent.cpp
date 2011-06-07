#include "VedioUIComponentStableHeaders.h"
#include "VedioUIComponent.h"

#include "VedioUIInterface.h"


using namespace Orz;

VedioUIComponent::VedioUIComponent(void):_vedioInterface(new VedioUIInterface)
{

	using namespace CEGUI;
	WindowManager& winMgr = WindowManager::getSingleton();
	_window= winMgr.createWindow("TaharezLook/StaticImage", "vedio");

	_window->setPosition(UVector2(cegui_reldim(0), cegui_reldim( -0.001f)));

	_window->setSize(UVector2(cegui_reldim(1), cegui_reldim(0.5)));	
	_vedioInterface->load = boost::bind(&VedioUIComponent::load, this, _1);
	_vedioInterface->play = boost::bind(&VedioUIComponent::play, this);
	_vedioInterface->getWindow = boost::bind(&VedioUIComponent::getWindow, this);
	_vedioInterface->isEnd = boost::bind(&VedioUIComponent::isEnd, this);
	_vedioInterface->reset = boost::bind(&VedioUIComponent::reset, this);


}


VedioUIComponent::~VedioUIComponent(void)
{
	//using namespace Ogre;
	//OgreVideoManager* mgr=(OgreVideoManager*) OgreVideoManager::getSingletonPtr();
	//mgr->destroyAdvancedTexture("video_material");
	//Ogre::TextureManager::getSingleton().getByName("startmovie.ogg");
}

CEGUI::Window * VedioUIComponent::getWindow(void)
{
	return _window;
}


void VedioUIComponent::createTexture(const std::string & filename)
{
	using namespace  Ogre;
	OgreVideoManager* mgr=(OgreVideoManager*) OgreVideoManager::getSingletonPtr();

	//createQuad("video_quad","video_material",-0.5,1,1,-0.94);
	mgr->setInputName(filename);
	mgr->createDefinedTexture("video_material");

	TheoraVideoClip* clip = mgr->getVideoClipByName(filename);

	clip->pause();
}
bool VedioUIComponent::load(const std::string & filename)
{

	_filename = filename;

	using namespace Ogre;
	using namespace CEGUI;

	createTexture(filename);
	//ImagesetManager::getSingleton().createFromImageFile("abc","10points.png");


	//Ogre::TextureManager::getSingleton().load("10points.png",ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(filename);//createManual("RttTex:"+nam
	//std::cout<<tex->getName()<<std::endl;
	CEGUI::OgreTexture& ceguiTex = static_cast<CEGUI::OgreTexture&>(CEGUI::System::getSingleton().getRenderer()->createTexture());
	ceguiTex.setOgreTexture(tex);
	Imageset & iset = ImagesetManager::getSingleton().create("vedio", ceguiTex);
	iset.defineImage( 
		"vedio", 
		CEGUI::Point( 0.0f, 0.0f ),
		CEGUI::Size( 640, 480 ),
		CEGUI::Point( 0.0f, 0.0f ) );
	_window->setPosition(UVector2(cegui_reldim(0), cegui_reldim( -0.001f)));
	_window->setSize(UVector2(cegui_reldim(1), cegui_reldim(1)));	

	// disable frame and standard background
	_window->setProperty("FrameEnabled", "false");
	_window->setProperty("BackgroundEnabled", "false");
	_window->setProperty("Image", "set:vedio image:vedio");
	//setProperty("Image", "set:vedio_ "+filename+" image:image");
	return true;
}
bool VedioUIComponent::play(void)
{
	using namespace Ogre;
	OgreVideoManager* mgr=(OgreVideoManager*) OgreVideoManager::getSingletonPtr();



	TheoraVideoClip* clip = mgr->getVideoClipByName(_filename);
	clip->restart();
	clip->play();
	
	return true;	
}

ComponentInterface * VedioUIComponent::_queryInterface(const TypeInfo & info) const
{


	if(info == TypeInfo(typeid(VedioUIInterface)))
		return _vedioInterface.get();
	return NULL;

}



bool VedioUIComponent::isEnd(void)
{

	using namespace Ogre;
	OgreVideoManager* mgr=(OgreVideoManager*) OgreVideoManager::getSingletonPtr();
	TheoraVideoClip* clip = mgr->getVideoClipByName(_filename);
	if(!clip)
		return false;
	return clip->isDone();

}



void VedioUIComponent::reset(void)
{

	using namespace Ogre;
	OgreVideoManager* mgr=(OgreVideoManager*) OgreVideoManager::getSingletonPtr();
	TheoraVideoClip* clip = mgr->getVideoClipByName(_filename);
	//clip->stop();

}
