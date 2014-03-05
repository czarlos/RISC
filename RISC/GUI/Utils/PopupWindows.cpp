#include "PopupWindows.h"

PopupWindows::PopupWindows() {

}

void PopupWindows::addInfoPanel(Board* board, TerritoryBinder* binder) {
	RenderWindow info(sf::VideoMode(320, 480), "Information Panel");
	info.setPosition(Vector2i(0, 0));
	UnitPainter* info_up = new UnitPainter(&info);

	Font* font = new Font();
	font->loadFromFile("Resources/Fonts/arial.ttf");

	Text* owner = new Text();
	std::string ownerString = std::string("Owner: ") + binder->getTerritory()->getOwner();
	makeText(owner, ownerString, font, 10, 10, 14);

	Text* production = new Text();
	string productionString = makeProductionString(binder);
	makeText(production, productionString, font, 10, 50, 14);

	Text* units = new Text();
	string unitString = makeInfoString(binder);
	makeText(units, unitString, font, 10, 120, 14);

	cout << Mouse::getPosition().x << " " << Mouse::getPosition().y << endl;
	while (info.isOpen()) {
		sf::Event e;
		while (info.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) {
				info.close();
			}
		}
		info_up->paintBackground("Resources/carbon.jpg");

		info.draw(*owner);
		info.draw(*production);
		info.draw(*units);

		info.display();
	}

	delete(info_up);
	delete(font);
	delete(owner);
	delete(production);
	delete(units);
}

void PopupWindows::makeText(Text* text, string str, Font* font, int x, int y, int size) {
	text->setFont(*font);
	text->setColor(Color::White);
	text->setString(str);
	text->setCharacterSize(size);
	text->setPosition(x, y);
}

string PopupWindows::makeInfoString(TerritoryBinder* binder) {
	map<string, int> unitMap;

	for each (Unit* unit in binder->getTerritory()->getTerritoryContents())
	{
		if (unitMap.count(unit->getUnitType()->getType()) == 0) {
			unitMap[unit->getUnitType()->getType()] = 1;
		}
		else {
			unitMap[unit->getUnitType()->getType()] += 1;
		}
	}

	std::string unitString = std::string("Unit: \n");

	for (map<string, int>::iterator it = unitMap.begin(); it != unitMap.end(); ++it) {
		unitString += it->first + " " + to_string(unitMap[it->first]) + "\n";

	}

	return unitString;

}

string PopupWindows::makeProductionString(TerritoryBinder* binder) {
	map<string, int> resourceMap;

	for each (ResourceType* resource in binder->getTerritory()->getProduction())
	{
		if (resourceMap.count(resource->getResourceName()) == 0) {
			resourceMap[resource->getResourceName()] = 1;
		}
		else {
			resourceMap[resource->getResourceName()] += 1;
		}
	}

	std::string productionString = std::string("Production: \n");


	for (map<string, int>::iterator iterator = resourceMap.begin(); iterator != resourceMap.end(); iterator++) {

		productionString += iterator->first + " " + to_string(resourceMap[iterator->first]) + "\n";
	}
	return productionString;
}

void PopupWindows::addOrderPanel(Board* board, TerritoryBinder* binder) {
	RenderWindow info(sf::VideoMode(200, 200), "Order Panel");
	info.setPosition(Vector2i(0, 0));
	UnitPainter* info_up = new UnitPainter(&info);

	Font* font = new Font();
	font->loadFromFile("Resources/Fonts/arial.ttf");

	Text* owner = new Text();
	std::string ownerString = std::string("Owner: ") + binder->getTerritory()->getOwner();
	makeText(owner, ownerString, font, 10, 10, 14);

	while (info.isOpen()) {
		sf::Event e;
		while (info.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) {
				info.close();
			}
		}
		info_up->paintBackground("Resources/carbon.jpg");

		info.draw(*owner);

		info.display();
	}
}

PopupWindows::~PopupWindows() {

}