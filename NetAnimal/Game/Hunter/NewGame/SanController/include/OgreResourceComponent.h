#ifndef __Orz_OgreResourceComponent__
#define __Orz_OgreResourceComponent__
#include "SanControllerConfig.h"
namespace Orz
{
class COgreResourceInterface;
class  OgreResourceComponent: public Component
{
public :
	OgreResourceComponent(void);
	virtual ~OgreResourceComponent(void);
private:

	bool addResourceLocation(const std::string & path, const std::string & type);
	bool initResourceGroup(void);
	bool createResourceGroup(const std::string & groupName);
	std::string getResourceGroup(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);
	boost::scoped_ptr<COgreResourceInterface> _resourceInterface;

	std::string _groupName;
};
}
#endif