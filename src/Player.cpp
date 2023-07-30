#include "Player.hpp"

const int Player::FieldWidth = 100; // Example field width
const int Player::FieldHeight = 50; // Example field height

Player::Player(int x, int y, double skillLevel)
    : positionX(x), positionY(y), skillLevel(skillLevel), hasBall(false) {}

void Player::move(int deltaX, int deltaY) {
    // Implement player movement within the field boundaries
    // You can add boundary checks here to avoid moving outside the field
    positionX += deltaX;
    positionY += deltaY;
}

void Player::dribble(int deltaX, int deltaY) {
    // Update the ball's position while dribbling
    // Assuming the ball is an external object and the Player class has access to it
    // ball.setPosition(ball.getPositionX() + deltaX, ball.getPositionY() + deltaY);
    // Additional dribbling logic if needed
}

void Player::pass(int targetX, int targetY, double passSpeed) {
    // Implement passing logic and update ball's position and direction
    // ball.setPosition(targetX, targetY);
    // ball.setVelocity(passSpeed);
    // Additional passing logic if needed
    hasBall = false;
}

void Player::shoot(int targetX, int targetY, double shotSpeed) {
    // Implement shooting logic and update ball's position and velocity
    // ball.setPosition(targetX, targetY);
    // ball.setVelocity(shotSpeed);
    // Additional shooting logic if needed
    hasBall = false;
}

int Player::getPositionX() const {
    return positionX;
}

int Player::getPositionY() const {
    return positionY;
}

double Player::getSkillLevel() const {
    return skillLevel;
}
