#include "Resource.h"

Resource::Resource(){
	this->resourceType = ResourceType();
	this->amount = 0;
}

Resource::Resource(string resourceName){
	this->getResourceType = ResourceType(resourceName);
	this->amount = 0;

}

double Resource::getAmount(){
	return this->amount;
}

ResourceType Resource::getResourceType(){
	return this->resourceType;
}

void Resource::deposit(int numToDeposit){
	this->amount = this->amount + numToDeposit;
}

void Resource::withdraw(int numToWithdraw){
	this->amount = this->amount - numToWithdraw;
}

void Resource::replenish(){
	//depending on whether to automatically replenish or not
	//such as if resource retrieve from the territory counts as a deposit or not
	//method is bascially generating resources every X turn by Y amount
}

Resource::~Resource(){

}