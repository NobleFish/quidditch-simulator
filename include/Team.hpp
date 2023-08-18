#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <Player.hpp>
#include <algorithm>
#include <ranges>



class Team {
    public:
        explicit Team(std::string initTeamName);

        const std::string& getTeamName() const;
        void setTeamName(std::string newTeamName);

        void rosterAdd(const Player& newPlayer);
        const Player& rosterLookup(const Player& pKey) const;
        void rosterRemove(const Player& pKey);

        std::vector<Player> getRoster() const;

        bool isValidTeam() const;

    private:
        bool validTeam = false;
        std::string teamName = "";
        std::vector<Player> roster = {};

        void updateTeamValidity();
        unsigned short seekerCount = 0;
        unsigned short chaserCount = 0;
        unsigned short beaterCount = 0;
        unsigned short keeperCount = 0;
        
};

class PlayerNotFoundException : public std::runtime_error {
public:
    explicit PlayerNotFoundException(const std::string& playerName)
        : std::runtime_error("Player not found: " + playerName) {}
};