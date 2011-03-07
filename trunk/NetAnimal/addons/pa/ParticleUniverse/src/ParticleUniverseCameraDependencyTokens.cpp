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

#include "ParticleUniverseCameraDependencyTokens.h"
#include "ParticleUniverseCameraDependency.h"

namespace ParticleUniverse
{
	/**************************************************************************
	 * CameraDependencyTranslator
	 *************************************************************************/
	CameraDependencyTranslator::CameraDependencyTranslator()
	{
	}
	//-------------------------------------------------------------------------
	void CameraDependencyTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		CameraDependency* cameraDependency = Ogre::any_cast<CameraDependency*>(obj->context);

		// Run through properties
		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			if((*i)->type == Ogre::ANT_PROPERTY)
			{
				Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
				if (prop->name == token[TOKEN_DISTANCE_THRESHOLD])
				{
					// Property: distance_threshold
					if (passValidateProperty(compiler, prop, token[TOKEN_DISTANCE_THRESHOLD], VAL_REAL))
					{
						Ogre::Real val;
						if(getReal(prop->values.front(), &val))
						{
							cameraDependency->setThreshold(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_INCREASE])
				{
					// Property: increase
					if (passValidateProperty(compiler, prop, token[TOKEN_INCREASE], VAL_BOOL))
					{
						bool val;
						if(getBoolean(prop->values.front(), &val))
						{
							cameraDependency->setIncrease(val);
						}
					}
				}
				else
				{
					errorUnexpectedProperty(compiler, prop);
				}
			}
			else if((*i)->type == Ogre::ANT_OBJECT)
			{
				processNode(compiler, *i);
			}
            else
			{
				errorUnexpectedToken(compiler, *i);
			}
		}
	}
	//-----------------------------------------------------------------------
	void CameraDependencyWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a CameraDependency
		const CameraDependency* dependency = static_cast<const CameraDependency*>(element);

		// Write attributes
		if (dependency->getThreshold() != CameraDependency::DEFAULT_DISTANCE_THRESHOLD) serializer->writeLine(
			token[TOKEN_DISTANCE_THRESHOLD], Ogre::StringConverter::toString(dependency->getThreshold()), 12);
		if (dependency->isIncrease() != CameraDependency::DEFAULT_INCREASE) serializer->writeLine(
			token[TOKEN_INCREASE], Ogre::StringConverter::toString(dependency->isIncrease()), 12);
	}

}
