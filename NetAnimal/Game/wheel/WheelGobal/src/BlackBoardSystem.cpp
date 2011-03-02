#include "WheelGobalStableHeaders.h"
#include "BlackBoardSystem.h"
#include <orz/Toolkit_Base/Exception.h>

using namespace Orz;


BlackBoardSystem & BlackBoardSystem::getInstance()
{
	return *(getInstancePtr());
}
BlackBoardSystem * BlackBoardSystem::getInstancePtr()
{
	static BlackBoardSystem instance;
	return &instance;
}

BlackBoardSystem::~BlackBoardSystem(void)
{

}
BlackBoardSystem::BlackBoardSystem(void)
{
	
}

		
bool BlackBoardSystem::has(const std::string & key) const
{
	
	BBSMap::const_iterator it = _map.find(key);
	if(it == _map.end())
	{
		return false;
	}
	return true;
}
void BlackBoardSystem::_write(const std::string & key, const Orz::Variant & value)
{
	BBSMap::iterator it = _map.find(key);
	if(it == _map.end())
	{
		_map.insert(std::make_pair(key, value));
	}else
	{
		it->second = value;
	}
}
Orz::Variant BlackBoardSystem::_read(const std::string & key) const
{
	BBSMap::const_iterator it = _map.find(key);
	if(it == _map.end())
	{
		throw ORZ_EXCEPTION(Exception::ERR_ITEM_NOT_FOUND)<<errno_info_text("Can't find the BlackBoardSystem Item!");
	}
	else
	{
		return it->second;
	}
}