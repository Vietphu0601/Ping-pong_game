/*
#include "SFML/Graphics.hpp"
#include <iostream>

int main(int argc, char ** argv){
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

  sf::Event event;
  sf::Texture texture[6];
  texture[0].loadFromFile("res/sprite/blue/1.png");
  texture[1].loadFromFile("res/sprite/blue/2.png");
  texture[2].loadFromFile("res/sprite/blue/3.png");
  texture[3].loadFromFile("res/sprite/blue/4.png");
  texture[4].loadFromFile("res/sprite/blue/5.png");
  texture[5].loadFromFile("res/sprite/blue/6.png");
  sf::Clock clock;

  sf::Font font;
  if (!font.loadFromFile("res/font/arial.ttf")) {
	std::cout << "Hello you idiots" << std::endl;
  }
  sf::Text text;
  text.setFont(font);

  text.setString("Hello World");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);


  sf::Sprite sprite(texture[0],sf::IntRect(0,0,49,19));

 int i = 0;
  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }
	
	if (clock.getElapsedTime().asMilliseconds() > 100.f){
		i++;
		if (i == 6) {
			i = 0;
		}
		//text.setString("Hello World " + std::to_string (i));
		sprite.setTexture(texture[i]);
	
      clock.restart();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
	//renderWindow.draw(text);
    renderWindow.display();
  }
}*/