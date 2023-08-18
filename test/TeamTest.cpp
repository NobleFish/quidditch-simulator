
// Include files for the test
#include <gtest/gtest.h>
#include <Team.hpp>
#include <Player.hpp>

namespace teamTest {
// The fixture for testing class Foo.
class TeamTest : public ::testing::Test {};

TEST_F(TeamTest, Initialization)
{    
    Team t1("Team1");
    EXPECT_EQ(t1.getTeamName(),"Team1");
    EXPECT_TRUE(t1.getRoster().empty());
}

TEST_F(TeamTest, ManualUpdates)
{    
    Team t1("Team1");
    t1.setTeamName("ModTeam1");
    EXPECT_EQ(t1.getTeamName(),"ModTeam1");

}

TEST_F(TeamTest, rosterInteraction)
{    
    Team t1("Team1");

    Player p1("Player1",Player::Role::KEEPER);
    Player p2("Player2",Player::Role::KEEPER);

    // Adding a player to the roster
    t1.rosterAdd(p1);
    // Lookup up a player in the roster
    EXPECT_EQ(t1.rosterLookup(p1), p1);

    // PlayerNotFoundException thrown when given player is not in roster.
    EXPECT_THROW(t1.rosterLookup(p2), PlayerNotFoundException);
    try 
    {
        t1.rosterLookup(p2);
    }
    catch (const PlayerNotFoundException& e){
        EXPECT_STREQ(e.what(), "Player not found: Player2");
    }
    t1.rosterAdd(p2);

    // Removing a player from the roster
    t1.rosterRemove(p1);
    EXPECT_THROW(t1.rosterLookup(p1), PlayerNotFoundException);

    // Roster is functional after remove
    EXPECT_EQ(t1.rosterLookup(p2),p2);
    
}

TEST_F(TeamTest, TeamValidity){   
    using enum Player::Role;
    Team t1("Team1");
    EXPECT_FALSE(t1.isValidTeam());

    Player p1("Player1",KEEPER);
    Player p2("Player2",BEATER);
    Player p3("Player3",BEATER);
    Player p4("Player4",CHASER);
    Player p5("Player5",CHASER);
    Player p6("Player6",CHASER);
    Player p7("Player7",SEEKER);
    t1.rosterAdd(p1);
    t1.rosterAdd(p2);
    t1.rosterAdd(p3);
    t1.rosterAdd(p4);
    t1.rosterAdd(p5);
    t1.rosterAdd(p6);
    t1.rosterAdd(p7);
    EXPECT_TRUE(t1.isValidTeam());

    t1.rosterRemove(p1);
    EXPECT_FALSE(t1.isValidTeam());
    
}
}  // namespace
