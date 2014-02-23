#pragma once

#include <iostream>
#include "../GameState/GameState.h"
#include "Response.h"

class Order {
private:
	//GameState myState;
public:
	Order();
	//Order(GameState* state);
	virtual ~Order() {};
protected:
	//virtual void execute(GameState* state) = 0;
	virtual Response execute(GameState* state);
};

