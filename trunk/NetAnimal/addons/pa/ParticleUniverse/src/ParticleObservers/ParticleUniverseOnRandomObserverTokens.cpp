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

#include "ParticleObservers/ParticleUniverseOnRandomObserver.h"
#include "ParticleObservers/ParticleUniverseOnRandomObserverTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool OnRandomObserverTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		ParticleObserver* ob = Ogre::any_cast<ParticleObserver*>(prop->parent->context);
		OnRandomObserver* observer = static_cast<OnRandomObserver*>(ob);

		if (prop->name == token[TOKEN_ONRANDOM_THRESHOLD])
		{
			// Property: random_threshold
			if (passValidateProperty(compiler, prop, token[TOKEN_ONRANDOM_THRESHOLD], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					observer->setThreshold(val);
					return true;
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool OnRandomObserverTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		// No objects
		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void OnRandomObserverWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a OnRandomObserver
		const OnRandomObserver* observer = static_cast<const OnRandomObserver*>(element);

		// Write the header of the OnRandomObserver
		serializer->writeLine(token[TOKEN_OBSERVER], observer->getObserverType(), observer->getName(), 8);
		serializer->writeLine("{", 8);

		// Write base attributes
		ParticleObserverWriter::write(serializer, element);

		// Write own attributes
		if (observer->getThreshold() != OnRandomObserver::DEFAULT_THRESHOLD) serializer->writeLine(
			token[TOKEN_ONRANDOM_THRESHOLD], Ogre::StringConverter::toString(observer->getThreshold()), 12);

		// Write the close bracket
		serializer->writeLine("}", 8);
	}

}
