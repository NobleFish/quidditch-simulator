
#include <PlayerInstance.hpp>

PlayerInstance::PlayerInstance(const Player& basePlayer, Location startLocation) : Player(basePlayer), currentLocation(startLocation)
{}


void PlayerInstance::moveTo(Location movementLocation)
{
    std::cout << getPlayerName() << " moving to" << movementLocation << std::endl; 
    // Implement Player Velocity
    currentLocation = movementLocation;

    if(hasBall)
    {
        activeBall->setLocation(movementLocation);
        activeBall->setTarget(movementLocation);
    }

}

void PlayerInstance::takePossession(Ball& ball){
    
    // Reach should be implemented
    if(!ball.getPossession())
    {
        activeBall = &ball;
        activeBall->setPossession(true);
        activeBall->setLocation(currentLocation);
        // Player Velocity should be implemented
        activeBall->setVelocity(0.0F);
        activeBall->setTarget(currentLocation);
        hasBall = true;
    }
}

void PlayerInstance::passTo(Location target)
{
    if(hasBall){
        std::cout << getPlayerName() << " passing @ " << target << std::endl;
        activeBall->setTarget(target);
        activeBall->setVelocity(getThrowSpeed());
        releasePossession();
    }

}

void PlayerInstance::shootAt(Location target){
    if(hasBall){
        std::cout << getPlayerName()  << " shooting @ " << target << std::endl;
        activeBall->setTarget(target);
        activeBall->setVelocity(getThrowSpeed());
        releasePossession();
    }
}

void PlayerInstance::releasePossession(){
    activeBall->setPossession(false);
    activeBall = nullptr;
    hasBall = false;
}

Location PlayerInstance::getLocation() const {return currentLocation;}
void PlayerInstance::setLocation(Location newLocation){currentLocation = newLocation;}

bool PlayerInstance::carrying() const {return hasBall;}
const Ball* PlayerInstance::getActiveBall() const {return activeBall;}
