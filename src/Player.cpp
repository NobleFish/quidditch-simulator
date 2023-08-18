#include <Player.hpp>

int Player::idProvider = 0;

Player::Player(std::string pName, Role pRole) : playerName(std::move(pName)), playerRole(pRole)
{
    player_id = ++idProvider;
}

// Add setPlayerName() function
const std::string& Player::getPlayerName() const {return playerName;}

float Player::getMoveSpeed() const {return moveSpeed;}
void Player::setMoveSpeed(float newMoveSpeed) {moveSpeed = newMoveSpeed;}

float Player::getThrowSpeed() const {return throwSpeed;}
void Player::setThrowSpeed(float newThrowSpeed) {throwSpeed = newThrowSpeed;}

Player::Role Player::getRole() const {return playerRole;}
