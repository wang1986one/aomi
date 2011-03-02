#ifndef __Orz_F5TableComponent_h__
#define __Orz_F5TableComponent_h__
//#include "CodingInterface.h"
namespace Orz
{
	class F5TableInterface;
	class F6TableInterface;
	class F5TableComponent: public Component
	{
	private:
	public:
		virtual ~F5TableComponent(void);
		F5TableComponent(void);

	private:


		//const CodingSet & push(unsigned int begin, unsigned int end, unsigned long num);
		//unsigned long pop(unsigned int begin, unsigned int end);
		//void clear(void);

		//void write(std::ostream & os);
		//void read(std::istream & is);
		//
		//unsigned short getCheck16(unsigned int n);
		//unsigned char getCheck8(unsigned int n);


		//
		//void encode(unsigned int key);
		//void decode(unsigned int key);


		//CodingSet _set;

		virtual ComponentInterface * _queryInterface(const TypeInfo & info);

		boost::scoped_ptr<F5TableInterface> _f5TableInterface;
		boost::scoped_ptr<F6TableInterface> _f6TableInterface;

		ComponentQueryInterface _query;
	};
}


#endif
