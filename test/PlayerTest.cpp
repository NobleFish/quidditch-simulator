
// Include files for the test
#include <gtest/gtest.h>

namespace playerTest {
// The fixture for testing class Foo.
class PlayerTest : public ::testing::Test {
    /*
    protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    
    PlayerTest() {
        // You can do set-up work for each test here.
    }

    ~PlayerTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    */
};


TEST_F(PlayerTest, Initialization)
{    
    // Tests
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
