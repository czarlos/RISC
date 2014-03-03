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
	owner->setFont(*font);
	owner->setColor(Color::White);
	std::string ownerString = std::string("Owner: ") + binder->getTerritory()->getOwner();
	owner->setString(ownerString);
	owner->setCharacterSize(18);
	owner->setPosition(10, 10);

	Text* production = new Text();
	production->setFont(*font);
	production->setColor(Color::White);

	map<ResourceType*, int> resourceMap;

	for each (ResourceType* resource in binder->getTerritory()->getProduction())
	{
		if (resourceMap.count(resource) == 0) {
			resourceMap[resource] = 1;
		}
		else {
			resourceMap[resource] = resourceMap[resource] + 1;
		}
	}

	std::string productionString = std::string("Production: \n");


	typedef map<ResourceType*, int>::iterator it_type;
	for (it_type iterator = resourceMap.begin(); iterator != resourceMap.end(); iterator++) {

		productionString += iterator->first->getResourceName() + " " + to_string(resourceMap[iterator->first]) + "\n";
	}

	production->setString(productionString);
	production->setCharacterSize(18);
	production->setPosition(10, 50);

	Text* units = new Text();
	units->setFont(*font);
	units->setColor(Color::White);
	units->setString("Units: ");
	units->setCharacterSize(18);
	units->setPosition(10, 120);

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

PopupWindows::~PopupWindows() {

}