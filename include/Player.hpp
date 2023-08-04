#pragma once

#include <Ball.hpp>

class Player {
public:
    Player(int x, int y, double skillLevel);

    void move(int deltaX, int deltaY);
    void carry(int deltaX, int deltaY);
    void pass(int targetX, int targetY, double passSpeed);
    void shoot(int targetX, int targetY, double shotSpeed);
    
    void takePossession(Ball& ball);

    int getPositionX() const;
    int getPositionY() const;

private:
    int positionX;
    int positionY;
    double skillLevel;
    bool hasBall;
    Ball& activeBall;
};
