#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Entity 
{
    private:
		double width;
		double height;

		double x;
		double y;

		sf::Color color;
    public:

		Entity();
		Entity(double x, double y);
		~Entity();

		virtual void render(sf::RenderWindow *window) = 0;

		int checkColision(double xx, double yy, double ww, double hh);

		double getX() {return x;}
		double getY() {return y;}
		void setX(double _x){x = _x;}
		void setY(double _y){y = _y;}
		double getWidth() {return width;}
		double getHeight() {return height;}
		void setWidth(double _x){width = _x;}
		void setHeight(double _y){height = _y;}

		sf::Color getColor() {return color;}
		void setColor(sf::Color c){color = c;}

};