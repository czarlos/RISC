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

ResourceType::~ResourceType(){

}