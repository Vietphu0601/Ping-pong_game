#include "Wall.h"

void Wall::render(sf::RenderWindow *window){
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(getWidth(), getHeight()));
	shape.setFillColor(getColor());
	shape.setPosition(getX(), getY());
	window->draw(shape);
}