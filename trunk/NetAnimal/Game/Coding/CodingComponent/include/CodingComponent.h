#ifndef __Orz_CodingComponent_h__
#define __Orz_CodingComponent_h__
#include "CodingInterface.h"
namespace Orz
{
	class CodingInterface;
	class CodingComponent: public Component
	{
	private:
	public:
		typedef CodingInterface::CodingSet CodingSet;
		virtual ~CodingComponent(void);
		CodingComponent(void);

	private:


		const CodingSet & push(unsigned int begin, unsigned int end, unsigned long num);
		unsigned long pop(unsigned int begin, unsigned int end);
		void clear(void);

		void write(std::ostream & os);
		void read(std::istream & is);
		
		void write10(std::ostream & os);
		void read10(std::istream & is);
		unsigned short getCheck16(unsigned int n);
		unsigned char getCheck8(unsigned int n);

		void print(void);
		
		void encode(unsigned int key,size_t size);
		void decode(unsigned int key,size_t size);


		CodingSet _set;

		virtual ComponentInterface * _queryInterface(const TypeInfo & info);

		boost::scoped_ptr<CodingInterface> _codingInterface;

		ComponentQueryInterface _query;
	};
}


#endif
