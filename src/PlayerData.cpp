class PlayerData {
public:
    int playerNumber;
    double skillLevel;
    std::string playerName;
    int teamNumber;

    // Constructor
    PlayerData(int playerNumber, double skillLevel, const std::string& playerName, int teamNumber)
        : playerNumber(playerNumber), skillLevel(skillLevel), playerName(playerName), teamNumber(teamNumber) {}
};