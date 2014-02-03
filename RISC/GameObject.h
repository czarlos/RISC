#pragma once
#include <iostream>
#include "Location.h"

using namespace std;

class GameObject
{
public:
	GameObject(string, Location);
	string getGameObjectID();
	virtual ~GameObject();

private:
	string id;
	Location location;
	
};

