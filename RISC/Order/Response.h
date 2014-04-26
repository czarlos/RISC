#pragma once

#include <iostream>
#include "../GameState/GameState.h"


class Response {
public:
	//default constructor for Response
	Response();

	//Note: adding a virtual keyword to a method allows childern classes
	//to override what the method does

	//Note: this is causing circular dependency
	// on the new methoding of using the response to update gamestate this should not be implemented

	virtual void executeResponse(GameState* state);
	//Note: since Response is the parent, it uses keyword Virtual for its destructor
	//its childerns will inherit the keyword for their destructors
	//so no need to virtualize the destructor of childerns.
	virtual ~Response();

	
protected:
	//Note: this is for the variables of the parent class that you want to
	//pass on to your childerns
};