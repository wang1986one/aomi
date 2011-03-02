#include "WheelGobalStableHeaders.h"
#include "ReferenceCount.h"
#include <orz/Toolkit_Base/Exception.h>

using namespace Orz;

ReferenceCount::ReferenceCount(void):_count(new int(1))
{

}
ReferenceCount::~ReferenceCount(void)
{
}
ReferenceCount::Referenced ReferenceCount::reference(void)
{
	return _count;
}
bool ReferenceCount::hasReferenced(void)
{

	return !_count.unique();
}
