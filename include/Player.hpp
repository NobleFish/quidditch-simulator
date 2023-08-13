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
    void releasePossession();

    Location getLocation() const;
    void setLocation(Location newLocation);

    float getMoveSpeed() const;
    void setMoveSpeed(float newMoveSpeed);

    float getThrowSpeed() const;
    void setThrowSpeed(float newThrowSpeed);

    bool carrying() const;

    Ball* getActiveBall() const;

private:
    std::string playerName = "";
    Location currentLocation;
    float moveSpeed;
    float throwSpeed;
    bool hasBall = false;
    Ball* activeBall = nullptr;
};
