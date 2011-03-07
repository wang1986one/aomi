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

#include "ParticleEventHandlers/ParticleUniverseDoScaleEventHandler.h"
#include "ParticleEventHandlers/ParticleUniverseDoScaleEventHandlerTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool DoScaleEventHandlerTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		ParticleEventHandler* evt = Ogre::any_cast<ParticleEventHandler*>(prop->parent->context);
		DoScaleEventHandler* handler = static_cast<DoScaleEventHandler*>(evt);

		if (prop->name == token[TOKEN_DOSCALE_FRACTION])
		{
			// Property: scale_fraction
			if (passValidateProperty(compiler, prop, token[TOKEN_DOSCALE_FRACTION], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					handler->setScaleFraction(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_DOSCALE_TYPE])
		{
			// Property: scale_type
			if (passValidateProperty(compiler, prop, token[TOKEN_DOSCALE_TYPE], VAL_STRING))
			{
				Ogre::String val;
				if(getString(prop->values.front(), &val))
				{
					if (val == token[TOKEN_TIME_TO_LIVE] || val == token[TOKEN_DOSCALE_TIME_TO_LIVE])
					{
						handler->setScaleType(DoScaleEventHandler::ST_TIME_TO_LIVE);
						return true;
					}
					else if (val == token[TOKEN_VELOCITY] || val == token[TOKEN_DOSCALE_VELOCITY])
					{
						handler->setScaleType(DoScaleEventHandler::ST_VELOCITY);
						return true;
					}
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool DoScaleEventHandlerTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		// No objects
		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void DoScaleEventHandlerWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a DoScaleEventHandler
		const DoScaleEventHandler* eventHandler = static_cast<const DoScaleEventHandler*>(element);

		// Write the header of the DoScaleEventHandler
		serializer->writeLine(token[TOKEN_HANDLER], eventHandler->getEventHandlerType(), eventHandler->getName(), 12);
		serializer->writeLine("{", 12);

		// Write base attributes
		ParticleEventHandlerWriter::write(serializer, element);

		// Write own attributes
		if (eventHandler->getScaleFraction() != DoScaleEventHandler::DEFAULT_SCALE_FRACTION) serializer->writeLine(
			token[TOKEN_DOSCALE_FRACTION], Ogre::StringConverter::toString(eventHandler->getScaleFraction()), 16);
		Ogre::String scaleType = token[TOKEN_DOSCALE_TIME_TO_LIVE];
		if (eventHandler->getScaleType() == DoScaleEventHandler::ST_VELOCITY) scaleType = token[TOKEN_DOSCALE_VELOCITY];
		serializer->writeLine(token[TOKEN_DOSCALE_TYPE], scaleType, 16);

		// Write the close bracket
		serializer->writeLine("}", 12);
	}

}
