#pragma once

class Player {
public:
    Player(int x, int y, double skillLevel);

    void move(int deltaX, int deltaY);
    void dribble(int deltaX, int deltaY);
    void pass(int targetX, int targetY, double passSpeed);
    void shoot(int targetX, int targetY, double shotSpeed);

    int getPositionX() const;
    int getPositionY() const;
    double getSkillLevel() const;

    static const int FieldWidth;
    static const int FieldHeight;

private:
    int positionX;
    int positionY;
    double skillLevel;
    bool hasBall;
};
