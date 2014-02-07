#include "GameObject.h"


GameObject::GameObject(string objID, Location* location)
{
	this->objID = objID;
	this->myLocation = *location;
}

GameObject::GameObject() {
	
}

string GameObject::getGameObjectID() {
	return this->objID;
}

Location* GameObject::getLocation() {
	return &(this->myLocation);
}

void GameObject::setLocation(Location destination) {
	this->myLocation = destination;
}

GameObject::~GameObject()
{
}
