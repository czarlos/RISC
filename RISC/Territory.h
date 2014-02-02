#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;

class Territory
{
public:
	Territory(string);
	void addToContent(GameObject itemToAdd);
	void removeFromContent(GameObject itemToRemove);
	int contentSize();
	void changeOwner(string newOwnerName);
	string getOwner();
	vector<GameObject> getGameContent();
	

private:
	string territoryID;
	string owner;
	vector<GameObject> contents;

	~Territory();
};

