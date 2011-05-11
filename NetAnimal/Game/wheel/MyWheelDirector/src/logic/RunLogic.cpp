
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;

//ÉèÖÃÓ²¼þÊôÐÔ
class SetAnimalScore
{

public:	

	//TimeType getWaitTime(void) const
	//{
	//	return 0.0f;
	//}

	void init(WheelGame * game)
	{
		assert(game);
		_communicate = game->getHardware()->queryInterface<CommunicateInterface>();
		/////////////////
	
		
		ScoreInterface  * scoreInterface = _scoreComp->queryInterface<ScoreInterface>();
		const ScoreInterface::ScoreResult & result = scoreInterface->getResult();
		_prototype = result.prototype;
	}


	//void init(CommunicateInterface * communicate)
	//{
	//	
	//}
	void exit(void)
	{
		if(_prototype->winMode == WheelEnum::MANY)
		{
			_communicate->nextManyN();
		}
	}
	SetAnimalScore(void):_communicate(NULL)
	{
			
		_scoreComp = Orz::ComponentFactories::getInstance().create("Score");
		_opComp = Orz::ComponentFactories::getInstance().create("OperatingPanel");
		
	}
	~SetAnimalScore(void)
	{

	}
	bool send(Orz::CommunicateInterface::PanelID id)
	{ 



		
		const WinData::Bonus & bonus = WinData::getInstance().getBonus();
		//ScoreInterface  * scoreInterface = _scoreComp->queryInterface<ScoreInterface>();
		//const ScoreInterface::ScoreResult & result = scoreInterface->getResult();
		
		OperatingPanelInterface * operation = _opComp->queryInterface<OperatingPanelInterface>();
		
		if(_prototype->winMode != WheelEnum::MANY)
		{
			size_t score = operation->testAnimal2Player(CommunicateInterface::PanelID(id), _prototype);
			operation->addScore(id, score);
			if(bonus.has)
			{
				
				operation->addScore(id, operation->getAnimalCoins(id) * bonus.profitForPerInvest);
				_communicate->setAnimalScore(id, operation->getScore(id), 11);
			}
			else
			{
				_communicate->setAnimalScore(id, operation->getScore(id), (_prototype->animalItems.size()-1));
			}
		}else
		{
			size_t n = _communicate->getManyN();
			if(n<_prototype->animalItems.size())
			{
				size_t score = operation->testAnimalItem2Player(CommunicateInterface::PanelID(id), _prototype->animalItems.at(n));
				operation->addScore(id, score);
				_communicate->setAnimalScore(id, operation->getScore(id), n);
			}else
			{
				return false;
			}
		}
		
		return false;

	}


	bool receive(CommunicateInterface::PackagePtr package, Orz::CommunicateInterface::PanelID id)
	{
		return (package->getId() == id); 
	}
	
private:
	ComponentPtr _opComp;
	Orz::ComponentPtr _scoreComp;
	ScoreInterface::WinPrototypePtr _prototype;
	CommunicateInterface * _communicate;
};

RunLogic::RunLogic(my_context ctx):LogicAdv(ctx)
{
	ORZ_LOG_NORMAL_MESSAGE("State In: RunLogic!");

	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_RUN_ENABLE, WheelEvents::PROCESS_RUN_DISABLE));
}
RunLogic::~RunLogic(void)
{
	ORZ_LOG_NORMAL_MESSAGE("State Out: RunLogic!");
}

void RunLogic::exit(void)
{
	int table = Orz::WinData::getInstance().getTable();
	if(table != -1)
	{
		CommunicateInterface * communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();
		communicate->table(CommunicateInterface::PanelID(table));
	}
}
sc::result RunLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();



	


	return transit<HardwareLogic<GameRunLogic,
		WinLogic, 
		SetAnimalScore>
	>();

}


//sc::result RunLogic::react(const LogicEvent::AskState & evt)
//{	
//	evt.execute(getOwner(), 0x02);
//	//Hardware::getSingleton().answerState(0x01);
//	return forward_event();
//}
