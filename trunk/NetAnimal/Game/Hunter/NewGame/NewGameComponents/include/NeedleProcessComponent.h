#ifndef __Orz_NeedleProcessComponent__
#define __Orz_NeedleProcessComponent__

#include "CSanProcessInterface.h"
#include "CGameBaseInterface.h"
#include "ITask.h"
namespace Ogre
{
	class SceneNode;
}

namespace Orz
{
	namespace UI
	{
		class TVUI;
	}
	class RunMoreWinner;
	class WinData;
	class CGameActionInterface;
	class CNeedleProcessInterface;
	class GameTranslate;
	class AllColorWinner;
	class AllAnimalWinner;
	class ChangeColor;
	class CGameTranslateInterface;
	class NeedleOpenTask;
	class  NeedleProcessComponent: public Component
	{

	public :
		NeedleProcessComponent(void);
		virtual ~NeedleProcessComponent(void);


	private:
		bool activate(SanProcess process);

		ComponentInterface * _queryInterface(const TypeInfo & info);


		bool enable(void);
		//bool update(TimeType i);
		//void disable(void);
		void setTranslate(ComponentPtr translate);
		ComponentPtr _rotationComponent;
		boost::scoped_ptr<CGameActionInterface> _actionInterface;
		boost::scoped_ptr<CNeedleProcessInterface> _needleProcessInterface;

		bool enableWinner(int winner, bool move);
		bool _enable(void);
		int _color;
		int _base;
		CGameBaseInterface::LIGHT_COLOR  _light;
		AnimalEnum::TYPE _type;
		boost::multi_array<std::string, 2> _multiArray;
		boost::array<std::string, 3> _colorArray;
		boost::array<std::string, 4> _animalArray;


		SoundPlayerPtr _wheel;
		ComponentPtr _translate_c;
	private:
		boost::scoped_ptr<RunMoreWinner> _moreWinner;
		boost::scoped_ptr<AllColorWinner> _allColorWinner;
		boost::scoped_ptr<AllAnimalWinner> _allAnimalWinner;
		boost::scoped_ptr<UI::TVUI> _ui;
		//boost::scoped_ptr<NeedleOpenTask> _needleOpen; 


		
		typedef std::map<std::pair<int, int>, TaskPtr> TaskMap;
		TaskMap _allTask;

	private:
		int getColor(void) const;
		int getBase(void) const;
		CGameTranslateInterface* getTranslateInterface(void) const;
		//const WinData & getWinData(void) const ;

		ComponentPtr _colourComp;// = ComponentFactories::getInstance().create("GameColour");
		


	};


}
#endif