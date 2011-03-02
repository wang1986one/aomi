#ifndef __Orz_CodingFormatComponent_h__
#define __Orz_CodingFormatComponent_h__
#include "CodingInterface.h"
namespace Orz
{
	class CodingFormatInterface;
	class CodingFormatComponent: public Component
	{
	private:
	public:
		virtual ~CodingFormatComponent(void);
		CodingFormatComponent(void);

	private:
		std::string encode(size_t size, size_t length);
		bool decode(const std::string & code, size_t size);
		unsigned int get(int begin, int end, int scale);
		bool set(int begin, int end, unsigned int data, int scale);

		bool set10(unsigned int data);
		bool set1check8(unsigned int data);

	/*	unsigned int get10(void);
		unsigned int get1check8(void);*/
		unsigned int getCheck8(size_t size);

	//	
	//_formatInterface->get10 = boost::bind(&CodingFormatComponent::get10, this);
	//_formatInterface->get1check8 = boost::bind(&CodingFormatComponent::get1check8, this);

	//_formatInterface->set10 = boost::bind(&CodingFormatComponent::set10, this, _1);
	//_formatInterface->set1check8 = boost::bind(&CodingFormatComponent::set1check8, this, _1);
		
		virtual ComponentInterface * _queryInterface(const TypeInfo & info);
		boost::scoped_ptr<CodingFormatInterface> _formatInterface;
		ComponentQueryInterface _query;
		ComponentPtr _codingComp;
	};
}


#endif
