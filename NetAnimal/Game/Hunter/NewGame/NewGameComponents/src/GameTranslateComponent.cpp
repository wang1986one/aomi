#include "NewGameComponentsStableHeaders.h"	
#include "GameTranslateComponent.h"	

using namespace Orz;
GameTranslateComponent::GameTranslateComponent(void):_translateInterface(new CGameTranslateInterface()),_randColor(0),_randType(0)
{
	_animal[0] = std::make_pair(AnimalEnum::TYPE0, AnimalEnum::KING);
	_animal[1] = std::make_pair(AnimalEnum::TYPE1, AnimalEnum::PEOPLE);
	_animal[2] = std::make_pair(AnimalEnum::TYPE2, AnimalEnum::PEOPLE);
	_animal[3] = std::make_pair(AnimalEnum::TYPE3, AnimalEnum::PEOPLE);
	_animal[4] = std::make_pair(AnimalEnum::TYPE0, AnimalEnum::PEOPLE);
	_animal[5] = std::make_pair(AnimalEnum::TYPE1, AnimalEnum::KING);
	_animal[6] = std::make_pair(AnimalEnum::TYPE2, AnimalEnum::PEOPLE);
	_animal[7] = std::make_pair(AnimalEnum::TYPE3, AnimalEnum::PEOPLE);
	_animal[8] = std::make_pair(AnimalEnum::TYPE0, AnimalEnum::PEOPLE);
	_animal[9] = std::make_pair(AnimalEnum::TYPE1, AnimalEnum::PEOPLE);


	_animal[10] = std::make_pair(AnimalEnum::TYPE2, AnimalEnum::KING);
	_animal[11] = std::make_pair(AnimalEnum::TYPE3, AnimalEnum::PEOPLE);
	_animal[12] = std::make_pair(AnimalEnum::TYPE0, AnimalEnum::PEOPLE);
	_animal[13] = std::make_pair(AnimalEnum::TYPE1, AnimalEnum::PEOPLE);
	_animal[14] = std::make_pair(AnimalEnum::TYPE2, AnimalEnum::PEOPLE);
	_animal[15] = std::make_pair(AnimalEnum::TYPE3, AnimalEnum::KING);
	_animal[16] = std::make_pair(AnimalEnum::TYPE0, AnimalEnum::PEOPLE);
	_animal[17] = std::make_pair(AnimalEnum::TYPE1, AnimalEnum::PEOPLE);
	_animal[18] = std::make_pair(AnimalEnum::TYPE2, AnimalEnum::PEOPLE);
	_animal[19] = std::make_pair(AnimalEnum::TYPE3, AnimalEnum::PEOPLE);


	_animal[20] = std::make_pair(AnimalEnum::TYPE0, AnimalEnum::PEOPLE);
	_animal[21] = std::make_pair(AnimalEnum::TYPE1, AnimalEnum::PEOPLE);
	_animal[22] = std::make_pair(AnimalEnum::TYPE2, AnimalEnum::PEOPLE);
	_animal[23] = std::make_pair(AnimalEnum::TYPE3, AnimalEnum::PEOPLE);


	_translateInterface->getAnimalList = boost::bind(&GameTranslateComponent::getAnimalList, this);
	_translateInterface->getColorList = boost::bind(&GameTranslateComponent::getColorList, this);
	_translateInterface->getColor = boost::bind(&GameTranslateComponent::getColor, this);
	_translateInterface->getType = boost::bind(&GameTranslateComponent::getType, this);
	_translateInterface->resetRate = boost::bind(&GameTranslateComponent::resetRate, this, _1);
	_translateInterface->random = boost::bind(&GameTranslateComponent::random, this, _1, _2);


}
GameTranslateComponent::~GameTranslateComponent(void)
{

}


void GameTranslateComponent::resetRate(WheelEnum::RATE rate)
{
	static int  n = 0;

	if(n %6 == 7)
	{
		for(int i =0; i<24; ++i)
		{
			if(i < 1)
				_light[i] =  CNewGameSceneInterface::Red ;
			else if (i <2)
				_light[i] =  CNewGameSceneInterface::Yellow ;
			else 
				_light[i] =  CNewGameSceneInterface::Green ;

		}

		return;
	}
	for(int i =0; i<24; ++i)
	{
		if(i < 8)
			_light[i] =  CNewGameSceneInterface::Red ;
		else if (i <16)
			_light[i] =  CNewGameSceneInterface::Yellow ;
		else 
			_light[i] =  CNewGameSceneInterface::Green ;

	}
	for(int i = 0; i<24; ++i)
	{
		std::swap(_light[i], _light[rand()%24]);
	}


	n++;
}
ComponentInterface * GameTranslateComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(CGameTranslateInterface)))
		return _translateInterface.get();

	return NULL;
}
void GameTranslateComponent::random(CNewGameSceneInterface::LIGHT_COLOR color, AnimalEnum::ANIMAL_TYPE type)
{
	_randColor = getItem<CNewGameSceneInterface::LIGHT_COLOR>(_light, color, rand()%3);
	_randType = getItem<AnimalEnum::ANIMAL_TYPE>(_animal, type, rand()%3);
}

int GameTranslateComponent::getColor()
{

	return _randColor;
}

int GameTranslateComponent::getType()
{
	return _randType;
}
const boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> & GameTranslateComponent::getColorList(void) const
{

	return 	_light;
}

const boost::array<AnimalEnum::ANIMAL_TYPE, 24> & GameTranslateComponent::getAnimalList(void) const
{

	return 	_animal;
}