#include <SFML/System/Time.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

#include "Ball.h"
#include "Player.h"
#include "Wall.h"
#include "Menu.h"
#include "AI.h"

class Game 
{
public:

	bool init();
	bool loadMedia();

	void checkScore();
	bool getGameState() {return gameState;}
	bool getPauseState() {return pauseState;}
	bool getMenuState() {return menuState;}
	void getAImove(double xBall, double yBall, double xPlayer, double yPlayer);
	void loadLevel();
	
	void handleEvents();
	void update();
	void render();

	void run();
	void reset();
	void close();
	
private:
	
	static const int WINDOW_WIDTH = 1000;
	static const int WINDOW_HEIGHT = 700;
	
	sf::RenderWindow *window;

	Entity *ball;
	Entity *player_one;
	Entity *player_two;
	Wall *line;
	Menu *menu;
	std::list<Entity*> listEntity;

	// init wall
	Wall *w1, *w2, *w3, *w4;

	AI *AIBrain;

	bool isMultiplayer;
	
	bool gameState;
	bool pauseState;
	bool menuState;
	bool selectMode;
	bool instructionState;
	int winState;
	int isOnePlayer;

	
	int level;

};