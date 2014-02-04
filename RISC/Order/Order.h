#pragma once

#include <iostream>

class Order {
public:
	Order();
	virtual ~Order() {};
protected:
	virtual void execute() = 0;
};

