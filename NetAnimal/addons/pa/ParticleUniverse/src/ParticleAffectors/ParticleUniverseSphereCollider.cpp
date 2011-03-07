/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#include "ParticleUniversePCH.h"

#ifndef PARTICLE_UNIVERSE_EXPORTS
#define PARTICLE_UNIVERSE_EXPORTS
#endif

#include "ParticleAffectors/ParticleUniverseSphereCollider.h"
#include "OgreAxisAlignedBox.h"

namespace ParticleUniverse
{
	// Constants
	const Ogre::Real SphereCollider::DEFAULT_RADIUS = 100.0f;

	//-----------------------------------------------------------------------
	SphereCollider::SphereCollider(void) : 
		BaseCollider(),
		mPredictedPosition(Ogre::Vector3::ZERO),
		mRadius(DEFAULT_RADIUS),
		mInnerCollision(false)
	{
	}
	//-----------------------------------------------------------------------
	const Ogre::Real SphereCollider::getRadius(void) const
	{
		return mRadius;
	}
	//-----------------------------------------------------------------------
	void SphereCollider::setRadius(const Ogre::Real radius)
	{
		mRadius = radius;
		mSphere.setRadius(mRadius);
	}
	//-----------------------------------------------------------------------
	bool SphereCollider::isInnerCollision(void) const
	{
		return mInnerCollision;
	}
	//-----------------------------------------------------------------------
	void SphereCollider::setInnerCollision(bool innerCollision)
	{
		mInnerCollision = innerCollision;
	}
	//-----------------------------------------------------------------------
	void SphereCollider::_preProcessParticles(ParticleTechnique* particleTechnique, Ogre::Real timeElapsed)
	{
		// Call parent
		BaseCollider::_preProcessParticles(particleTechnique, timeElapsed);

		// Calculate the affectors' center position.
		mSphere.setCenter(getDerivedPosition());
	}
	//-----------------------------------------------------------------------
	void SphereCollider::_affect(ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed)
	{
		mPredictedPosition = particle->position + mVelocityScale * particle->direction;
		bool collision = false;
		Ogre::Vector3 distance = particle->position - mDerivedPosition;
		Ogre::Real distanceLength = distance.length();

		switch(mIntersectionType)
		{
			case BaseCollider::IT_POINT:
			{
				// Validate for a point-sphere intersection
				if (mInnerCollision == (distanceLength > mRadius))
				{
					// Collision detected (re-position the particle)
					particle->position -= mVelocityScale * particle->direction;
					collision = true;
				}
				else
				{
					distance = mPredictedPosition - mDerivedPosition;
					distanceLength = distance.length();
					if (mInnerCollision == (distanceLength > mRadius))
					{
						// Collision detected
						collision = true;
					}
				}
			}
			break;

			case BaseCollider::IT_BOX:
			{
				// Validate for a box-sphere intersection
				if (particle->particleType != Particle::PT_VISUAL)
					break;

				VisualParticle* visualParticle = static_cast<VisualParticle*>(particle);
				Ogre::AxisAlignedBox box;
				populateAlignedBox(box,
					visualParticle->position, 
					visualParticle->width, 
					visualParticle->height,
					visualParticle->depth);

					if (mInnerCollision != box.intersects(mSphere))
					{
						// Collision detected (re-position the particle)
						particle->position -= mVelocityScale * particle->direction;
						collision = true;
					}
					else
					{
						Ogre::AxisAlignedBox box;
						populateAlignedBox(box,
							mPredictedPosition, 
							visualParticle->width, 
							visualParticle->height,
							visualParticle->depth);
						if (mInnerCollision != box.intersects(mSphere))
						{
							// Collision detected
							collision = true;
						}
					}
			}
			break;
		}

		if (collision)
		{
			calculateDirectionAfterCollision(particle, distance, distanceLength);
			calculateRotationSpeedAfterCollision(particle);
			particle->addEventFlags(Particle::PEF_COLLIDED);
		}
	}
	//-----------------------------------------------------------------------
	void SphereCollider::calculateDirectionAfterCollision(Particle* particle, Ogre::Vector3 distance, Ogre::Real distanceLength)
	{
		switch (mCollisionType)
		{
			case BaseCollider::CT_BOUNCE:
			{
				/** If the particle is on the surface (or just inside the sphere); bounce it
					Make use of formula R = 2 * (-I dot N) * N + I, where
					R = the new direction vector
					I = the old (unit) direction vector before the collision
					N = the Normal at the collision point
				*/
				Ogre::Real directionLength = particle->direction.length();
				particle->direction.normalise();
				distance.normalise();
				particle->direction = 2 * (-particle->direction.dotProduct(distance)) * distance + particle->direction;

				// Adjust to original speed
				particle->direction *= directionLength;

				// Accelerate/slow down, using the bounce value
				particle->direction *= mBouncyness;
			}
			break;
			case BaseCollider::CT_FLOW:
			{
				/** Reset the position (on the sphere), but keep the direction.
					This doesn't really work good for box-type collisions, because it doesn't take the particle
					dimensions into account.
				*/
				particle->position = mDerivedPosition + distance * (mRadius / distanceLength);
			}
			break;
		}
	}
	//-----------------------------------------------------------------------
	void SphereCollider::copyAttributesTo (ParticleAffector* affector)
	{
		BaseCollider::copyAttributesTo(affector);

		SphereCollider* sphereCollider = static_cast<SphereCollider*>(affector);
		sphereCollider->mRadius = mRadius;
		sphereCollider->mSphere = mSphere;
		sphereCollider->mInnerCollision = mInnerCollision;
	}
}
