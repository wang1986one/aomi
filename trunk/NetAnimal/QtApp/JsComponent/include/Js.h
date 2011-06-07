#ifndef __Orz_Js__
#define __Orz_Js__
#include "JsInterface.h"
#include "GameInterface.h"
#include <boost/property_tree/ptree.hpp>
#include <WheelGobal/WinData.h>
namespace Orz
{
	class Js
	{
	private:
		enum Type
		{
			None = 1,
			Color = 2,
			Animal = 3,
			Double = 4,
			Treble = 5,
			Many = 6
		};
	public:
		Js(void);
		~Js(void);

		static Js & getInstance(void);
		static Js * getInstancePtr(void);

		/*void setButtonEnable(bool enable);
		boost::signals2::connection subscribeEnableButton(const JsInterface::EnableButtonSignalType::slot_type &subscriber);*/


		void setTime(int time);
		boost::signals2::connection subscribeSetTime(const JsInterface::SetTimeSignalType::slot_type &subscriber);

		
		void askPanelData(void);
		boost::signals2::connection subscribeAskPanelData(const JsInterface::StartGameSignalType::slot_type &subscriber);
		boost::signals2::connection subscribeStartGame(const JsInterface::AskPanelDataSignalType::slot_type &subscriber);

		

		void postPanelData(JsInterface::ButtonId id, size_t num);
		boost::signals2::connection subscribePostPanelData(const GameInterface<0>::PostPanelDataSignalType::slot_type &subscriber);




		void addProfit(int profit);
		boost::signals2::connection subscribeAddProfit(const JsInterface::AddProfitSignalType::slot_type &subscriber);

		void setProfit(int profit);
		boost::signals2::connection subscribeSetProfit(const JsInterface::SetProfitSignalType::slot_type &subscriber);

		void rollProfit(void);
		boost::signals2::connection subscribeRollProfit(const JsInterface::RollProfitSignalType::slot_type &subscriber);


		void setWinner(JsInterface::ButtonId, int profit);
		boost::signals2::connection subscribeSetWinner(const JsInterface::SetWinnerSignalType::slot_type &subscriber);

		void setState(JsInterface::State);
		boost::signals2::connection subscribeSetState(const JsInterface::SetStateSignalType::slot_type &subscriber);



		void setWinData(const std::string & data);

		void startGame(void);


		
	private:
		//JsInterface::EnableButtonSignalType _enableButton;
		JsInterface::SetTimeSignalType _setTime;
		JsInterface::StartGameSignalType _startGame;
		JsInterface::AskPanelDataSignalType _askPanelData;

		
		JsInterface::AddProfitSignalType _addProfit;
		JsInterface::SetProfitSignalType _setProfit;
		JsInterface::RollProfitSignalType _rollProfit;
	
		JsInterface::SetWinnerSignalType _setWinner;

		GameInterface<0>::PostPanelDataSignalType _postPanelDataSignal;
		JsInterface::SetStateSignalType _setState;


	private:

		//void deal_None(boost::property_tree::ptree & pt);
		//void deal_Color(boost::property_tree::ptree & pt);
		//void deal_Animal(boost::property_tree::ptree & pt);
		//void deal_Double(boost::property_tree::ptree & pt);
		//void deal_Treble(boost::property_tree::ptree & pt);
		//void deal_Many(boost::property_tree::ptree & pt);
		Orz::WheelEnum::AnimalItem getItem(const std::string & c) const;
		
		Orz::WheelEnum::Winner getWinner(const std::string & c) const;
		


	};



}
#endif