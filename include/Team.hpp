#pragma once
#include <string>
#include <vector>
#include <Player.hpp>
#include <algorithm>
#include <ranges>

class Team {
    public:
        explicit Team(std::string initTeamName);

        const std::string& getTeamName() const;
        void setTeamName(std::string newTeamName);

        void addToRoster(const Player& newPlayer);
        int rosterLookup(const Player& pKey) const;
        void removeFromRoster(const Player& pKey);

        std::vector<Player> getRoster() const;

    private:
        bool validTeam = false;
        std::string teamName = "";
        std::vector<Player> roster = {};

};