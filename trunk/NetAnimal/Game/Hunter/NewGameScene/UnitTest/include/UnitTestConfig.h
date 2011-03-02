#ifndef __Orz_UnitTestConfig_Config__
#define __Orz_UnitTestConfig_Config__
using namespace Orz;
//
//用于作为测试环境的Orz框架
struct UnitTestEnvironmen{
	UnitTestEnvironmen(void) 
	{ 

		using namespace Orz;
		//logMgr.reset(new TestLogSystem());	
		system.reset(new SystemList<boost::mpl::list<AsioTimerManager, OgreGraphicsManager, CEGUIManager, OISInputManager, FmodSoundManager, PluginsManager> >());
		
		SystemInterface::getSingleton().setParame<bool>("OGRE_NO_OUT", true);
	//	SystemInterface::getSingleton().setParame<bool>("SILENT", true);
		
		system->init();
		

		Ogre::ConfigFile cf;
		cf.load("HunterScene.cfg");

		Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
		Ogre::String sec, type, arch;

		// go through all specified resource groups
		while (seci.hasMoreElements())
		{
			sec = seci.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
			Ogre::ConfigFile::SettingsMultiMap::iterator i;

			// go through all resource paths
			for (i = settings->begin(); i != settings->end(); i++)
			{
				type = i->first;
				arch = i->second;


				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);

				//Ogre::ResourceGroupManager::getSingleton().addResourceLocation("D:/Test", "FileSystem", "General");
			}


		}

		Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("HunterScene");

		_timer = ITimerManager::getSingleton().createTimer(boost::bind(&UnitTestEnvironmen::step, this));
		_timer->start(0.015f);


		

		test_log.reset(new std::stringstream());

		{
		
			namespace logging = boost::log;
			namespace fmt = boost::log::formatters;
			namespace flt = boost::log::filters;
			namespace sinks = boost::log::sinks;
			namespace attrs = boost::log::attributes;
			namespace src = boost::log::sources;
			namespace keywords = boost::log::keywords;
			using boost::shared_ptr;



			
			// For now we only create a text output sink:
			typedef sinks::synchronous_sink< sinks::text_ostream_backend > text_sink;
			shared_ptr< text_sink > pSink(new text_sink);

		
			 
			{
				text_sink::locked_backend_ptr pBackend = pSink->locked_backend();
				
				pBackend->add_stream(test_log);
			}
			
		
			Orz::LogSystem::getInstance().addSink(pSink);
			
			pSink->set_filter( flt::attr< Orz::LogSystem::severity_level >("Severity", std::nothrow) == Orz::LogSystem::trace ); 
		}
		

		PluginsManager::getSingleton().loadPlugin("NewGameSceneComponent");
		PluginsManager::getSingleton().loadPlugin("GameDiamondComponent");
			{
				const Ogre::ResourceGroupManager::LocationList  & list = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList("sound");
		
				Orz::ISoundManager::getSingleton().setResourcesPath((*list.begin())->archive->getName());
			}
	}

	~UnitTestEnvironmen(void)
	{ 
		PluginsManager::getSingleton().unloadPlugin("NewGameSceneComponent");
		_timer.reset();
		system->shutdown();
		system.reset();
	}

	
	bool step(void)
	{
		Orz::SystemInterface::getSingleton().exit();
		return true;
	}
	static SystemPtr system;
	//static boost::shared_ptr<TestLogSystem> logMgr;
	boost::shared_ptr<Timer> _timer;
	static boost::shared_ptr< std::stringstream > test_log;
};
// Orz系统
SystemPtr UnitTestEnvironmen::system;
//
boost::shared_ptr< std::stringstream > UnitTestEnvironmen::test_log;
/// 测试日志
//boost::shared_ptr<TestLogSystem> UnitTestEnvironmen::logMgr;
//
//配置全局的环境
BOOST_GLOBAL_FIXTURE( UnitTestEnvironmen )
//
//
//
//
#endif