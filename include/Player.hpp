#pragma once
#include<string>

class Player {
public:
    explicit Player(std::string pName, float moveSpeed, float throwSpeed);

    const std::string& getPlayerName() const;

    float getMoveSpeed() const;
    void setMoveSpeed(float newMoveSpeed);

    float getThrowSpeed() const;
    void setThrowSpeed(float newThrowSpeed);

private: 
    std::string playerName = "";
    float moveSpeed;
    float throwSpeed;

};