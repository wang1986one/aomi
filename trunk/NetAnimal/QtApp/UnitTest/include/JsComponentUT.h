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

//���������I�����_�������ʹ���ʧ�����������е�һС�Εr�gـ�ڿ��Ԅ���һ��ȫ��δ��ęC���ϡ����r�Єӣ��^������е�������~�O�����ޡ����dȤ��Ո��늣�1-800-�L�㋌�ĵ