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

#include "ParticleUniverseBehaviourTokens.h"

namespace ParticleUniverse
{
	/**************************************************************************
	 * BehaviourTranslator
	 *************************************************************************/
	BehaviourTranslator::BehaviourTranslator()
		:mBehaviour(0)
	{
	}
	//-------------------------------------------------------------------------
	void BehaviourTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		Ogre::ObjectAbstractNode* parent = obj->parent ? reinterpret_cast<Ogre::ObjectAbstractNode*>(obj->parent) : 0;

		// The name of the obj is the type of the Behaviour
		Ogre::String type;
		if(!obj->name.empty())
		{
			type = obj->name;
		}
		else
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		// Get the factory
		ParticleBehaviourFactory* behaviourFactory = ParticleSystemManager::getSingletonPtr()->getBehaviourFactory(type);
		if (!behaviourFactory)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		// Create the Behaviour
		mBehaviour = ParticleSystemManager::getSingletonPtr()->createBehaviour(type);
		if (!mBehaviour)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		if (!obj->parent->context.isEmpty())
		{
			ParticleTechnique* technique = Ogre::any_cast<ParticleTechnique*>(obj->parent->context);
			technique->_addBehaviourTemplate(mBehaviour);
		}
		else
		{
			// It is an alias
			mBehaviour->setAliasName(parent->name);
			ParticleSystemManager::getSingletonPtr()->addAlias(mBehaviour);
		}

		// Set it in the context
		obj->context = Ogre::Any(mBehaviour);

		// Run through properties
		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			// No properties of its own
			if((*i)->type == Ogre::ANT_PROPERTY)
			{
				Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
				if (behaviourFactory->translateChildProperty(compiler, *i))
				{
					// Parsed the property by another translator; do nothing
				}
				else
				{
					errorUnexpectedProperty(compiler, prop);
				}
			}
			else if((*i)->type == Ogre::ANT_OBJECT)
			{
				if (behaviourFactory->translateChildObject(compiler, *i))
				{
					// Parsed the object by another translator; do nothing
				}
				else
				{
					processNode(compiler, *i);
				}
			}
            else
			{
				errorUnexpectedToken(compiler, *i);
			}
		}
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	void ParticleBehaviourWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Nothing yet
	}

}
