#pragma once
#include <iostream>

using namespace std;

class GameObject
{
public:
	GameObject(string);
	string getGameObjectID();
	virtual ~GameObject();

private:
	string id;
	
};

