#pragma once

#include <iostream>

#include <Ball.hpp>
#include <Location.hpp>

class Player {
public:
    Player(std::string pName,Location startLocation, float moveSpeed, float throwSpeed);

    const std::string& getPlayerName() const;
    void moveTo(Location movementLocation);
    void passTo(Location targetLocation);
    void shootAt(Location targetLocation);
    
    void takePossession(Ball* ball);

    Location getLocation() const;
    Location setLocation(Location newLocation);

private:
    std::string playerName = "";
    Location currentLocation;
    float moveSpeed;
    float throwSpeed;
    bool hasBall = false;
    Ball* activeBall = nullptr;
};
