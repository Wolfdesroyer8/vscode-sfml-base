//this file is the main file with the game loop and event loop

#include "deps.hpp"
#include "input.hpp"
#include "game.hpp"
#include "player.hpp"

//creates a new game, player, and inputsystem object
Game game;
Player player;
inputSystem playerInput;

Game::Game()
{
	//creates the window
	this->videoMode = sf::VideoMode(1000, 600);
	this->window = new sf::RenderWindow(videoMode, "SFML");
}

Game::~Game()
{
	//removes window for memory to prevent memory leak
	delete this->window;
}

//make an accsesor for the main loop so the loop can be in any file
const bool Game::running() const
{
	return this->window->isOpen();
}

//updates everything
void Game::update()
{
	game.event();
	player.update(playerInput);
}

void Game::render()
{
	//clears past window
	this->window->clear();
	//put draw functions here
	this->window->draw(*player.charactor);
	//displayer new frame drawing
	this->window->display();
};

//event loop
void Game::event()
{
	while (this->window->pollEvent(this->ev))
	{
		//makes switch case for the event
		switch (this->ev.type)
		{
		//make it so when you press close it actually closes the window
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			//movement input
			if (this->ev.key.code == sf::Keyboard::W)
			{
				playerInput.upKeyDown = true;
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::A)
			{
				playerInput.leftKeyDown = true;
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::S)
			{
				playerInput.downKeyDown = true;
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::D)
			{
				playerInput.rightKeyDown = true;
				break;
			}
			//closes window when pressing escape
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
			break;
		case sf::Event::KeyReleased:
			//movement input
			if (this->ev.key.code == sf::Keyboard::W)
			{
				playerInput.upKeyDown = false;
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::A)
			{
				playerInput.leftKeyDown = false;
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::S)
			{
				playerInput.downKeyDown = false;
				break;
			}
			else if (this->ev.key.code == sf::Keyboard::D)
			{
				playerInput.rightKeyDown = false;
				break;
			}
		}
	}
}

void gameLoop()
{
	//Game Loop
	while (game.running())
	{
		game.update();
		game.render();
	}
}

//for linux, mac
int main()
{
	gameLoop();
}

//for windows
int WinMain()
{
	gameLoop();
}