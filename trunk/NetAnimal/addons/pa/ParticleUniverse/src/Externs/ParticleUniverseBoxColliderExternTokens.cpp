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

#include "Externs/ParticleUniverseBoxColliderExtern.h"
#include "Externs/ParticleUniverseBoxColliderExternTokens.h"
#include "ParticleAffectors/ParticleUniverseBaseColliderTokens.h"

namespace ParticleUniverse
{
	bool BoxColliderExternTranslator::translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>(node.get());
		Extern* ex = Ogre::any_cast<Extern*>(prop->parent->context);
		BoxColliderExtern* externObject = static_cast<BoxColliderExtern*>(ex);
//		BaseColliderTranslator baseColliderTranslator;

		if (prop->name == token[TOKEN_BOX_WIDTH])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_BOX_WIDTH], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setWidth(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_BOXCOLL_WIDTH])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_BOXCOLL_WIDTH], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setWidth(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_BOX_HEIGHT])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_BOXCOLL_HEIGHT], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setHeight(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_BOXCOLL_HEIGHT])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_BOXCOLL_HEIGHT], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setHeight(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_BOX_DEPTH])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_BOXCOLL_DEPTH], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setDepth(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_BOXCOLL_DEPTH])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_BOXCOLL_DEPTH], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setDepth(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_DISTANCE_THRESHOLD])
		{
			// Property: distance_threshold
			if (passValidateProperty(compiler, prop, token[TOKEN_DISTANCE_THRESHOLD], VAL_REAL))
			{
				Ogre::Real val;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setDistanceThreshold(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_EXTERN_DISTANCE_THRESHOLD])
		{
			// Property: attachable_distance_threshold (deprecated and replaced by 'distance_threshold')
			if (passValidateProperty(compiler, prop, token[TOKEN_EXTERN_DISTANCE_THRESHOLD], VAL_REAL))
			{
				Ogre::Real val;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setDistanceThreshold(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_FRICTION])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_COLLIDER_FRICTION], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setFriction(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_BOUNCYNESS])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_COLLIDER_BOUNCYNESS], VAL_REAL))
			{
				Ogre::Real val = 0.0f;
				if(getReal(prop->values.front(), &val))
				{
					externObject->setBouncyness(val);
					return true;
				}
			}
		}
		else if (prop->name == token[TOKEN_INTERSECTION])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_COLLIDER_INTERSECTION], VAL_STRING))
			{
				Ogre::String val;
				if(getString(prop->values.front(), &val))
				{
					if (val == token[TOKEN_COLLIDER_INTERSECTION_POINT])
					{
						externObject->setIntersectionType(BaseCollider::IT_POINT);
						return true;
					}
					else if (val == token[TOKEN_COLLIDER_INTERSECTION_BOX])
					{
						externObject->setIntersectionType(BaseCollider::IT_BOX);
						return true;
					}
				}
			}
		}
		else if (prop->name == token[TOKEN_COLLIDER_COLLISION_TYPE])
		{
			if (passValidateProperty(compiler, prop, token[TOKEN_COLLIDER_COLLISION_TYPE], VAL_STRING))
			{
				Ogre::String val;
				if(getString(prop->values.front(), &val))
				{
					if (val == token[TOKEN_COLLIDER_BOUNCE])
					{
						externObject->setCollisionType(BaseCollider::CT_BOUNCE);
						return true;
					}
					else if (val == token[TOKEN_COLLIDER_FLOW])
					{
						externObject->setCollisionType(BaseCollider::CT_FLOW);
						return true;
					}
				}
			}
		}

		return false;
	}
	//-----------------------------------------------------------------------
	bool BoxColliderExternTranslator::translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		// No objects
		return false;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void BoxColliderExternWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a BoxColliderExtern
		const Extern* externObject = static_cast<const Extern*>(element);
		const BoxColliderExtern* boxColliderExtern = static_cast<const BoxColliderExtern*>(externObject);
		serializer->writeLine(token[TOKEN_EXTERN], externObject->getExternType(), externObject->getName(), 8);
		serializer->writeLine("{", 8);

		// Write base attributes
		ExternWriter::write(serializer, element);
		AttachableWriter::write(serializer, element);

		// Write own attributes
		if (boxColliderExtern->getWidth() != BoxCollider::DEFAULT_WIDTH) serializer->writeLine(
			token[TOKEN_BOX_WIDTH], Ogre::StringConverter::toString(boxColliderExtern->getWidth()), 12);
		if (boxColliderExtern->getHeight() != BoxCollider::DEFAULT_HEIGHT) serializer->writeLine(
			token[TOKEN_BOX_HEIGHT], Ogre::StringConverter::toString(boxColliderExtern->getHeight()), 12);
		if (boxColliderExtern->getDepth() != BoxCollider::DEFAULT_DEPTH) serializer->writeLine(
			token[TOKEN_BOX_DEPTH], Ogre::StringConverter::toString(boxColliderExtern->getDepth()), 12);
		if (boxColliderExtern->getFriction() != BaseCollider::DEFAULT_FRICTION) serializer->writeLine(
			token[TOKEN_FRICTION], Ogre::StringConverter::toString(boxColliderExtern->getFriction()), 12);
		if (boxColliderExtern->getBouncyness() != BaseCollider::DEFAULT_BOUNCYNESS) serializer->writeLine(
			token[TOKEN_BOUNCYNESS], Ogre::StringConverter::toString(boxColliderExtern->getBouncyness()), 12);
		if (boxColliderExtern->getIntersectionType() != BaseCollider::DEFAULT_INTERSECTION_TYPE) 
		{
			Ogre::String intersectionType = token[TOKEN_COLLIDER_INTERSECTION_POINT];
			if (boxColliderExtern->getIntersectionType() == BaseCollider::IT_BOX) intersectionType = token[TOKEN_COLLIDER_INTERSECTION_BOX];
			serializer->writeLine(token[TOKEN_COLLIDER_INTERSECTION], intersectionType, 12);
		}
		if (boxColliderExtern->getCollisionType() != BaseCollider::DEFAULT_COLLISION_TYPE) 
		{
			Ogre::String collisionType = token[TOKEN_COLLIDER_BOUNCE];
			if (boxColliderExtern->getCollisionType() == BaseCollider::CT_FLOW) collisionType = token[TOKEN_COLLIDER_FLOW];
			else if (boxColliderExtern->getCollisionType() == BaseCollider::CT_NONE) collisionType = token[TOKEN_COLLIDER_NONE];
			serializer->writeLine(token[TOKEN_COLLIDER_COLLISION_TYPE], collisionType, 12);
		}

		// Write the close bracket
		serializer->writeLine("}", 8);
	}

}
