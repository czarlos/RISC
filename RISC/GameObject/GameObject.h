#pragma once
#include <iostream>
#include "../GameMap/Location.h"

using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(string, Location);
	Location getLocation();
	string getGameObjectID();
	virtual ~GameObject();

private:
	string id;
	Location myLocation;
	
};

