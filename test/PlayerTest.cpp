#include <Player.hpp>
#include <gtest/gtest.h>

// Test Player Initialization
TEST(PlayerTest, Initialization) {
    Player player(1,1,1);
    EXPECT_EQ(1,player.getPositionX());
}
/*
// Test Player Movement
TEST(PlayerTest, Movement) {
    Player player(0, 0, 1.0);
    player.move(1, 2); // Move right by 1, up by 2
    EXPECT_EQ(player.getPositionX(), 1);
    EXPECT_EQ(player.getPositionY(), 2);

    player.move(-2, 1); // Move left by 2, up by 1
    EXPECT_EQ(player.getPositionX(), -1);
    EXPECT_EQ(player.getPositionY(), 3);
}

// Test Dribbling
TEST(PlayerTest, Dribbling) {
    Player player(0, 0, 1.0);
    Ball ball(0, 0);
    player.dribble(2, 2); // Dribble right by 2, up by 2
    EXPECT_EQ(player.getPositionX(), 2);
    EXPECT_EQ(player.getPositionY(), 2);
    EXPECT_EQ(ball.getPositionX(), 2); // Ball moves with player
    EXPECT_EQ(ball.getPositionY(), 2);
}

// Test Passing
TEST(PlayerTest, Passing) {
    Player player1(0, 0, 1.0);
    Player player2(5, 5, 0.8);
    Ball ball(0, 0);
    player1.hasBall = true; // Player1 has the ball
    player1.pass(player2.getPositionX(), player2.getPositionY(), 1.5); // Pass to player2

    EXPECT_EQ(player1.hasBall, false); // Player1 loses the ball after passing
    EXPECT_EQ(ball.getPositionX(), player2.getPositionX());
    EXPECT_EQ(ball.getPositionY(), player2.getPositionY());
}

// Test Shooting
TEST(PlayerTest, Shooting) {
    Player player(0, 0, 1.0);
    Ball ball(0, 0);
    player.hasBall = true; // Player has the ball
    player.shoot(2, 2, 3.0); // Shoot to position (2, 2) with speed 3.0

    EXPECT_EQ(player.hasBall, false); // Player loses the ball after shooting
    EXPECT_EQ(ball.getPositionX(), 2);
    EXPECT_EQ(ball.getPositionY(), 2);
    EXPECT_EQ(ball.getVelocity(), 3.0);
}

// Test Player Boundaries
TEST(PlayerTest, Boundaries) {
    Player player(0, 0, 1.0);
    player.move(-100, 200); // Try to move far outside the field boundaries

    // Expect player to stay within boundaries
    EXPECT_LE(player.getPositionX(), Player::FieldWidth / 2);
    EXPECT_GE(player.getPositionX(), -Player::FieldWidth / 2);
    EXPECT_LE(player.getPositionY(), Player::FieldHeight / 2);
    EXPECT_GE(player.getPositionY(), -Player::FieldHeight / 2);
}

// Test Player Has Ball
TEST(PlayerTest, HasBall) {
    Player player(0, 0, 1.0);
    Ball ball(0, 0);
    player.hasBall = true; // Player has the ball

    // Move the player
    player.move(1, 1);
    // Expect the ball to move with the player since they have the ball
    EXPECT_EQ(ball.getPositionX(), 1);
    EXPECT_EQ(ball.getPositionY(), 1);

    // Now pass the ball to another player
    Player player2(5, 5, 0.8);
    player.pass(player2.getPositionX(), player2.getPositionY(), 1.5);

    // Expect player to lose the ball after passing
    EXPECT_EQ(player.hasBall, false);
}
*/
// Add more test cases as needed for other functionalities of the Player class.

