/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_ONVELOCITY_OBSERVER_TOKENS_H__
#define __PU_ONVELOCITY_OBSERVER_TOKENS_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseObserverTokens.h"

namespace ParticleUniverse
{
	/** The OnVelocityObserverTranslator parses 'OnVelocityObserver' tokens
	*/
	class _ParticleUniverseExport OnVelocityObserverTranslator : public ScriptTranslator
	{
		public:
			OnVelocityObserverTranslator(void){};
			~OnVelocityObserverTranslator(void){};
			virtual bool translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node);
			virtual bool translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node);
	};
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	/** 
    */
	class _ParticleUniverseExport OnVelocityObserverWriter : public ParticleObserverWriter
	{
		public:

			OnVelocityObserverWriter(void) {};
			virtual ~OnVelocityObserverWriter(void) {};

			/** @see
				ScriptWriter::write
			*/
			virtual void write(ParticleScriptSerializer* serializer, const IElement* element);
	};

}
#endif
