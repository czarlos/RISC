#include "ResourceType.h"

ResourceType::ResourceType(){
	this->resourceName = "";
}

ResourceType::ResourceType(string resourceName){
	this->resourceName = resourceName;
}

string ResourceType::getResourceName(){
	return this->resourceName;
}

int ResourceType::Compare(const ResourceType& r)const{
	if (this->resourceName < r.resourceName){
		return -1;
	}
	else if (this->resourceName > r.resourceName){
		return 1;
	}

	return 0;
}

ResourceType::~ResourceType(){

}