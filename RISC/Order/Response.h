#pragma once

#include <iostream>
#include "../GameState/GameState.h"



class Response {
public:
	//default constructor for Response
	Response();

	//Note: adding a virtual keyword to a method allows childern classes
	//to override what the method does
	virtual void executeResponse(GameState* state);
	//Note: since Response is the parent, it uses keyword Virtual for its destructor
	//its childerns will inherit the keyword for their destructors
	//so no need to virtualize the destructor of childerns.
	virtual ~Response();

	
protected:
	//Note: this is for the variables of the parent class that you want to
	//pass on to your childerns
};