#include "Game.h"

/* Static Functions */

/* Initializer Functions */

void Game::initWindow()
{
	// initialize settings
	std::string sWindowTitle = "Window Title";
	sf::VideoMode vmWindowBounds(800, 600);
	unsigned int uFramerateLimit = 120;
	bool bVSyncEnabled = false;

	// overwrite settings using .ini file
	std::ifstream ifsSettings("Config/settings.ini");
	if (ifsSettings.is_open()) {
		std::getline(ifsSettings, sWindowTitle);
		ifsSettings >> vmWindowBounds.width >> vmWindowBounds.height;
		ifsSettings >> uFramerateLimit;
		ifsSettings >> bVSyncEnabled;
	}
	ifsSettings.close();

	this->gameWindow = new sf::RenderWindow(vmWindowBounds, sWindowTitle);
	this->gameWindow->setFramerateLimit(uFramerateLimit);
	this->gameWindow->setVerticalSyncEnabled(bVSyncEnabled);
	return;
}

/* Constructors/Destructors */

Game::Game()
{
	this->initWindow();
	return;
}


Game::~Game()
{
	delete this->gameWindow;
	return;
}

/* Functions */

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
	std::cout << this->dt << std::endl;
	return;
}

void Game::updateSFMLEvents()
{
	while (this->gameWindow->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed) {
			this->gameWindow->close();
		}
	}
	return;
}

void Game::update()
{
	this->updateSFMLEvents();
	return;
}

void Game::render()
{
	this->gameWindow->clear(sf::Color(239, 255, 255));

	// Render items

	this->gameWindow->display();
	return;
}

void Game::run()
{
	while (this->gameWindow->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
	return;
}
