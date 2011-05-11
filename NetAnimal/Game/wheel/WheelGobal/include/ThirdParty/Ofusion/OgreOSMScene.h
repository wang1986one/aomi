/**********************************************************************
 *<
	oFusion Scene Loader Pro (see License.txt)

	FILE: OgreOSMScene.h

	DESCRIPTION: OE_XMLScene reader (oe_scene) include header	

	IMPLEMENTED BY: Andres Carrera

	HISTORY: 

		Original implementation by Lasse Tassing (Channex)
		2005 ITE ApS, Lasse Tassing

 *>	Copyright (c) 2007, All Rights Reserved.
 **********************************************************************/


#ifndef _OGREOSMSCENE_H_
#define _OGREOSMSCENE_H_

#include <boost/property_tree/detail/rapidxml.hpp>
#include "WheelGobalConfig.h"
#include <Ogre/Ogre.h>

#include "IOSMSceneCallbacks.h"
#include "OSMAnimSerializer.h"

#define OSM_RENDERTEXTURE_GROUP "OSM_RENDERTEXTURE_GROUP_"

//class boost::shared_ptr<rapidxml::xml_document<> > : public Ogre::SharedPtr<rapidxml::xml_document<>> {
//public:
//	boost::shared_ptr<rapidxml::xml_document<> >() : Ogre::SharedPtr<rapidxml::xml_document<>>() {}	
//	explicit boost::shared_ptr<rapidxml::xml_document<> >(rapidxml::xml_document<>* rep) : Ogre::SharedPtr<rapidxml::xml_document<>>(rep) {}
//	
//};


inline const char * GetAttrString(rapidxml::xml_attribute<> * attr)
{
	if(attr)
		return attr->value();
	return NULL;
}

typedef struct TAG_SCENE_HEADER_PROPS {
	TAG_SCENE_HEADER_PROPS() : version(0), unitsPerMasterRef(1) {}

	float version;

	float unitsPerMasterRef;

	Ogre::String	masterScaleRef;
	Ogre::String	unitType;

} OSceneHeader;

class _OrzWheelGobalExport OSMScene
{
public:

	typedef std::vector<Ogre::Camera*>	CameraList;
	typedef std::vector<Ogre::Light*>	LightList;
	typedef std::vector<Ogre::Entity*>	EntityList;

	OSMScene(Ogre::SceneManager* pSceneMgr = 0, Ogre::RenderWindow* win = 0);
	~OSMScene(void);

	// Initialise
	bool	initialise(const char* pszFilename, OSMSceneCallbacks* pCallbacks = NULL);

	// Declare all resources used in the scene
	void	declareResources(void);

	// Create scene, optionally attaching it to a parent node
	bool	createScene(Ogre::SceneNode* pParent = NULL);

	// Get list of cameras in this scene
	CameraList&	getCameraList(void);

	// Get list of lights in this scene
	LightList&	getLightList(void);

	// Get list of lights in this scene
	EntityList&	getEntityList(void);

	// Get created scene manager
	Ogre::SceneManager* getSceneManager(void) { return mSceneMgr; }

	const OSceneHeader& getSceneHeader(void) { return mSceneHeader; }

protected:
	// Create node from information
	Ogre::SceneNode* createNode(rapidxml::xml_node<> * pElem, Ogre::SceneNode* pSceneRoot);

	// Create SceneManager
	Ogre::SceneNode* initSceneManager(rapidxml::xml_node<> * sceneProp, bool& bHandled);
	//Ogre::SceneNode* createSceneManager(rapidxml::xml_node<> * sceneProp, bool& bHandled);

	// Set scene properties
	void setSceneProperties(rapidxml::xml_node<> * sceneProp);

	// Creation helpers		
	void	createEntities(rapidxml::xml_node<> * pEntityNode, Ogre::SceneNode* pSceneRoot);
	void	createLights(rapidxml::xml_node<> * pLightNode, Ogre::SceneNode* pSceneRoot);
	void	createCameras(rapidxml::xml_node<> * pCameraNode, Ogre::SceneNode* pSceneRoot);
	void	createStaticGeometry(rapidxml::xml_node<> * pStaticGeom);
	void	createHelpers(rapidxml::xml_node<> * pLightNode, Ogre::SceneNode* pSceneRoot);
	void	createShapes(rapidxml::xml_node<> * pHelperNode);
	void	createRenderTexture(rapidxml::xml_node<> * pRenderTexNode);
	
	typedef std::set<unsigned int> SkeletonHandles;
	void	loadAnimations(rapidxml::xml_node<> * animationsNode, SkeletonHandles& handles);

	void	loadMaterialAnimations(rapidxml::xml_node<> * animationsNode);

	void	setRenderTextureNodes(Ogre::RenderTexture* rTex, const EntityList* showNodes, const EntityList* hideNodes);

	// Created objects
	CameraList	mCameras;
	LightList	mLights;
	EntityList	mEntities;

	Ogre::SceneNode*	mSceneRoot;
	Ogre::String		mSceneName, mFileExtension;

	// Callback interface
	OSMSceneCallbacks* mCallbacks;

	// Scene manager
	Ogre::SceneManager* mSceneMgr;
	Ogre::RenderWindow* mWindow;

	// Current Scene header properties
	OSceneHeader mSceneHeader;

	// Incremented count for next node name extension
	static unsigned long mNextGeneratedNameExt;

	// Scene XML document
	boost::shared_ptr<rapidxml::xml_document<> > mXMLDoc;
	std::string _data;
};

#endif // _OGREOSMSCENE_H_