#pragma once
#include <iostream>

using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(string objID);
	string getGameObjectID();
	virtual ~GameObject();

private:
	string objID;	
};

