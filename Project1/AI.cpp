#include "AI.h"

int AI::decideMove(double xBall, double yBall, double xPlayer, double yPlayer){
	if (yBall > yPlayer + 25) return 1;
	if (yBall < yPlayer + 25) return -1;
	return 0;
}