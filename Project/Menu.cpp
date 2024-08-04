#include "Menu.h"
#include <iostream>

int Menu::HandleMouseClick(sf::Vector2f mousePos) {
	for (int i = 0; i <= 11; i++) {
		sf::FloatRect itemBounds = menuItems[i].getGlobalBounds();
		if (itemBounds.contains(mousePos)) {
			menuItems[i].setColor(sf::Color(0, 0, 128));
			menuIndex = i;
		} else {
			menuItems[i].setColor(sf::Color::White);
		}
	}
	return menuIndex;
}

void Menu::render(sf::RenderWindow* window) {
	window->draw(background);
	for (int i = 0; i < 3; i++) {
		window->draw(menuItems[i]);
	}
	
}

void Menu::renderOption(sf::RenderWindow* window) {
	for (int i = 3; i < 6; i++) {
		window->draw(menuItems[i]);
	}
}

void Menu::renderInstruction(sf::RenderWindow* window) {
	window->draw(background);
	for (int i = 12; i < 16; i++) {
		window->draw(menuItems[i]);
	}
	window->draw(menuItems[4]);
}

void Menu::selectPlayer(sf::RenderWindow* window){
	window->draw(background);
	for (int i = 6; i < 8; i++) {
		window->draw(menuItems[i]);
	}
	window->draw(menuItems[4]);
}

void Menu::renderWinState(sf::RenderWindow* window, int winState, int level, int isOnePlayer) {
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(400, 200);
	if (winState == 1 && isOnePlayer == 1) text.setString("VERY NICE! YOU WIN");
	else if (winState == 2 && isOnePlayer == 1) text.setString("YOU LOSE AI !");
	else if (winState == 2) text.setString("PLAYER 2 WIN!");
	else if (winState == 1) text.setString("PLAYER 1 WIN!");
	window->draw(background);
	window->draw(text);

	for (int i = 4; i < 6; i++) {
		window->draw(menuItems[i]);
	}

	if (level != 3 && isOnePlayer != 1) {
		window->draw(menuItems[8]);
	}
	
}

void Menu::renderTextLevel(sf::RenderWindow* window, int level) {
	if (level == 1) {
		levelText.setString("Level 1: Easy");
	} else if (level == 2) {
		levelText.setString("Level 2: Medium");
	} else if (level == 3) {
		levelText.setString("Level 3: Hard");
	}
	window->draw(levelText);
}

void Menu::renderSelect(sf::RenderWindow* window) {
	window->draw(background);
	for (int i = 9; i <= 11; i++) {
		window->draw(menuItems[i]);
	}
	window->draw(menuItems[4]);
}




void Menu::loadMedia()
{
	font.loadFromFile("res/font/arial.ttf");

	menuText[0] = "Play";
	menuText[1] = "Instruction";
	menuText[2] =  "Exit";
	menuText[3] = "Resume";
	menuText[4] = "Back to Menu";
	menuText[5] = "Restart";
	menuText[6] = "One player";
	menuText[7] = "Two players";
	menuText[8] = "Next Level";
	menuText[9] = "Level 1";
	menuText[10] = "Level 2";
	menuText[11] = "Level 3";
	menuText[12] = "Up: Move Up";
	menuText[13] = "Down: Move Down";
	menuText[14] = "W: Move Up";
	menuText[15] = "S: Move Down";

	for (int i = 0; i < 3; i++) {
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(100, 100 + i * 100);
		text.setString(menuText[i]);
		menuItems[i] = text;
	}

	for (int i = 3; i < 6; i++) {
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(100, 100 + i * 100);
		text.setString(menuText[i]);
		menuItems[i] = text;
	}
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(200, 600);
	text.setString(menuText[8]);
	menuItems[8] = text;

	levelText.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(400, 50);

	for (int i = 6; i < 8; i++)
	{
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(300, 100 + (i-6) * 100);
		text.setString(menuText[i]);
		menuItems[i] = text;
	}

	for (int i = 12; i < 16; i++)
	{
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(500, 100 + (i-12) * 100);
		text.setString(menuText[i]);
		menuItems[i] = text;
	}


	for (int i = 9; i <= 11; i++) {
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(200 + (i - 9) * 200, 200);
		text.setString(menuText[i]);
		menuItems[i] = text;
	}

	texture.loadFromFile("res/img/background.jpg");
	background.setTexture(texture);
}

Menu::Menu() {
	menuIndex = -1;
}


