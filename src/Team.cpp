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

void Team::rosterAdd(const Player& newPlayer)
{
    roster.push_back(newPlayer);
    
    switch(newPlayer.getRole())
    {
        using enum Player::Role;
        case KEEPER:
            keeperCount++;
            break;
        case CHASER:
            chaserCount++;
            break;
        case BEATER:
            beaterCount++;
            break;
        case SEEKER:
            seekerCount++;
            break;
    }
    updateTeamValidity();
}

void Team::rosterRemove(const Player& pKey)
{
    if(auto it = std::ranges::find(roster, pKey); it != roster.end())
    {
        roster.erase(it);
        switch(pKey.getRole())
        {
            using enum Player::Role;
            case KEEPER:
                keeperCount--;
                break;
            case CHASER:
                chaserCount--;
                break;
            case BEATER:
                beaterCount--;
                break;
            case SEEKER:
                seekerCount--;
                break;
        }
        updateTeamValidity();
    }
    else
    {
        throw PlayerNotFoundException(pKey.getPlayerName());
    }
}

const Player& Team::rosterLookup(const Player& pKey) const
{
    auto it = std::ranges::find(roster, pKey);
    if(it != roster.end())
    {
        return *it;
    }
    else
    {
        throw PlayerNotFoundException(pKey.getPlayerName());
    }
}

std::vector<Player> Team::getRoster() const
{
    return roster;
}

void Team::updateTeamValidity()
{
    if(
        keeperCount >= 1 && 
        beaterCount >= 2 && 
        chaserCount >= 3 && 
        seekerCount >= 1
      )
    {
        validTeam = true;
    }
    else
    {
        validTeam = false;
    }
}

bool Team::isValidTeam() const 
{
    //std::cout << "\nKeeper Count:" << keeperCount;
    //std::cout << "\nBeater Count:" << beaterCount;
    //std::cout << "\nChaser Count:" << chaserCount;
    //std::cout << "\nSeeker Count:" << seekerCount << std::endl;
    
    return validTeam;
}