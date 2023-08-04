#include <Ball.hpp>

Ball::Ball(int x, int y): positionX(x), positionY(y) {
    
}

int Ball::getPositionX() const {
    return positionX;
}

int Ball::getPositionY() const {
    return positionY;
}

Location Ball::getLocation() const {
    return {x(positionX), y(positionY)}
} 


int Ball::getVelocity() const {
    return velocity;
}

void Ball::update(){

}