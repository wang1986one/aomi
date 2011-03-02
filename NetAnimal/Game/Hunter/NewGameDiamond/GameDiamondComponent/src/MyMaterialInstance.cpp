#include "GameDiamondComponentStableHeaders.h"
#include "MyMaterialInstance.h"

MyMaterialInstance::MyMaterialInstance (Ogre::MaterialPtr mat) {
	mCurrentTransparency = 0.0f;

	mSBT = SBT_TRANSPARENT_ALPHA;
	mOriginalMat = mat;
	Ogre::String name;
	do {
		name = mOriginalMat->getName () + StringConverter::toString (Math::UnitRandom ());
	} while (MaterialManager::getSingleton ().resourceExists (name));
	mColoneMat = mOriginalMat->clone(name);
}

MyMaterialInstance::~MyMaterialInstance () {
	MaterialManager::getSingleton().remove(mColoneMat->getName());
	mColoneMat.setNull ();
}

void MyMaterialInstance::setSceneBlending (SceneBlendType sbt) {
	mSBT = sbt;

	if (!mOriginalMat.isNull ()) {
		Material::TechniqueIterator techniqueIt = mOriginalMat->getTechniqueIterator ();
		while (techniqueIt.hasMoreElements ()) {
			Technique *t = techniqueIt.getNext ();
			Technique::PassIterator passIt = t->getPassIterator ();
			while (passIt.hasMoreElements ()) {
				passIt.getNext ()->setSceneBlending (mSBT);
			}
		}
	}
}

void MyMaterialInstance::setTransparency (Real transparency) {
	mCurrentTransparency = transparency;
	if (mCurrentTransparency > 0.0f) {
		if (mCurrentTransparency > 1.0f)
			mCurrentTransparency = 1.0f;

		if (mOriginalMat.isNull ()) {
			return;
		}

		unsigned short i = 0, j;
		ColourValue sc, dc; // Source colur, destination colour
		Material::TechniqueIterator techniqueIt = mOriginalMat->getTechniqueIterator ();
		while (techniqueIt.hasMoreElements ()) {
			Technique *t = techniqueIt.getNext ();
			Technique::PassIterator passIt = t->getPassIterator ();
			j = 0;
			while (passIt.hasMoreElements ()) {
				sc = mColoneMat->getTechnique (i)->getPass (j)->getDiffuse ();

				switch (mSBT) {
		  case SBT_ADD:
			  dc = sc;
			  dc.r -= sc.r * mCurrentTransparency;
			  dc.g -= sc.g * mCurrentTransparency;
			  dc.b -= sc.b * mCurrentTransparency;
			  passIt.peekNext ()->setAmbient (ColourValue::Black);
			  break;
		  case SBT_TRANSPARENT_ALPHA:
		  default:
			  dc = sc;
			  dc.a = sc.a * (1.0f - mCurrentTransparency);
			  passIt.peekNext ()->setAmbient (mColoneMat->getTechnique (i)->getPass (j)->getAmbient ());
			  break;
				}
				passIt.peekNext ()->setDiffuse (dc);
				passIt.moveNext ();

				++j;
			}

			++i;
		}
	}
	else {
		mCurrentTransparency = 0.0f;
	}
}
