#include "AI.h"

AI::AI(float x, float y) : Player(x, y) {}

void AI::update(float ballY) {
    if (ballY < shape.getPosition().y) {
        setVelocity(-2);
    } else if (ballY > shape.getPosition().y) {
        setVelocity(2);
    } else {
        setVelocity(0);
    }
    move();
}
