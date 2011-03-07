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

#include "ParticleUniverseAliasTokens.h"

namespace ParticleUniverse
{
	/**************************************************************************
	 * AliasTranslator
	 *************************************************************************/
	AliasTranslator::AliasTranslator()
	{
	}
	//-------------------------------------------------------------------------
	void AliasTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		if(obj->name.empty())
			compiler->addError(Ogre::ScriptCompiler::CE_OBJECTNAMEEXPECTED, obj->file, obj->line);

		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			if((*i)->type == Ogre::ANT_OBJECT)
			{
				processNode(compiler, *i);
			}
		}
	}

}
