#include <Player.hpp>

Player::Player(std::string pName,Location startLocation, float mSpeed, float tSpeed) : playerName(std::move(pName)),currentLocation(startLocation), moveSpeed(mSpeed), throwSpeed(tSpeed)
{

}

void Player::moveTo(Location movementLocation)
{
    std::cout << playerName << " moving to" << movementLocation << std::endl; 
    currentLocation = movementLocation;

    if(hasBall){
        activeBall->setLocation(movementLocation);
    }

}

void Player::takePossession(Ball* ball){
    activeBall = ball;
    activeBall->setPossession(true);
    hasBall = true;

}

void Player::passTo(Location target)
{
    if(hasBall){
        std::cout << playerName << " passing @ " << target << std::endl;
        activeBall->setTarget(target);
        hasBall = false;
    }

}
void Player::shootAt(Location target){
    if(hasBall){
        std::cout << playerName << " shooting @ " << target << std::endl;
        activeBall->setTarget(target);
        hasBall = false;
    }
}

Location Player::getLocation() const {return currentLocation;}
const std::string& Player::getPlayerName() const {return playerName;};