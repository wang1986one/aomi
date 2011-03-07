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

#include "ParticleUniverseExternTokens.h"

namespace ParticleUniverse
{
	/**************************************************************************
	 * ExternTranslator
	 *************************************************************************/
	ExternTranslator::ExternTranslator()
		:mExtern(0)
	{
	}
	//-------------------------------------------------------------------------
	void ExternTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		Ogre::ObjectAbstractNode* parent = obj->parent ? reinterpret_cast<Ogre::ObjectAbstractNode*>(obj->parent) : 0;

		// The name of the obj is the type of the Extern
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
		ExternFactory* externFactory = ParticleSystemManager::getSingletonPtr()->getExternFactory(type);
		if (!externFactory)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		// Create the Extern
		mExtern = ParticleSystemManager::getSingletonPtr()->createExtern(type);
		if (!mExtern)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		if (!obj->parent->context.isEmpty())
		{
			ParticleTechnique* technique = Ogre::any_cast<ParticleTechnique*>(obj->parent->context);
			technique->addExtern(mExtern);
		}
		else
		{
			// It is an alias
			mExtern->setAliasName(parent->name);
			ParticleSystemManager::getSingletonPtr()->addAlias(mExtern);
		}

		// The first value is the (optional) name
		Ogre::String name;
		if(!obj->values.empty())
		{
			getString(obj->values.front(), &name);
			mExtern->setName(name);
		}

		// Set it in the context
		obj->context = Ogre::Any(mExtern);

		// Run through properties
		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			// No properties of its own
			if((*i)->type == Ogre::ANT_PROPERTY)
			{
				Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
				if (externFactory->translateChildProperty(compiler, *i))
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
				if (externFactory->translateChildObject(compiler, *i))
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

	void ExternWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Nothing yet
	}

}
