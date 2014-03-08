#pragma once
#include "Button.h"
#include "../../GameState/Managers/ResourceManager.h"

class ResourceManagerButton :public Button{
public:
	ResourceManagerButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setResourceManager(ResourceManager*);
	virtual ~ResourceManagerButton();

private:
	ResourceManager * resourceManager;
};