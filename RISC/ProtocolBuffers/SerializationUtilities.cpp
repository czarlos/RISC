#include "SerializationUtilities.h"

SerializationUtilities::SerializationUtilities() {

}

Buffers::UnitType* SerializationUtilities::getUnitType(Unit* unit) {
    
	string unitType = unit->getUnitType()->getType();
       
    Buffers::UnitType* unitTypeBuffer = new Buffers::UnitType();
       
	if (unitType == "Infantry") {   
	    unitTypeBuffer->set_level(0);
    	unitTypeBuffer->set_type("Infantry");
    	unitTypeBuffer->set_combatbonus(0);
    	unitTypeBuffer->set_upgradecost(0);
    	unitTypeBuffer->set_costtounlock(0);
    	unitTypeBuffer->set_spy(false);
		unitTypeBuffer->set_nexttype("AutomaticWeapons");
		unitTypeBuffer->set_previoustype("");
	}   
	else if (unitType == "AutomaticWeapons") {
        unitTypeBuffer->set_level(1);
        unitTypeBuffer->set_type("AutomaticWeapons");
        unitTypeBuffer->set_combatbonus(1);
        unitTypeBuffer->set_upgradecost(3);
        unitTypeBuffer->set_costtounlock(20);
        unitTypeBuffer->set_spy(false);
        unitTypeBuffer->set_nexttype("RocketLaunchers");
        unitTypeBuffer->set_previoustype("Infantry"); 
	}   
	else if (unitType == "RocketLaunchers") {
        unitTypeBuffer->set_level(2);
        unitTypeBuffer->set_type("RocketLaunchers");
        unitTypeBuffer->set_combatbonus(2);
        unitTypeBuffer->set_upgradecost(19);
        unitTypeBuffer->set_costtounlock(50);
        unitTypeBuffer->set_spy(false);
        unitTypeBuffer->set_nexttype("Tank");
        unitTypeBuffer->set_previoustype("AutomaticWeapons"); 
	}   
	else if (unitType == "Tanks") {
       	unitTypeBuffer->set_level(3);
        unitTypeBuffer->set_type("Tanks");
        unitTypeBuffer->set_combatbonus(6);
        unitTypeBuffer->set_upgradecost(25);
        unitTypeBuffer->set_costtounlock(80);
        unitTypeBuffer->set_spy(false);
        unitTypeBuffer->set_nexttype("Tanks");
        unitTypeBuffer->set_previoustype("RocketLaunchers");    
	}   
	else if (unitType == "ImprovedTanks") {
        unitTypeBuffer->set_level(4);
        unitTypeBuffer->set_type("Infantry");
        unitTypeBuffer->set_combatbonus(12);
        unitTypeBuffer->set_upgradecost(25);
        unitTypeBuffer->set_costtounlock(120);
        unitTypeBuffer->set_spy(false);
        unitTypeBuffer->set_nexttype("FighterPlanes");
        unitTypeBuffer->set_previoustype("Tanks");
	}   
	else if (unitType == "FighterPlanes") {
        unitTypeBuffer->set_level(5);
        unitTypeBuffer->set_type("FighterPlanes");
        unitTypeBuffer->set_combatbonus(15);
        unitTypeBuffer->set_upgradecost(35);
        unitTypeBuffer->set_costtounlock(150);
        unitTypeBuffer->set_spy(false);
        unitTypeBuffer->set_nexttype("");
        unitTypeBuffer->set_previoustype("ImprovedTanks");
	}   

    return unitTypeBuffer;
}

void SerializationUtilities::createUnitBuffer(Unit* unit, Buffers::Unit* unitBuffer) {
	unitBuffer->set_health(unit->getHealth());
	unitBuffer->set_allocated_unittype(getUnitType(unit));
	unitBuffer->set_teamname(unit->getTeamName());
	unitBuffer->set_unitid(unit->getGameObjectID());
	unitBuffer->set_movementrange(unit->getMovementRange());
}

SerializationUtilities::~SerializationUtilities() {

}
