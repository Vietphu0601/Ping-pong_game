#include "Mobility.h"

class Player : public Mobility
{
    private:
		int score;
		sf::Font font;

		int scorePosX;
		int scorePosY;

    public:
		Player(double x, double y) : Mobility(x, y){
			setWidth(5.f);
			setHeight(50.f);
			score = 0;
			font.loadFromFile("res/font/arial.ttf");
		}

		void render(sf::RenderWindow *window);

		int getScore(){return score;}
		void setScore(int s){score = s;}

		void setScorePosX(int x){scorePosX = x;}
		void setScorePosY(int y){scorePosY = y;}
		int getScorePosX(){return scorePosX;}
		int getScorePosY(){return scorePosY;}
};