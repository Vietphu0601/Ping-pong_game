#pragma once

#include <SFML/Graphics.hpp>


class Menu {
public:
	Menu();
	void loadMedia();
	int HandleMouseClick(sf::Vector2f mousePos);
	void render(sf::RenderWindow* window);

	int getMenuIndex() {return menuIndex;}
	void renderOption(sf::RenderWindow* window);
	void renderInstruction(sf::RenderWindow* window);
	void renderWinState(sf::RenderWindow* window, int winState, int level, int isOnePlayer);
	void renderSelect(sf::RenderWindow* window);
	void selectPlayer(sf::RenderWindow* window);
	void renderTextLevel(sf::RenderWindow *window, int level);
	

private:
	std::string menuText[16];
	sf::Font font;
	sf::Text menuItems[16];

	sf::Texture texture;
	sf::Text title;
	sf::Sprite background;
	sf::RectangleShape rectangle[16];
	int menuIndex;

	sf::Text levelText;
};