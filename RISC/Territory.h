#pragma once
#include <iostream>
#include <string>
#include <list>

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
	list<GameObjects> getGameContent();
	

private:
	string territoryID;
	string owner;
	list<GameObject> contents;

	~Territory();
};

