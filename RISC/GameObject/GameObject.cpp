#include "GameObject.h"


GameObject::GameObject(string id, Location location)
{
	this->id = id;
	this->location = location;
}

GameObject::GameObject() {
	
}

string GameObject::getGameObjectID(){
	return this->id;
}


GameObject::~GameObject()
{
}
