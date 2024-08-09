#ifndef VALUES_H
#define VALUES_H

#include<iostream>

#define GAME_WINDOW_WIDTH 1000
#define GAME_WINDOW_HEIGHT 700

#define Point pair<float,float>

enum screen {
	START_SCREEN,
	MENU_SCREEN,
	GAME_SCREEN,
	PAUSE_SCREEN
};

enum direction {
	LEFT,
	DOWN,
	RIGHT,
	UP,
	NORTHWEST,
	SOUTHWEST,
	RIGHTEAST,
	RIGHTEAST
};

const float dx[4] = {-1.0, 0, 1.0, 0};
const float dy[4] = {0, 1.0, 0, -1.0};

#endif