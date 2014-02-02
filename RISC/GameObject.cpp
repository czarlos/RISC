#include "GameObject.h"


GameObject::GameObject(string id)
{
	this->id = id;
}

string GameObject::getGameObjectID(){
	return this->id;
}


GameObject::~GameObject()
{
}
