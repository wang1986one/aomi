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

#include "ParticleAffectors/ParticleUniverseBaseCollider.h"
#include "OgreAxisAlignedBox.h"

namespace ParticleUniverse
{
	// Constants
	const Ogre::Real BaseCollider::DEFAULT_BOUNCYNESS = 1.0f;
	const Ogre::Real BaseCollider::DEFAULT_FRICTION = 0.0f;
	const BaseCollider::IntersectionType BaseCollider::DEFAULT_INTERSECTION_TYPE = BaseCollider::IT_POINT;
	const BaseCollider::CollisionType BaseCollider::DEFAULT_COLLISION_TYPE = BaseCollider::CT_BOUNCE;

	//-----------------------------------------------------------------------
	BaseCollider::BaseCollider(void) :
		ParticleAffector(),
		mBouncyness(DEFAULT_BOUNCYNESS),
		mFriction(DEFAULT_FRICTION),
		mIntersectionType(DEFAULT_INTERSECTION_TYPE),
		mCollisionType(DEFAULT_COLLISION_TYPE),
		mVelocityScale(1.0f)
	{
	}
	//-----------------------------------------------------------------------
	void BaseCollider::_preProcessParticles(ParticleTechnique* particleTechnique, Ogre::Real timeElapsed)
	{
		// Take scaled velocity into account
		mVelocityScale = 1.0f;
		if (mParentTechnique)
		{
			mVelocityScale = timeElapsed * mParentTechnique->getParticleSystemScaleVelocity();
		}
	}
	//-----------------------------------------------------------------------
	const BaseCollider::IntersectionType BaseCollider::getIntersectionType(void) const
	{
		return mIntersectionType;
	}
	//-----------------------------------------------------------------------
	void BaseCollider::setIntersectionType(const BaseCollider::IntersectionType& intersectionType)
	{
		mIntersectionType = intersectionType;
	}
	//-----------------------------------------------------------------------
	const BaseCollider::CollisionType BaseCollider::getCollisionType(void) const
	{
		return mCollisionType;
	}
	//-----------------------------------------------------------------------
	void BaseCollider::setCollisionType(const BaseCollider::CollisionType& collisionType)
	{
		mCollisionType = collisionType;
	}
	//-----------------------------------------------------------------------
	const Ogre::Real BaseCollider::getFriction(void) const
	{
		return mFriction;
	}
	//-----------------------------------------------------------------------
	void BaseCollider::setFriction(const Ogre::Real friction)
	{
		mFriction = friction;
	}
	//-----------------------------------------------------------------------
	const Ogre::Real BaseCollider::getBouncyness(void) const
	{
		return mBouncyness;
	}
	//-----------------------------------------------------------------------
	void BaseCollider::setBouncyness(const Ogre::Real bouncyness)
	{
		mBouncyness = bouncyness;
	}
	//-----------------------------------------------------------------------
	void BaseCollider::populateAlignedBox(Ogre::AxisAlignedBox& box,
		const Ogre::Vector3& position, 
		const Ogre::Real width,
		const Ogre::Real height,
		const Ogre::Real depth)
	{
		Ogre::Real halfWidth = 0.5f * width;
		Ogre::Real halfHeight = 0.5f * height;
		Ogre::Real halfDepth = 0.5f * depth;
		box.setMinimum(position.x - halfWidth, 
			position.y - halfHeight, 
			position.z - halfDepth);
		box.setMaximum(position.x + halfWidth, 
			position.y + halfHeight, 
			position.z + halfDepth);
	}
	//-----------------------------------------------------------------------
	void BaseCollider::calculateRotationSpeedAfterCollision(Particle* particle)
	{
		if (particle->particleType != Particle::PT_VISUAL)
			return;

		VisualParticle* visualParticle = static_cast<VisualParticle*>(particle);
		Ogre::Real signedFriction = Ogre::Math::UnitRandom() > 0.5 ? -(mFriction - 1) : (mFriction - 1);
		visualParticle->rotationSpeed *= signedFriction;
		visualParticle->zRotationSpeed *= signedFriction;
	}
	//-----------------------------------------------------------------------
	void BaseCollider::copyAttributesTo (ParticleAffector* affector)
	{
		ParticleAffector::copyAttributesTo(affector);

		BaseCollider* baseCollider = static_cast<BaseCollider*>(affector);
		baseCollider->mBouncyness = mBouncyness;
		baseCollider->mFriction = mFriction;
		baseCollider->mIntersectionType = mIntersectionType;
		baseCollider->mCollisionType = mCollisionType;
	}

}
