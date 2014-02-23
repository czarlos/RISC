#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	this->resourceMap = map<ResourceType*, Resource*>();
}

void ResourceManager::withdraw(int amount, ResourceType* typeOfResource){
	if (this->resourceMap.find(typeOfResource) != this->resourceMap.end()){
		//if found
		this->resourceMap.at(typeOfResource)->withdraw(amount);
	}
}

void ResourceManager::deposit(int amount, ResourceType* typeOfResource){
	if (this->resourceMap.find(typeOfResource) != this->resourceMap.end()){
		//if found
		this->resourceMap.at(typeOfResource)->deposit(amount);
	}
}

void ResourceManager::replenish(){
	//implement if it is going to be needed
}

void ResourceManager::replenishSpecific(ResourceType* resourceType){
	//implement if it is going to be needed
}

void ResourceManager::replenishExcept(vector<ResourceType*> listOfResourceToReplenish){
	//implement if it is going ot be needed
}

map<ResourceType*, Resource*> ResourceManager::getResourceMap(){
	return this->resourceMap;
}

Resource* ResourceManager::getResource(ResourceType* resourceType){
	//a default resource constructor has a resourceType with a name ""
	Resource* desiredResource = new Resource();

	if (this->resourceMap.find(resourceType) == this->resourceMap.end()){
		desiredResource = this->resourceMap.at(resourceType);
	}
		
	return desiredResource;
}

void ResourceManager::addResource(ResourceType* resourceType) {
	//remember to instantiate resource
	if(this->resourceMap.find(resourceType) == this->resourceMap.end()){
		cout << "This resource already exist" << endl;
		return;
	}
	else{
		//this should already search for common insertions
		this->resourceMap.insert(pair<ResourceType*, Resource*>(resourceType, new Resource((*resourceType))));
	}
}

ResourceManager::~ResourceManager()
{
}
