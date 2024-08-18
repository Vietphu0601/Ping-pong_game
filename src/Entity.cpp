#include "Entity.h"
#include <iostream>

Entity::Entity() {

}

Entity::~Entity() {

}

Entity::Entity(double x, double y) {
	this->setX(x);
	this->setY(y);
}

int Entity::checkColision(double xx, double yy, double ww, double hh){
	if ( (x > xx + ww || x + width < xx) || (y > yy + hh || y + height < yy) ) return 0;

	if ( x >= xx && x <= xx + ww && x + width > xx + ww && (y >= 150 && y + height <= 650)) return 4;
	else if ( x+width >= xx && x+width <= xx + ww && x < xx && (y >= 150 && y + height <= 650)) return 2;
	else if ( y >= yy && y <= yy + hh && y + height > yy + hh ) return 1;
	else if ( y + height >= yy && y <= yy + hh && y < yy) return 3;
	
}