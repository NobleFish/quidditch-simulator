#include <Player.hpp>
#include <gtest/gtest.h>


// Test Player Initialization
TEST(PlayerTest, Initialization) {
    Player player(0,1,1);
    EXPECT_EQ(player.getPositionX(),0);
    EXPECT_EQ(player.getPositionY(),1);
}
