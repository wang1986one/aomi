/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_OBSERVER_FACTORY_H__
#define __PU_OBSERVER_FACTORY_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseObserver.h"
#include "ParticleUniverseObserverTokens.h"
#include "ParticleUniverseScriptDeserializer.h"
#include "ParticleUniverseScriptReader.h"

namespace ParticleUniverse
{
	/** This is the base factory of all ParticleObserver implementations.
    */
	class _ParticleUniverseExport ParticleObserverFactory : public ScriptReader, public ScriptWriter, public Ogre::FactoryAlloc
	{
	    protected:

			/** 
	        */
			template <class T>
			ParticleObserver* _createObserver(void)
			{
				ParticleObserver* particleObserver = OGRE_NEW_T(T, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
				particleObserver->setObserverType(getObserverType());
				return particleObserver;
			};

	public:
			ParticleObserverFactory(void) {};
	        virtual ~ParticleObserverFactory(void) {};

		    /** Returns the type of the factory, which identifies the particle observer type this factory creates. */
			virtual Ogre::String getObserverType(void) const = 0;

	        /** Creates a new observer instance.
		    @remarks
	        */
		    virtual ParticleObserver* createObserver(void) = 0;

			/** Delete an observer
	        */
			void destroyObserver (ParticleObserver* observer)
			{
				OGRE_DELETE_T(observer, ParticleObserver, Ogre::MEMCATEGORY_SCENE_OBJECTS);
			};
	};

}
#endif
