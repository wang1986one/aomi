/**********************************************************************
 *<
	oFusion Scene Loader Pro (see License.txt)

	FILE: OgreOSMScene.cpp

	DESCRIPTION: Contains the OE_XMLScene reader (oe_scene)	

	IMPLEMENTED BY: Andres Carrera

	HISTORY: 

		Original implementation by Lasse Tassing (Channex)
		2005 ITE ApS, Lasse Tassing

 *>	Copyright (c) 2006, All Rights Reserved.
 **********************************************************************/

#include "WheelGobalStableHeaders.h"
#include "OgreOSMScene.h"
#include <Ogre/OgreTagPoint.h>
#include "OSMRenderTexListener.h"

using namespace Ogre;

enum {
	SCENE_SKYPLANE = 1,
	SCENE_SKYBOX,
	SCENE_SKYDOME,
};

#define ENABLE_LOGMANAGER LogManager::getSingleton().setLogDetail(LL_NORMAL);
#define DISABLE_LOGMANAGER LogManager::getSingleton().setLogDetail(static_cast<LoggingLevel>(0));

unsigned long OSMScene::mNextGeneratedNameExt = 1;


OSMScene::OSMScene(SceneManager* pSceneMgr, RenderWindow* win)
{
	mSceneMgr = pSceneMgr;

	if(win)	
		mWindow = win;		
	else
		mWindow = Ogre::Root::getSingleton().getAutoCreatedWindow();
	
	mCallbacks = 0;
}

OSMScene::~OSMScene(void)
{	
	
}

// Init overloads - use either of them
bool OSMScene::initialise(const char* pszFilename, OSMSceneCallbacks* pCallbacks)
{
	// Hook up callback interface
	mCallbacks = pCallbacks;

	LogManager::getSingleton().logMessage("********************************");	
	LogManager::getSingleton().logMessage("**     oScene Loader Lib      **");
	LogManager::getSingleton().logMessage("********************************");
	
	String msg("oSceneLoader: Loading '");
	msg += pszFilename;
	msg += "' file";
	LogManager::getSingleton().logMessage(msg);

	String path;
	StringUtil::splitFullFilename(pszFilename, mSceneName, mFileExtension, path);
	//StringUtil::splitBaseFilename(pszFilename, mSceneName, mFileExtension);

	String resourceGroupName = pszFilename;

	String sceneFilename = pszFilename;
	
	DataStreamPtr pStream;

	if(mFileExtension == "zip") 
	{
		ResourceGroupManager::getSingleton().addResourceLocation(pszFilename, "Zip", resourceGroupName, true);

		sceneFilename = mSceneName + ".osm";

		pStream = ResourceGroupManager::getSingleton().openResource(sceneFilename, resourceGroupName);
	}
	else 
	{
		pStream = ResourceGroupManager::getSingleton().openResource(sceneFilename);
	}

	// Create new XML document
	mXMLDoc = boost::shared_ptr<rapidxml::xml_document<> >(new rapidxml::xml_document<>());
	
	//DataStreamPtr pStream = ResourceGroupManager::getSingleton().openResource(pszFilename);
	if(!pStream->size())
	{
		mXMLDoc.reset();

		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
					"oSceneLoader: Empty scene file", 
					"OSMScene::initialise");
		
	}			
				/*
	size_t iSize = pStream->size();
	char *pBuf = new char[iSize+1];*/
	//memset(pBuf, 0, iSize+1);
	//pStream->read(pBuf, iSize);

	_data = pStream->getAsString();
	mXMLDoc->parse<0>(&_data[0]);
	pStream.setNull();

	//mXMLDoc->Parse(pBuf);
	//delete[] pBuf;
	//
	//// check for errors
	//if(mXMLDoc->Error())
	//{
	//	mXMLDoc.setNull();

	//	String errDesc = "oSceneLoader: Failed to load scene file, ";
	//	msg += mXMLDoc->ErrorDesc();

	//	OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
	//				errDesc.c_str(), 
	//				"OSMScene::initialise");		
	//}

	rapidxml::xml_node<> * rootElem = mXMLDoc->first_node();;

	const char* pszType = GetAttrString(rootElem->first_attribute("type"));
	
	rapidxml::xml_node<> * locations = rootElem->first_node("locations");

	if(locations || pszType)
	{
		String sceneType;

		if(pszType)
			sceneType = pszType;

		if(sceneType != "zip") {
			const String& grpName = ResourceGroupManager::getSingleton().findGroupContainingResource(sceneFilename);
			//const String& grpName = ResourceGroupManager::getSingleton().findGroupContainingResource(pszFilename);

			if(!grpName.empty()) {
				FileInfoListPtr fileInfo = ResourceGroupManager::getSingleton().findResourceFileInfo(grpName, sceneFilename);
				//FileInfoListPtr fileInfo = ResourceGroupManager::getSingleton().findResourceFileInfo(grpName, pszFilename);

				String strPath = (*fileInfo)[0].archive->getName();

				strPath = StringUtil::standardisePath(strPath);		

				for (rapidxml::xml_node<> * pLocationElem = locations->first_node();
					pLocationElem != 0; pLocationElem = pLocationElem->next_sibling())
				{
					// Ogre could cast an exception, in which case we just try to 
					// continue reading the other location paths
					try 
					{	
						const char *pszName = GetAttrString(pLocationElem->first_attribute("path"));

						if(String(pszName) == "/")
							continue;

						String strDir = strPath + pszName;

						ResourceGroupManager::getSingleton().addResourceLocation(strDir, "FileSystem", resourceGroupName);


					}
					catch(...) {

					}
				}
			}
		}

		try {
			ResourceGroupManager::getSingleton().initialiseResourceGroup(resourceGroupName);
		}
		catch(...) {

		}
	}

	const char* pszVersion = GetAttrString(rootElem->first_attribute("version"));

	if(pszVersion)
		mSceneHeader.version = Ogre::StringConverter::parseReal(pszVersion);
	
	const char* pszScaleRef = GetAttrString(rootElem->first_attribute("unitsPerMasterScale"));

	if(pszScaleRef)
		mSceneHeader.unitsPerMasterRef = Ogre::StringConverter::parseReal(pszScaleRef);

	const char* pszMasterScaleType = GetAttrString(rootElem->first_attribute("masterScaleRef"));

	if(pszMasterScaleType)
		mSceneHeader.masterScaleRef = pszMasterScaleType;

	const char* pszUnitType = GetAttrString(rootElem->first_attribute("unitType"));
	
	if(pszUnitType)
		mSceneHeader.unitType = pszUnitType;

	return true;
}

