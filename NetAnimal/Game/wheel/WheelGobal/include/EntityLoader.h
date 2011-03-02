#ifndef __Orz_EntityLoader_h__
#define __Orz_EntityLoader_h__	


#include "WheelGobalConfig.h"
namespace Orz
{
	class _OrzWheelGobalExport EntityLoader
	{
	public:
		void addEntity(EntityPtr entity);
		void removeAll(void);
		EntityLoader(void);
		~EntityLoader(void);
		void enable(EventWorld * world);
		void disable(void);
		void loadScene(const std::string & typeName, const std::string & name = IDManager::BLANK, NameValueList * parameter = NULL);
		void loadActor(const std::string & typeName, const std::string & name = IDManager::BLANK, NameValueList * parameter = NULL);
		bool loadFromXML(const std::string & xmlFile);

	public:
		std::vector<EntityPtr> _entities;
		EventWorld * _world;
	
	};
}

#endif



