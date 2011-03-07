#include "config.h"
#include <orz/Framework_Base/FrameworkBase.h>
#include <orz/View_OGRE3D/OgreUpdateInRenderingQueued.h>
#include <OGRE/ogre.h>
#include <orz/Toolkit_Base/EventSystem/EventWorld.h>
#include <ParticleUniverse/ParticleUniverseSystemManager.h>
#include <ParticleUniverse/ParticleUniverseSystem.h>

#include <orz/Toolkit_Component_Task/Component/ComponentInterface.h>	
#include <orz/Toolkit_Component_Task/Component/Component.h>	
#include <orz/Toolkit_Component_Task/Component/ComponentFactories.h>
#include "CParticleInterface.h"

namespace Orz
{
	//这里 我们把OIS输入管理器的update放入到Ogre渲染过程中update，这样更好的利用Ogre渲染过程中的时间。继而提高一些效率。
	typedef UpdateInOgreRenderingQueued<OISInputManager> InputUpdateInOgre;
	SYSTEMUNIT_BEGIN(InputUpdateInOgre) 
		SYSTEMUNIT_INIT 
		SYSTEMUNIT_SHUTDOWN 
		SYSTEMUNIT_END(InputUpdateInOgre)


}

ParticleUniverse::ParticleSystemManager* mParticleSystemManager = NULL; 
ParticleUniverse::ParticleSystem* mySystem = NULL; 

int main(int argc, char **argv)
{

	using namespace Orz;

#ifdef _smallsystem_
	SystemPtr system(new SystemList<boost::mpl::list<SimpleTimerManager, PluginsManager> >());
#else
	SystemPtr system(new SystemList<boost::mpl::list</*LogSystem, */SimpleTimerManager, OgreGraphicsManager ,CEGUIManager, InputUpdateInOgre, FmodSoundManager, PluginsManager, EventWorldUpdate> >());
#endif

	LogicConfiger::LogicFacadePtr logic(new LogicConfiger::LogicFacade());

	if(argc == 1)
	{
		logic->building(LogicConfiger::XMLBuilder("orzconfig.xml"));
	}
	else
	{
		logic->building(LogicConfiger::ArgBuilder(argc, argv));
	}

	//SystemInterface::getSingleton().setParame<bool>("SILENT", true);
	//SystemInterface::getSingleton().setParame<bool>("NOESC", true);
	//SystemInterface::getSingleton().setParame<bool>("OGRE_NO_OUT", true);
	SystemInterface::getSingleton().setParame<bool>("CEGUI_LOGO", true);
	if(system->init())
	{

		PluginsManager::getSingleton().loadPlugin("PUComponent");
		{

			
			ComponentPtr comp = ComponentFactories::getInstance().create("PUComponent");
			CParticleInterface * particle = comp->queryInterface<CParticleInterface>();


			Ogre::SceneManager * mSceneMgr = Orz::OgreGraphicsManager::getSingleton().getSceneManager();

			//mParticleSystemManager = ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
			////mySystem = mParticleSystemManager->createParticleSystem("Test", mSceneMgr); 
			//mySystem = mParticleSystemManager->createParticleSystem("mySystem", "explosionSystem", mSceneMgr); 

			Ogre::SceneNode * sn  = mSceneMgr->getRootSceneNode()->createChildSceneNode("Particle",Ogre::Vector3(0,0,0)); 
			//sn->attachObject("explosionSystem", mySystem); 
			Orz::OgreGraphicsManager::getSingleton().getCamera()->lookAt(Ogre::Vector3(0,0,-1000));
			particle->enable("explosionSystem",sn);
			particle->update(0.015f);
			system->reset();
			while(system->isRunning())
			{
				if(!system->update(system->getInterval()))
				{
					break;
				}
			}
			particle->disable();
		}
		PluginsManager::getSingleton().unloadPlugin("PUComponent");


		//if(logic->load(EventWorld::Parameter()))
		//{

		//	system->run();
		//	logic->unload();
		//}
		system->shutdown();
	}
	__ORZ_TRACE_PRINT__

		return 0;
}