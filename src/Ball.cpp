#include "Ball.h"

Ball::Ball(float x, float y) : xVelocity(-4), yVelocity(-4) {
    shape.setSize(sf::Vector2f(50, 50));
    shape.setPosition(x, y);
}

sf::RectangleShape& Ball::getShape() {
    return shape;
}

void Ball::setTexture(const sf::Texture* texture) {
    shape.setTexture(texture);
}

void Ball::move() {
    shape.move(xVelocity, yVelocity);
}

void Ball::reverseXVelocity() {
    xVelocity = -xVelocity;
}

void Ball::reverseYVelocity() {
    yVelocity = -yVelocity;
}
