//this file has all the vars and functions related to the player

#include "deps.hpp"
#include "input.hpp"
#include "player.hpp"

Player::Player()
{
	this->charactor = new sf::RectangleShape(sf::Vector2f(35.f, 200.f));
	this->acceleration = 0.00001;
	this->maxVel = 0.05;
	this->velocity = 0.0;
}

Player::~Player()
{
	delete this->charactor;
}

void Player::update(inputSystem playerInput)
{
	//up movement
	if (playerInput.upKeyDown && this->velocity < this->maxVel)
	{
		velocity += acceleration;
		charactor->move(0.f, -velocity);
	}
	else if (playerInput.upKeyDown && this->velocity == this->maxVel)
	{
		charactor->move(0.f, -velocity);
	}
	else if (velocity > maxVel)
	{
		velocity = maxVel;
	}
	//left movement
	if (playerInput.leftKeyDown && this->velocity < this->maxVel)
	{
		velocity += acceleration;
		charactor->move(-velocity, 0.f);
	}
	else if (playerInput.leftKeyDown && this->velocity == this->maxVel)
	{
		charactor->move(-velocity, 0.f);
	}
	else if (velocity > maxVel)
	{
		velocity = maxVel;
	}
	//down movement
	if (playerInput.downKeyDown && this->velocity < this->maxVel)
	{
		velocity += acceleration;
		charactor->move(0.f, velocity);
	}
	else if (playerInput.downKeyDown && this->velocity == this->maxVel)
	{
		charactor->move(0.f, velocity);
	}
	else if (velocity > maxVel)
	{
		velocity = maxVel;
	}
	//right movement
	if (playerInput.rightKeyDown && this->velocity < this->maxVel)
	{
		velocity += acceleration;
		charactor->move(velocity, 0.f);
	}
	else if (playerInput.rightKeyDown && this->velocity == this->maxVel)
	{
		charactor->move(velocity, 0.f);
	}
	else if (velocity > maxVel)
	{
		velocity = maxVel;
	}
}
