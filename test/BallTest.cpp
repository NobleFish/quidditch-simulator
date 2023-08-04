#include <Ball.hpp>
#include <gtest/gtest.h>


TEST(BallTest, Initialization){
    Ball genericBall(0,1);

    EXPECT_EQ(genericBall.getPositionX(),0);
    EXPECT_EQ(genericBall.getPositionY(),1);

}
