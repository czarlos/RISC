#include "ResourceManagerButton.h"

ResourceManagerButton::ResourceManagerButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Resource Manager");
}

void ResourceManagerButton::setResourceManager(ResourceManager* resourceManager){
	this->resourceManager = resourceManager;
}

void ResourceManagerButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		sf::RenderWindow techManagerInfo(sf::VideoMode(320, 480), "Resource Manager");
		UnitPainter* up = new UnitPainter(&techManagerInfo);
		techManagerInfo.setPosition(Vector2i(0, 0));
		while (techManagerInfo.isOpen()) {
			sf::Event ex;
			while (techManagerInfo.pollEvent(ex))
			{
				if (ex.type == sf::Event::Closed) {
					techManagerInfo.close();
				}
			}
			up->paintBackground("Resources/carbon.jpg");
			techManagerInfo.display();
		}
		delete(up);
	}
}

ResourceManagerButton ::~ResourceManagerButton(){

}