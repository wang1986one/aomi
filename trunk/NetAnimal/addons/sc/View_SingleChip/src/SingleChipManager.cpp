
#include <orz/View_SingleChip/SingleChipManager.h>
#include "SingleChipManagerImpl.h"
#include "SingleChip.h"
using namespace Orz;



template<> SingleChipManager* Singleton<SingleChipManager>::_singleton = NULL;


SingleChipManager::SingleChipManager(void)//:_impl(new SingleChipManagerImpl())
{

}
SingleChipManager::~SingleChipManager(void)
{

}
bool SingleChipManager::init(void)
{
	
	return true;//_impl->init();
}


void SingleChipManager::loadXML(rapidxml::xml_node<> * node)
{
	if(node)
	{
		for(rapidxml::xml_node<> * sc = node->first_node("single-chip"); sc ;sc = sc->next_sibling("single-chip"))
		{
			std::string port;
			unsigned int rate = 0; 
			rapidxml::xml_attribute<> * attribute = NULL;
			attribute = sc->first_attribute("port");
			if(attribute)
			{
				port = attribute->value();
			}
		
			attribute = sc->first_attribute("baud-rate");
			if(attribute)
			{
				rate = boost::lexical_cast<unsigned int>(attribute->value());
			}
		
			if(!port.empty() && rate != 0)
			{
				
				SingleChipPtr scm(new SingleChip());

				if(scm->enable(_SCMs.size(), port, rate,_ioService))
				{
					_SCMs.push_back(scm);
				}

			}
		}
		_threadOver = false;
		_thread.reset(new boost::thread(boost::bind(&SingleChipManager::threadUpdate, this)));
	}
}

void SingleChipManager::shutdown(void)
{


	BOOST_FOREACH(SingleChipPtr sc, _SCMs)
	{
		sc->disable();
	}


	if(_thread)
	{
		_thread->join();
		_thread.reset();
	}	
	_SCMs.clear();
	//_impl->shutdown();
	
}



//bool SingleChipManager::write(const MsgBuffer & buffer)
//{
//	return _impl->write(buffer);
//}
//
//
//bool SingleChipManager::write(unsigned char * data, int num)
//{
//	return _impl->write(data, num);
//}
//
//bool SingleChipManager::write(char * data, int num)
//{
//	return _impl->write(data, num);
//
//}

size_t SingleChipManager::getSCMAmount(void) const
{
	return _SCMs.size();
}
bool SingleChipManager::update(TimeType i)
{
	
	__ORZ_TRACE__

		
	BOOST_FOREACH(SingleChipPtr sc, _SCMs)
	{
		sc->update(i);
	}


	//BOOST_FOREACH(SCMList::value_type it, _SCMs)
	//{
	//	it.second->update(i);
	//}
	return true;//_impl->update(i);
}
//void SingleChipManager::addListener(SingleChipListener * listener)
//{
//	_impl->addListener(listener);
//}


void SingleChipManager::addListener(unsigned int id, SingleChipListener * listener)
{


	if(id<0  || id >= _SCMs.size())
		return;
	
	SingleChipPtr sc = _SCMs.at(id);
	sc->addListener(listener);


}
void SingleChipManager::removeListener(unsigned int id, SingleChipListener * listener)
{

	if(id<0  || id >= _SCMs.size())
		return;
	
	SingleChipPtr sc = _SCMs.at(id);
	sc->removeListener(listener);
	
}


void SingleChipManager::addListener(SingleChipListener * listener)
{
	BOOST_FOREACH(SingleChipPtr sc, _SCMs)
	{
		sc->addListener(listener);
	}
	
	


}
void SingleChipManager::removeListener(SingleChipListener * listener)
{


	BOOST_FOREACH(SingleChipPtr sc, _SCMs)
	{
		sc->removeListener(listener);
	}

	
}

//void SingleChipManager::removeListener(SingleChipListener * listener)
//{
//	_impl->removeListener(listener);
//}

void SingleChipManager::threadUpdate()
{
	/*BOOST_FOREACH(SingleChipPtr sc, _SCMs)
	{
		sc->_writeToBuffer();
	}*/
    //boost::asio::async_read(*_sp, boost::asio::buffer(_buf), boost::bind(&SingleChipManagerImpl::_writeToBuffer, this, _buf, _1, _2)); 
	_ioService.run();
}