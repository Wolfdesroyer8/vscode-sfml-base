//Player class header file
#pragma once

#include "input.hpp"

class Player
{
private:
	float velocity;
	float acceleration;
	float maxVel;

public:
	sf::RectangleShape *charactor;
	//Des / Con
	Player();
	virtual ~Player();
	//Functions
	void update(inputSystem playerInput);
};