// Declare all resources used in the scene
void OSMScene::declareResources(void)
{
	if(mXMLDoc)
	{

		rapidxml::xml_node<> * rootElem = mXMLDoc->first_node();;

		// Get mesh filename from entities
		rapidxml::xml_node<> *pMeshNode = rootElem->first_node("entities");
		if(pMeshNode)
		{
			// Iterate all meshes, creating them. 
			for (rapidxml::xml_node<> * pMeshElem = pMeshNode->first_node();
				pMeshElem != 0; pMeshElem = pMeshElem->next_sibling())
			{	
				// Declare mesh resource
				const char *pszFileName = GetAttrString(pMeshElem->first_attribute("filename"));	
				ResourceGroupManager::getSingleton().declareResource(pszFileName, "Mesh");
			}
		}
	}
}

// Create scene, optionally attaching it to a parent node
bool OSMScene::createScene(Ogre::SceneNode* pParent)
{
	if(mXMLDoc)
	{
		String msg("oSceneLoader: Creating scene on '");
		msg += pParent ? pParent->getName() : "Root";
		msg += "' node";
		LogManager::getSingleton().logMessage(msg);

		mSceneRoot = pParent;

		bool bHandled = false;

		rapidxml::xml_node<> * rootElem = mXMLDoc->first_node();

		pParent = initSceneManager(rootElem, bHandled);
		
		if(pParent==NULL)
			pParent=mSceneMgr->getRootSceneNode()->createChildSceneNode();

		assert(pParent);

		rapidxml::xml_node<> * list;

		// Entities
		list = rootElem->first_node("entities");
		if(list)
			createEntities(list, pParent);

		// lights
		list = rootElem->first_node("lights");
		if(list)
			createLights(list, pParent);

		if(!bHandled) {
			// cameras
			list = rootElem->first_node("cameras");
			if(list)
				createCameras(list, pParent);
		}

		// helpers
		list = rootElem->first_node("helpers");
		if(list)
			createHelpers(list, pParent);

		// shapes
		list = rootElem->first_node("shapes");
		if(list)
			createShapes(list);

		// material animations
		list = rootElem->first_node("materialAnimations");
		if(list)
			loadMaterialAnimations(list);

		// External skeletal animation files
		list = rootElem->first_node("skeletal_animations");
		if(list)
		{
			SkeletonHandles skelHandles;
			loadAnimations(list, skelHandles);

			if(!skelHandles.empty())
			{

				SceneManager::MovableObjectIterator it = mSceneMgr->getMovableObjectIterator("Entity");

				while(it.hasMoreElements()) {
					Entity* entity = (Entity*)it.getNext();

					if( entity->hasSkeleton() && (skelHandles.find(entity->getMesh()->getSkeleton()->getHandle()) != skelHandles.end()) )
						entity->refreshAvailableAnimationState();
				}
			}
		}

		/*
		try {
			// Entities
			list = rootElem->first_node("entities");
			if(list)
				createEntities(list, pParent);
		} catch(...)
		{
			LogManager::getSingleton().logMessage("Error while loading entities");
			
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: Error while loading entities",
				"OSMScene::createScene");
		}
		
		try {
			// lights
			list = rootElem->first_node("lights");
			if(list)
				createLights(list, pParent);
		} catch(...)
		{
			LogManager::getSingleton().logMessage("Error while loading lights");

			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: Error while loading lights",
				"OSMScene::createScene");
		}
		
		if(!bHandled) {
			try {
				// cameras
				list = rootElem->first_node("cameras");
				if(list)
					createCameras(list, pParent);
			} catch(...)
			{
				LogManager::getSingleton().logMessage("Error while loading cameras");

				OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: Error while loading cameras",
				"OSMScene::createScene");
			}
		}
		
		try {
			// helpers
			list = rootElem->first_node("helpers");
			if(list)
				createHelpers(list, pParent);
		} catch(...)
		{
			LogManager::getSingleton().logMessage("Error while loading helpers");

			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: Error while loading helpers",
				"OSMScene::createScene");
		}
		
		try {
			// shapes
			list = rootElem->first_node("shapes");
			if(list)
				createShapes(list);
		} catch(...)
		{
			LogManager::getSingleton().logMessage("Error while loading shapes");

			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: Error while loading shapes",
				"OSMScene::createScene");
		}
		
		try 
		{
			// material animations
			list = rootElem->first_node("materialAnimations");
			if(list)
				loadMaterialAnimations(list);
		}catch(...)
		{
			LogManager::getSingleton().logMessage("Error while loading material animations");

			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: Error while loading material animations",
				"OSMScene::createScene");
		}
		
		try {
			// External skeletal animation files
			list = rootElem->first_node("skeletal_animations");
			if(list)
			{
				SkeletonHandles skelHandles;
				loadAnimations(list, skelHandles);

				if(!skelHandles.empty())
				{

					SceneManager::MovableObjectIterator it = mSceneMgr->getMovableObjectIterator("Entity");

					while(it.hasMoreElements()) {
						Entity* entity = (Entity*)it.getNext();

						if( entity->hasSkeleton() && (skelHandles.find(entity->getMesh()->getSkeleton()->getHandle()) != skelHandles.end()) )
							entity->refreshAvailableAnimationState();
					}
				}
			}
		}catch(...)
		{
			LogManager::getSingleton().logMessage("Error while loading external animations");

			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: Error while loading external animations",
				"OSMScene::createScene");
		}
		*/

		// Set scene properties
		setSceneProperties(rootElem);

		// Static Geometry
		list = rootElem->first_node("staticGeometry");
		if(list)
			createStaticGeometry(list);

		LogManager::getSingleton().logMessage("********************************");
		LogManager::getSingleton().logMessage("** oSceneLoader: Scene loaded **");
		LogManager::getSingleton().logMessage("********************************");

		return true;
	}

	return false;

	
}

// Get list of cameras in this scene
OSMScene::CameraList& OSMScene::getCameraList(void)
{
	return mCameras;
}

// Get list of lights in this scene
OSMScene::LightList& OSMScene::getLightList(void)
{
	return mLights;
}

// Get list of lights in this scene
OSMScene::EntityList& OSMScene::getEntityList(void)
{
	return mEntities;
}

