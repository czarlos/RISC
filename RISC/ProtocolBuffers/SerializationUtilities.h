#pragma once

#include "UnitType.pb.h"
#include "Unit.pb.h"
#include "../GameObject/Unit/Unit.h"

class SerializationUtilities {

public:
	SerializationUtilities();
	Buffers::UnitType getUnitType(Unit* unit);
	Buffers::Unit createUnitBuffer(Unit* unit);
	virtual ~SerializationUtilities();

}

