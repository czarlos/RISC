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
	void setLocation(Location destination);
	virtual ~GameObject();

private:
	string objID;
	Location myLocation;
	
};

