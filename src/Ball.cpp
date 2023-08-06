#include <Ball.hpp>

Ball::Ball(Location startLocation): location(startLocation)
{

}

Location Ball::getLocation() const 
{
    return location;
}

void Ball::setLocation(Location newLocation)
{
    location = newLocation;
}

float Ball::getVelocity() const 
{
    return velocity;
}

void Ball::setVelocity(float newVelocity)
{
    velocity = newVelocity;
}

bool Ball::getPossession() const
{
    return possession;
}

void Ball::setPossession(bool isControlled){
    possession = isControlled;
}

Location Ball::getTarget() const
{
    return targetLocation;
}

void Ball::setTarget(Location newTargetLocation)
{
    targetLocation = newTargetLocation;
}