// Include files for the test
#include <gtest/gtest.h>
#include <Player.hpp>

namespace playerTest {
// The fixture for testing class Foo.
class PlayerTest : public ::testing::Test {
    
};

TEST_F(PlayerTest, Initialization)
{    
    Player p1("Player1", 5.0F, 4.0F);

    EXPECT_EQ(p1.getPlayerName(), "Player1");
    EXPECT_EQ(p1.getMoveSpeed(),5.0F);
    EXPECT_EQ(p1.getThrowSpeed(),4.0F);
}

TEST_F(PlayerTest, ManualUpdates)
{    
    Player p1("Player1", 5.0F, 4.0F);
    
    p1.setMoveSpeed(2.5F);
    EXPECT_EQ(p1.getMoveSpeed(),2.5F);
    
    p1.setThrowSpeed(3.5F);
    EXPECT_EQ(p1.getThrowSpeed(),3.5F);

}


}  // namespace

