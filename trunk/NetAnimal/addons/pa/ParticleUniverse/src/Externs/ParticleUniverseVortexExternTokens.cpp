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

#include "Externs/ParticleUniverseVortexExtern.h"
#include "Externs/ParticleUniverseVortexExternTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool VortexExternTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		Extern* ex = Ogre::any_cast<Extern*>(prop->parent->context);
		VortexExtern* externObject = static_cast<VortexExtern*>(ex);

		if (prop->name == token[TOKEN_ROTATION_AXIS])
		{
			// Property: rotation_axis
			if (passValidateProperty(compiler, prop, token[TOKEN_ROTATION_AXIS], VAL_VECTOR3))
			{
				Ogre::Vector3 val;
				if(getVector3(prop->values.begin(), prop->values.end(), &val))
				{
					externObject->setRotationVector(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_VORTEX_ROTATION_VECTOR])
		{
			// Property: vortex_aff_vector
			if (passValidateProperty(compiler, prop, token[TOKEN_SCENE_SCALE], VAL_VECTOR3))
			{
				Ogre::Vector3 val;
				if(getVector3(prop->values.begin(), prop->values.end(), &val))
				{
					externObject->setRotationVector(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_ROTATION_SPEED])
		{
			// Property: rotation_speed
			if (passValidateProperty(compiler, prop, token[TOKEN_VORTEX_ROTATION_SPEED], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					DynamicAttributeFixed* dynamicAttributeFixed = OGRE_NEW_T(DynamicAttributeFixed, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
					dynamicAttributeFixed->setValue(val);
					externObject->setRotationSpeed(dynamicAttributeFixed);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_VORTEX_ROTATION_SPEED])
		{
			// Property: vortex_aff_speed
			if (passValidateProperty(compiler, prop, token[TOKEN_VORTEX_ROTATION_SPEED], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					DynamicAttributeFixed* dynamicAttributeFixed = OGRE_NEW_T(DynamicAttributeFixed, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
					dynamicAttributeFixed->setValue(val);
					externObject->setRotationSpeed(dynamicAttributeFixed);
					return true;
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool VortexExternTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* child = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		Extern* ex = Ogre::any_cast<Extern*>(child->parent->context);
		VortexExtern* externObject = static_cast<VortexExtern*>(ex);

		DynamicAttributeTranslator dynamicAttributeTranslator;
		if (child->cls == token[TOKEN_ROTATION_SPEED])
		{
			// Property: rotation_speed
			dynamicAttributeTranslator.translate(compiler, node);
			DynamicAttribute* dynamicAttribute = Ogre::any_cast<DynamicAttribute*>(child->context);
			externObject->setRotationSpeed(dynamicAttribute);
			return true;
		}
		else if (child->cls == token[TOKEN_VORTEX_ROTATION_SPEED])
		{
			// Property: vortex_aff_speed
			dynamicAttributeTranslator.translate(compiler, node);
			DynamicAttribute* dynamicAttribute = Ogre::any_cast<DynamicAttribute*>(child->context);
			externObject->setRotationSpeed(dynamicAttribute);
			return true;
		}

		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void VortexExternWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a VortexExtern
		const Extern* externObject = static_cast<const Extern*>(element);
		const VortexExtern* vortexExtern = static_cast<const VortexExtern*>(externObject);
		serializer->writeLine(token[TOKEN_EXTERN], externObject->getExternType(), externObject->getName(), 8);
		serializer->writeLine("{", 8);

		// Write base attributes
		ExternWriter::write(serializer, element);
		AttachableWriter::write(serializer, element);

		// Write own attributes
		if (vortexExtern->getRotationVector() != VortexAffector::DEFAULT_ROTATION_VECTOR) serializer->writeLine(
			token[TOKEN_ROTATION_AXIS], Ogre::StringConverter::toString(vortexExtern->getRotationVector()), 12);
		DynamicAttributeFactory dynamicAttributeFactory;
		if (dynamicAttributeFactory._getDefaultValue(vortexExtern->getRotationSpeed()) != VortexAffector::DEFAULT_ROTATION_SPEED)
		{
			serializer->setKeyword(token[TOKEN_ROTATION_SPEED]);
			serializer->setIndentation(12);
			dynamicAttributeFactory.write(serializer, vortexExtern->getRotationSpeed());
		}

		// Write the close bracket
		serializer->writeLine("}", 8);
	}

}
