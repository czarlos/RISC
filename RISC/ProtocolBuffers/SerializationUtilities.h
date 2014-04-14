#pragma once

#include "UnitType.pb.h"
#include "Unit.pb.h"
#include "../GameObject/Unit/Unit.h"

class SerializationUtilities {

public:
	SerializationUtilities();
	static Buffers::UnitType* getUnitType(Unit* unit);
	static void createUnitBuffer(Unit* unit, Buffers::Unit* unitBuffer);
	virtual ~SerializationUtilities();
};

