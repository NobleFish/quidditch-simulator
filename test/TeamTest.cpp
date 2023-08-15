
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

TEST_F(TeamTest, AddToRoster)
{    
    Team t1("Team1");

    // Need to change this :: Player instance vs. Player
    Player p1("Player1",0.4F, 0.4F);

    t1.addToRoster(p1);
    EXPECT_GE(t1.rosterLookup(p1), 0);

}

TEST_F(TeamTest, TeamValidity){   
    EXPECT_EQ(true,false);
}

TEST_F(TeamTest, StartingLineUp){
    EXPECT_EQ(true,false);
}


}  // namespace
