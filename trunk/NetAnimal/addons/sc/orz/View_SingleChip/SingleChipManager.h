#ifndef __Orz_ViewSingleChip_SingleChipManager_h__
#define __Orz_ViewSingleChip_SingleChipManager_h__

#include <orz/View_SingleChip/ViewSingleChipConfig.h>
#include <orz/Toolkit_Base/Singleton.h>
#include <boost/circular_buffer.hpp>
#include <boost/asio.hpp>
#include <boost/property_tree/detail/rapidxml.hpp>
#include <orz/Framework_Base/System/SystemInterface.h>
namespace Orz
{
class _OrzViewSingleChipExport SingleChipListener
{
public:
	virtual void read(boost::circular_buffer<unsigned char> & data) = 0;
	virtual void readFromSCM(unsigned int id, unsigned char c) = 0;
	virtual ~SingleChipListener(void){}

};
class SingleChipManagerImpl;
class SingleChip;
class _OrzViewSingleChipExport SingleChipManager : public Singleton<SingleChipManager>
{
public:
	SingleChipManager(void);
	~SingleChipManager(void);
	bool init(void);
	void shutdown(void);
	/*bool write(unsigned char * data, int num);
	bool write(char * data, int num);
	bool write(const MsgBuffer & buffer);*/

	bool update(TimeType i);

	void addListener(unsigned int id, SingleChipListener * listener);
	void removeListener(unsigned int id, SingleChipListener * listener);

	
	void addListener(SingleChipListener * listener);
	void removeListener( SingleChipListener * listener);


	size_t getSCMAmount(void) const;
	//void addListener(SingleChipListener * listener);
	//void removeListener(SingleChipListener * listener);
	
	void SingleChipManager::loadXML(rapidxml::xml_node<> * node);
private:

	typedef boost::shared_ptr<SingleChip> SingleChipPtr;
	typedef std::vector<SingleChipPtr> SCMList;
	SCMList _SCMs;
	boost::asio::io_service _ioService;
	
	
	void threadUpdate();
	boost::scoped_ptr<boost::thread> _thread;
	bool _threadOver;
};


SYSTEMUNIT_BEGIN(SingleChipManager) 
SYSTEMUNIT_INIT 
SYSTEMUNIT_UPDATE 
SYSTEMUNIT_SHUTDOWN 
SYSTEMUNIT_END(SingleChipManager)


}



#endif