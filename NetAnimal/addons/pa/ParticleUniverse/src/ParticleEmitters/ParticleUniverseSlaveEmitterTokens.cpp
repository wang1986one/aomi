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

#include "ParticleEmitters/ParticleUniverseSlaveEmitter.h"
#include "ParticleEmitters/ParticleUniverseSlaveEmitterTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool SlaveEmitterTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		ParticleEmitter* em = Ogre::any_cast<ParticleEmitter*>(prop->parent->context);
		SlaveEmitter* emitter = static_cast<SlaveEmitter*>(em);

		if (prop->name == token[TOKEN_MASTER_TECHNIQUE])
		{
			// Property: master_technique_name
			if (passValidateProperty(compiler, prop, token[TOKEN_MASTER_TECHNIQUE], VAL_STRING))
			{
				Ogre::String val;
				if(getString(prop->values.front(), &val))
				{
					emitter->setMasterTechniqueName(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_MASTER_EMITTER])
		{
			// Property: master_emitter_name
			if (passValidateProperty(compiler, prop, token[TOKEN_MASTER_EMITTER], VAL_STRING))
			{
				Ogre::String val;
				if(getString(prop->values.front(), &val))
				{
					emitter->setMasterEmitterName(val);
					return true;
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool SlaveEmitterTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		// No objects
		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void SlaveEmitterWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a SlaveEmitter
		const SlaveEmitter* emitter = static_cast<const SlaveEmitter*>(element);

		// Write the header of the SlaveEmitter
		serializer->writeLine(token[TOKEN_EMITTER], emitter->getEmitterType(), emitter->getName(), 8);
		serializer->writeLine("{", 8);

		// Write base attributes
		ParticleEmitterWriter::write(serializer, element);

		// Write own attributes
		if (emitter->getMasterTechniqueName() != Ogre::StringUtil::BLANK) serializer->writeLine(
			token[TOKEN_MASTER_TECHNIQUE], emitter->getMasterTechniqueName(), 12);
		if (emitter->getMasterEmitterName() != Ogre::StringUtil::BLANK) serializer->writeLine(
			token[TOKEN_MASTER_EMITTER], emitter->getMasterEmitterName(), 12);

		// Write the close bracket
		serializer->writeLine("}", 8);
	}

}
