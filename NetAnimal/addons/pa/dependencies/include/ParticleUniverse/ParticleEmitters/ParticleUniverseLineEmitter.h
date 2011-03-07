/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_LINE_EMITTER_H__
#define __PU_LINE_EMITTER_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseSystem.h"
#include "ParticleUniverseEmitter.h"

namespace ParticleUniverse
{
	/** The LineEmitter is a ParticleEmitter that emits particles on or near a line.
    */
	class _ParticleUniverseExport LineEmitter : public ParticleEmitter
	{
		protected:
			Ogre::Vector3 mEnd; // End point of the line (startpoint is determined by means of position)
			Ogre::Vector3 mPerpendicular; // Generated unit vector perpendicular on the line
			Ogre::Real mMaxDeviation;	// Determines how far from the line a particle is emitted.
										// This attribute defines the maximum value.
			Ogre::Real mMinIncrement;	// Defines the minimum increment value.
			Ogre::Real mMaxIncrement;	// If > 0, it defines the maximum (random) increment value that is
										// taken on the line traject. If not set, there is no particular 
										// order in particle generation.
			Ogre::Real mIncrement; // Defines the trajectory path along the line in terms of increments
			Ogre::Real mLength; // The length of the line
			bool mIncrementsLeft;	// Indicates whether there are more increments on the path towards the end
									// of the line.
			bool mFirst; // True when the first particle is emitted (only for generating particles incremental)

			// Internal scaled values
			Ogre::Vector3 _mScaledEnd;
			Ogre::Real _mScaledMaxDeviation;
			Ogre::Real _mScaledMinIncrement;
			Ogre::Real _mScaledMaxIncrement;
			Ogre::Real _mScaledLength;

		public:
			// Constants
			static const Ogre::Vector3 DEFAULT_END;
			static const Ogre::Real DEFAULT_MIN_INCREMENT;
			static const Ogre::Real DEFAULT_MAX_INCREMENT;
			static const Ogre::Real DEFAULT_MAX_DEVIATION;

			LineEmitter(void);
	        virtual ~LineEmitter(void) {};

			/** 
	        */
			virtual void _notifyStart (void);

			/** Override the default implementation, to allow that no particles are emitted if there
				is an incremental emission of particles (along a path), and the end of the line has
				been reached.
	        */
			virtual unsigned short _calculateRequestedParticles(Ogre::Real timeElapsed);

			/** 
	        */
			Ogre::Real getMaxDeviation(void) const;
			void setMaxDeviation(Ogre::Real maxDeviation);

			/** 
	        */
			Ogre::Real getMaxIncrement(void) const;
			void setMaxIncrement(Ogre::Real maxIncrement);
			
			/** 
	        */
			Ogre::Real getMinIncrement(void) const;
			void setMinIncrement(Ogre::Real minIncrement);
			
			/** Get the end vector. This is the vector that defines the end of the line (in local space).
	        */
			const Ogre::Vector3& getEnd(void) const;

			/** Set the end vector.
	        */
			void setEnd(const Ogre::Vector3& end);

			/** 
	        */
			virtual void _notifyRescaled(const Ogre::Vector3& scale);

			/** 
	        */
			virtual void _initParticlePosition(Particle* particle);

			/** 
	        */
			virtual void _initParticleDirection(Particle* particle);

			/** 
	        */
			virtual void copyAttributesTo (ParticleEmitter* emitter);
	};

}
#endif