Ogre::SceneNode* OSMScene::createNode(rapidxml::xml_node<> * pElem, Ogre::SceneNode* pSceneRoot)
{
	SceneNode *pNode=0;

	// Try to find the parent node
	const char *pszName	= GetAttrString(pElem->first_attribute("name"));
	if(pszName == NULL) return NULL;

	// Check if this node has a parent
	const char *pszParent = GetAttrString(pElem->first_attribute("parent"));						
	if(pszParent == NULL)
	{
		// Check if the scene node has already been created by a child
		if(mSceneMgr->hasSceneNode(pszName))
		{
			pNode = mSceneMgr->getSceneNode(pszName);
		} else
		{
			pNode = pSceneRoot->createChildSceneNode(pszName);
		}

	} else
	{
		SceneNode *pParent=0;

		if(mSceneMgr->hasSceneNode(pszParent))
		{
			pParent = mSceneMgr->getSceneNode(pszParent);

		}else 
		{
			// We try to create the parent node as child of root node.
			// Later when the parent (hopefully) is created, we can adjust it,
			// if it is child of another node.
			pParent = pSceneRoot->createChildSceneNode(pszParent);
		}

		if(mSceneMgr->hasSceneNode(pszName))
		{
			// Check if the scene node has already been created by a child
			// In this case we would have to change the parent.
			pNode = mSceneMgr->getSceneNode(pszName);

			// Get old parent (probably scene root)
			SceneNode* pOldParent = pNode->getParentSceneNode();

			// Remove this node
			pOldParent->removeChild(pNode);

			// Insert us as child on the "real" parent
			pParent->addChild(pNode);

		} else
		{
			pNode = pParent->createChildSceneNode(pszName);
		}
	}

	// Position
	rapidxml::xml_node<> * posElem = pElem->first_node("position");
    if(posElem)
    {
		Vector3 pos;			
		pos.x = StringConverter::parseReal(GetAttrString(posElem->first_attribute("x")));
		pos.y = StringConverter::parseReal(GetAttrString(posElem->first_attribute("y")));
		pos.z = StringConverter::parseReal(GetAttrString(posElem->first_attribute("z")));
		pNode->setPosition(pos);		
    }

	// Rotation
	rapidxml::xml_node<> * rotElem = pElem->first_node("rotation");
    if(rotElem)
    {				
		pNode->setOrientation(
			StringConverter::parseReal(GetAttrString(rotElem->first_attribute("w"))),
			StringConverter::parseReal(GetAttrString(rotElem->first_attribute("x"))),
			StringConverter::parseReal(GetAttrString(rotElem->first_attribute("y"))),
			StringConverter::parseReal(GetAttrString(rotElem->first_attribute("z"))));

    }
	
	// Scale
	rapidxml::xml_node<> * scaleElem = pElem->first_node("scale");
    if(scaleElem)
    {
		Vector3 scale;
		scale.x = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("x")));
		scale.y = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("y")));
		scale.z = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("z")));
		pNode->setScale(scale);
    }

	// Notify
	if(mCallbacks)
		mCallbacks->OnNodeCreate(pNode, pElem);

	// Animation
	rapidxml::xml_node<> * animList = pElem->first_node("animations");
    if(animList)
	{
		// 
		for (rapidxml::xml_node<> * animElem = animList->first_node();
            animElem != 0; animElem = animElem->next_sibling())
		{		
			// Get name of animation
			const char *pszName = GetAttrString(animElem->first_attribute("name"));

			Animation *pAnim = 0;

			if(mSceneMgr->hasAnimation(pszName))
			{
				pAnim = mSceneMgr->getAnimation(pszName);
			}

			// If this animation has not been created yet, we create it
			if(pAnim == 0)
			{			
				float fLength = StringConverter::parseReal(GetAttrString(animElem->first_attribute("length")));
				pAnim = mSceneMgr->createAnimation(pszName, fLength);
				pAnim->setInterpolationMode(Animation::IM_LINEAR);				
			}		

			// Create animation track for this node
			NodeAnimationTrack *pTrack = pAnim->createNodeTrack(pAnim->getNumNodeTracks()+1, pNode);

			// Iterate all keyframes for this node
			for (rapidxml::xml_node<> * pKeyframeElem = animElem->first_node();
					pKeyframeElem != 0; pKeyframeElem = pKeyframeElem->next_sibling())
			{
				float fTime=StringConverter::parseReal(GetAttrString(pKeyframeElem->first_attribute("time")));
				TransformKeyFrame *pKeyFrame = pTrack->createNodeKeyFrame(fTime);

				// Position
				rapidxml::xml_node<> * posElem = pKeyframeElem->first_node("position");
				if(posElem)
				{
					Vector3 trans;			
					trans.x = StringConverter::parseReal(GetAttrString(posElem->first_attribute("x")));
					trans.y = StringConverter::parseReal(GetAttrString(posElem->first_attribute("y")));
					trans.z = StringConverter::parseReal(GetAttrString(posElem->first_attribute("z")));				
					pKeyFrame->setTranslate(trans);
				}

				// Rotation
				rapidxml::xml_node<> * rotElem = pKeyframeElem->first_node("rotation");
				if(rotElem)
				{		
					Quaternion qRot;
					qRot.x = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("x")));
					qRot.y = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("y")));
					qRot.z = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("z")));		
					qRot.w = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("w")));		
					pKeyFrame->setRotation(qRot);
				}
				
				// Scale
				rapidxml::xml_node<> * scaleElem = pKeyframeElem->first_node("scale");
				if(scaleElem)
				{
					Vector3 scale;
					scale.x = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("x")));
					scale.y = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("y")));
					scale.z = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("z")));				
					pKeyFrame->setScale(scale);
				}
			}		
		}
	}

	return pNode;
}

