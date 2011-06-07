#include "WheelGobalStableHeaders.h"
#include "EntityLoader.h"/*
#include <orz/Toolkit_Base/Exception.h>
#include <orz/Toolkit_Base/PluginsManager.h>
#include <tinyxml/tinyxml.h>
using namespace Orz;
const std::string ENTITY_LOADER("EntityLoader");
const std::string PLUGIN("plugin");
const std::string SCENE("scene");
const std::string ACTOR("actor");
const std::string TYPE("type");
const std::string NAME("name");

bool loadPlugin(rapidxml::xml_node<>*  element)
{
	const std::string  * name = element->Attribute(NAME);
	PluginsManager::getSingleton().loadPlugin(*name);
	return true;
}

bool readSceneFromXML(rapidxml::xml_node<>*  element, EntityLoader * loader)
{
	
	const std::string * type = element->Attribute(TYPE);
	const std::string * name = element->Attribute(NAME);
	loader->loadScene(*type, *name);

	return true;
}
bool readActorFromXML(rapidxml::xml_node<>*  element, EntityLoader * loader)
{
	
	const std::string * type = element->Attribute(TYPE);
	const std::string * name = element->Attribute(NAME);
	loader->loadActor(*type, *name);
	return true;
}

EntityLoader::~EntityLoader(void)
{
	
}
EntityLoader::EntityLoader(void):_world(NULL)
{
	
}

bool EntityLoader::loadFromXML(const std::string & xmlFile)
{
	TiXmlDocument document(xmlFile.c_str());
	document.LoadFile();
	rapidxml::xml_node<>* root = document.FirstChildElement(ENTITY_LOADER.c_str());

	if (root)
	{	
		
	
		for(rapidxml::xml_node<>*  element = root->FirstChildElement();  element; element = element->NextSiblingElement(  ) ) 
		{ 
			if(element->ValueStr() == PLUGIN)
			{
				if(!loadPlugin(element))
					return false;
			}
			else if(element->ValueStr() == SCENE)
			{
				if(!readSceneFromXML(element, this))
					return false;
			}else if(element->ValueStr() == ACTOR)
			{
				if(!readActorFromXML(element, this))
					return false;
			}
		} 
		
		return true;
	}

	
	return false;
}
void EntityLoader::addEntity(EntityPtr entity)
{
	if(_world)
		_world->comeIn(entity);
	_entities.push_back(entity);
}
void EntityLoader::removeAll(void)
{
	_entities.clear();
}

void  EntityLoader::enable(EventWorld * world)
{

	_world = world;
	BOOST_FOREACH(EntityPtr entity, _entities)
	{
		_world->comeIn(entity);
	}
}

void  EntityLoader::disable(void)
{

	BOOST_FOREACH(EntityPtr entity, _entities)
	{
		_world->goOut(entity);
	}
	_world = NULL;
}


void EntityLoader::loadScene(const std::string & typeName, const std::string & name, NameValueList * parameter)
{
	addEntity(Orz::GameFactories::getInstance().createScene(typeName, name, parameter));
}
void EntityLoader::loadActor(const std::string & typeName, const std::string & name, NameValueList * parameter)
{
	addEntity(Orz::GameFactories::getInstance().createActor(typeName, name, parameter));
}*/