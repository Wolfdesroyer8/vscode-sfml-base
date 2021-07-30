#include "input.hpp"
#include "deps.hpp"

//inits vars to false so they don't cause the player to move without input
inputSystem::inputSystem()
{
	this->upKeyDown = false;
	this->leftKeyDown = false;
	this->downKeyDown = false;
	this->rightKeyDown = false;
	this->jumpKeyDown = false;
}