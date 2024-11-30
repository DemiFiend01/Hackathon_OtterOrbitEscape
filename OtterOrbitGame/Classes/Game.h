#ifndef GAME_HPP
#define GAME_HPP

#include<SFML/Graphics.hpp>
#include "UI.h"

#include <iostream>

#include "Physics.h"
#include "PhysicalObject.h"

class Game
{
public:
	Game();
	~Game();
	void run();

	PhysicalObject pH1;
	PhysicalObject pH2;

	sf::Clock clk;
	float deltaTime;

private:
	void processEvents();
	void update(float deltaTime);
	void render(float deltaTime);

	sf::RenderWindow* mWindow;
	sf::Font font;
	UI* ui;

	static const int WINDOW_WIDTH = 1920;
	static const int WINDOW_HEIGHT = 1080;  
};

#endif