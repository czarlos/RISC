#pragma once
#include <iostream>
#include "../GameMap/Location.h"

using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(string);
	string getGameObjectID();
	virtual ~GameObject();

private:
	string objID;	
};

