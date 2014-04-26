#include "TerritoryBinder.h"

TerritoryBinder::TerritoryBinder() {

}

TerritoryBinder::TerritoryBinder(Territory* territory, Shape* shape) {
	this->myTerritory = territory;
	this->myShape = shape;
}

Territory* TerritoryBinder::getTerritory() {
	return this->myTerritory;
}

Shape* TerritoryBinder::getShape() {
	return this->myShape;
}

TerritoryBinder::~TerritoryBinder() {

}