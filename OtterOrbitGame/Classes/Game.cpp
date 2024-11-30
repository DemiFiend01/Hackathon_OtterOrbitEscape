#include "Game.h"
#include "UI.h"
#include <cmath>
#


/*const float Game::SATURN_RADIUS = 50.0f; // Saturn radius [const value]
const float Game::ORBIT_DISTANCE_INCREMENT = 100.0f;
const int Game::ORBIT_COUNT = 4; //Our Orbit amount is 4*/

/*Game::Game() {
	mWindow = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hyperion");


	mWindow->setFramerateLimit(60); // Frame rate 60 FPS


}

void Game::run()
{
	while (mWindow->isOpen())
	{

	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mWindow->close();
		}
	}

	//Handling the spaceship?
}

void Game::update(float delta_time)
{
	//updating the shaceship position.
}

void Game::render()
{

}*/

// -----------------------UI-------------------------

sf::Font font;
UI ui(font);

Game::Game()
{
	mWindow = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hyperion");
	//mWindow->setFramerateLimit(60); // Frame rate 60 FPS

	if (!font.loadFromFile("Jersey15-Regular.ttf"))
	{
		throw std::runtime_error("Unable to load font!");
	}

	ui = new UI(font);

	this->pH1.pos = sf::Vector2f(900.0f, 500.0f);
	this->pH2.pos = sf::Vector2f(500.0f, 500.0f);

	this->pH1.rectangle.setPosition(sf::Vector2f(750.0f, 500.0f));
	this->pH2.rectangle.setPosition(sf::Vector2f(100.0f, 500.0f));

	this->pH2.velocity = sf::Vector2f(0.0f, -500.0f);

	this->pH1.gravityConst = 1.0f;
	this->pH2.gravityConst = 100000000.0f;
}

Game::~Game()
{
	delete mWindow;
	delete ui;
}

void Game::run()
{
	while (mWindow->isOpen())
	{
		deltaTime = clk.restart().asSeconds();

		processEvents();
		update(deltaTime);
		render(deltaTime);
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mWindow->close();
		}
	}
}

void Game::update(float deltaTime)
{
	ui->update(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(5.0f, -3.0f), 75.0f);

	Physics::applyGravityForce(this->pH1, this->pH2);

	pH1.updatePosition(deltaTime);
	pH2.updatePosition(deltaTime);

	pH1.applyForces(deltaTime);
	pH2.applyForces(deltaTime);

	pH1.updatePosition(deltaTime);
	pH2.updatePosition(deltaTime);
}

void Game::render(float deltaTime)
{
	mWindow->clear(sf::Color::Black);

	ui->render(*mWindow);

	mWindow->draw(this->pH1.rectangle);
	mWindow->draw(this->pH2.rectangle);

	mWindow->display();
}
