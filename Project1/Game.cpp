#include "Game.h"

#include <iostream>



const sf::Keyboard::Key controls[5] = {
	sf::Keyboard::W,
	sf::Keyboard::S,
	sf::Keyboard::Up,
	sf::Keyboard::Down,
	sf::Keyboard::P
};

bool Game::init() {
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong Game");
	menuState = true;
	gameState = true;
	pauseState = false;
	isOnePlayer = -2;
	instructionState = false;

	menu = new Menu();
	ball = new Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 1);
	player_one = new Player(25, WINDOW_HEIGHT / 2);
	player_two = new Player(970, WINDOW_HEIGHT / 2);
	static_cast<Player*>(player_one)->setScorePosX(400);
	static_cast<Player*>(player_one)->setScorePosY(100);
	static_cast<Player*>(player_two)->setScorePosX(590);
	static_cast<Player*>(player_two)->setScorePosY(100);

	line = new Wall(500, 150, 1, 500, sf::Color::White);

	static_cast<Ball*>(ball)->initBall(1, 1, 0.2);

	// init wall
	w1 = new Wall(0, 145, 1000, 5, sf::Color(119, 247, 247));
	w2 = new Wall(995, 150, 5, 500, sf::Color(119, 247, 247));
	w3 = new Wall(0, 650, 1000, 5, sf::Color(119, 247, 247));
	w4 = new Wall(0, 150, 5, 500, sf::Color(119, 247, 247));
	listEntity.push_back(w1);
	listEntity.push_back(w2);
	listEntity.push_back(w3);
	listEntity.push_back(w4);

	listEntity.push_back(ball);
	listEntity.push_back(player_one);
	listEntity.push_back(player_two);

	
	// font.loadFromFile("res/font/arial.ttf");
	// level_text.setFont(font);
	// level_text.setPosition(200, 200);
	// level_text.setString("Level " + std::to_string(level));

	return true;
}

bool Game::loadMedia() {

	menu->loadMedia();
	return true;
}


void Game::loadLevel() {
	if (level == 1) {
		w1->changeColor(sf::Color(79, 195, 247));
		w2->changeColor(sf::Color(79, 195, 247));
		w3->changeColor(sf::Color(79, 195, 247));
		w4->changeColor(sf::Color(79, 195, 247));
		static_cast<Ball*>(ball)->setBallType(level - 1);
	} else if (level == 2) {
		w1->changeColor(sf::Color(244, 67, 54));
		w2->changeColor(sf::Color(244, 67, 54));
		w3->changeColor(sf::Color(244, 67, 54));
		w4->changeColor(sf::Color(244, 67, 54));
		static_cast<Ball*>(ball)->setBallType(level - 1);
	} else {
		w1->changeColor(sf::Color(240, 98, 146));
		w2->changeColor(sf::Color(240, 98, 146));
		w3->changeColor(sf::Color(240, 98, 146));
		w4->changeColor(sf::Color(240, 98, 146));
		static_cast<Ball*>(ball)->setBallType(level - 1);
	}
}



void Game::handleEvents() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}

	if (getMenuState() || getPauseState() || winState != 0 || selectMode || instructionState || isOnePlayer == -1) {
		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
		int menuIndex = menu->HandleMouseClick(mousePos);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			if (menuIndex == 0) {
				isOnePlayer = -1;
			} else if (menuIndex == 1) {
				instructionState = true;
				menuState = false;
			} else if (menuIndex == 2) {
				gameState = false;
			} else if (menuIndex == 3) {
				pauseState = !pauseState;
			} else if (menuIndex == 4) {
				menuState = true;
				isOnePlayer = -2;
				pauseState = false;
				instructionState = false;
			} else if (menuIndex == 5) {
				menuState = false;
				reset();
				pauseState = !pauseState;
				winState = 0;
			} else if (menuIndex == 6) {
				menuState = false;
				winState = 0;
				isOnePlayer = 1;

				selectMode = true;
			} else if (menuIndex == 7) {
				menuState = false;
				selectMode = true;
				winState = 0;
				isOnePlayer = 0;
			
			}  else if (menuIndex == 9) {
				selectMode = false;
				level = 1;
				reset();
				loadLevel();
			} else if (menuIndex == 10) {
				selectMode = false;
				level = 2;
				reset();
				loadLevel();
			} else if (menuIndex == 11) {
				selectMode = false;
				level = 3;
				reset();
				loadLevel();
			} else if (menuIndex == 8) {
				level++;
				loadLevel();
				winState = 0;
				reset();
			}
		}
	}
	if (!getPauseState() && !getMenuState()) {
		if (sf::Keyboard::isKeyPressed(controls[0])) {
			if (player_one->getY() > 150)
				static_cast<Player*>(player_one)->move(0, -1, 0.4);
		}
		if (sf::Keyboard::isKeyPressed(controls[1])) {
			if (player_one->getY() < 600)
				static_cast<Player*>(player_one)->move(0, 1, 0.4);
		}
		if (sf::Keyboard::isKeyPressed(controls[2]) && isOnePlayer == 0) {
			if (player_two->getY() > 150)
				static_cast<Player*>(player_two)->move(0, -1, 0.4);
		}
		if (sf::Keyboard::isKeyPressed(controls[3]) && isOnePlayer == 0) {
			if (player_two->getY() < 600)
				static_cast<Player*>(player_two)->move(0, 1, 0.4);
		}

	}

	if (event.key.code == sf::Keyboard::P) {
		pauseState = !pauseState;
	}


}

