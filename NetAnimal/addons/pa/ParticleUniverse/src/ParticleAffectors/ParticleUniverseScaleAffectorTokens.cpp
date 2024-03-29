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

#include "ParticleAffectors/ParticleUniverseScaleAffector.h"
#include "ParticleAffectors/ParticleUniverseScaleAffectorTokens.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool ScaleAffectorTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		ParticleAffector* af = Ogre::any_cast<ParticleAffector*>(prop->parent->context);
		ScaleAffector* affector = static_cast<ScaleAffector*>(af);

		if (prop->name == token[TOKEN_SCALE_XYZ_SCALE])
		{
			// Property: xyz_scale
			if (passValidateProperty(compiler, prop, token[TOKEN_SCALE_XYZ_SCALE], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					DynamicAttributeFixed* dynamicAttributeFixed = OGRE_NEW_T(DynamicAttributeFixed, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
					dynamicAttributeFixed->setValue(val);
					affector->setDynScaleXYZ(dynamicAttributeFixed);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_SCALE_X_SCALE])
		{
			// Property: x_scale
			if (passValidateProperty(compiler, prop, token[TOKEN_SCALE_X_SCALE], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					DynamicAttributeFixed* dynamicAttributeFixed = OGRE_NEW_T(DynamicAttributeFixed, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
					dynamicAttributeFixed->setValue(val);
					affector->setDynScaleX(dynamicAttributeFixed);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_SCALE_Y_SCALE])
		{
			// Property: y_scale
			if (passValidateProperty(compiler, prop, token[TOKEN_SCALE_Y_SCALE], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					DynamicAttributeFixed* dynamicAttributeFixed = OGRE_NEW_T(DynamicAttributeFixed, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
					dynamicAttributeFixed->setValue(val);
					affector->setDynScaleY(dynamicAttributeFixed);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_SCALE_Z_SCALE])
		{
			// Property: z_scale
			if (passValidateProperty(compiler, prop, token[TOKEN_SCALE_Z_SCALE], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					DynamicAttributeFixed* dynamicAttributeFixed = OGRE_NEW_T(DynamicAttributeFixed, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
					dynamicAttributeFixed->setValue(val);
					affector->setDynScaleZ(dynamicAttributeFixed);
					return true;
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool ScaleAffectorTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* child = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		ParticleAffector* af = Ogre::any_cast<ParticleAffector*>(child->parent->context);
		ScaleAffector* affector = static_cast<ScaleAffector*>(af);

		DynamicAttributeTranslator dynamicAttributeTranslator;
		if (child->cls == token[TOKEN_SCALE_XYZ_SCALE])
		{
			// Property: xyz_scale
			dynamicAttributeTranslator.translate(compiler, node);
			DynamicAttribute* dynamicAttribute = Ogre::any_cast<DynamicAttribute*>(child->context);
			affector->setDynScaleXYZ(dynamicAttribute);
			return true;
		}
		else if (child->cls == token[TOKEN_SCALE_X_SCALE])
		{
			// Property: x_scale
			dynamicAttributeTranslator.translate(compiler, node);
			DynamicAttribute* dynamicAttribute = Ogre::any_cast<DynamicAttribute*>(child->context);
			affector->setDynScaleX(dynamicAttribute);
			return true;
		}
		else if (child->cls == token[TOKEN_SCALE_Y_SCALE])
		{
			// Property: y_scale
			dynamicAttributeTranslator.translate(compiler, node);
			DynamicAttribute* dynamicAttribute = Ogre::any_cast<DynamicAttribute*>(child->context);
			affector->setDynScaleY(dynamicAttribute);
			return true;
		}
		else if (child->cls == token[TOKEN_SCALE_Z_SCALE])
		{
			// Property: z_scale
			dynamicAttributeTranslator.translate(compiler, node);
			DynamicAttribute* dynamicAttribute = Ogre::any_cast<DynamicAttribute*>(child->context);
			affector->setDynScaleZ(dynamicAttribute);
			return true;
		}

		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void ScaleAffectorWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a ScaleAffector
		const ScaleAffector* affector = static_cast<const ScaleAffector*>(element);

		// Write the header of the ScaleAffector
		serializer->writeLine(token[TOKEN_AFFECTOR], affector->getAffectorType(), affector->getName(), 8);
		serializer->writeLine("{", 8);

		// Write base attributes
		ParticleAffectorWriter::write(serializer, element);

		// Write own attributes
		DynamicAttributeFactory dynamicAttributeFactory;
		if (dynamicAttributeFactory._getDefaultValue(affector->getDynScaleXYZ()) != ScaleAffector::DEFAULT_XYZ_SCALE)
		{
			serializer->setKeyword(token[TOKEN_SCALE_XYZ_SCALE]);
			serializer->setIndentation(12);
			dynamicAttributeFactory.write(serializer, affector->getDynScaleXYZ());
		}
		if (dynamicAttributeFactory._getDefaultValue(affector->getDynScaleX()) != ScaleAffector::DEFAULT_X_SCALE)
		{
			serializer->setKeyword(token[TOKEN_SCALE_X_SCALE]);
			dynamicAttributeFactory.write(serializer, affector->getDynScaleX());
		}
		if (dynamicAttributeFactory._getDefaultValue(affector->getDynScaleY()) != ScaleAffector::DEFAULT_Y_SCALE)
		{
			serializer->setKeyword(token[TOKEN_SCALE_Y_SCALE]);
			dynamicAttributeFactory.write(serializer, affector->getDynScaleY());
		}
		if (dynamicAttributeFactory._getDefaultValue(affector->getDynScaleZ()) != ScaleAffector::DEFAULT_Z_SCALE)
		{
			serializer->setKeyword(token[TOKEN_SCALE_Z_SCALE]);
			dynamicAttributeFactory.write(serializer, affector->getDynScaleZ());
		}

		// Write the close bracket
		serializer->writeLine("}", 8);
	}

}
