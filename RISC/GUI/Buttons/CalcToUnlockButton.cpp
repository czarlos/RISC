#include "CalcToUnlockButton.h"

CalcToUnlockButton::CalcToUnlockButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Calculate Cost To Unlock");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void CalcToUnlockButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		sf::RenderWindow calcToUnlockInfo(sf::VideoMode(320, 480), "Calculate Cost To Unlock");

		UnitPainter* background = new UnitPainter(&calcToUnlockInfo);
		calcToUnlockInfo.setPosition(Vector2i(100, 50));

		this->initButtons(&calcToUnlockInfo, this->techManager);

		while (calcToUnlockInfo.isOpen()) {
			sf::Event ex;
			while (calcToUnlockInfo.pollEvent(ex))
			{
				if (ex.type == sf::Event::Closed) {
					calcToUnlockInfo.close();
				}
			}
			this->setEventForButtons(ex);
			background->paintBackground("Resources/carbon.jpg");

			
			this->updateButtons();
			TextToDisplay::displayText(&calcToUnlockInfo, "This is the total Cost: ",this->font, 0, 180);
			calcToUnlockInfo.display();
		}
		this->deleteButtons();
	}
}

void CalcToUnlockButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

void CalcToUnlockButton::setEventForButtons(sf::Event event){
	for (vector<Button*>::iterator iter = this->buttons.begin(); iter != this->buttons.end(); iter++){
		(*iter)->setEvent(event);
	}

}

void CalcToUnlockButton::initButtons(sf::RenderWindow* window, TechnologyManager* techManager){
	this->buttons = vector<Button*>();
	this->buttons.push_back(new InfantryButton(window, .5, .5, 170, 25, 0, 0));
	this->buttons.push_back(new AutomaticWeaponsButton(window, .5, .5, 170, 25, 0, 30));
	this->buttons.push_back(new RocketLauncherButton(window, .5, .5, 170, 25, 0, 60));
	this->buttons.push_back(new TankButton(window, .5, .5, 170, 25, 0, 90));
	this->buttons.push_back(new ImprovedTanksButton(window, .5, .5, 170, 25, 0, 120));
	this->buttons.push_back(new FighterPlanesButton(window, .5, .5, 170, 25, 0, 150));

	for (vector<Button*>::iterator iter = this->buttons.begin(); iter != this->buttons.end(); iter++){
		(*iter)->setTechManager(techManager);
	}

}

void CalcToUnlockButton::deleteButtons(){
	for (vector<Button*>::iterator iter = this->buttons.begin(); iter != this->buttons.end(); iter++){
		delete((*iter));
	}
	
}

void CalcToUnlockButton::updateButtons(){
	for (vector<Button*>::iterator iter = this->buttons.begin(); iter != this->buttons.end(); iter++){
		(*iter)->updateButtonStatus();

	}
}

CalcToUnlockButton::~CalcToUnlockButton(){

}