void Game::reset() {
	static_cast<Ball*>(ball)->setX(WINDOW_WIDTH / 2 );
	static_cast<Ball*>(ball)->setY(WINDOW_HEIGHT / 2);
	static_cast<Player*>(player_one)->setX(25);
	static_cast<Player*>(player_one)->setY(WINDOW_HEIGHT / 2);
	static_cast<Player*>(player_two)->setX(970);
	static_cast<Player*>(player_two)->setY(WINDOW_HEIGHT / 2);
	static_cast<Player*>(player_one)->setScore(0);
	static_cast<Player*>(player_two)->setScore(0);
}

void Game::checkScore(){
	if( ball->checkColision(w4->getX(), w4->getY(), w4->getWidth(), w4->getHeight()) == 4) {
		static_cast<Player*>(player_two)->setScore(static_cast<Player*>(player_two)->getScore() + 1);
		static_cast<Ball*>(ball)->initBall(1, 1, 0.2);
	}
	if( ball->checkColision(w2->getX(), w2->getY(), w2->getWidth(), w2->getHeight()) == 2) {
		static_cast<Player*>(player_one)->setScore(static_cast<Player*>(player_one)->getScore() + 1);
		static_cast<Ball*>(ball)->initBall(-1, -1, 0.2);
	}
	int score1 = static_cast<Player*>(player_one)->getScore();
	int score2 = static_cast<Player*>(player_two)->getScore();
	if (score1 == 10) 
	{
		if (isOnePlayer == 1) {
			winState = 1;
			reset();
			level++;
		} else if(isOnePlayer == 0){
			winState = 1;
		}
		loadLevel();
	}
	if (score2 == 10) {
		if (isOnePlayer == 1) {
			winState = 2;
			reset();
			level++;
		} else if(isOnePlayer == 0){
			winState = 2;
		}
		loadLevel();
	}
}

void Game::update() {
	handleEvents();
	if (isOnePlayer == 1) {
		getAImove(ball->getX(), ball->getY(), player_two->getX(), player_two->getY());
	}
	if (!getPauseState() && !getMenuState() && instructionState == false) {
		static_cast<Ball*>(ball)->update(listEntity);
	}
	checkScore();
}

void Game::render() {
	window->clear();
	if (getMenuState() && isOnePlayer != -1) {
		menu->render(window);
	} else if (isOnePlayer == -1) {
		menu->selectPlayer(window);
	} else if(selectMode == true) {
		menu->renderSelect(window);
	} else if (winState != 0 && ((level == 4 && isOnePlayer == 1) || isOnePlayer == 0 ) ) {
		menu->renderWinState(window, winState, level, isOnePlayer);
	} if (instructionState == true && !getMenuState()) {
		menu->renderInstruction(window);

	} else if((!getMenuState()) && instructionState == false && selectMode == false && winState == false){
		if (isOnePlayer == 1) {
			menu->renderTextLevel(window, level);
		}
		line->render(window);
		//window->draw(level_text);
		for(std::list<Entity*>::iterator it=listEntity.begin();it!=listEntity.end();++it)
		{
			(*it)->render(window);       
		}
		if (getPauseState()) {
			menu->renderOption(window);
		}

	}

	window->display();
}

void Game::getAImove(double xBall, double yBall, double xPlayer, double yPlayer){
	int getMove = AIBrain->decideMove(xBall, yBall, xPlayer, yPlayer);
	if (getMove == 1 && player_two->getY() < 600) {
		static_cast<Player*>(player_two)->move(0, 1, 0.3);
	} else if (getMove == -1 && player_two->getY() > 150) {
		static_cast<Player*>(player_two)->move(0, -1, 0.3);
	}
}

void Game::close() {
	gameState = false;
	for(std::list<Entity*>::iterator it=listEntity.begin();it!=listEntity.end();++it)
	{
		delete *it;      
	}
	delete line;
	delete AIBrain;
	delete window;
	window = nullptr;
	menu = nullptr;
	ball = nullptr;
}
