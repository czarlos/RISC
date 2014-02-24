#pragma once

#include <iostream>
#include "../GameState/GameState.h"
#include "Response.h"

class Order {
public:
	//constructor for orders
	Order();
	//execute and returns a response
	virtual Response* execute(GameState* gamestate);
	//destructor for orders
	virtual ~Order();

private:

protected:

};

