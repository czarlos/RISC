#include "GameObject.h"


GameObject::GameObject(string objID)
{
	this->objID = objID;
}

GameObject::GameObject() {
	
}

string GameObject::getGameObjectID() {
	return this->objID;
}

GameObject::~GameObject()
{
}
