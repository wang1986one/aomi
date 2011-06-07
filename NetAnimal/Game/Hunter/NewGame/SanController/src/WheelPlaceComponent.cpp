
#include "SanControllerBaseStableHeaders.h"
#include "WheelPlaceComponent.h"

#include "CWheelPlaceInterface.h"
using namespace Orz;
WheelPlaceComponent::WheelPlaceComponent(void): _placeInterface(new CWheelPlaceInterface())
{
	_placeInterface->place =  boost::bind(&WheelPlaceComponent::doPlace,this, _1, _2); 
}
WheelPlaceComponent::~WheelPlaceComponent(void)
{
	
}
ComponentInterface * WheelPlaceComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(CWheelPlaceInterface)))
	{
		return _placeInterface.get();
	}
	return NULL;
}


void WheelPlaceComponent::doPlace(int n, Orz::NameValueList * nvl)
{
	float l = (-7733.47f+5500.09f -250.f);
	int i = n/3;
	int m = n%3 -1;
	float radian = Ogre::Math::PI/4 *i +Ogre::Math::HALF_PI;
	float y = Ogre::Math::Sin(Ogre::Radian(radian) ) * l;
	float x = Ogre::Math::Cos(Ogre::Radian(radian))* l;
	float y2= Ogre::Math::Cos(Ogre::Radian(radian) ) * 500 *m;
	float x2 = Ogre::Math::Sin(Ogre::Radian(radian)) * 500 *m;
	
	(*nvl)["radian"] = Orz::VariantData<float>::set( Ogre::Math::HALF_PI -radian);
	(*nvl)["pos"] = Orz::VariantData<Ogre::Vector3>::set(Ogre::Vector3(
		0.712143f +x +x2 ,
		-1179.04f, 
		-5500.09f +y- y2 
		));
}