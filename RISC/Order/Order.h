#pragma once

#include <iostream>

class Order {
public:
	Order();
	virtual ~Order() {};
	virtual void execute() = 0;
};

