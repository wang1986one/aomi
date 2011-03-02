#ifndef __Orz_UnitTest_Config__
#define __Orz_UnitTest_Config__
#include <boost/test/unit_test.hpp>


#include <orz/Toolkit_Base/LogManager.h>
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include <orz/Framework_Base/Logic.h>
#include <orz/Framework_Base/FrameworkBase.h>
#include <orz/View_SingleChip/SingleChipManager.h>
#include <orz/View_OIS/OISInputManager.h>
#include <orz/View_Fmod/FmodSoundManager.h>
#include <orz/View_CEGUI/CEGUIManager.h>
#include <orz/Toolkit_Base/TimerManager.h>
#include <orz/Toolkit_Base/PluginsManager.h>
#include <orz/Toolkit_Base/UnitTestTools.h>
using namespace Orz;

///用于作为测试环境的Orz框架
struct UnitTestEnvironmen{
	UnitTestEnvironmen(void) 
	{ 
		//logMgr.reset(new TestLogSystem());	
		system.reset(new SystemList<boost::mpl::list<SimpleTimerManager, OgreGraphicsManager, CEGUIManager, OISInputManager, FmodSoundManager, PluginsManager, SingleChipManager> >());

		SystemInterface::getSingleton().setParame<bool>("OGRE_NO_OUT", true);
		
		SystemInterface::getSingleton().setParame<std::string>("SingleChip_Port", std::string("COM3"));
		SystemInterface::getSingleton().setParame<int>("SingleChip_BaudRate", 19200);
		system->init();
		_timer = ITimerManager::getSingleton().createTimer(boost::bind(&UnitTestEnvironmen::step, this));
		_timer->start(10.f);




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
			
			Orz::PluginsManager::getSingleton().loadPlugin("MyWheelDirector");
		}



	}

	~UnitTestEnvironmen(void)
	{ 
		std::cout<<test_log->str()<<"!"<<std::endl;
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
/// Orz系统
SystemPtr UnitTestEnvironmen::system;

boost::shared_ptr< std::stringstream > UnitTestEnvironmen::test_log;
///// 测试日志
//boost::shared_ptr<TestLogSystem> UnitTestEnvironmen::logMgr;

///配置全局的环境
BOOST_GLOBAL_FIXTURE( UnitTestEnvironmen )




#endif