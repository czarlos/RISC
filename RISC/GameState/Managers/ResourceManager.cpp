#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
	this->resourceMap = new map<ResourceType, Resource>();
}

void ResourceManager:: withdraw(int amount, ResourceType resourceType){


}

map<ResourceType, Resource>* ResourceManager::getResourceMap(){
	return this->resourceMap;
}

Resource ResourceManager::getResource(ResourceType resourceType){
	//a default resource constructor has a resourceType with a name ""
	Resource desiredResource = Resource();

	if (this->resourceMap->find(resourceType) == this->resourceMap->end()){
		desiredResource = this->resourceMap->at(resourceType);
	}
		
	return desiredResource;
}

void ResourceManager::addResource(ResourceType resourceType) {
	//remember to instantiate resource
	if (this->resourceMap->find(resourceType) == this->resourceMap->end()){
		cout << "This resource already exist" << endl;
		return;
	}
	else{
		//this should already search for common insertions
		this->resourceMap->insert(pair<ResourceType, Resource>(resourceType, Resource(resourceType)));
	}
}

ResourceManager::~ResourceManager()
{
}
