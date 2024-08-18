#include "Mobility.h"

void Mobility::move(double dx, double dy, double vel) {
	double x = this->getX();
	double y = this->getY();
	this->setX(x += dx * vel);
	this->setY(y += dy * vel);
}