#pragma once

#include "Location.pb.h"
#include "Territory.pb.h"
#include "UnitType.pb.h"
#include "Unit.pb.h"
#include "../GameObject/Unit/Unit.h"
#include "../GameMap/Territory.h"
#include "../GameMap/Location.h"

class SerializationUtilities {

public:
	SerializationUtilities();
	static Buffers::UnitType* getUnitType(Unit* unit);
	static Buffers::UnitType* getUnitType(UnitType* unit);
	static void createUnitBuffer(Unit* unit, Buffers::Unit* unitBuffer);
	static Buffers::TechnologyManager* createTechnologyManagerBuffer(TechnologyManager* technology);
	static void createUnitTypeBuffer(UnitType* unitType, Buffers::UnitType* unitTypeBuffer)
	static Buffers::Territory* createTerritoryBuffer(Territory* myTerritory);
	static Buffers::Location* createLocationBuffer(Location* location);
	virtual ~SerializationUtilities();
};

