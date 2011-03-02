#ifndef __Orz_DataServerComponent_h__
#define __Orz_DataServerComponent_h__
#include "DataServerInterface.h"
namespace Orz
{
	class DataServerInterface;
	class LockInterface;
	class DataServerComponent: public Component
	{
	private:
	public:
		virtual ~DataServerComponent(void);
		DataServerComponent(void);

	private:
		bool load(void);
		bool save(void);

		

		bool loadCodingData(void);
		void saveCodingData(void);
		/*
		unsigned int index2Profits(unsigned int index);
		unsigned int profits2Index(unsigned int index);*/
		
		//int getLevingsProfits(void);

		int getEarn(void) const;
		void cleanCostBackTimeCode2(void);
		bool setCostAndBack(unsigned int cost, unsigned int back);
		unsigned int getBack(void) const;
		void setBack(unsigned int);
		
		unsigned int getCost(void) const;
		void setCost(unsigned int);

		unsigned int getSeconds(void);
		unsigned int getLevingsProfits(void) const;
		void setLevingsProfits(unsigned int);
		void reset(void);
		bool hasLevings(void);
		typedef boost::function<void (unsigned int)> SetProfitsFunction;
		boost::scoped_ptr<DataServerInterface> _dataInterface;
		virtual ComponentInterface * _queryInterface(const TypeInfo & info);
		ComponentQueryInterface _query;
		ComponentPtr _lock;
		ComponentPtr _format;
		LockInterface * _lockInterface; 
		boost::posix_time::ptime _startTime;
		uint32 _seconds;

	};
}


#endif
