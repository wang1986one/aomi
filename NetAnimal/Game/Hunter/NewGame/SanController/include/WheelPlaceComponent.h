#ifndef __Orz_WheelPlaceComponent__
#define __Orz_WheelPlaceComponent__
#include "SanControllerConfig.h"

namespace Orz
{

class CWheelPlaceInterface;
class  WheelPlaceComponent: public Component
{ 
public:
	WheelPlaceComponent(void);
	virtual ~WheelPlaceComponent(void);
	
private:
	
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);
	void doPlace(int n, Orz::NameValueList * nvl);
	boost::scoped_ptr<CWheelPlaceInterface> _placeInterface;
};
}
#endif