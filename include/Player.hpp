#pragma once
#include<string>

class Player {
public:
    enum class Role 
    {
        KEEPER,  // 0
        BEATER,  // 1
        CHASER,  // 2
        SEEKER   // 3
    };

    explicit Player(std::string pName, Role pRole);

    const std::string& getPlayerName() const;

    float getMoveSpeed() const;
    void setMoveSpeed(float newMoveSpeed);

    float getThrowSpeed() const;
    void setThrowSpeed(float newThrowSpeed);

    Role getRole() const;

    friend bool operator== (const Player& lhp,const Player& rhp)
    {
        return (lhp.player_id == rhp.player_id);
    }

private: 
    int player_id;
    std::string playerName = "";
    Role playerRole;

    //Attributes w/ default values
    float moveSpeed = 0.5;
    float throwSpeed = 0.5;
    

    static int idProvider;
};