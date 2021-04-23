#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class App {
private:
	sf::RenderWindow* window;
	sf::Event event;

	GameObject* background;
	GameObject* field;


public:
	App();
	~App();
};

