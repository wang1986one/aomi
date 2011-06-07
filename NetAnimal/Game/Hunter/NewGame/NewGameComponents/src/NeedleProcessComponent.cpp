
#include "NewGameComponentsStableHeaders.h"	
#include "NeedleProcessComponent.h"	
#include "CGameActionInterface.h"	
#include "CGameRotationInterface.h"
#include "CGameBaseInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameTranslateInterface.h"
#include "ComputeWinner.h"
#include "RunMoreWinner.h"
#include "AllColorWinner.h"
#include "AllAnimalWinner.h"
#include <WheelGobal/WinData.h>
#include <WheelGobal/WheelData.h>
#include <WheelGobal/WheelEnum.h>
#include "ChangeColor.h"
#include "NeedleOpenTask.h"
#include "NeedleAllColorRunTask.h"
#include "NoneRunTask.h"
#include "CGameColourInterface.h"
#include "NeedleAllColorWinTask.h"
using namespace Orz;
NeedleProcessComponent::NeedleProcessComponent(void):_actionInterface(new CGameActionInterface()),_needleProcessInterface(new CNeedleProcessInterface()),_color(0),_base(0),
_multiArray(boost::extents[3][4])
{


	
	_colourComp = ComponentFactories::getInstance().create("GameColour");
	_rotationComponent = Orz::ComponentFactories::getInstance().create("GameRotation");
	_actionInterface->activate = boost::bind(&NeedleProcessComponent::activate, this, _1);
	_needleProcessInterface->setTranslate =  boost::bind(&NeedleProcessComponent::setTranslate, this, _1);
	_needleProcessInterface->getBase =  boost::bind(&NeedleProcessComponent::getBase, this);
	_needleProcessInterface->getColor =  boost::bind(&NeedleProcessComponent::getColor, this);
	_needleProcessInterface->getTranslateInterface = boost::bind(&NeedleProcessComponent::getTranslateInterface, this);
	//_needleProcessInterface->getWinData = boost::bind(&NeedleProcessComponent::getWinData, this);
	
	_needleProcessInterface->getBase =  boost::bind(&NeedleProcessComponent::getBase, this);
	_needleProcessInterface->getColor =  boost::bind(&NeedleProcessComponent::getColor, this);
	_needleProcessInterface->getTranslateInterface = boost::bind(&NeedleProcessComponent::getTranslateInterface, this);
	//_needleProcessInterface->getWinData = boost::bind(&NeedleProcessComponent::getWinData, this);
	
	_allAnimalWinner.reset(new AllAnimalWinner(_rotationComponent));
	_moreWinner.reset(new RunMoreWinner(_rotationComponent));

	//CGameRotationInterface * ratation, CNeedleProcessInterface * nInterface, CGameBaseInterface * bInterface

	_multiArray[WheelEnum::Red][AnimalEnum::TYPE0] = "panada_red.wav";//ÐÜÃ¨
	_multiArray[WheelEnum::Red][AnimalEnum::TYPE1]  = "tiger_red.wav";//ÀÏ»¢
	_multiArray[WheelEnum::Red][AnimalEnum::TYPE2]  = "elephant_red.wav";//´óÏó
	_multiArray[WheelEnum::Red][AnimalEnum::TYPE3]  = "crocodile_red.wav";//öùÓã

	_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE0]  = "panada_yellow.wav";
	_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE1]  = "tiger_yellow.wav";
	_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE2]  = "elephant_yellow.wav";
	_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE3]  = "crocodile_yellow.wav";

	_multiArray[WheelEnum::Green][AnimalEnum::TYPE0]  = "panada_green.wav";
	_multiArray[WheelEnum::Green][AnimalEnum::TYPE1]  = "tiger_green.wav";
	_multiArray[WheelEnum::Green][AnimalEnum::TYPE2]  = "elephant_green.wav";
	_multiArray[WheelEnum::Green][AnimalEnum::TYPE3]  = "crocodile_green.wav";

	_colorArray[WheelEnum::Red] = "red.wav";
	_colorArray[WheelEnum::Green] = "green.wav";
	_colorArray[WheelEnum::Yellow] = "yellow.wav";


	_animalArray[AnimalEnum::TYPE0] = "win_panada.wav";
	_animalArray[AnimalEnum::TYPE1] = "win_tiger.wav";
	_animalArray[AnimalEnum::TYPE2] = "win_elephant.wav";
	_animalArray[AnimalEnum::TYPE3] = "win_crocodile.wav";

	TaskPtr colorRun(new NeedleAllColorRunTask(
	_colourComp->queryInterface<CGameColourInterface>(),
	_rotationComponent->queryInterface<CGameNeedleInterface>()
	));
	colorRun->compose(TaskPtr( new NoneRunTask(_needleProcessInterface.get(), _rotationComponent->queryInterface<CGameRotationInterface>())));
	_allTask[std::pair<int, int>(PROCESS_RUN, Orz::WheelEnum::ALL_COLOR)] = colorRun;


	TaskPtr	allColorWinner(new AllColorWinner(
	_rotationComponent->queryInterface<CGameRotationInterface>(),
	_needleProcessInterface.get(),
	_rotationComponent->queryInterface<CGameBaseInterface>()
	
	));
	allColorWinner->compose(TaskPtr(new NeedleAllColorWinTask(	
		_colourComp->queryInterface<CGameColourInterface>(),
	_rotationComponent->queryInterface<CGameNeedleInterface>(),
	_needleProcessInterface.get()
	)));
	_allTask[std::pair<int, int>(PROCESS_WIN, Orz::WheelEnum::ALL_COLOR)] = allColorWinner;
	

}
NeedleProcessComponent::~NeedleProcessComponent(void)
{
}

