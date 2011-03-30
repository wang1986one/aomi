#ifndef __Orz_UnitTest_JsComponentUT__
#define __Orz_UnitTest_JsComponentUT__

#include "UnitTestConfig.h"
#include "JsInterface.h"
#include "GameInterface.h"
namespace UnitTest
{
	class MyJs
	{

	public:
		void enableButton(bool enable)
		{
			std::cout<<"enableButton"<<std::endl;
		
		}

		void setTime(int time)
		{
			std::cout<<"setTime"<<time<<std::endl;
		}
	};
	
	class MyGame
	{

	};
}
BOOST_AUTO_TEST_CASE(JsComponentUT)
{
	using namespace UnitTest;
	using namespace Orz;
	MyJs myJs;
	//MyGame myGame;
//typedef boost::function<boost::signals2::connection  (const SignalType::slot_type &subscriber)> ResetSubscribeFunction;
	
	Orz::ComponentPtr jsComp = Orz::ComponentFactories::getInstance().create("Js");

	GameInterface<0> * game = jsComp->queryInterface<GameInterface<0> >();
	assert(game);

	JsInterface * js = jsComp->queryInterface<JsInterface>();
	assert(js);
	js->subscribeEnableButton(boost::bind(&MyJs::enableButton, &myJs, _1));
	js->subscribeSetTime(boost::bind(&MyJs::setTime, &myJs, _1));

	
	game->setButtonEnable(true);
	game->setTime(123);

}

#endif

//作家研習營。拋開你的生活，就此消失。將你生命中的一小段時間賭在可以創造一個全新未來的機會上。及時行動，過你夢想中的生活，名額極其有限。有興趣者請來電：1-800-滾你媽的蛋