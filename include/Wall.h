#include "Entity.h"

class Wall : public Entity {

    private:

    public:
		Wall(double x, double y) : Entity(x, y){}
		Wall(double x, double y, double w, double h){
			setX(x);
			setY(y);
			setWidth(w);
			setHeight(h);
		}

		Wall(double x, double y, double w, double h, sf::Color c){
			setX(x);
			setY(y);
			setWidth(w);
			setHeight(h);
			setColor(c);
		}

		void changeColor(sf::Color c) {setColor(c);}


		void render(sf::RenderWindow *window);

};