#pragma once

#include <QuidditchUtilities.hpp>

// Generic Ball Class
class Ball {
public:
    Ball(int x, int y);

    int getPositionX() const;
    int getPositionY() const;

    int getVelocity() const;
    

    // Add any additional ball-related properties and functions

private:
    int positionX;
    int positionY;
    int velocity;
    // Add any other ball-related properties
};