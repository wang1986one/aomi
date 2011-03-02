#include "CodingComponentStableHeaders.h"
#include "ET299Component.h"
#include "LockInterface.h"
#include "md5.h"
//#include "FT_ET299_API.h"
using namespace Orz;



ET299Component::~ET299Component(void)
{
	
}



ET299Component::ET299Component(void):_lockInterface(new LockInterface())
{
	_lockInterface->link = boost::bind(&ET299Component::link, this);
	_lockInterface->unlink = boost::bind(&ET299Component::unlink, this);
	_lockInterface->key = boost::bind(&ET299Component::key, this, _1);
	_query.add(_lockInterface.get());
}


bool ET299Component::link(void)
{
	
	return true;
}
unsigned int  ET299Component::key(int seed)
{
	return 13641689489;
}
void ET299Component::unlink(void)
{

}


ComponentInterface * ET299Component::_queryInterface(const TypeInfo & info)
{

	return _query.queryInterface(info);
}