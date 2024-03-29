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

#include "ParticleUniversePrerequisites.h"
#include "OgreRoot.h"
#include "ParticleUniversePlugin.h"

namespace ParticleUniverse
{
	ParticleUniversePlugin* plugin;
	//-----------------------------------------------------------------------
	extern "C" void _ParticleUniverseExport dllStartPlugin(void) throw()
	{
		plugin = OGRE_NEW ParticleUniversePlugin();
		Ogre::Root::getSingleton().installPlugin(plugin);
	}

	//-----------------------------------------------------------------------
	extern "C" void _ParticleUniverseExport dllStopPlugin(void)
	{
		Ogre::Root::getSingleton().uninstallPlugin(plugin);
		OGRE_DELETE plugin;
	}

}
