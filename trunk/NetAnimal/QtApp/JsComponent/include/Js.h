#ifndef __Orz_Js__
#define __Orz_Js__
#include "JsInterface.h"
namespace Orz
{
	class Js
	{

	public :
		Js(void);
		~Js(void);

		static Js & getInstance(void);
		static Js * getInstancePtr(void);

		void setButtonEnable(bool enable);
		boost::signals2::connection subscribeEnableButton(const JsInterface::EnableButtonSignalType::slot_type &subscriber);
		void setTime(int time);
		boost::signals2::connection subscribeSetTime(const JsInterface::SetTimeSignalType::slot_type &subscriber);


		
	private:
		JsInterface::EnableButtonSignalType _enableButtonSignal;
		JsInterface::SetTimeSignalType _setTimeSignal;

		//typedef boost::function<boost::signals2::connection (const EnableButtonSignalType::slot_type &subscriber)> SubscribeEnableButtonFunction;


	};



}
#endif