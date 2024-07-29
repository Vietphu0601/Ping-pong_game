#include "Mobility.h"

class Ball : public Mobility
{
	private:

		  sf::Texture texture[18];
		  sf::Clock clock;
		  sf::Sprite sprite;
		  int ballType;

	public:

		

		Ball(double x, double y) : Mobility(x, y){
		    setWidth(10.f);
			setHeight(10.f);
		}

		Ball(double x, double y, int type) : Mobility(x, y){
		    setWidth(10.f);
			setHeight(10.f);
			ballType = type;
		}


		void setBallType(int ballType) {
			this->ballType = ballType;
		}
		

		void render(sf::RenderWindow *window);

		void move(std::list<Entity*> listEntity);

		void initBall(double dx, double dy, double vel);

		void setPos(double x, double y);

		void update(std::list<Entity*> listEntity);
};