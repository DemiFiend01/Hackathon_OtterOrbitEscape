#include"UI.h"

UI::UI(const sf::Font& font): playerPosition(0.0f, 0.0f), playerVelocity(0.0f, 0.0f)
, playerFuel(100.0f)
{
	//Background setup
	ui_background.setSize(sf::Vector2f(200.0f, 100.0f));
	ui_background.setFillColor(sf::Color(0, 0, 0, 150)); // semi-transparent black
	ui_background.setPosition(1000.0f, 1000.0f); // bottom - right corner

	//Text setup
	position.setFont(font);
	velocity.setFont(font);
	fuel.setFont(font);

	position.setCharacterSize(14);
	velocity.setCharacterSize(14);
	fuel.setCharacterSize(14);

	position.setFillColor(sf::Color::White);
	velocity.setFillColor(sf::Color::White);
	fuel.setFillColor(sf::Color::White);

	position.setPosition(1000.0f, 510.0f);
	velocity.setPosition(1000.0f, 530.0f);
	fuel.setPosition(1000.0f, 550.0f);
}

void UI::update(const sf::Vector2f& position, const sf::Vector2f& velocity, float fuel)
{
	playerPosition = position;
	playerVelocity = velocity;
	playerFuel = fuel;
	
	updateText();
}

void UI::updateText()
{
	position.setString("Pos: (" + std::to_string((int)playerPosition.x) + ", " + std::to_string((int)playerPosition.y) + ")");
	velocity.setString("Vel: (" + std::to_string((int)playerVelocity.x) + ", " + std::to_string((int)playerVelocity.y) + ")");
	fuel.setString("Fuel: " + std::to_string((int)playerFuel) + "%");
}

void UI::render(sf::RenderWindow& window) const 
{
	window.draw(ui_background);
	window.draw(position);
	window.draw(velocity);
	window.draw(fuel);
}