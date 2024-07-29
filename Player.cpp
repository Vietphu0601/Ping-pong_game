#include "Player.h"
#include <SFML/Graphics.hpp>

void Player::render(sf::RenderWindow *window){
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(getWidth(), getHeight()));
	shape.setPosition(getX(), getY());
	window->draw(shape);

	sf::Text text(std::to_string(score), font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setPosition(scorePosX, scorePosY);
	// Draw it
	window->draw(text);
}