// Create SceneManager
Ogre::SceneNode* OSMScene::initSceneManager(rapidxml::xml_node<> * sceneProp, bool& bHandled)
{
	assert(sceneProp);

	SceneType sceneType = ST_GENERIC;

	rapidxml::xml_node<> * sceneMgrElem = sceneProp->first_node("sceneManager");

	if(mSceneMgr == NULL)
	{
		if(sceneMgrElem)
		{
			// Scene manager
			int type = Ogre::StringConverter::parseInt(GetAttrString(sceneMgrElem->first_attribute("type")));
			sceneType = static_cast<Ogre::SceneType>(1 << (type));
			mSceneMgr = Ogre::Root::getSingleton().createSceneManager(sceneType);

		} else
		{
			mSceneMgr = Root::getSingleton().createSceneManager(sceneType);
		}
	}
	
	assert(mSceneMgr);

	if(mSceneRoot == NULL) {
		StringUtil::StrStreamType nodeName;
		nodeName << "OSM_" << mSceneName << "_" << mNextGeneratedNameExt++;

		mSceneRoot = mSceneMgr->getRootSceneNode()->createChildSceneNode(nodeName.str());
	}

	//SceneNode* pSceneRoot = mSceneMgr->getRootSceneNode()->createChildSceneNode();

	assert(mSceneRoot);	

	if(sceneMgrElem)
	{
		// Scene shadows
		rapidxml::xml_node<> * shadowsElem = sceneProp->first_node("shadowTechnique");
		if(shadowsElem)
		{
			int type = StringConverter::parseInt(GetAttrString(shadowsElem->first_attribute("type")));

			ShadowTechnique shadowType = Ogre::SHADOWTYPE_NONE;

			if(type > 0 && type < 10) {
				// Serializer version 2 (Eihort shadow type)
				switch(type)
				{
				case 1:
					shadowType = Ogre::SHADOWTYPE_STENCIL_MODULATIVE;
					break;

				case 2:
					shadowType = Ogre::SHADOWTYPE_STENCIL_ADDITIVE;
					break;

				case 3:
					shadowType = Ogre::SHADOWTYPE_TEXTURE_MODULATIVE;
					break;

				case 4:
					shadowType = Ogre::SHADOWTYPE_TEXTURE_ADDITIVE;
					break;
				}		

			}
			else {
				// Serializer version 1 (Dagon based shadow type)
				shadowType = static_cast<Ogre::ShadowTechnique>(type);
			}

			mSceneMgr->setShadowTechnique(shadowType);

			int tex_size = StringConverter::parseInt(GetAttrString(shadowsElem->first_attribute("tex_size")));
			int tex_count = StringConverter::parseInt(GetAttrString(shadowsElem->first_attribute("tex_count")));

			mSceneMgr->setShadowTextureSettings(tex_size, tex_count);

			// Shadow Color
			rapidxml::xml_node<> * colorElem = shadowsElem->first_node("color");
			if(colorElem)
			{	
				ColourValue color;
				color.r = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("r")));
				color.g = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("g")));
				color.b = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("b")));

				mSceneMgr->setShadowColour(color);
			

			}

			// Scene fog
			rapidxml::xml_node<> * fogElem = sceneProp->first_node("fogMode");
			if(fogElem)
			{
				int type = StringConverter::parseInt(GetAttrString(fogElem->first_attribute("type")));
				FogMode mode = static_cast<FogMode>(type);

				float density = StringConverter::parseReal(GetAttrString(fogElem->first_attribute("density")));
				float linearStart = StringConverter::parseReal(GetAttrString(fogElem->first_attribute("linearStart")));
				float linearEnd = StringConverter::parseReal(GetAttrString(fogElem->first_attribute("linearEnd")));

				ColourValue color;

				// Fog Color
				rapidxml::xml_node<> * colorElem = fogElem->first_node("color");
				if(colorElem)
				{
					color.r = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("r")));
					color.g = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("g")));
					color.b = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("b")));			
				}

				mSceneMgr->setFog(mode, color, density, linearStart, linearEnd);
			}

			// World Geometry
			const char* worldGeometry = GetAttrString(sceneMgrElem->first_attribute("worldGeometry"));
			if(worldGeometry != NULL)
			{
				// Some scene managers need cameras created before the world geometry
				rapidxml::xml_node<> * list = sceneProp->first_node("cameras");
				if(list)
					createCameras(list, mSceneRoot);

				if(sceneType == ST_EXTERIOR_CLOSE)
				{

					if(mCameras.empty()) 
					{

						OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
							"oSceneLoader: Scene dont contain cameras, \
							Terrain Scene Manager needs a camera to initialize",
							"OSMScene::createSceneManager");
					}

					Camera* primaryCamera = mCameras[0];

					mWindow->getViewport(0)->setCamera(primaryCamera);

					mSceneMgr->setOption("PrimaryCamera", primaryCamera);
				}

				// cameras created, the main scene loader method should not re-parse the list
				bHandled = true;

				mSceneMgr->setWorldGeometry(worldGeometry);
			}
		}
	}


	return mSceneRoot;
}

// Set Scene Properties
void OSMScene::setSceneProperties(rapidxml::xml_node<> * sceneProp)
{
	// Ambient light Color
	rapidxml::xml_node<> * colorElem = sceneProp->first_node("lightColor");
	if(colorElem)
	{	
		ColourValue color;
		color.r = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("r")));
		color.g = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("g")));
		color.b = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("b")));

		mSceneMgr->setAmbientLight(color);
	}

	// Background Color
	colorElem = sceneProp->first_node("bkgcolor");
	if(colorElem && mWindow)
	{	
		int numViewports = mWindow->getNumViewports();
		if(numViewports)
		{
			Ogre::ColourValue color;
			color.r = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("r")));
			color.g = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("g")));
			color.b = StringConverter::parseReal(GetAttrString(colorElem->first_attribute("b")));			
		
			for(int i=0; i<numViewports; ++i)
				mWindow->getViewport(i)->setBackgroundColour(color);
		}
	}

	// Scene sky
	rapidxml::xml_node<> * skyElem = sceneProp->first_node("skyTechnique");
	if(skyElem)
	{
		int type = StringConverter::parseInt(GetAttrString(skyElem->first_attribute("type")));
		String materialName = GetAttrString(skyElem->first_attribute("material"));
		
		if(!materialName.empty() && materialName != " ") {
			try {
				bool drawFirst = StringConverter::parseBool(GetAttrString(skyElem->first_attribute("drawFirst")));
				float tiling = StringConverter::parseReal(GetAttrString(skyElem->first_attribute("tiling")));
				float scale = StringConverter::parseReal(GetAttrString(skyElem->first_attribute("scale")));
				float dist = StringConverter::parseReal(GetAttrString(skyElem->first_attribute("dist")));
				float bow = StringConverter::parseReal(GetAttrString(skyElem->first_attribute("bow")));
				int xSegments = StringConverter::parseInt(GetAttrString(skyElem->first_attribute("xSegments")));
				int ySegments = StringConverter::parseInt(GetAttrString(skyElem->first_attribute("ySegments")));
				Ogre::Quaternion quat(Quaternion::IDENTITY);
				Ogre::Plane plane;
				plane.d = dist;
				plane.normal = -(Vector3::UNIT_Y);

				switch(type) {

				case SCENE_SKYPLANE:

					mSceneMgr->setSkyPlane(true, plane, materialName, scale, 
										   tiling, drawFirst, bow, xSegments, ySegments);

					mSceneMgr->setSkyBox(false, "");
					mSceneMgr->setSkyDome(false, "");

					break;

				case SCENE_SKYBOX:

					mSceneMgr->setSkyBox(true, materialName, dist, drawFirst, quat);
					mSceneMgr->setSkyPlane(false, plane, "");
					mSceneMgr->setSkyDome(false, "");

					break;

				case SCENE_SKYDOME:

					mSceneMgr->setSkyDome(true, materialName, bow, tiling, dist,
						drawFirst, quat, xSegments, ySegments);

					mSceneMgr->setSkyPlane(false, plane, "");
					mSceneMgr->setSkyBox(false, "");

					break;

				}
			}
			catch(Exception& /*e*/) {
				// Sky Material might not be in the resource list
				// More details were logged in the log file
			}
		}
	}
}

