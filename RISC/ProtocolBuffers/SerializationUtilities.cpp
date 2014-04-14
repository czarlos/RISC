#include "SerializationUtilities.h"

SerializationUtilities::SerializationUtilities() {

}

Buffers::UnitType* SerializationUtilities::getUnitType(Unit* unit) {
    
	string unitType = unit->getUnitType->getType();
       
    Buffers::UnitType* unitTypeBuffer = new Buffers::UnitType();
       
	if (unitType == "Infantry") {   
	    unitType->set_level(0);
    	unitType->set_type("Infantry");
    	unitType->set_combatbonus(0);
    	unitType->set_upgradecost(0);
    	unitType->set_costtounlock(0);
    	unitType->set_spy(false);
		unitType->set_nexttype("AutomaticWeapons");
		unitType->set_previoustype("");
	}   
	else if (unitType == "AutomaticWeapons") {
        unitType->set_level(1);
        unitType->set_type("AutomaticWeapons");
        unitType->set_combatbonus(1);
        unitType->set_upgradecost(3);
        unitType->set_costtounlock(20);
        unitType->set_spy(false);
        unitType->set_nexttype("RocketLaunchers");
        unitType->set_previoustype("Infantry"); 
	}   
	else if (unitType == "RocketLaunchers") {
        unitType->set_level(2);
        unitType->set_type("RocketLaunchers");
        unitType->set_combatbonus(2);
        unitType->set_upgradecost(19);
        unitType->set_costtounlock(50);
        unitType->set_spy(false);
        unitType->set_nexttype("Tank");
        unitType->set_previoustype("AutomaticWeapons"); 
	}   
	else if (unitType == "Tanks") {
       	unitType->set_level(3);
        unitType->set_type("Tanks");
        unitType->set_combatbonus(6);
        unitType->set_upgradecost(25);
        unitType->set_costtounlock(80);
        unitType->set_spy(false);
        unitType->set_nexttype("Tanks");
        unitType->set_previoustype("RocketLaunchers");    
	}   
	else if (unitType == "ImprovedTanks") {
        unitType->set_level(4);
        unitType->set_type("Infantry");
        unitType->set_combatbonus(12);
        unitType->set_upgradecost(25);
        unitType->set_costtounlock(120);
        unitType->set_spy(false);
        unitType->set_nexttype("FighterPlanes");
        unitType->set_previoustype("Tanks");
	}   
	else if (unitType == "FighterPlanes") {
        unitType->set_level(5);
        unitType->set_type("FighterPlanes");
        unitType->set_combatbonus(15);
        unitType->set_upgradecost(35);
        unitType->set_costtounlock(150);
        unitType->set_spy(false);
        unitType->set_nexttype("");
        unitType->set_previoustype("ImprovedTanks");
	}   

    return unitTypeBuffer;
}

void SerializationUtilities::createUnitBuffer(Unit* unit, Buffers::Unit* unitBuffer) {
	unitBuffer->set_health(unit->getHealth());
	unitBuffer->set_allocated_unittype(getUnitType(unit));
	unitBuffer->set_teamname(unit->getTeamName());
	unitBuffer->set_unitid(unit->getUnitID());
	unitBuffer->set_movementrange(unit->getMovementRange());
}

SerializationUtilities::~SerializationUtilities() {

}
