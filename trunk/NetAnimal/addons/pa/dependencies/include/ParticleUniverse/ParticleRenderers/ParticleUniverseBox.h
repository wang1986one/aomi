/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_BOX_H__
#define __PU_BOX_H__

#include "ParticleUniversePrerequisites.h"
#include "OgreMemoryAllocatorConfig.h"
#include "OgreVector3.h"
#include "OgreColourValue.h"
#include "OgreQuaternion.h"

namespace ParticleUniverse
{
	class BoxSet;

	/** 
    */
	class _ParticleUniverseExport Box : public Ogre::FXAlloc
	{
		friend class BoxSet;
		friend class BoxRenderer;

		protected:
			bool mOwnDimensions;
			Ogre::Real mWidth;
			Ogre::Real mHeight;
			Ogre::Real mDepth;
			Ogre::Real mHalfWidth;
			Ogre::Real mHalfHeight;
			Ogre::Real mHalfDepth;
			bool mDimensionsChanged;


			/** Corners of the box in local space.
			*/
			Ogre::Vector3 mCorners[8];
			Ogre::Vector3 mTempCorner;

			/** Calculates the corners.
			*/
			void _calculateCorners(void);

		public:
			Ogre::Vector3 mPosition;
			Ogre::ColourValue mColour;
			Ogre::Quaternion mOrientation;
			BoxSet* mParentSet;
			
			/** Default constructor.
			*/
			Box(void);

			/** Default destructor.
			*/
	        virtual ~Box(void);

			/** Constructor as called by BoxSet.
			*/
			Box(const Ogre::Vector3& position, BoxSet* owner);

			/** Return the boxcorner in local space of a specified corner.
			*/
			const Ogre::Vector3& getCorner(size_t index);

			/** Return the boxcorner in world space of a specified corner.
			*/
			const Ogre::Vector3& getWorldspaceCorner(size_t index);

			/** 
			*/
			void setPosition(const Ogre::Vector3& position);

			/** 
			*/
			void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z);

			/** 
			*/
			const Ogre::Vector3& getPosition(void) const;

			/** Sets the colour of this box.
			*/
			void setColour(const Ogre::ColourValue& colour);

			/** Get the colour of this box.
			*/
			const Ogre::ColourValue& getColour(void) const;
		
			/** Resets this box to use the parent BoxSet's dimensions instead of it's own.
			*/
			void resetDimensions(void) { mOwnDimensions = false; }

			/** Sets the width, height and depth for this box.
			*/
			void setDimensions(Ogre::Real width, Ogre::Real height, Ogre::Real depth);

			/** Returns true if this box deviates from the BoxSet's default dimensions.
			@see
				Box::setDimensions
			*/
			bool hasOwnDimensions(void) const;

			/** Retrieves the box's personal width, if hasOwnDimensions is true.
			*/
			Ogre::Real getOwnWidth(void) const;

			/** Retrieves the box's personal height, if hasOwnDimensions is true.
			*/
			Ogre::Real getOwnHeight(void) const;

			/** Retrieves the box's personal depth, if hasOwnDimensions is true.
			*/
			Ogre::Real getOwnDepth(void) const;

			/** Internal method for notifying the box of it's owner.
			*/
			void _notifyOwner(BoxSet* owner);
	};

}
#endif
