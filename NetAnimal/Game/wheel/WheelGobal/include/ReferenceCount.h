#ifndef __Orz_ReferenceCount_h__
#define __Orz_ReferenceCount_h__	


#include "WheelGobalConfig.h"
namespace Orz
{
	class _OrzWheelGobalExport ReferenceCount
	{
	public:
		typedef boost::shared_ptr<int> Referenced;
	public:
	
		ReferenceCount(void);
		~ReferenceCount(void);
		Referenced reference(void);
		bool hasReferenced(void);
		Referenced _count;
	};

	typedef boost::shared_ptr<ReferenceCount> ReferenceCountPtr;

}

#endif



