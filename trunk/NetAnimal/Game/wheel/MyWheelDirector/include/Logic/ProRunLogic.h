#ifndef __Orz_ProRunLogic_h__
#define __Orz_ProRunLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

//תׯ�кͣ��������𣬴��ף��ʵ�����ȡ���
class ProRunLogic: public FSM::LogicAdv<ProRunLogic, GameRunLogic>
{
public:
	ProRunLogic(my_context ctx);
	~ProRunLogic(void);
	
	typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
	sc::result react(const UpdateEvt & evt);

	
private:
	ProcessPtr _process;
};
}
#endif