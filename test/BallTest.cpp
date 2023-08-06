#include <Ball.hpp>
#include <QuidditchUtilityStructs.hpp>
#include <gtest/gtest.h>

namespace ballTest {
// The fixture for testing class Foo.
class BallTest : public ::testing::Test {};

TEST_F(BallTest, Initialization)
{    
    // Ball initializes correctly with initialization list for Location
    Ball genericBall_A({0,1}); 

    EXPECT_EQ(genericBall_A.getLocation().x,0);
    EXPECT_EQ(genericBall_A.getLocation().y,1);

    // Ball initializes correctly with predefined Location
    Location testLocation;
    testLocation.x = 2;
    testLocation.y = 3;
    
    Ball genericBall_B(testLocation);

    EXPECT_EQ(genericBall_B.getLocation().x,2);
    EXPECT_EQ(genericBall_B.getLocation().y,3);

    // Initial velocity is 0.0F    
    EXPECT_EQ(genericBall_A.getVelocity(), 0.0F);
    
    // Initial targetLocation is {0,0}
    testLocation = {0,0};
    EXPECT_EQ(genericBall_A.getTarget(), testLocation);

    // Initial possession is false
    EXPECT_FALSE(genericBall_A.getPossession());

}

TEST_F(BallTest, ManualUpdates)
{    
    // Generic Ball @ {0,0}
    Ball testBall({0,0});
    
    // CurrentLocation
    Location testLocation;
    testLocation.x = 1;
    testLocation.y = 2;

    testBall.setLocation(testLocation);
    EXPECT_EQ(testBall.getLocation(),testLocation);

    // Velocity
    testBall.setVelocity(1.0F);
    EXPECT_EQ(testBall.getVelocity(),1.0F);    
    
    // Possession Boolean 
    testBall.setPossession(true);
    EXPECT_TRUE(testBall.getPossession());

    // TargetLocation 
    Location testTargetLocation;
    testTargetLocation.x = 3;
    testTargetLocation.y = 4;

    testBall.setTarget(testTargetLocation);
    EXPECT_EQ(testBall.getTarget(),testTargetLocation);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}