#include "GameObject.h"


GameObject::GameObject(string id, Location location)
{
	this->id = id;
	this->myLocation = location;
}

GameObject::GameObject() {
	
}

string GameObject::getGameObjectID() {
	return this->id;
}

Location GameObject::getLocation() {
	return this->myLocation;
}

void GameObject::setLocation(Location destination) {
	this->myLocation = destination;
}

GameObject::~GameObject()
{
}
