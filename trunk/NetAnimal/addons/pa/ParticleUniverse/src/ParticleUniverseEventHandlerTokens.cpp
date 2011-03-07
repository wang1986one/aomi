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

#include "ParticleUniverseEventHandlerTokens.h"

namespace ParticleUniverse
{
	/**************************************************************************
	 * ParticleEventHandlerTranslator
	 *************************************************************************/
	ParticleEventHandlerTranslator::ParticleEventHandlerTranslator()
		:mParticleEventHandler(0)
	{
	}
	//-------------------------------------------------------------------------
	void ParticleEventHandlerTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		Ogre::ObjectAbstractNode* parent = obj->parent ? reinterpret_cast<Ogre::ObjectAbstractNode*>(obj->parent) : 0;

		// The name of the obj is the type of the ParticleEventHandler
		// Remark: This can be solved by using a listener, so that obj->values is filled with type + name. Something for later
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
		ParticleEventHandlerFactory* particleEventHandlerFactory = ParticleSystemManager::getSingletonPtr()->getEventHandlerFactory(type);
		if (!particleEventHandlerFactory)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		// Create the ParticleEventHandler
		mParticleEventHandler = ParticleSystemManager::getSingletonPtr()->createEventHandler(type);
		if (!mParticleEventHandler)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		if (!obj->parent->context.isEmpty())
		{
			ParticleObserver* observer = Ogre::any_cast<ParticleObserver*>(obj->parent->context);
			observer->addEventHandler(mParticleEventHandler);
		}
		else
		{
			// It is an alias
			mParticleEventHandler->setAliasName(parent->name);
			ParticleSystemManager::getSingletonPtr()->addAlias(mParticleEventHandler);
		}

		// The first value is the (optional) name
		Ogre::String name;
		if(!obj->values.empty())
		{
			getString(obj->values.front(), &name);
			mParticleEventHandler->setName(name);
		}

		// Set it in the context
		obj->context = Ogre::Any(mParticleEventHandler);

		// Run through properties
		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			// No properties of its own
			if((*i)->type == Ogre::ANT_PROPERTY)
			{
				Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
				if (particleEventHandlerFactory->translateChildProperty(compiler, *i))
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
				if (particleEventHandlerFactory->translateChildObject(compiler, *i))
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

	void ParticleEventHandlerWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Nothing yet
	}

}
