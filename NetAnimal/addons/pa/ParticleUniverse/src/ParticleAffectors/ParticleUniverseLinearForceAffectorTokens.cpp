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

#include "ParticleAffectors/ParticleUniverseLinearForceAffector.h"
#include "ParticleAffectors/ParticleUniverseLinearForceAffectorTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool LinearForceAffectorTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		ParticleAffector* af = Ogre::any_cast<ParticleAffector*>(prop->parent->context);

		// No own properties. Parse the BaseForceAffector
		BaseForceAffectorTranslator BaseForceAffectorTranslator;
		return BaseForceAffectorTranslator.translateChildProperty(compiler, node);
	}
	//-----------------------------------------------------------------------
	bool LinearForceAffectorTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		// No objects
		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void LinearForceAffectorWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a LinearForceAffector
		const LinearForceAffector* affector = static_cast<const LinearForceAffector*>(element);

		// Write the header of the LinearForceAffector
		serializer->writeLine(token[TOKEN_AFFECTOR], affector->getAffectorType(), affector->getName(), 8);
		serializer->writeLine("{", 8);

		// Write base attributes
		BaseForceAffectorWriter::write(serializer, element);

		// Write the close bracket
		serializer->writeLine("}", 8);
	}

}
