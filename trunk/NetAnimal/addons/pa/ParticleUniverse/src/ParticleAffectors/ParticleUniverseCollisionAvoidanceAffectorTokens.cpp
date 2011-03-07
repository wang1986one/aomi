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

#include "ParticleAffectors/ParticleUniverseCollisionAvoidanceAffector.h"
#include "ParticleAffectors/ParticleUniverseCollisionAvoidanceAffectorTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool CollisionAvoidanceAffectorTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		ParticleAffector* af = Ogre::any_cast<ParticleAffector*>(prop->parent->context);
		CollisionAvoidanceAffector* affector = static_cast<CollisionAvoidanceAffector*>(af);

		if (prop->name == token[TOKEN_AVOIDANCE_RADIUS])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_AVOIDANCE_RADIUS], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					affector->setRadius(val);
					return true;
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool CollisionAvoidanceAffectorTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		// No objects
		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void CollisionAvoidanceAffectorWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a CollisionAvoidanceAffector
		const CollisionAvoidanceAffector* affector = static_cast<const CollisionAvoidanceAffector*>(element);

		// Write the header of the CollisionAvoidanceAffector
		serializer->writeLine(token[TOKEN_AFFECTOR], affector->getAffectorType(), affector->getName(), 8);
		serializer->writeLine("{", 8);

		// Write base attributes
		ParticleAffectorWriter::write(serializer, element);

		// Write own attributes
		if (affector->getRadius() != CollisionAvoidanceAffector::DEFAULT_RADIUS) serializer->writeLine(
			token[TOKEN_AVOIDANCE_RADIUS], Ogre::StringConverter::toString(affector->getRadius()), 12);

		// Write the close bracket
		serializer->writeLine("}", 8);
	}

}
