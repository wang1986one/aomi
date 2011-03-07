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

#include "OgreScriptLexer.h"
#include "OgreScriptParser.h"

namespace ParticleUniverse
{
	//-------------------------------------------------------------------------
	ScriptTranslator::ScriptTranslator(void)
	{
	}
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	bool ScriptTranslator::getVector2(Ogre::AbstractNodeList::const_iterator i, 
		Ogre::AbstractNodeList::const_iterator end, 
		Ogre::Vector2* result, 
		int maxEntries)
	{
		int n = 0;
		while(i != end && n < maxEntries)
		{
			float v = 0;
			if(getFloat(*i, &v))
			{
				switch(n)
				{
				case 0:
					result->x = v;
					break;
				case 1:
					result->y = v;
					break;
				}
			}
			else
			{
				return false;
			}
			++n;
			++i;
		}
		// return error if we found less than xy before end, unless constrained
		return (n >= 2 || n == maxEntries);
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::getVector3(Ogre::AbstractNodeList::const_iterator i, 
		Ogre::AbstractNodeList::const_iterator end, 
		Ogre::Vector3* result, 
		int maxEntries)
	{
		int n = 0;
		while(i != end && n < maxEntries)
		{
			float v = 0;
			if(getFloat(*i, &v))
			{
				switch(n)
				{
				case 0:
					result->x = v;
					break;
				case 1:
					result->y = v;
					break;
				case 2:
					result->z = v;
					break;
				}
			}
			else
			{
				return false;
			}
			++n;
			++i;
		}
		// return error if we found less than xyz before end, unless constrained
		return (n >= 3 || n == maxEntries);
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::getVector4(Ogre::AbstractNodeList::const_iterator i, 
		Ogre::AbstractNodeList::const_iterator end, 
		Ogre::Vector4* result, 
		int maxEntries)
	{
		int n = 0;
		while(i != end && n < maxEntries)
		{
			float v = 0;
			if(getFloat(*i, &v))
			{
				switch(n)
				{
				case 0:
					result->x = v;
					break;
				case 1:
					result->y = v;
					break;
				case 2:
					result->z = v;
					break;
				case 3:
					result->w = v;
					break;
				}
			}
			else
			{
				return false;
			}
			++n;
			++i;
		}
		// return error if we found less than xyz before end, unless constrained
		return (n >= 4 || n == maxEntries);
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::getQuaternion(Ogre::AbstractNodeList::const_iterator i, 
		Ogre::AbstractNodeList::const_iterator end, 
		Ogre::Quaternion* result, 
		int maxEntries)
	{
		int n = 0;
		while(i != end && n < maxEntries)
		{
			float v = 0;
			if(getFloat(*i, &v))
			{
				switch(n)
				{
				case 0:
					result->w = v;
					break;
				case 1:
					result->x = v;
					break;
				case 2:
					result->y = v;
					break;
				case 3:
					result->z = v;
					break;
				}
			}
			else
			{
				return false;
			}
			++n;
			++i;
		}
		// return error if we found less than xyz before end, unless constrained
		return (n >= 4 || n == maxEntries);
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidateProperty(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop, 
		const Ogre::String& token,
		ValidationType validationType)
	{
		if (!passValidatePropertyNoValues(compiler, prop, token))
		{
			return false;
		}

		bool ret = true;
		switch(validationType)
		{
			case VAL_BOOL:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 1) && passValidatePropertyValidBool(compiler, prop);
			}
			break;
			case VAL_COLOURVALUE:
			{
				ret = passValidatePropertyNumberOfValuesRange(compiler, prop, token, 3, 4);
			}
			break;
			case VAL_INT:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 1) && passValidatePropertyValidInt(compiler, prop);
			}
			break;
			case VAL_QUATERNION:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 4) && passValidatePropertyValidQuaternion(compiler, prop);
			}
			break;
			case VAL_REAL:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 1) && passValidatePropertyValidReal(compiler, prop);
			}
			break;
			case VAL_STRING:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 1);
			}
			break;
			case VAL_UINT:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 1) && passValidatePropertyValidUint(compiler, prop);
			}
			break;
			case VAL_VECTOR2:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 2) && passValidatePropertyValidVector2(compiler, prop);
			}
			break;
			case VAL_VECTOR3:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 3) && passValidatePropertyValidVector3(compiler, prop);
			}
			break;
			case VAL_VECTOR4:
			{
				ret = passValidatePropertyNumberOfValues(compiler, prop, token, 4) && passValidatePropertyValidVector4(compiler, prop);
			}
			break;
		}

		return ret;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyNoValues(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop, 
		const Ogre::String& token)
	{
		if(prop->values.empty())
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line, "PU Compiler: No values found for " + token + ".");
			return false;
		}
		return true;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyNumberOfValues(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop, 
		const Ogre::String& token,
		Ogre::ushort numberOfValues)
	{
		if(prop->values.size() > numberOfValues)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_FEWERPARAMETERSEXPECTED, 
				prop->file, 
				prop->line, 
				"PU Compiler: " + token + " must have " + Ogre::StringConverter::toString(numberOfValues) + " argument(s).");
			return false;
		}
		return true;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyNumberOfValuesRange(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop, 
		const Ogre::String& token,
		Ogre::ushort minNumberOfValues,
		Ogre::ushort maxNumberOfValues)
	{
		if(prop->values.size() < minNumberOfValues || prop->values.size() > maxNumberOfValues)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_FEWERPARAMETERSEXPECTED, 
				prop->file, 
				prop->line, 
				"PU Compiler: " + token + " must have between" + 
				Ogre::StringConverter::toString(minNumberOfValues) + 
				" and " +
				Ogre::StringConverter::toString(maxNumberOfValues) +
				" argument(s).");
			return false;
		}
		return true;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidReal(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		Ogre::Real val = 0.0f;
		if(getReal(prop->values.front(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid Real");
		return false;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidInt(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		int val = 0;
		if(getInt(prop->values.front(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid int");
		return false;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidUint(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		Ogre::uint val = 0;
		if(getUInt(prop->values.front(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid uint");
		return false;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidBool(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		bool val;
		if(getBoolean(prop->values.front(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid bool");
		return false;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidVector2(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		Ogre::Vector2 val;
		if(getVector2(prop->values.begin(), prop->values.end(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid Vector2");
		return false;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidVector3(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		Ogre::Vector3 val;
		if(getVector3(prop->values.begin(), prop->values.end(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid Vector3");
		return false;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidVector4(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		Ogre::Vector4 val;
		if(getVector4(prop->values.begin(), prop->values.end(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid Vector4");
		return false;
	}
	//-------------------------------------------------------------------------
	bool ScriptTranslator::passValidatePropertyValidQuaternion(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		Ogre::Quaternion val;
		if(getQuaternion(prop->values.begin(), prop->values.end(), &val))
		{
			return true;
		}

		compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line,
			"PU Compiler: " + prop->values.front()->getValue() + " is not a valid Quaternion");
		return false;
	}
	//-------------------------------------------------------------------------
	void ScriptTranslator::errorUnexpectedToken(Ogre::ScriptCompiler* compiler, 
		Ogre::AbstractNodePtr token)
	{
		compiler->addError(Ogre::ScriptCompiler::CE_UNEXPECTEDTOKEN, token.getPointer()->file, token.getPointer()->line, 
			"PU Compiler: token is not recognized");
	}
	//-------------------------------------------------------------------------
	void ScriptTranslator::errorUnexpectedProperty(Ogre::ScriptCompiler* compiler, 
		Ogre::PropertyAbstractNode* prop)
	{
		compiler->addError(Ogre::ScriptCompiler::CE_UNEXPECTEDTOKEN, prop->file, prop->line, 
			"PU Compiler: token \"" + prop->name + "\" is not recognized");
	}
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

}
