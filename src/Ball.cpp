#include <Ball.hpp>

Ball::Ball(int x, int y)
    : positionX(x), positionY(y) {}

int Ball::getPositionX() const {
    return positionX;
}

int Ball::getPositionY() const {
    return positionY;
}
