#pragma once

#include "UnitType.pb.h"
#include "../GameObject/Unit/Unit.h"

class SerializationUtilities {

public:
	SerializationUtilities();
	Buffers::UnitType getUnitType(Unit* unit);
	virtual ~SerializationUtilities();

}

