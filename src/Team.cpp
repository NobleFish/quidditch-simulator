#include <Team.hpp>

Team::Team(std::string initTeamName) : teamName(std::move(initTeamName)){}

const std::string& Team::getTeamName() const
{
    return teamName;
}
void Team::setTeamName(std::string newTeamName)
{
    teamName = std::move(newTeamName);
}

void Team::addToRoster(const Player& newPlayer)
{
    roster.push_back(newPlayer);
}

std::vector<Player> Team::getRoster() const
{
    return roster;
}

int Team::rosterLookup(const Player& pKey) const
{
   return -1;
}

void Team::removeFromRoster(const Player& pKey)
{
    
}