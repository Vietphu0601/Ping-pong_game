#pragma once

#include "Entity.h"


class Mobility : public Entity 
{
    private:

		// velocity
        double vel;

		// direction: dx, dy in -1 -> 1
		double dx, dy;


    public:

		Mobility(double x, double y) : Entity(x, y){}

		//logic
		void move(double dx, double dy, double vel);

		//getter, setter
		double getVel() {return vel;}
		void setVel(double _vel){vel = _vel;}

		double getDx() {return dx;}
		double getDy() {return dy;}
		void setDx(double _dx){dx = _dx;}
		void setDy(double _dy){dy = _dy;}	
};