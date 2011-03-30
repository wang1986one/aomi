#ifndef __Orz_Js__
#define __Orz_Js__
#include "JsInterface.h"
#include "GameInterface.h"
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

		
		void askPanelData(void);
		boost::signals2::connection subscribeAskPanelData(const JsInterface::AskPanelDataSignalType::slot_type &subscriber);


		//
		//void askPanelData(void);
		//boost::signals2::connection subscribeAskPanelData(const JsInterface::AskPanelDataSignalType::slot_type &subscriber);
		//

		void postPanelData(JsInterface::ButtonId id, size_t num);
		boost::signals2::connection subscribePostPanelData(const GameInterface<0>::PostPanelDataSignalType::slot_type &subscriber);



		
	private:
		JsInterface::EnableButtonSignalType _enableButtonSignal;
		JsInterface::SetTimeSignalType _setTimeSignal;
		JsInterface::AskPanelDataSignalType _askPanelDataSignal;
		GameInterface<0>::PostPanelDataSignalType _postPanelDataSignal;




	};



}
#endif