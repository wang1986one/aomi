/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_INTERPARTICLE_COLLIDER_FACTORY_H__
#define __PU_INTERPARTICLE_COLLIDER_FACTORY_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseInterParticleColliderTokens.h"
#include "ParticleUniverseInterParticleCollider.h"
#include "ParticleUniverseAffectorFactory.h"

namespace ParticleUniverse
{
	/** Factory class responsible for creating the InterParticleCollider.
    */
	class _ParticleUniverseExport InterParticleColliderFactory : public ParticleAffectorFactory
	{
		public:
			InterParticleColliderFactory(void){};
	        virtual ~InterParticleColliderFactory(void){};

			/** See ParticleAffectorFactory */
			Ogre::String getAffectorType(void) const
			{
				return "InterParticleCollider";
			}

			/** See ParticleAffectorFactory  */
			ParticleAffector* createAffector(void)
			{
				return _createAffector<InterParticleCollider>();
			}

			/** See ScriptReader */
			virtual bool translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
			{
				return mInterParticleColliderTranslator.translateChildProperty(compiler, node);
			};

			/** See ScriptReader */
			virtual bool translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
			{
				return mInterParticleColliderTranslator.translateChildObject(compiler, node);
			};

			/*  */
			virtual void write(ParticleScriptSerializer* serializer , const IElement* element)
			{
				// Delegate
				mInterParticleColliderWriter.write(serializer, element);
			}

		protected:
			InterParticleColliderWriter mInterParticleColliderWriter;
			InterParticleColliderTranslator mInterParticleColliderTranslator;
	};

}
#endif
