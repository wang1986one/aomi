/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_SPHERE_COLLIDER_H__
#define __PU_SPHERE_COLLIDER_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseBaseCollider.h"
#include "OgreSphere.h"

namespace ParticleUniverse
{
	/** The SphereCollider is a sphere shape that collides with the particles. The SphereCollider can only collide 
		with particles that are created within the same ParticleTechnique as where the SphereCollider is registered.
    */
	class _ParticleUniverseExport SphereCollider : public BaseCollider
	{
		public:
			// Constants
			static const Ogre::Real DEFAULT_RADIUS;

			SphereCollider(void);
	        virtual ~SphereCollider(void){};

			/** Returns the radius of the sphere
			*/
			const Ogre::Real getRadius(void) const;

			/** Sets the radius of the sphere
			*/
			void setRadius(const Ogre::Real radius);

			/** Returns indication whether the collision is inside or outside of the box
			@remarks
				If value is true, the collision is inside of the box.
			*/
			bool isInnerCollision(void) const;

			/** Set indication whether the collision is inside or outside of the box
			@remarks
				If value is set to true, the collision is inside of the box.
			*/
			void setInnerCollision(bool innerCollision);

			/** 
			*/
			void calculateDirectionAfterCollision(Particle* particle, Ogre::Vector3 distance, Ogre::Real distanceLength);

			/** @copydoc ParticleAffector::_preProcessParticles */
			virtual void _preProcessParticles(ParticleTechnique* particleTechnique, Ogre::Real timeElapsed);

			/** @copydoc ParticleAffector::_affect */
			virtual void _affect(ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed);

			/** @copydoc ParticleAffector::copyAttributesTo */
			virtual void copyAttributesTo (ParticleAffector* affector);

		protected:
			Ogre::Real mRadius;
			Ogre::Sphere mSphere;
			Ogre::Vector3 mPredictedPosition;
			bool mInnerCollision;
	};

}
#endif
