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

#include "ParticleUniverseRendererTokens.h"
#include "ParticleUniverseRenderer.h"
#include "ParticleRenderers/ParticleUniverseBillboardRenderer.h"


namespace ParticleUniverse
{
	/**************************************************************************
	 * RendererSetTranslator
	 *************************************************************************/
	void RendererSetTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		ParticleRenderer* renderer = Ogre::any_cast<ParticleRenderer*>(obj->parent->context);

		// Run through properties
		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			if((*i)->type == Ogre::ANT_PROPERTY)
			{
				Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
				if (prop->name == token[TOKEN_RENDERER_TEXCOORDS_DEFINE])
				{
					// Property: render_queue_group
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_TEXCOORDS_DEFINE], VAL_VECTOR4))
					{
						Ogre::Vector4 val;
						if(getVector4(prop->values.begin(), prop->values.end(), &val))
						{
							renderer->addTextureCoords(val.x, val.y, val.z, val.w);
						}
					}
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

	/**************************************************************************
	 * RendererTranslator
	 *************************************************************************/
	RendererTranslator::RendererTranslator()
		:mRenderer(0)
	{
	}
	//-------------------------------------------------------------------------
	void RendererTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());
		Ogre::ObjectAbstractNode* parent = obj->parent ? reinterpret_cast<Ogre::ObjectAbstractNode*>(obj->parent) : 0;

		// The name of the obj is the type of the Renderer
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
		ParticleRendererFactory* particleRendererFactory = ParticleSystemManager::getSingletonPtr()->getRendererFactory(type);
		if (!particleRendererFactory)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		// Create the Renderer
		mRenderer = ParticleSystemManager::getSingletonPtr()->createRenderer(type);
		if (!mRenderer)
		{
			compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, obj->file, obj->line);
			return;
		}

		if (!obj->parent->context.isEmpty())
		{
			ParticleTechnique* technique = Ogre::any_cast<ParticleTechnique*>(obj->parent->context);
			technique->setRenderer(mRenderer);
		}
		else
		{
			// It is an alias
			mRenderer->setAliasName(parent->name);
			ParticleSystemManager::getSingletonPtr()->addAlias(mRenderer);
		}

		// Set it in the context
		obj->context = Ogre::Any(mRenderer);

		// Run through properties
		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			// No properties of its own
			if((*i)->type == Ogre::ANT_PROPERTY)
			{
				Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
				if (prop->name == token[TOKEN_RENDERER_Q_GROUP])
				{
					// Property: render_queue_group
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_Q_GROUP], VAL_UINT))
					{
						Ogre::uint val = 0;
						if(getUInt(prop->values.front(), &val))
						{
							mRenderer->setRenderQueueGroup(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_RENDERER_SORTING])
				{
					// Property: sorting
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_SORTING], VAL_BOOL))
					{
						bool val = 0;
						if(getBoolean(prop->values.front(), &val))
						{
							mRenderer->setSorted(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_RENDERER_TEXCOORDS_ROWS])
				{
					// Property: texture_coords_rows
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_TEXCOORDS_ROWS], VAL_UINT))
					{
						Ogre::uint val = 0;
						if(getUInt(prop->values.front(), &val))
						{
							mRenderer->setTextureCoordsRows(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_RENDERER_TEXCOORDS_COLUMNS])
				{
					// Property: texture_coords_columns
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_TEXCOORDS_COLUMNS], VAL_UINT))
					{
						Ogre::uint val = 0;
						if(getUInt(prop->values.front(), &val))
						{
							mRenderer->setTextureCoordsColumns(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_RENDERER_USE_SOFT_PARTICLES])
				{
					// Property: use_soft_particles
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_USE_SOFT_PARTICLES], VAL_BOOL))
					{
						bool val = 0;
						if(getBoolean(prop->values.front(), &val))
						{
							mRenderer->setUseSoftParticles(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_RENDERER_SOFT_PARTICLES_CONTRAST_POWER])
				{
					// Property: soft_particles_contrast_power
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_SOFT_PARTICLES_CONTRAST_POWER], VAL_REAL))
					{
						Ogre::Real val = 0;
						if(getReal(prop->values.front(), &val))
						{
							mRenderer->setSoftParticlesContrastPower(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_RENDERER_SOFT_PARTICLES_SCALE])
				{
					// Property: soft_particles_scale
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_SOFT_PARTICLES_SCALE], VAL_REAL))
					{
						Ogre::Real val = 0;
						if(getReal(prop->values.front(), &val))
						{
							mRenderer->setSoftParticlesScale(val);
						}
					}
				}
				else if (prop->name == token[TOKEN_RENDERER_SOFT_PARTICLES_DELTA])
				{
					// Property: soft_particles_delta
					if (passValidateProperty(compiler, prop, token[TOKEN_RENDERER_SOFT_PARTICLES_DELTA], VAL_REAL))
					{
						Ogre::Real val = 0;
						if(getReal(prop->values.front(), &val))
						{
							mRenderer->setSoftParticlesDelta(val);
						}
					}
				}
				else if (particleRendererFactory->translateChildProperty(compiler, *i))
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
				Ogre::ObjectAbstractNode* child = reinterpret_cast<Ogre::ObjectAbstractNode*>((*i).get());
				if (child->cls == token[TOKEN_RENDERER_TEXCOORDS_SET])
				{
					// Property: soft_particles_delta
					RendererSetTranslator rendererSetTranslator;
					rendererSetTranslator.translate(compiler, *i);
				}
				else if (particleRendererFactory->translateChildObject(compiler, *i))
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

	void ParticleRendererWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// Cast the element to a ParticleRenderer
		const ParticleRenderer* renderer = static_cast<const ParticleRenderer*>(element);

		// Write base attributes
		if (renderer->getRenderQueueGroup() != ParticleRenderer::DEFAULT_RENDER_QUEUE_GROUP) serializer->writeLine(
			token[TOKEN_RENDERER_Q_GROUP], Ogre::StringConverter::toString(renderer->getRenderQueueGroup()), 12);
		if (renderer->isSorted() != ParticleRenderer::DEFAULT_SORTED) serializer->writeLine(
			token[TOKEN_RENDERER_SORTING], Ogre::StringConverter::toString(renderer->isSorted()), 12);
		if (renderer->getTextureCoordsRows() != ParticleRenderer::DEFAULT_TEXTURECOORDS_ROWS) serializer->writeLine(
			token[TOKEN_RENDERER_TEXCOORDS_ROWS], Ogre::StringConverter::toString(renderer->getTextureCoordsRows()), 12);
		if (renderer->getTextureCoordsColumns() != ParticleRenderer::DEFAULT_TEXTURECOORDS_COLUMNS) serializer->writeLine(
			token[TOKEN_RENDERER_TEXCOORDS_COLUMNS], Ogre::StringConverter::toString(renderer->getTextureCoordsColumns()), 12);

		const Ogre::vector<Ogre::FloatRect*>::type uvList = renderer->getTextureCoords();
		if (!uvList.empty())
		{
			serializer->writeLine(token[TOKEN_RENDERER_TEXCOORDS_SET], 12);
			serializer->writeLine("{", 12);
			Ogre::vector<Ogre::FloatRect*>::type::const_iterator it;
			Ogre::vector<Ogre::FloatRect*>::type::const_iterator itEnd = uvList.end();
			for (it = uvList.begin(); it != itEnd; ++it)
			{
				serializer->writeLine(token[TOKEN_RENDERER_TEXCOORDS_DEFINE], Ogre::StringConverter::toString(*it), 12);
			}
			serializer->writeLine("}", 12);
		}

		if (renderer->getUseSoftParticles() != ParticleRenderer::DEFAULT_USE_SOFT_PARTICLES) serializer->writeLine(
			token[TOKEN_RENDERER_USE_SOFT_PARTICLES], Ogre::StringConverter::toString(renderer->getUseSoftParticles()), 12);
		if (renderer->getSoftParticlesContrastPower() != ParticleRenderer::DEFAULT_SOFT_PARTICLES_CONTRAST_POWER) serializer->writeLine(
			token[TOKEN_RENDERER_SOFT_PARTICLES_CONTRAST_POWER], Ogre::StringConverter::toString(renderer->getSoftParticlesContrastPower()), 12);
		if (renderer->getSoftParticlesScale() != ParticleRenderer::DEFAULT_SOFT_PARTICLES_SCALE) serializer->writeLine(
			token[TOKEN_RENDERER_SOFT_PARTICLES_SCALE], Ogre::StringConverter::toString(renderer->getSoftParticlesScale()), 12);
		if (renderer->getSoftParticlesDelta() != ParticleRenderer::DEFAULT_SOFT_PARTICLES_DELTA) serializer->writeLine(
			token[TOKEN_RENDERER_SOFT_PARTICLES_DELTA], Ogre::StringConverter::toString(renderer->getSoftParticlesDelta()), 12);
	}

}
