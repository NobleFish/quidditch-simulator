#include <Player.hpp>

Player::Player(int posX, int posY, double initSkillLevel) : positionX(posX), positionY(posY), skillLevel(initSkillLevel)
{

}

void Player::move(int deltaX, int deltaY)
{
    positionX += deltaX;
    positionY += deltaY;

}

void Player::takePossession(Ball& ball){
    activeBall = ball;
    ball.setPossession(true);
}

void Player::pass(int targetX, int targetY, double passSpeed)
{
    if(hasBall){

    }
}
void Player::shoot(int targetX, int targetY, double shotSpeed){

}

int Player::getPositionX() const {return positionX;}
int Player::getPositionY() const {return positionY;}
