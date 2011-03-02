#ifndef __Orz_ProRunLogic_h__
#define __Orz_ProRunLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

//תׯ�кͣ��������𣬴��ף��ʵ�����ȡ���
class ProRunLogic: public FSM::LogicAdv<ProRunLogic, GameLogic>
{
public:
	ProRunLogic(my_context ctx);
	~ProRunLogic(void);
	
	typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > , sc::custom_reaction< LogicEvent::AskState > > reactions;
	sc::result react(const UpdateEvt & evt);
	sc::result react(const LogicEvent::AskState & evt);
	
private:
	ProcessPtr _process;
};
}
#endif