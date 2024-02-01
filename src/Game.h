#pragma once

#include "State.h"

class Game {
public:
	/* Constructors/Destructors */
	Game();
	virtual ~Game();

	/* Functions */
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

private:
	/* Variables */
	sf::RenderWindow *gameWindow;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	/* Initializer Functions */
	void initWindow();
};

