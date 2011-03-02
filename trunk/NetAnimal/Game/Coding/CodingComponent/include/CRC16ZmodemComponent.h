#ifndef __Orz_CRC16ZmodemComponent_h__
#define __Orz_CRC16ZmodemComponent_h__
#include "CRC16ZmodemInterface.h"
namespace Orz
{
	class CRC16ZmodemInterface;
	class CRC16ZmodemComponent: public Component
	{
	private:
	public:
		virtual ~CRC16ZmodemComponent(void);
		CRC16ZmodemComponent(void);

	private:

		void result(unsigned char * ret);
		void reset(void);
		void push_back(unsigned char data);

	private:

		std::vector<unsigned char> _datas;

	private:

		virtual ComponentInterface * _queryInterface(const TypeInfo & info);

		boost::scoped_ptr<CRC16ZmodemInterface> _crc16Interface;

		ComponentQueryInterface _query;

	};
}


#endif
