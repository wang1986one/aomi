#ifndef __MyMaterialInstance_H__
#define __MyMaterialInstance_H__

#include "Ogre/Ogre.h"

using namespace Ogre;
//只针对一种材质只应用于一个物体的情况，不适合用于多个物体
class MyMaterialInstance {
	// Attributes =================================================================================
public:
protected:
	/** Reference to the original material.
	*/
	MaterialPtr mOriginalMat;
	MaterialPtr mColoneMat;
	Real mCurrentTransparency;
	/** Current blending method.
	*/
	SceneBlendType mSBT;
	// Methods ====================================================================================
public:
	/** Constructor. 
	* Initialises references and parameters.
	*/
	MyMaterialInstance (Ogre::MaterialPtr mat);
	/** Destructor.
	* @note Destroys the copy material if needed.
	*/
	~MyMaterialInstance ();
	/** Sets the blending method to use to adjust transparency.
	* @param sbt The SceneBlendType desired.
	*/
	void setSceneBlending (SceneBlendType sbt);
	/** Changes this instance transparency. 
	* @param transparency The new transparency. Values will be clamped to [0..1].
	* @note This changes transparency. A value of 0 means full opacity, while 1 means full 
	*       transparency (invisible)
	* @note If transparency equals 0, it will use the original material instead of the copy 
	*       (the copy is mandatory transparent, and thus might be slower than the original).
	*/
	void setTransparency (Real transparency);
};

#endif // __MyMaterialInstance_H__