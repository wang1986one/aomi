#ifndef __Orz_SenselockComponent_h__
#define __Orz_SenselockComponent_h__
#include "LockInterface.h"
namespace Orz
{
	class SenselockComponent: public Component
	{
	public:
		virtual ~SenselockComponent(void);
		SenselockComponent(void);

	private:

		bool link(void);
		void unlink(void);

		unsigned int key(int seed);
		bool check(void);
		std::string getLockCode(void);
		bool setLockCode(const std::string & code);

		std::string getLockCode2(void);
		bool setLockCode2(const std::string & code);

		virtual ComponentInterface * _queryInterface(const TypeInfo & info);

		boost::scoped_ptr<LockInterface> _lockInterface;

		ComponentQueryInterface _query;

		uint8 getData8(LockInterface::Data8 index) const;
		uint16 getData16(LockInterface::Data16 index) const;
		uint32 getData32(LockInterface::Data32 index) const;
		
		void setData8(LockInterface::Data8 index, uint8 data);
		void setData16(LockInterface::Data16 index, uint16 data);
		void setData32(LockInterface::Data32 index, uint32 data);





	};
}


#endif
