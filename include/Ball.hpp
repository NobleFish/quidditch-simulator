#pragma once

class Ball {
public:
    Ball(int x, int y);

    int getPositionX() const;
    int getPositionY() const;

    // Add any additional ball-related properties and functions

private:
    int positionX;
    int positionY;
    // Add any other ball-related properties
};