// Create all entities in scene
void OSMScene::createEntities(rapidxml::xml_node<> * pEntityNode, Ogre::SceneNode* pSceneRoot)
{
	// Iterate all meshes, creating them. 
	for (rapidxml::xml_node<> * pMeshElem = pEntityNode->first_node();
            pMeshElem != 0; pMeshElem = pMeshElem->next_sibling())
	{
		const char *pszName = GetAttrString(pMeshElem->first_attribute("name"));
		const char *pszFileName = GetAttrString(pMeshElem->first_attribute("filename"));

		// try to create the mesh
		Entity *pEntity = mSceneMgr->createEntity(pszName, pszFileName);			
		if(pEntity==0) continue;

		// Check if the object should cast shadows
		const char *pszCastShadows=GetAttrString(pMeshElem->first_attribute("CastShadows"));
		if(pszCastShadows && stricmp(pszCastShadows, "no")==0) {
			pEntity->setCastShadows(false);	
		}
		else {
			// Enable auto edge list generation if needed by the mesh
			pEntity->getMesh()->setAutoBuildEdgeLists(true);
			pEntity->setCastShadows(true);	
		}

		const char* pszTagPoint = GetAttrString(pMeshElem->first_attribute("tagPoint"));

		if(pszTagPoint)
		{
			const char* pszParentName = GetAttrString(pMeshElem->first_attribute("parent"));

			if(mSceneMgr->hasEntity(pszParentName))
			{
				Entity* entity = mSceneMgr->getEntity(pszParentName);

				Vector3 pos, scale;
				Quaternion rot;

				// Position
				rapidxml::xml_node<> * posElem = pMeshElem->first_node("position");
				if(posElem)
				{
					pos.x = StringConverter::parseReal(GetAttrString(posElem->first_attribute("x")));
					pos.y = StringConverter::parseReal(GetAttrString(posElem->first_attribute("y")));
					pos.z = StringConverter::parseReal(GetAttrString(posElem->first_attribute("z")));

				} else
				{
					pos = Vector3::ZERO;
				}

				// Rotation
				rapidxml::xml_node<> * rotElem = pMeshElem->first_node("rotation");
				if(rotElem)
				{
					rot.w = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("w")));
					rot.x = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("x")));
					rot.y = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("y")));
					rot.z = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("z")));

				} else 
				{
					rot = Quaternion::IDENTITY;
				}

				// Scale
				rapidxml::xml_node<> * scaleElem = pMeshElem->first_node("scale");
				if(scaleElem)
				{
					scale.x = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("x")));
					scale.y = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("y")));
					scale.z = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("z")));

				} else
				{
					scale = Vector3::UNIT_SCALE;
				}

				TagPoint* tp = entity->attachObjectToBone(pszTagPoint, pEntity, rot, pos);

				tp->setScale(scale);
				tp->setBindingPose();
			}

		} else 
		{
			// Create node with full information
			SceneNode *pObjNode = createNode(pMeshElem, pSceneRoot);

			// Attach the mesh entity to node
			pObjNode->attachObject(pEntity);
		}

		// Notify
		if(mCallbacks)
			mCallbacks->OnEntityCreate(pEntity, pMeshElem);

		// Add to entity list
		mEntities.push_back(pEntity);
	}
}

// Create all Lights in scene
void OSMScene::createLights(rapidxml::xml_node<> * pLightNode, Ogre::SceneNode* pSceneRoot)
{
	// Iterate all Lights, creating them. We do not attach them yet, since
	// we need to make sure all potential parent entities have been created.
	for (rapidxml::xml_node<> * pLightElem = pLightNode->first_node();
            pLightElem != 0; pLightElem = pLightElem->next_sibling())
	{
		const char *pszName = GetAttrString(pLightElem->first_attribute("name"));

		Light *pLight = mSceneMgr->createLight(pszName);
		if(pLight==0) continue;

		// Figure out which type of light we are using
		const char *pszType = GetAttrString(pLightElem->first_attribute("type"));
		if(stricmp(pszType, "omni")==0)
		{
			pLight->setType(Light::LT_POINT);
		} else if(stricmp(pszType, "spot")==0)
		{	
			pLight->setType(Light::LT_SPOTLIGHT);
			pLight->setSpotlightRange(
				Degree(StringConverter::parseReal(GetAttrString(pLightElem->first_attribute("hotspot")))),
				Degree(StringConverter::parseReal(GetAttrString(pLightElem->first_attribute("falloff")))));
			pLight->setDirection(0,0,-1);

		}  else if(stricmp(pszType, "directional")==0)
		{
			pLight->setType(Light::LT_DIRECTIONAL);
		}

		// Check if the light should be on
		const char *pszOn = GetAttrString(pLightElem->first_attribute("on"));
		if(pszOn!=0 && stricmp(pszOn, "true")==0)
			pLight->setVisible(true);
		else
			pLight->setVisible(false);

		// Check if the object should cast shadows
		const char *pszCastShadows = GetAttrString(pLightElem->first_attribute("CastShadows"));
		if(pszCastShadows && stricmp(pszCastShadows, "no")==0)
			pLight->setCastShadows(false);	
		else
			pLight->setCastShadows(true);	

		float lightIntens = 1.0f;

		const char* pszIntensity = GetAttrString(pLightElem->first_attribute("intensity"));

		if(pszIntensity) {
			lightIntens = StringConverter::parseReal(pszIntensity);

			if(lightIntens > 1.0f)
				lightIntens = 1.0f;

			if(lightIntens < 0.0f)
				lightIntens = 0.0f;
		}

		// Diffuse Color
		rapidxml::xml_node<> * colorElem = pLightElem->first_node("color");
		if(colorElem)
		{					
			pLight->setDiffuseColour(
				StringConverter::parseReal(GetAttrString(colorElem->first_attribute("r"))) * lightIntens,
				StringConverter::parseReal(GetAttrString(colorElem->first_attribute("g"))) * lightIntens,
				StringConverter::parseReal(GetAttrString(colorElem->first_attribute("b"))) * lightIntens);
		}

		// Specular Color
		rapidxml::xml_node<> * specularElem = pLightElem->first_node("specular");
		if(specularElem)
		{						
			pLight->setSpecularColour(
				StringConverter::parseReal(GetAttrString(specularElem->first_attribute("r"))) * lightIntens,
				StringConverter::parseReal(GetAttrString(specularElem->first_attribute("g"))) * lightIntens,
				StringConverter::parseReal(GetAttrString(specularElem->first_attribute("b"))) * lightIntens);
		}

		// Attenuation
		rapidxml::xml_node<> * attenElem = pLightElem->first_node("attenuation");
		if(attenElem) {
			pLight->setAttenuation(
				StringConverter::parseReal(GetAttrString(attenElem->first_attribute("range"))),
				StringConverter::parseReal(GetAttrString(attenElem->first_attribute("constant"))),
				StringConverter::parseReal(GetAttrString(attenElem->first_attribute("linear"))),
				StringConverter::parseReal(GetAttrString(attenElem->first_attribute("quadratic"))));
		}

		// Create node with full information
		SceneNode* pLightNode = createNode(pLightElem, pSceneRoot);

		// Attach the Light entity to node
		pLightNode->attachObject(pLight);

		// Target
		rapidxml::xml_node<> * targetElem = pLightElem->first_node("target");
		if(targetElem)
		{	
			// Create node with full information
			SceneNode* pTargetNode = createNode(targetElem, pSceneRoot);
			pLightNode->setAutoTracking(true, pTargetNode);
		}		

		// Notify
		if(mCallbacks)
			mCallbacks->OnLightCreate(pLight, pLightElem);

		// Add to light list
		mLights.push_back(pLight);
	}	
}

