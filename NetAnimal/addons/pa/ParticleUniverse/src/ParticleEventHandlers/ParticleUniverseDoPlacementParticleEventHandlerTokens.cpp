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

#include "ParticleEventHandlers/ParticleUniverseDoPlacementParticleEventHandler.h"
#include "ParticleEventHandlers/ParticleUniverseDoPlacementParticleEventHandlerTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool DoPlacementParticleEventHandlerTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		ParticleEventHandler* evt = Ogre::any_cast<ParticleEventHandler*>(prop->parent->context);
		DoPlacementParticleEventHandler* handler = static_cast<DoPlacementParticleEventHandler*>(evt);

		if (prop->name == token[TOKEN_DOPLACE_FORCE_EMITTER])
		{
			// Property: force_emitter
			if (passValidateProperty(compiler, prop, token[TOKEN_DOPLACE_FORCE_EMITTER], VAL_STRING))
			{
				Ogre::String val;
				if(getString(prop->values.front(), &val))
				{
					handler->setForceEmitterName(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_DOPLACE_NUMBER_OF_PARTICLES])
		{
			// Property: number_of_particles
			if (passValidateProperty(compiler, prop, token[TOKEN_DOPLACE_NUMBER_OF_PARTICLES], VAL_UINT))
			{
				unsigned int val = 0;
				if(getUInt(prop->values.front(), &val))
				{
					handler->setNumberOfParticles(val);
					return true;
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool DoPlacementParticleEventHandlerTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		// No objects
		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void DoPlacementParticleEventHandlerWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a DoPlacementParticleEventHandler
		const DoPlacementParticleEventHandler* eventHandler = static_cast<const DoPlacementParticleEventHandler*>(element);

		// Write the header of the DoPlacementParticleEventHandler
		serializer->writeLine(token[TOKEN_HANDLER], eventHandler->getEventHandlerType(), eventHandler->getName(), 12);
		serializer->writeLine("{", 12);

		// Write base attributes
		ParticleEventHandlerWriter::write(serializer, element);

		// Write own attributes
		if (eventHandler->getForceEmitterName() != Ogre::StringUtil::BLANK) serializer->writeLine(
			token[TOKEN_DOPLACE_FORCE_EMITTER], eventHandler->getForceEmitterName(), 16);
		if (eventHandler->getNumberOfParticles() != DoPlacementParticleEventHandler::DEFAULT_NUMBER_OF_PARTICLES) serializer->writeLine(
			token[TOKEN_DOPLACE_NUMBER_OF_PARTICLES], Ogre::StringConverter::toString(eventHandler->getNumberOfParticles()), 16);

		// Write the close bracket
		serializer->writeLine("}", 12);
	}

}
