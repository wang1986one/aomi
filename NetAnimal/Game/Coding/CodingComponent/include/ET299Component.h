#ifndef __Orz_ET299Component_h__
#define __Orz_ET299Component_h__
#include "CodingInterface.h"
namespace Orz
{
	class LockInterface;
	class ET299Component: public Component
	{
	public:
		virtual ~ET299Component(void);
		ET299Component(void);

	private:

		bool link(void);
		void unlink(void);

		unsigned int key(int seed);
		virtual ComponentInterface * _queryInterface(const TypeInfo & info);

		boost::scoped_ptr<LockInterface> _lockInterface;

		ComponentQueryInterface _query;
	};
}


#endif