// Create all Cameras in scene
void OSMScene::createCameras(rapidxml::xml_node<> * pCameraNode, Ogre::SceneNode* pSceneRoot)
{
	// Iterate all Cameras, creating them. We do not attach them yet, since
	// we need to make sure all potential parent entities have been created.
	for (rapidxml::xml_node<> * pCameraElem = pCameraNode->first_node();
            pCameraElem != 0; pCameraElem = pCameraElem->next_sibling())
	{
		const char *pszName = GetAttrString(pCameraElem->first_attribute("name"));

		// Create camera
		Camera* pCamera = mSceneMgr->createCamera(pszName);
		
		if(pCamera == 0) 
			continue;

		//pCamera->setFOVy(Radian(StringConverter::parseReal(pCameraElem->first_attribute("FOV"))));

		rapidxml::xml_node<> * pClipElem = pCameraElem->first_node("clipPlane");

		if(pClipElem) {
			const char* pszNearClip = GetAttrString(pClipElem->first_attribute("NEAR"));

			if(pszNearClip)
				pCamera->setNearClipDistance(StringConverter::parseReal(pszNearClip));

			const char* pszFarClip = GetAttrString(pClipElem->first_attribute("FAR"));

			if(pszFarClip)
				pCamera->setFarClipDistance(StringConverter::parseReal(pszFarClip));
		}
		else {
			pCamera->setNearClipDistance(5.0f);
		}

		// Create node with full information
		SceneNode* pCameraNode = createNode(pCameraElem, pSceneRoot);

		// Attach the Camera entity to node
		pCameraNode->attachObject(pCamera);

		// Target
		rapidxml::xml_node<> * targetElem = pCameraElem->first_node("target");
		if(targetElem)
		{	
			// Create node with full information
			SceneNode* pTargetNode = createNode(targetElem, pSceneRoot);
			pCameraNode->setAutoTracking(true, pTargetNode);
		}

		if(!mWindow)
		{

			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"oSceneLoader: RenderWindow not valid, \
				If the RenderWindow was not auto created, \
				you must add it in the OSMScene object contructor",
				"OSMScene::createCameras");

		}

		// If viewport(s) are not present, create a default viewport
		if(mWindow->getNumViewports() == 0)
		{
			Viewport* vp = mWindow->addViewport(pCamera);
		}

		// Alter the camera aspect ratio to match the viewport
		float aspectRatio = (float)mWindow->getWidth() / (float)mWindow->getHeight();

		pCamera->setAspectRatio(aspectRatio);

		// Set Field of View on camera
		const char* pszFov = GetAttrString(pCameraElem->first_attribute("FOV"));

		if(pszFov) {
			float fov = StringConverter::parseReal(pszFov);

			fov = 2.0 * atan(tan(fov/2.0f) / aspectRatio);

			pCamera->setFOVy(Radian(fov));
		}

		/*
		pCamera->setAspectRatio(
			Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
		*/


		// Notify
		if(mCallbacks)
			mCallbacks->OnCameraCreate(pCamera, pCameraElem);

		// Add to camera list
		mCameras.push_back(pCamera);
	}
	
}

void OSMScene::createHelpers(rapidxml::xml_node<> * pHelperNode, Ogre::SceneNode* pSceneRoot)
{
	// Iterate all helpers, creating them. 
	for (rapidxml::xml_node<> * pHelperElem = pHelperNode->first_node();
            pHelperElem != 0; pHelperElem = pHelperElem->next_sibling())
	{
		// Helper objects are scene nodes, create node with full information
		SceneNode* pHelperNode = createNode(pHelperElem, pSceneRoot);

		// Notify
		if(mCallbacks)
			mCallbacks->OnHelperCreated(pHelperNode, pHelperElem);
	}
}

void OSMScene::createShapes(rapidxml::xml_node<> * pShapeNode)
{
	// Spline and Shapes are loaded as SimpleSpline (Catmull-Rom splines)
	// SimpleSpline objects are not managed by the resource system or the scene manager	
	// Because of this, loaded spline shapes are constructed as SplineObjects in the stack
	// and sent to the client in the OnShapeLoaded method
	// The client should copy and store the SimpleSpline object in order to use it

	// Load spline shapes only if the client uses notifications
	if(mCallbacks) {

		// Iterate all shapes, creating them. 
		for (rapidxml::xml_node<> * pShapeElem = pShapeNode->first_node();
				pShapeElem != 0; pShapeElem = pShapeElem->next_sibling())
		{
			const char* pszName = GetAttrString(pShapeElem->first_attribute("name"));

			Vector3 pos, scale;
			Quaternion rot;

			// Position
			rapidxml::xml_node<> * posElem = pShapeElem->first_node("position");
			if(posElem)
			{
				pos.x = StringConverter::parseReal(GetAttrString(posElem->first_attribute("x")));
				pos.y = StringConverter::parseReal(GetAttrString(posElem->first_attribute("y")));
				pos.z = StringConverter::parseReal(GetAttrString(posElem->first_attribute("z")));
			}

			// Rotation
			rapidxml::xml_node<> * rotElem = pShapeElem->first_node("rotation");
			if(rotElem)
			{				
				rot.w = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("w")));
				rot.x = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("x")));
				rot.y = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("y")));
				rot.z = StringConverter::parseReal(GetAttrString(rotElem->first_attribute("z")));
			}

			// Scale
			rapidxml::xml_node<> * scaleElem = pShapeElem->first_node("scale");
			if(scaleElem)
			{
				scale.x = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("x")));
				scale.y = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("y")));
				scale.z = StringConverter::parseReal(GetAttrString(scaleElem->first_attribute("z")));
			}

			// Iterate all knot points for this shape
			rapidxml::xml_node<> * pointList = pShapeElem->first_node("points");
			if(pointList)
			{
				SimpleSpline spline;

				// Load all knot points and then calculate the spline tangents
				spline.setAutoCalculate(false);

				for (rapidxml::xml_node<> * pKnotElem = pointList->first_node();
						pKnotElem != 0; pKnotElem = pKnotElem->next_sibling())
				{
					Vector3 knotPos;

					knotPos.x = StringConverter::parseReal(GetAttrString(pKnotElem->first_attribute("x")));
					knotPos.y = StringConverter::parseReal(GetAttrString(pKnotElem->first_attribute("y")));
					knotPos.z = StringConverter::parseReal(GetAttrString(pKnotElem->first_attribute("z")));

					spline.addPoint(knotPos);
				}

				// Calculate spline tangents
				spline.recalcTangents();

				// Notify
				mCallbacks->OnShapeLoaded(spline, pos, rot, scale);
			}
		}
	}

}

