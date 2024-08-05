/*
#include <SFML/Graphics.hpp>
#include <iostream>


void HandleMouseClick(sf::Vector2f mousePos, std::vector<sf::Text> &menuItems) {
	for (int i = 0; i < menuItems.size(); i++) {
			sf::FloatRect itemBounds = menuItems[i].getGlobalBounds();
			if (itemBounds.contains(mousePos)) {
				menuItems[i].setColor(sf::Color::Blue);
			} else {
				menuItems[i].setColor(sf::Color::White);
			}
		}
}

void render(sf::RenderWindow* window, std::vector<sf::Text> menuItems) {
	for (int i = 0; i < menuItems.size(); i++) {
		window->draw(menuItems[i]);
	}
}

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(640, 480), "Demo Game");
	std::string menuText[] = {"Play", "Options", "Exit"};
	sf::Font font;
	font.loadFromFile("res/font/arial.ttf");
	std::vector<sf::Text> menuItems;
	
	for (int i = 0; i < 3; i++) {
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(100, 100 + i * 100);
		text.setString(menuText[i]);
		menuItems.push_back(text);
	}

	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
		  if (event.type == sf::Event::EventType::Closed)
			window->close();
		}

		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
		HandleMouseClick(mousePos, menuItems);
				
		window->clear();
		render(window, menuItems);
		window->display();
	  }
}*/