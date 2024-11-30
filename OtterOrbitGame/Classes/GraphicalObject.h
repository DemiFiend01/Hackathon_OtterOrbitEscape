#ifndef GRAPHICAL_OBJECT_CLASS
#define GRAPHICAL_OBJECT_CLASS

#include <SFML/Graphics.hpp>

class GraphicalObject
{
	sf::RectangleShape object;

	sf::RenderWindow win;

public:
	//constructors and destructors
	GraphicalObject();
	~GraphicalObject();
	//functions:
	void setGraphics();
};

#endif // !GRAPHICAL_OBJECT_CLASS

