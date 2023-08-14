#pragma once
#include <iostream>

#include <Player.hpp>
#include <Ball.hpp>
#include <Location.hpp>

class PlayerInstance : public Player {
public:
    PlayerInstance(const Player& basePlayer, Location startLocation);

    void moveTo(Location movementLocation);
    void passTo(Location targetLocation);
    void shootAt(Location targetLocation);
    
    void takePossession(Ball& ball);
    void releasePossession();

    Location getLocation() const;
    void setLocation(Location newLocation);

    bool carrying() const;

    const Ball* getActiveBall() const;

private:
    Location currentLocation;
    bool hasBall = false;
    Ball* activeBall = nullptr;
};