CGameTranslateInterface* NeedleProcessComponent::getTranslateInterface(void) const
{
	if(!_translate_c)
		return NULL;
	return _translate_c->queryInterface<CGameTranslateInterface>();
}
int NeedleProcessComponent::getColor(void) const
{
	return _color;
}
int NeedleProcessComponent::getBase(void)const
{
	return _base;
}

bool NeedleProcessComponent::enable(void)
{

	CGameRotationInterface * gameRotation = _rotationComponent->queryInterface<CGameRotationInterface>();
	ComputeWinner compute;
	compute.compute(_base, _color, 6);


	gameRotation->play(compute.getNeedle(), 12.f,compute.getRotate(), 17.f);

	_actionInterface->update =  gameRotation->update;
	return true;
}


bool NeedleProcessComponent::enableWinner(int winner, bool move)
{


	CGameTranslateInterface * translate = _translate_c->queryInterface<CGameTranslateInterface>();


	if(_needleProcessInterface->_callback)
		_needleProcessInterface->_callback(translate->getType());
	Orz::ISoundManager::getSingleton().quickPlay(_multiArray[WheelEnum::LIGHT_COLOR(_light)][_type]);
	CGameRotationInterface * gameRotation = _rotationComponent->queryInterface<CGameRotationInterface>();
	CGameBaseInterface * base = _rotationComponent->queryInterface<CGameBaseInterface>();
	gameRotation->winner(winner, move);
	base->setColor(_base, _light);
	_actionInterface->update =  gameRotation->update;
	return true;
}
//bool NeedleProcessComponent::update(TimeType i)
//{
//	return false;
//}
//const WinData & NeedleProcessComponent::getWinData(void) const 
//{
//	return WinData::getInstance();
//}

