#ifndef __Orz_GetWinMsg_h__
#define __Orz_GetWinMsg_h__	

#include "WheelLogic.h"
#include "StartLogic.h"
#include "WMHardwareInterface.h"
#include "DataCentreInterface.h"
#include "OperatingPanelInterface.h"	
namespace Orz
{



	//ÉèÖÃÓ²¼þÊôÐÔ
	class GetWinMsg
	{
	public:

		GetWinMsg(void):_communicate(NULL)
		{

			_opComp = Orz::ComponentFactories::getInstance().create("OperatingPanel");
			_dataComp = Orz::ComponentFactories::getInstance().create("DataCentre");
		}
		~GetWinMsg(void)
		{

		}
		/*TimeType getWaitTime(void) const
		{
			return 0.2f;
		}*/
		bool send(Orz::CommunicateInterface::PanelID id)
		{
			_communicate->readCoins(id);
			return true;

		}

		void init(WheelGame * game)
		{
			_communicate = game->getHardware()->queryInterface<CommunicateInterface>();
		}
		void exit(void){}
		bool receive(CommunicateInterface::PackagePtr package, Orz::CommunicateInterface::PanelID id)
		{

			if(package->getFunction() == CommunicateInterface::ReadCoins && package->getId() == id)
			{
		
				Orz::DataCentreInterface * data = _dataComp->queryInterface<DataCentreInterface>();
				OperatingPanelInterface * operation = _opComp->queryInterface<OperatingPanelInterface>();
				for(int i =0; i<3; i++)
				{
					for(int j =0; j<4; j++)
					{
						WheelEnum::AnimalItem item(static_cast<WheelEnum::TYPE>(j), static_cast<WheelEnum::LIGHT_COLOR>(i));
						size_t coins = GetCoins(_communicate->getCommunicateId(item), package);
						operation->setItem(package->getId(), data->item2Id(item), coins);
					}
				}

				size_t dealer = GetCoins(CommunicateInterface::Dealer, package);
				operation->setItem(package->getId(), data->winner2Id(WheelEnum::Dealer), dealer);

				size_t draw =  GetCoins(CommunicateInterface::Draw, package);
				operation->setItem(package->getId(), data->winner2Id(WheelEnum::Draw), draw);

				size_t player =  GetCoins(CommunicateInterface::Player, package);
				operation->setItem(package->getId(), data->winner2Id(WheelEnum::Player), player);

				return true;
			}

			return false;

		}
	private:
		CommunicateInterface * _communicate;
		Orz::ComponentPtr _opComp;
		Orz::ComponentPtr _dataComp;
	};
}
#endif