#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>


void Ball::render(sf::RenderWindow *window){
	int x = getX(), y = getY(), dx = getDx(), dy = getDy();
	
	int i = (clock.getElapsedTime().asMilliseconds() / 60) % 6;
	i = i + ballType * 6;
	sprite.setTexture(texture[i]);

	if (dx == 1) {
		if (dy == 1) {
			sprite.setRotation(225);
			sprite.setPosition(sf::Vector2f(x, y + 19)); 
		} else {
			sprite.setRotation(135);
			sprite.setPosition(sf::Vector2f(x + 19, y + 9));
		}
	} else if (dx == -1) {
		if (dy == 1) {
			sprite.setRotation(315);
			sprite.setPosition(sf::Vector2f(x-8, y+1));
		} else {
			sprite.setRotation(45);
			sprite.setPosition(sf::Vector2f(x+10, y-8));
		}
	} else if (dx == 2) {
		if (dy == 1) {
			sprite.setRotation(210);
			sprite.setPosition(sf::Vector2f(x + 5, y + 20));
		} else if (dy == -1) {
			sprite.setRotation(150);
			sprite.setPosition(sf::Vector2f(x + 17, y + 13));
		} else if (dy == 2) {
			sprite.setRotation(225);
			sprite.setPosition(sf::Vector2f(x+1, y + 19));
		} else if (dy == -2) {
			sprite.setRotation(135);
			sprite.setPosition(sf::Vector2f(x + 19, y + 9));
		} else if (dy == 0){
			sprite.setRotation(180);
			sprite.setPosition(sf::Vector2f(x+10, y+19)); 
		}
	} else if (dx == -2) {
		if (dy == 1) {
			sprite.setRotation(330);
			sprite.setPosition(sf::Vector2f(x-7, y-3));
		} else if (dy == -1) {
			sprite.setRotation(30);
			sprite.setPosition(sf::Vector2f(x+6, y-9));
		} else if (dy == 2) {
			sprite.setRotation(315);
			sprite.setPosition(sf::Vector2f(x-8, y+1));
		} else if (dy == -2) {
			sprite.setRotation(45);
			sprite.setPosition(sf::Vector2f(x+10, y-8));
		} else if (dy == 0){
			sprite.setRotation(0);
			sprite.setPosition(sf::Vector2f(x, y-7)); 
		}
	} else if (dy == 0){
		if (dx > 0) {
			sprite.setRotation(180);
			sprite.setPosition(sf::Vector2f(x+10, y+19)); 
		} else if (dx < 0){
			sprite.setRotation(0);
			sprite.setPosition(sf::Vector2f(x, y-7)); 
		}
	}

	sf::CircleShape p = sf::CircleShape(5.f);
	p.setPosition(getX(), getY());
	p.setFillColor(getColor());
	window->draw(p);
	window->draw(sprite);
}

void Ball::move(std::list<Entity*> listEntity){
	double x = this->getX();
	double y = this->getY();
	double dx = this->getDx();
	double dy = this->getDy();
	double vel = this->getVel();

	for(std::list<Entity*>::iterator it=listEntity.begin();it!=listEntity.end();++it)
    {       
			double xx = (*it)->getX();
			double yy = (*it)->getY();
			double ww = (*it)->getWidth();
			double hh = (*it)->getHeight();
			if (x == xx && y == yy && getWidth() == ww && getHeight() == hh) continue;

			if (checkColision(xx, yy, ww, hh) == 1 || checkColision(xx, yy, ww, hh) == 3) {
				setDy(-dy);
				this->setX(x += getDx());
				this->setY(y += getDy());
				break;
			} 
			if (checkColision(xx, yy, ww, hh) == 2 || checkColision(xx, yy, ww, hh) == 4) {
				int signY = (dy > 0) ? 1 : -1;
				dy = (rand() % 3) * signY;
				if (rand() % 5 == 0) dy = - dy;
				if (dx == 1 || dx == -1 ) dx *= 2;

				if (dy == 0) {
					if (abs(dx) == 2) dx *= 2;
				}
				else dx = dx / abs(dx) * 2;

				setDx(-dx);
				setDy(dy);
				
				this->setX(x += getDx());
				this->setY(y += getDy());
				break;
			}
    }

	this->setX(x += getDx() * vel);
	this->setY(y += getDy() * vel);

}

void Ball::initBall(double dx, double dy, double vel){
	setX(500);
	setY(350);
	setDx(dx);
	setDy(dy);
	setVel(vel);

	texture[0].loadFromFile("res/sprite/blue/1.png");
	texture[1].loadFromFile("res/sprite/blue/2.png");
	texture[2].loadFromFile("res/sprite/blue/3.png");
	texture[3].loadFromFile("res/sprite/blue/4.png");
	texture[4].loadFromFile("res/sprite/blue/5.png");
	texture[5].loadFromFile("res/sprite/blue/6.png");
	texture[6].loadFromFile("res/sprite/red/1.png");
	texture[7].loadFromFile("res/sprite/red/2.png");
	texture[8].loadFromFile("res/sprite/red/3.png");
	texture[9].loadFromFile("res/sprite/red/4.png");
	texture[10].loadFromFile("res/sprite/red/5.png");
	texture[11].loadFromFile("res/sprite/red/6.png");
	texture[12].loadFromFile("res/sprite/pink/1.png");
	texture[13].loadFromFile("res/sprite/pink/2.png");
	texture[14].loadFromFile("res/sprite/pink/3.png");
	texture[15].loadFromFile("res/sprite/pink/4.png");
	texture[16].loadFromFile("res/sprite/pink/5.png");
	texture[17].loadFromFile("res/sprite/pink/6.png");
	
}

void Ball::update(std::list<Entity*> listEntity){
	move(listEntity);
}