#include "GameObject.h"


GameObject::GameObject(string id, Location location)
{
	this->id = id;
	this->location = location;
}

string GameObject::getGameObjectID(){
	return this->id;
}


GameObject::~GameObject()
{
}
