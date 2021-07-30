//Game class header file
#pragma once

#include "player.hpp"

class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;

public:
	//Des / Con
	Game();
	virtual ~Game();
	//Accessors
	const bool running() const;
	//Functions
	void event();
	void update();
	void render();
};