void OSMScene::createRenderTexture(rapidxml::xml_node<> * pRenderTexNode)
{
	// Iterate all render textures, creating them. 
	for (rapidxml::xml_node<> * pRttElem = pRenderTexNode->first_node();
            pRttElem != 0; pRttElem = pRttElem->next_sibling())
	{
		oRenderTextureProps rtProps;

		const char* pszName = GetAttrString(pRttElem->first_attribute("name"));

		if(pszName) 
		{
			rtProps.name = pszName;

			const char* pszCamName = GetAttrString(pRttElem->first_attribute("cameraName"));

			if(pszCamName)
				rtProps.camName = pszCamName;

			const char* pszSchemeName = GetAttrString(pRttElem->first_attribute("schemeName"));

			if(pszSchemeName)
				rtProps.schemeName = pszSchemeName;

			rtProps.width = Ogre::StringConverter::parseInt(GetAttrString(pRttElem->first_attribute("width")));
			rtProps.height = Ogre::StringConverter::parseInt(GetAttrString(pRttElem->first_attribute("height")));

			rtProps.pixelFmt = Ogre::StringConverter::parseInt(GetAttrString(pRttElem->first_attribute("pixelFormat")));
			rtProps.type = Ogre::StringConverter::parseInt(GetAttrString(pRttElem->first_attribute("type")));

			rtProps.clearBkg = Ogre::StringConverter::parseBool(GetAttrString(pRttElem->first_attribute("clearBackground")));

			rapidxml::xml_node<> * colorElem = pRttElem->first_node("backgroundColor");

			if(colorElem)
			{
				rtProps.bkgColor.r = StringConverter::parseReal(GetAttrString(pRttElem->first_attribute("r")));
				rtProps.bkgColor.g = StringConverter::parseReal(GetAttrString(pRttElem->first_attribute("g")));
				rtProps.bkgColor.b = StringConverter::parseReal(GetAttrString(pRttElem->first_attribute("b")));
			}

			rapidxml::xml_node<> * nodesElem = pRttElem->first_node("showNodes");

			if(nodesElem)
			{
				// Iterate all static geometry groups, creating them.
				for(rapidxml::xml_node<> * pNodeElem = nodesElem->first_node();
					pNodeElem != 0; pNodeElem = pNodeElem->next_sibling())
				{
					const char* pszName = GetAttrString(pNodeElem->first_attribute("name"));

					if(mSceneMgr->hasEntity(pszName))
					{
						Entity* entity = mSceneMgr->getEntity(pszName);

						rtProps.showEntityList.push_back(entity);
					}
				}
			}

			nodesElem = pRttElem->first_node("hideNodes");

			if(nodesElem)
			{
				// Iterate all static geometry groups, creating them.
				for(rapidxml::xml_node<> * pNodeElem = nodesElem->first_node();
					pNodeElem != 0; pNodeElem = pNodeElem->next_sibling())
				{
					const char* pszName = GetAttrString(pNodeElem->first_attribute("name"));

					if(mSceneMgr->hasEntity(pszName))
					{
						Entity* entity = mSceneMgr->getEntity(pszName);

						rtProps.hideEntityList.push_back(entity);
					}
				}
			}

			if(!mWindow)
				return;

			RenderSystem* rend = Root::getSingleton().getRenderSystem();

			TexturePtr tex = Root::getSingleton().getTextureManager()->getByName(rtProps.name);
			assert(tex.isNull());

			Ogre::Camera* camera = 0;

			if(mSceneMgr->hasCamera(rtProps.camName))
			{
				camera = mSceneMgr->getCamera(rtProps.camName);

				TextureType texType = static_cast<TextureType>(rtProps.type);
				PixelFormat pixelFormat = static_cast<PixelFormat>(rtProps.pixelFmt);

				// Create the resource group, if its still not registered in the resource manager
				try {
					ResourceGroupManager::getSingleton().createResourceGroup(OSM_RENDERTEXTURE_GROUP);
				}
				catch(...) {

				}

				TexturePtr tex = Root::getSingleton().getTextureManager()->createManual(rtProps.name,
					OSM_RENDERTEXTURE_GROUP,
					texType,
					rtProps.width, 
					rtProps.height,
					0,
					pixelFormat,
					TU_RENDERTARGET);

				RenderTexture* rTex = tex->getBuffer()->getRenderTarget();

				if(rTex)
				{
					Viewport* vp = rTex->addViewport(camera);
					vp->setMaterialScheme(rtProps.schemeName);
					vp->setClearEveryFrame(rtProps.clearBkg);
					vp->setBackgroundColour(rtProps.bkgColor);
					vp->setOverlaysEnabled(false);

					setRenderTextureNodes(rTex, &rtProps.showEntityList, &rtProps.hideEntityList);

					// Notify
					if(mCallbacks)
						mCallbacks->OnRenderTextureCreate(rTex, pRttElem);
				}
			}
		}
	}
}

void OSMScene::createStaticGeometry(rapidxml::xml_node<> * pStaticGeom) 
{
	// Iterate all static geometry groups, creating them.
	for (rapidxml::xml_node<> * pSGElem = pStaticGeom->first_node();
            pSGElem != 0; pSGElem = pSGElem->next_sibling())
	{

		const char* pszName = GetAttrString(pSGElem->first_attribute("name"));

		StaticGeometry* sgGroup = mSceneMgr->createStaticGeometry(pszName);

		// Set the rendering distance
		const char* pszDist = GetAttrString(pSGElem->first_attribute("distance"));
		sgGroup->setRenderingDistance(StringConverter::parseReal(pszDist));

		// Statig Geometry cast shadows setting
		const char *pszCastShadows = GetAttrString(pSGElem->first_attribute("castShadows"));
		if(pszCastShadows && stricmp(pszCastShadows, "no")==0)
			sgGroup->setCastShadows(false);				
		else
			sgGroup->setCastShadows(true);

		// Region dimensions
		rapidxml::xml_node<> * pSizeElem = pSGElem->first_node("regionSize");
		if(pSizeElem)
		{
			Vector3 size;
			size.x = StringConverter::parseReal(GetAttrString(pSizeElem->first_attribute("x")));
			size.y = StringConverter::parseReal(GetAttrString(pSizeElem->first_attribute("y")));
			size.z = StringConverter::parseReal(GetAttrString(pSizeElem->first_attribute("z")));

			sgGroup->setRegionDimensions(size);
		}

		NodeList sceneNodesList;

		// Iterate all scene nodes in this group and them to the static geometry object.
		rapidxml::xml_node<> * pNodesElem = pSGElem->first_node("nodes");
		if(pNodesElem)
		{
			
			for (rapidxml::xml_node<> * pNodeElem = pNodesElem->first_node();
					pNodeElem != 0; pNodeElem = pNodeElem->next_sibling())
			{
				
				const char* pszNode = GetAttrString(pNodeElem->first_attribute("name"));

				SceneNode* node = mSceneMgr->getSceneNode(pszNode);
				node->setVisible(false);

				sgGroup->addSceneNode(node);
				
				sceneNodesList.push_back(node);

			}
		}

		// Build the static geometry
		sgGroup->build();

		bool keepNodes = false;

		// Notify
		if(mCallbacks)
			keepNodes = mCallbacks->OnStaticGeometryCreated(sgGroup, sceneNodesList);

		if(!keepNodes)
		{
			NodeList::iterator it = sceneNodesList.begin();
			NodeList::iterator iend = sceneNodesList.end();

			for(; it!=iend; ++it)
			{
				SceneNode* node = (*it);
				mSceneMgr->destroySceneNode(node->getName());
			}
		}
	}

}

