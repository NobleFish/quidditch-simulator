#pragma once

#include <Ball.hpp>

class Player {
public:
    Player(Location startLocation, double skillLevel);

    /*
    void move(Location movementLocation);
    void carry(Location movementLocation);
    void pass(Location targetLocation, double passSpeed);
    void shoot(Location targetLocation, double shotSpeed);
    
    void takePossession(Ball& ball);

    int getPositionX() const;
    int getPositionY() const;
    */

private:
    int positionX;
    int positionY;
    double skillLevel;
    bool hasBall;
    Ball& activeBall;
};
