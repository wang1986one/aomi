#ifndef __Orz_DiamondProcessComponent_
#define __Orz_DiamondProcessComponent__

#include "CSanProcessInterface.h"
#include "CGameDiamondInterface.h"

#include "ITask.h"
namespace Ogre
{
	class SceneNode;
}

namespace Orz
{
	class ChangeColor;
	class CGameActionInterface;
	class CDiamondProcessInterface;
	class DiamondOpenTask;
	class  DiamondProcessComponent: public Component
	{

	public :
		DiamondProcessComponent(void);
		virtual ~DiamondProcessComponent(void);
	private:

		bool activate(SanProcess process);
		ComponentInterface * _queryInterface(const TypeInfo & info);
		ComponentPtr _diamondComp;
		ComponentPtr _ballComp;
		boost::scoped_ptr<CGameActionInterface> _actionInterface;
		bool enable(CGameDiamondInterface::STATE state, TimeType allTime);
		bool update(TimeType i);
		bool goldEnable(void);
		void goldDisable(void);
		bool goldUpdate(TimeType i);
		

		bool goldPreEnable(void);
		bool goldPreUpdate(TimeType i);
		bool lightPreEnable(void);
		bool lightPreUpdate(TimeType i);

		bool lightEnable(int number);
		//bool lightUpdate(TimeType i);
		void step(int i);


		TimeType _allTime;
		SoundPlayerPtr _dang;

		boost::scoped_ptr<ChangeColor> _changeColor;
		boost::scoped_ptr<CDiamondProcessInterface> _processInterface;
		boost::scoped_ptr<DiamondOpenTask> _openTask;

		
		typedef std::map<std::pair<int, int>, TaskPtr> TaskMap;
		TaskMap _allTask;
	};


}
#endif