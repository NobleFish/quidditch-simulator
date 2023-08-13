#include <Player.hpp>

Player::Player(std::string pName,Location startLocation, float mSpeed, float tSpeed) : playerName(std::move(pName)),currentLocation(startLocation), moveSpeed(mSpeed), throwSpeed(tSpeed)
{

}

void Player::moveTo(Location movementLocation)
{
    std::cout << playerName << " moving to" << movementLocation << std::endl; 
    // Implement Player Velocity
    currentLocation = movementLocation;

    if(hasBall)
    {
        activeBall->setLocation(movementLocation);
        activeBall->setTarget(movementLocation);
    }

}

void Player::takePossession(Ball* ball){
    
    // Reach should be implemented
    if(!ball->getPossession())
    {
        activeBall = ball;
        activeBall->setPossession(true);
        activeBall->setLocation(currentLocation);
        // Player Velocity should be implemented
        activeBall->setVelocity(0.0F);
        activeBall->setTarget(currentLocation);
        hasBall = true;
    }
}

void Player::passTo(Location target)
{
    if(hasBall){
        std::cout << playerName << " passing @ " << target << std::endl;
        activeBall->setTarget(target);
        activeBall->setVelocity(throwSpeed);
        releasePossession();
    }

}
void Player::shootAt(Location target){
    if(hasBall){
        std::cout << playerName << " shooting @ " << target << std::endl;
        activeBall->setTarget(target);
        activeBall->setVelocity(throwSpeed);
        releasePossession();
    }
}

void Player::releasePossession(){
    activeBall->setPossession(false);
    activeBall = nullptr;
    hasBall = false;
}

Location Player::getLocation() const {return currentLocation;}
void Player::setLocation(Location newLocation){currentLocation = newLocation;}

const std::string& Player::getPlayerName() const {return playerName;};

float Player::getMoveSpeed() const {return moveSpeed;}
void Player::setMoveSpeed(float newMoveSpeed) {moveSpeed = newMoveSpeed;}

float Player::getThrowSpeed() const {return throwSpeed;}
void Player::setThrowSpeed(float newThrowSpeed) {throwSpeed = newThrowSpeed;}

bool Player::carrying() const {return hasBall;}
Ball* Player::getActiveBall() const {return activeBall;}