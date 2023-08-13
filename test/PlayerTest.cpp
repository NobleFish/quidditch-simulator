// Include files for the test
#include <gtest/gtest.h>
#include <Player.hpp>
#include <Location.hpp>
#include <iostream>

namespace playerTest {
// The fixture for testing class Foo.
class PlayerTest : public ::testing::Test {
    
};

TEST_F(PlayerTest, Initialization)
{    
    // CurrentLocation
    Location testLocation;
    testLocation.x = 1;
    testLocation.y = 0;

    Player p1("Player1", {1,0}, 5.0F, 4.0F);

    EXPECT_EQ(p1.getPlayerName(), "Player1");
    EXPECT_EQ(p1.getLocation(), testLocation);
    EXPECT_EQ(p1.getMoveSpeed(),5.0F);
    EXPECT_EQ(p1.getThrowSpeed(),4.0F);
    EXPECT_FALSE(p1.carrying());
    EXPECT_EQ(p1.getActiveBall(), nullptr);

}

TEST_F(PlayerTest, ManualUpdates)
{    
    // CurrentLocation
    Location testLocation;
    testLocation.x = 2;
    testLocation.y = 1;

    Player p1("Player1", {1,0}, 5.0F, 4.0F);

    p1.setLocation({2,1});
    EXPECT_EQ(p1.getLocation(), testLocation);
    
    p1.setMoveSpeed(2.5F);
    EXPECT_EQ(p1.getMoveSpeed(),2.5F);
    
    p1.setThrowSpeed(3.5F);
    EXPECT_EQ(p1.getThrowSpeed(),3.5F);

}

TEST_F(PlayerTest, TakePossession)
{    
    Ball b1({1,0});
    b1.setVelocity(1.0F);
    b1.setTarget({10,10});
    Player p1("Player1", {1,0}, 5.0F, 4.0F);

    p1.takePossession(&b1);

    EXPECT_TRUE(p1.carrying());
    EXPECT_EQ(p1.getActiveBall(), &b1);
    EXPECT_TRUE(b1.getPossession());
    EXPECT_EQ(b1.getVelocity(),0.0F);
    EXPECT_EQ(b1.getTarget(), p1.getLocation());

}

TEST_F(PlayerTest, LosePossession)
{    
    Ball b1({1,0});
    Player p1("Player1", {1,0}, 5.0F, 4.0F);

    p1.takePossession(&b1);
    p1.releasePossession();

    EXPECT_FALSE(p1.carrying());
    EXPECT_EQ(p1.getActiveBall(), nullptr);

}

TEST_F(PlayerTest, TakePossessionConflict)
{    
    Ball b1({1,0});
    
    Player p1("Player1", {1,0}, 5.0F, 4.0F);
    Player p2("Player2", {2,2}, 5.0F, 4.0F);

    // p1 has ball
    p1.takePossession(&b1);
    EXPECT_TRUE(p1.carrying());
    EXPECT_EQ(p1.getActiveBall(), &b1);

    // p2 should not be able to claim that ball
    p2.takePossession(&b1);
    EXPECT_FALSE(p2.carrying());
    EXPECT_NE(p2.getActiveBall(), &b1);

}

TEST_F(PlayerTest, Move)
{    
    Location testLocation = {2,2};
    Player p1("Player1", {1,0}, 5.0F, 4.0F);

    p1.moveTo(testLocation);
    EXPECT_EQ(p1.getLocation(),testLocation);
}

TEST_F(PlayerTest, MoveWithBall)
{    
    Location testLocation = {2,2};
    Ball b1({1,0});
    Player p1("Player1", {1,0}, 5.0F, 4.0F);

    p1.takePossession(&b1);

    p1.moveTo(testLocation);

    EXPECT_EQ(p1.getLocation(),testLocation);
    EXPECT_EQ(p1.getActiveBall()->getLocation(), testLocation);
    EXPECT_EQ(b1.getTarget(), testLocation);
}

TEST_F(PlayerTest, PassBall)
{    
    Ball b1({0,0});
    Player p1("Player1", {0,0}, 5.0F, 4.0F);
    Player p2("Player2", {2,2}, 5.0F, 4.0F);

    p1.takePossession(&b1);
    p1.passTo(p2.getLocation());
    // p1 lost possession of b1
    EXPECT_FALSE(p1.carrying());
    EXPECT_EQ(p1.getActiveBall(), nullptr);
    // target of ball is p2, with p1's throwSpeed as ball velocity
    EXPECT_EQ(b1.getTarget(), p2.getLocation());
    EXPECT_EQ(b1.getVelocity(), p1.getThrowSpeed());

    p2.takePossession(&b1);
    // p2 has possession of b1
    EXPECT_TRUE(p2.carrying());
    EXPECT_EQ(p2.getActiveBall(), &b1);
    

}

TEST_F(PlayerTest, ShootBall)
{    
    Location goalLocation = {2,2};
    Ball b1({1,0});
    Player p1("Player1", {1,0}, 5.0F, 4.0F);
    p1.takePossession(&b1);

    p1.shootAt(goalLocation);
    // p1 lost possession of b1
    EXPECT_FALSE(p1.carrying());
    EXPECT_EQ(p1.getActiveBall(), nullptr);
    // target of ball is goalLocation, with p1's throwSpeed as ball velocity
    EXPECT_EQ(b1.getTarget(), goalLocation);
    EXPECT_EQ(b1.getVelocity(), p1.getThrowSpeed());

}

}  // namespace

