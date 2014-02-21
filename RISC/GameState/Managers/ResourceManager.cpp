#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
	this->resourceMap = new map<ResourceType, Resource>();
}


void ResourceManager::addResource(string resourceName) {
	//remember to instantiate resource
}

ResourceManager::~ResourceManager()
{
}
