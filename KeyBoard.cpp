#include "KeyBoard.h"

KeyBoard::KeyBoard() {
	isMultiPlayer = true;
}

KeyBoard::~KeyBoard() {
	isMultiPlayer= false;
}

bool KeyBoard::getIsMultiPlayer() {
	return this->getIsMultiPlayer();
}

void KeyBoard::pressKey() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			
	}

	if (getIsMultiPlayer()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			
		}
	}
}

void KeyBoard::setMultiPlayer(bool isMultiPlayer) {
	this->isMultiPlayer = isMultiPlayer;
}