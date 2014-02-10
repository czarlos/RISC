/*
 * Tester.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include <iostream>
#include "MyEngine.h"

using namespace sge_base;
using namespace std;

int main () {
	MyEngine * g = new MyEngine();

	g->runGame();


	delete g;
 	cout << "LOLZ" << endl;
	return 0;
}


