#include <Player.hpp>

Player::Player(std::string pName, float mSpeed, float tSpeed) : playerName(std::move(pName)), moveSpeed(mSpeed), throwSpeed(tSpeed)
{

}

const std::string& Player::getPlayerName() const {return playerName;}

float Player::getMoveSpeed() const {return moveSpeed;}
void Player::setMoveSpeed(float newMoveSpeed) {moveSpeed = newMoveSpeed;}

float Player::getThrowSpeed() const {return throwSpeed;}
void Player::setThrowSpeed(float newThrowSpeed) {throwSpeed = newThrowSpeed;}