void NeedleProcessComponent::setTranslate(ComponentPtr translate_c)
{

	WinData::getInstance() = WinData::getInstance();

	//_winData = winData;
	_translate_c = translate_c;
	CGameTranslateInterface * translate = _translate_c->queryInterface<CGameTranslateInterface>();
	translate->random((CNewGameSceneInterface::LIGHT_COLOR)WinData::getInstance().getLightColor(), WinData::getInstance().getAnimalType());

	_color = translate->getColor();
	_base = translate->getType();
	//_color = color;
	//_base = base;
	_light = (CGameBaseInterface::LIGHT_COLOR)WinData::getInstance().getLightColor();
	_type = WinData::getInstance().getType();
}
bool NeedleProcessComponent::_enable(void)
{	

	CGameBaseInterface * base = _rotationComponent->queryInterface<CGameBaseInterface>();
	for(int i=0 ;i <24; i++)
		base->setColor(i,CGameBaseInterface::None);
	return true;
}

//
//void NeedleProcessComponent::disable(void)
//{
//	//_wheel->stop();
//}



bool NeedleProcessComponent::activate(SanProcess process)
{

	
	TaskMap::iterator it = _allTask.find(std::pair<int, int>(process, WinData::getInstance().getWinMode()));
	if(it != _allTask.end())
	{
		_actionInterface->enable = boost::bind(&ITask::enable, (it->second).get());
		_actionInterface->update = boost::bind(&ITask::update, (it->second).get(), _1);
		_actionInterface->disable =boost::bind(&ITask::disable, (it->second).get());
		return true;
	}

	CGameRotationInterface * gameRotation = _rotationComponent->queryInterface<CGameRotationInterface>();

	switch(process)
	{
	case PROCESS_RUN:

		if(WinData::getInstance().getWinMode() == Orz::WheelEnum::MANY )
		{
			_moreWinner->setMoreWinner(_needleProcessInterface.get(), _actionInterface.get(), _translate_c->queryInterface<CGameTranslateInterface>());

			return true;
		}
		_actionInterface->enable = boost::bind(&NeedleProcessComponent::enable, this);
		_actionInterface->disable = boost::bind(&___disable);
		//boost::bind(&NeedleProcessComponent::update, this, _1);
		return true;
		break;

	case PROCESS_WIN:


		switch(WinData::getInstance().getWinMode())
		{

		case Orz::WheelEnum::MANY:
			_actionInterface->enable = boost::lambda::constant(true);
			_actionInterface->disable = boost::bind(&___disable);
			break;
		case Orz::WheelEnum::ALL_COLOR:

			Orz::ISoundManager::getSingleton().quickPlay(_colorArray.at(WinData::getInstance().getLightColor()));
			
			//_allColorWinner->setFlower(WinData::getInstance().getLightColor(),_rotationComponent->queryInterface<CGameFlowerInterface>());
			//_allColorWinner->setWinner(_actionInterface.get(), _translate_c->queryInterface<CGameTranslateInterface>(), WinData::getInstance());

			break;
		case Orz::WheelEnum::ALL_ANIMAL:
			Orz::ISoundManager::getSingleton().quickPlay(_animalArray.at(WinData::getInstance().getType()));
			_allAnimalWinner->setWinner(_actionInterface.get(), _translate_c->queryInterface<CGameTranslateInterface>());
			break;


		default:
			_actionInterface->enable = boost::bind(&NeedleProcessComponent::enableWinner, this, _base, true);
			_actionInterface->disable = boost::bind(&___disable);
		}

		return true;	

	case PROCESS_END:

		_actionInterface->enable = boost::bind(&NeedleProcessComponent::_enable, this);//boost::bind(&SanSceneComponent::enableParticle, this, "explosionSystem", newNode);
		_actionInterface->disable =gameRotation->reset;
		_actionInterface->update = boost::lambda::constant(false);
		return true;
		break;

	}
	return false;

}


ComponentInterface * NeedleProcessComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(CGameColourInterface)))
		return _colourComp->_queryInterface(info);
	if(info == TypeInfo(typeid(CNeedleProcessInterface)))
		return _needleProcessInterface.get();
	if(info == TypeInfo(typeid(CGameActionInterface)))
		return _actionInterface.get();
	ComponentInterface * face = _rotationComponent->_queryInterface(info);
	if(face)
		return face;
	return NULL;
}
