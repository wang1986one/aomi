/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_DO_STOP_SYSTEM_EVENT_HANDLER_H__
#define __PU_DO_STOP_SYSTEM_EVENT_HANDLER_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseEventHandler.h"

namespace ParticleUniverse
{
	/** The DoStopSystemEventHandler stops the ParticleSystem.
    */
	class _ParticleUniverseExport DoStopSystemEventHandler : public ParticleEventHandler
	{
		protected:

		public:
			DoStopSystemEventHandler(void) : ParticleEventHandler()
			{
			};
	        virtual ~DoStopSystemEventHandler(void) {};

			/** 
	        */
			virtual void _handle (ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed);
	};

}
#endif