void OSMScene::loadAnimations(rapidxml::xml_node<> * animationsNode, SkeletonHandles& handles) {

	// Iterate all skeletons, adding animations from ".anim" files
	for (rapidxml::xml_node<> * pSkeletonElem = animationsNode->first_node();
            pSkeletonElem != 0; pSkeletonElem = pSkeletonElem->next_sibling())
	{
		const char *pszName = GetAttrString(pSkeletonElem->first_attribute("name"));

		if(pszName == 0)
			continue;

		const Ogre::SkeletonPtr& skel = Ogre::SkeletonManager::getSingleton().getByName(pszName);

		if(!skel.isNull())
		{

			for (rapidxml::xml_node<> * animElem = pSkeletonElem->first_node();
				animElem != 0; animElem = animElem->next_sibling())
			{
				const char* pszFileName = GetAttrString(animElem->first_attribute("name"));

				if(pszFileName) 
				{
					OSMAnimSerializer animSerializer;

					animSerializer.addAnimation(skel, pszFileName);
				}
			}

			handles.insert(skel->getHandle());
		}
	}
}

void OSMScene::setRenderTextureNodes(RenderTexture* rTex, const EntityList* showNodes, const EntityList* hideNodes)
{
	int visibleNodes = showNodes->size();
	int hiddenNodes = hideNodes->size();		

	if(visibleNodes || hiddenNodes) 
	{
		oRenderTextureListener* rTexListener = 0;

		rTexListener = new oRenderTextureListener();

		assert(rTexListener);

		rTex->addListener(rTexListener);

		int i;

		for(i=0; i<hiddenNodes; ++i) {
			Entity* entity = (*hideNodes)[i];

			if(entity == NULL)
				continue;

			// Add entity to the listener's list
			rTexListener->addEntityToHideList(entity);

		}

		for(i=0; i<visibleNodes; ++i) {
			Entity* entity = (*showNodes)[i];

			if(entity == NULL)
				continue;

			// Add entity to the listener's list
			rTexListener->addEntityToShowList(entity);
		}
	}
}

void OSMScene::loadMaterialAnimations(rapidxml::xml_node<> * animationsNode) {

	// Iterate all animations, adding them to the target material
	for (rapidxml::xml_node<> * pAnimElem = animationsNode->first_node();
            pAnimElem != 0; pAnimElem = pAnimElem->next_sibling())
	{
		const char* pszName = GetAttrString(pAnimElem->first_attribute("name"));

		if(pszName == 0)
			continue;

		const MaterialPtr& material = MaterialManager::getSingleton().getByName(pszName);

		if(!material.isNull()) {
			// Animation
			rapidxml::xml_node<> * animList = pAnimElem->first_node("animations");
			if(animList)
			{

				for (rapidxml::xml_node<> * animElem = animList->first_node();
					animElem != 0; animElem = animElem->next_sibling())
				{

					// Get name of animation
					const char* pszAnimName = GetAttrString(animElem->first_attribute("name"));

					if(pszAnimName == 0)
						continue;

					for(rapidxml::xml_node<> * techElem = animElem->first_node();
						techElem != 0; techElem = techElem->next_sibling())
					{
						const char* pszIndex = GetAttrString(techElem->first_attribute("index"));

						UINT idx = StringConverter::parseInt(pszIndex);

						oMaterialAnimation materialAnim;
						materialAnim.materialName = pszName;
						materialAnim.animationName = pszAnimName;
						materialAnim.techniqueIndex = idx;

						Technique* tech = material->getTechnique(idx);

						for(rapidxml::xml_node<> * passElem = techElem->first_node();
							passElem != 0; passElem = passElem->next_sibling())
						{
							UINT index = StringConverter::parseInt(GetAttrString(passElem->first_attribute("index")));

							Pass* pass = tech->getPass(index);

							rapidxml::xml_node<> * alphaAnim = passElem->first_node("alphaAnimation");
							if(alphaAnim) {
								oPassAnimation passAnim;
								passAnim.index = index;

								float length = StringConverter::parseReal(GetAttrString(alphaAnim->first_attribute("length")));

								passAnim.alphaLength = length;

								// Iterate all alpha keyframes
								for(rapidxml::xml_node<> * pKeyFrameElem = alphaAnim->first_node();
									pKeyFrameElem != 0; pKeyFrameElem = pKeyFrameElem->next_sibling())
								{
									float time = StringConverter::parseReal(GetAttrString(pKeyFrameElem->first_attribute("time")));
									float value = StringConverter::parseReal(GetAttrString(pKeyFrameElem->first_attribute("value")));

									passAnim.alphaKeyFrames[time] = value;
								}

								materialAnim.passAnims.push_back(passAnim);
							}
						}

						// Notify
						if(mCallbacks)
							mCallbacks->OnMaterialAnimatorLoaded(materialAnim);
					}
				}
			}
		}
	}

}

OSMAnimSerializer::OSMAnimSerializer() {
	mVersion = "[oFusion_Serializer_v1.0]";
}

void OSMAnimSerializer::addAnimation(Ogre::SkeletonPtr skel, const Ogre::String& filename) {

	SkeletonSerializer serializer;
	StringUtil::StrStreamType msg;
	msg << "Skeletal Animation: Loading " << filename;
	LogManager::getSingleton().logMessage(msg.str());

	DataStreamPtr stream = ResourceGroupManager::getSingleton().openResource(filename);

	// Check header
	readFileHeader(stream);

	uint16 numBones;

	// Read number of bones needed for this animation
	readShorts(stream, &numBones, 1);

	if(numBones != skel->getNumBones())
	{
		OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"oSceneLoader: Animation not valid for skeleton: " + skel->getName(), 
					"OSMScene::addAnimation");
	}

	size_t size = (stream->size() - stream->tell());

	unsigned char* buffer = new unsigned char[size];

	stream->read(buffer, size);

	DataStreamPtr bufferStream(new MemoryDataStream(buffer, size, false));

	serializer.importSkeleton(bufferStream, skel.get());
}
