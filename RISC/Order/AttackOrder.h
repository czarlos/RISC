#pragma once
#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"
#include "AttackResponse.h"
#include "SpoofResponse.h"
#include "../ProtocolBuffers/SerializationUtilities.h"
#include "../ProtocolBuffers/AttackOrder.pb.h"
#include "../ProtocolBuffers/Unit.pb.h"

class AttackOrder : public Order {
	
public:
	AttackOrder();
	AttackOrder(Location* source, Location* destination, vector<Unit*> unitList);
	Response* execute(GameState* gamestate);
	string getName();
	void serializeAndSend();
	void setDestination(Location* destination);
	void setSource(Location* source);
	void setUnitList(vector<Unit*> unitList);
	~AttackOrder();

private:
	Location* myDestination;
	Location* mySource;
	vector<Unit*> myUnitList;
	string myName = "AttackOrder";
};
