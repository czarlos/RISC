#pragma once
#include <iostream>

using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(string objID);
	string getGameObjectID();
	void setObjectID(string id);
	virtual ~GameObject();

private:
	string objID;	
};

