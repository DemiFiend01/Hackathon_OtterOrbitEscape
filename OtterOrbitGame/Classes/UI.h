#pragma once
#ifndef UI_CLASS
#define UI_CLASS

#include <SFML/Graphics.hpp>

class UI
{
public:
	UI(const sf::Font& font);
	~UI(){};

	void update(const sf::Vector2f& position, const sf::Vector2f& velocity, float fuel);
	void render(sf::RenderWindow& window) const;

private:
	sf::RectangleShape ui_background;
	sf::Text position;
	sf::Text velocity;
	sf::Text fuel;

	void updateText();
	sf::Vector2f playerPosition;
	sf::Vector2f playerVelocity;
	float playerFuel;
};

#endif
